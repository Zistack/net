# User-configurable options

Switch-CFLAGS ::=
Switch-LFLAGS ::=

# Boilerplate that shouldn't be touched

Switch-path ::= $(net-src-dir)/Switch

Switch-header-files-and-directories ::= \
	$(patsubst \
		./%,$\
		$(Switch-path)/%,$\
		$(shell \
			cd $(Switch-path); \
			find -type f -regex '\(/[^./][^/]*\)*\.hpp' -or \
				-type d -regex '\(/[^./][^/]*\)*' \
		)$\
	)
#	$(shell cliide list-files-and-directories $(Switch-path))

Switch-header-files ::= $(filter %.hpp, $(Switch-header-files-and-directories))
Switch-directories ::= $(filter-out %.hpp, $(Switch-header-files-and-directories))

Switch-dependency-candidates ::= \
	$(shell sed -ne 's~\#include *<\(.*\)\.hpp>.*~\1~p' $(Switch-path)/include.hpp)

Switch-dependencies ::= $(filter \
	$(net-export-targets),$\
	$(Switch-dependency-candidates)$\
)

Switch-dependency-targets ::= $(foreach \
	Switch-dependency,$\
	$(Switch-dependencies),$\
	$($(Switch-dependency)-target)$\
)

Switch-dependency-install-targets ::= $(foreach \
	Switch-dependency,$\
	$(Switch-dependencies),$\
	$($(Switch-dependency)-install-target)$\
)

Switch-inc-dirs ::= $(net-inc-dir) $(net-reference-inc-dirs)
Switch-inc-dir-flags ::= $(Switch-inc-dirs:%=-I %)
Switch-include-flags ::= -I $(net-src-dir) $(Switch-inc-dir-flags)

Switch-top-file ::= $(Switch-path)/.build/Switch.hpp
Switch-build-file ::= $(Switch-path)/.build/Switch.hpp.gch

Switch-include-file ::= $(net-inc-dir)/Switch.hpp
Switch-include-path ::= $(net-inc-dir)/Switch
Switch-include-files ::= \
	$(Switch-header-files:$(Switch-path)/%=$(Switch-include-path)/%)
Switch-include-directories ::= \
	$(Switch-directories:$(Switch-path)/%=$(Switch-include-path)/%)

Switch-target ::= $(Switch-include-files) $(Switch-include-file)

Switch-install-file ::= $(net-header-install-dir)/Switch.hpp
Switch-install-path ::= $(net-header-install-dir)/Switch
Switch-install-files ::= \
	$(Switch-header-files:$(Switch-path)/%=$(Switch-install-path)/%)
Switch-install-directories ::= \
	$(Switch-directories:$(Switch-path)/%=$(Switch-install-path)/%)

Switch-install-target ::= $(Switch-install-files) $(Switch-install-file)

.PHONY : Switch
Switch : $(Switch-target)

.PHONY : Switch-clean
Switch-clean :
	rm -rf $(Switch-include-file)
	rm -rf $(Switch-include-files)
	rm -rf $(Switch-include-directories)
	rm -rf $(Switch-build-file)
	rm -rf $(Switch-top-file)

.PHONY : Switch-install
Switch-install : $(Switch-install-target)

.PHONY : Switch-uninstall
Switch-uninstall :
	rm -rf $(Switch-install-file)
	rm -rf $(Switch-install-files)
	rm -rf $(Switch-install-directories)

$(Switch-top-file) : $(Switch-header-files) $(Switch-directories)
	cliide header-include-file $(Switch-path) > $(@)

$(Switch-build-file) : $(Switch-top-file) $(Switch-header-files) $(Switch-dependency-targets)
	$(net-CPP) $(Switch-include-flags) $(net-CFLAGS) $(Switch-CFLAGS) -c -o $(@) $(<)

$(Switch-include-path)/%.hpp : $(Switch-path)/%.hpp $(Switch-build-file)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(Switch-include-file) : $(Switch-top-file) $(Switch-build-file)
	cp $(<) $(@)

$(Switch-install-path)/%.hpp : $(Switch-include-path)/%.hpp $(Switch-dependency-install-targets)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(Switch-install-file) : $(Switch-include-file)
	cp $(<) $(@)
