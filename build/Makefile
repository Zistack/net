# User-configurable options

SHELL ::= /bin/sh

net-WARNINGS ::= -Wchar-subscripts -Wcomment -Wformat=2 -Winit-self -Wimplicit \
-Wignored-qualifiers -Wmain -Wmissing-braces -Wmissing-include-dirs \
-Wparentheses -Wsequence-point -Wreturn-type -Wswitch -Wtrigraphs -Wunused \
-Wuninitialized -Wstrict-aliasing -Warray-bounds -Wfloat-equal -Wundef \
-Wno-endif-labels -Wpointer-arith -Wtype-limits -Wconversion -Wenum-compare \
-Wsign-conversion -Waddress -Wmissing-field-initializers \
-Wvolatile-register-var -Wno-write-strings -Wsign-promo

net-CPP ::= clang++
net-CFLAGS ::= $(net-WARNINGS) -Werror -pipe -std=c++17
net-LFLAGS ::=

net-header-install-dir ::= /usr/local/include
net-binary-install-dir ::= /usr/local/bin
net-library-install-dir ::= /usr/local/lib

# Boilerplate that should not be touched

ifndef net-base-dir
	net-base-dir ::= $(realpath ..)
	net-previously-included ::=
else
	net-target-prefix ::= net-
endif

net-inc-dir ::= $(net-base-dir)/inc
net-src-dir ::= $(net-base-dir)/src
net-bin-dir ::= $(net-base-dir)/bin
net-ref-dir ::= $(net-base-dir)/ref
net-build-dir ::= $(net-base-dir)/build

include $(net-build-dir)/.makefile-includes

net-module-cleans = $(net-modules:%=%-clean)
net-module-installs = $(net-modules:%=%-install)
net-module-uninstalls = $(net-modules:%=%-uninstall)

.DEFAULT_GOAL := all

.PHONY : all
$(net-target-prefix)all : $(net-modules)

.PHONY : clean
$(net-target-prefix)clean : $(net-module-cleans)

.PHONE : install
$(net-target-prefix)install : $(net-module-installs)

.PHONY : uninstall
$(net-target-prefix)uninstall : $(net-module-uninstalls)
