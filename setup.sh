#!/bin/sh

case "$1" in
 "kernel") 
 	PROJECT="kernel"
	;;
 "hello") 
 	PROJECT="examples/hello"
	;;
 *)
	echo "Invalid project"
	exit 1
	;;
esac

rm -rf build

meson setup build $PROJECT --cross-file=cross/gcc-rv64imac.ini --optimization 2