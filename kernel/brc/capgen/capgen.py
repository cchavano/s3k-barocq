#!/usr/bin/env python3
import argparse
import re
import yaml


def binpack(bin_capacities, items):
    """
    Solves the binpacking problem optimally
    """
    if not items:
        return {i: [] for i in bin_capacities.keys()}
    name, size = items[0]
    for i, capacity in bin_capacities.items():
        if size > capacity:
            continue
        new_bins = bin_capacities.copy()
        new_bins[i] -= size
        packing = binpack(new_bins, items[1:])
        if packing is not None:
            packing[i].append(name)
            return packing
    return None


class Capability:
    def __init__(self, name, fields):
        self._name = name
        self._fields = fields.keys()
        self._sizes = fields.copy()
        items = list(fields.items())
        self._alloc = binpack({'word0': 60}, items)
        if not self._alloc:
            raise Exception(f"No allocation for {name} capability")
        self._offsets = {}
        for word, word_fields in self._alloc.items():
            offset = 4
            for field in word_fields[::-1]:
                self._offsets[field] = offset
                offset += self._sizes[field]

    def type(self):
        return f"CAPTY_{self._name.upper()}"

    def name(self):
        return self._name

    def size(self, field):
        return self._sizes[field]

    def offset(self, field):
        return self._offsets[field]

    def word(self, field):
        for word, fields in self._alloc.items():
            if field in fields:
                return word
        return None

    def fields(self, word=None):
        if word:
            return self._alloc[word]
        return self._fields

    def constr_fun(self):
        output = []
        parameters = [f"{name}: u64" for name in self.fields() if name != "pad"]
        output.append(f"def mk_{self.name()}({', '.join(parameters)}) : u64 =")
        builder = f"  {self.type()}"
        for field in self.fields('word0'):
            if field == "pad":
                continue
            offset = self.offset(field)
            builder += f" | {field} << {offset}UL"
        output.append(builder)
        return "\n".join(output)

    def getter_fun(self, field):
        name = self.name()
        word = self.word(field)
        offset = self.offset(field)
        mask = (1 << self.size(field)) - 1
        output = []
        if self.size(field) == 1:
            output.append(f"def {name}_get_{field}(cap: cap_t) : bool =")
            if offset:
                output.append(f"  ((cap >> {offset}UL) & 0x1UL) as bool")
            else:
                output.append(f"  (cap & 0x1UL) as bool")
        else:
            output.append(f"def {name}_get_{field}(cap: cap_t) : u64 =")
            if offset:
                output.append(f"  (cap >> {offset}UL) & {hex(mask)}UL")
            else:
                output.append(f"  (cap & {hex(mask)}UL)")
        return "\n".join(output)

    def setter_fun(self, field):
        name = self.name()
        word = self.word(field)
        offset = self.offset(field)
        mask = (1 << self.size(field)) - 1
        output = []
        if self.size(field) == 1:
            output.append(f"def {name}_set_{field}(cap: cap_t, v: bool) : u64 =")
            if offset:
                output.append(f"  (cap & ~{hex(mask)}UL) | ((v as u64) << {offset}UL)")
            else:
                output.append(f"  (cap & ~{hex(mask)}UL) | (v as u64)")
        else:
            output.append(f"def {name}_set_{field}(cap: cap_t, v: u64) : u64 =")
            if offset:
                mask = mask << offset
                output.append(f"  (cap & ~{hex(mask)}UL) | (v << {offset}UL)")
            else:
                output.append(f"  (cap & ~{hex(mask)}UL) | v")
        return "\n".join(output)


# Open the file and load the file
def main(capabilities):
    output = ["module Cap\n", "type cap_t = u64\n", "(* Capability types *)"]
    for i, cap in enumerate(capabilities):
        output.append(f"def CAPTY_{cap['name'].upper()} : u64 = {i}UL")
    output.append("\n(* Number of capability types (incl. null cap) *)")
    output.append(f"def CAPTY_COUNT : u64 = {len(capabilities)}UL")
    output.append("\n(* Capability type *)")
    output.append(f"def get_type(cap: cap_t) : u64 = (cap & 0xfUL)")
    for cap in capabilities:
        output.append(f"\n(* {cap['name']} capability *)")
        capability = Capability(**cap)
        output.append(capability.constr_fun())
        for field in capability.fields():
            if field == "pad":
                continue
            output.append(capability.getter_fun(field))
        for field in capability.fields():
            if field == "pad":
                continue
            output.append(capability.setter_fun(field))

    output = "\n".join(output)
    output = output.replace("\t", " "*8)
    return output


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
            prog="gen_cap",
            description="Generate capability header "
                        "file from yaml description")
    parser.add_argument("yaml", type=argparse.FileType('r'))
    parser.add_argument("output", type=argparse.FileType('w'))
    args = parser.parse_args()
    data = yaml.safe_load(args.yaml)
    print(main(**data), file=args.output)
