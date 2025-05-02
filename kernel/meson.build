project(
	's3k',
	'c',
	version : '0.1',
	meson_version : '>= 1.5.1',
	default_options : [
		'buildtype=debug',
		'warning_level=2',
		'c_std=c11',
		'b_ndebug=if-release',
	],
)

sources = files(
	'src/head.S',
	'src/stack.S',
	'src/trap.S',
	'src/cap/ipc.c',
	'src/cap/monitor.c',
	'src/cap/ops.c',
	'src/cap/pmp.c',
	'src/cap/table.c',
	'src/cap/util.c',
	'src/exception.c',
	'src/interrupt.c',
	'src/kernel.c',
	'src/kprint.c',
	'src/proc.c',
	'src/sched.c',
	'src/syscall.c',
	'src/trap.c',
	'src/rtc.c',
)

include_directories = include_directories(
	'include',
)

if get_option('platdir') == ''
	platdir = meson.current_source_dir() / 'plat' / get_option('plat')
else
	platdir = get_option('platdir') / get_option('plat')
endif

c_args = [
	'-ffreestanding',
	'-fno-stack-protector',
	'-fno-builtin',
	'-fno-omit-frame-pointer',
	'-include', platdir / 'config.h',
	'-include', 's3k_conf.h',
]

link_args = [
	'-nostdlib',
	'-T', platdir / 'linker.ld',
]

executable('s3k',
	sources : sources,
	include_directories : include_directories,
	c_args : c_args,
	link_args : link_args,
)
