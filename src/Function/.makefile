# User-configurable options

Function-CFLAGS ::=
Function-LFLAGS ::=

# Boilerplate that shouldn't be touched

Function-path ::= $(net-src-dir)/Function

Function-header-files-and-directories ::= \
	$(patsubst \
		./%,$\
		$(Function-path)/%,$\
		$(shell \
			cd $(Function-path); \
			find -type f -regex '\(/[^./][^/]*\)*\.hpp' -or \
				-type d -regex '\(/[^./][^/]*\)*' \
		)$\
	)
#	$(shell cliide list-files-and-directories $(Function-path))

Function-header-files ::= $(filter %.hpp, $(Function-header-files-and-directories))
Function-directories ::= $(filter-out %.hpp, $(Function-header-files-and-directories))

Function-dependency-candidates ::= \
	$(shell sed -ne 's~\#include *<\(.*\)\.hpp>.*~\1~p' $(Function-path)/include.hpp)

Function-dependencies ::= $(filter \
	$(net-export-targets),$\
	$(Function-dependency-candidates)$\
)

Function-dependency-targets ::= $(foreach \
	Function-dependency,$\
	$(Function-dependencies),$\
	$($(Function-dependency)-target)$\
)

Function-dependency-install-targets ::= $(foreach \
	Function-dependency,$\
	$(Function-dependencies),$\
	$($(Function-dependency)-install-target)$\
)

Function-inc-dirs ::= $(net-inc-dir) $(net-reference-inc-dirs)
Function-inc-dir-flags ::= $(Function-inc-dirs:%=-I %)
Function-include-flags ::= -I $(net-src-dir) $(Function-inc-dir-flags)

Function-top-file ::= $(Function-path)/.build/Function.hpp
Function-build-file ::= $(Function-path)/.build/Function.hpp.gch

Function-include-file ::= $(net-inc-dir)/Function.hpp
Function-include-path ::= $(net-inc-dir)/Function
Function-include-files ::= \
	$(Function-header-files:$(Function-path)/%=$(Function-include-path)/%)
Function-include-directories ::= \
	$(Function-directories:$(Function-path)/%=$(Function-include-path)/%)

Function-target ::= $(Function-include-files) $(Function-include-file)

Function-install-file ::= $(net-header-install-dir)/Function.hpp
Function-install-path ::= $(net-header-install-dir)/Function
Function-install-files ::= \
	$(Function-header-files:$(Function-path)/%=$(Function-install-path)/%)
Function-install-directories ::= \
	$(Function-directories:$(Function-path)/%=$(Function-install-path)/%)

Function-install-target ::= $(Function-install-files) $(Function-install-file)

.PHONY : Function
Function : $(Function-target)

.PHONY : Function-clean
Function-clean :
	rm -rf $(Function-include-file)
	rm -rf $(Function-include-files)
	rm -rf $(Function-include-directories)
	rm -rf $(Function-build-file)
	rm -rf $(Function-top-file)

.PHONY : Function-install
Function-install : $(Function-install-target)

.PHONY : Function-uninstall
Function-uninstall :
	rm -rf $(Function-install-file)
	rm -rf $(Function-install-files)
	rm -rf $(Function-install-directories)

$(Function-top-file) : $(Function-header-files) $(Function-directories)
	cliide header-include-file $(Function-path) > $(@)

$(Function-build-file) : $(Function-top-file) $(Function-header-files) $(Function-dependency-targets)
	$(net-CPP) $(Function-include-flags) $(net-CFLAGS) $(Function-CFLAGS) -c -o $(@) $(<)

$(Function-include-path)/%.hpp : $(Function-path)/%.hpp $(Function-build-file)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(Function-include-file) : $(Function-top-file) $(Function-build-file)
	cp $(<) $(@)

$(Function-install-path)/%.hpp : $(Function-include-path)/%.hpp $(Function-dependency-install-targets)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(Function-install-file) : $(Function-include-file)
	cp $(<) $(@)
