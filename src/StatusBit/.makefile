# User-configurable options

StatusBit-CFLAGS ::=
StatusBit-LFLAGS ::=

# Boilerplate that shouldn't be touched

StatusBit-path ::= $(net-src-dir)/StatusBit

StatusBit-header-files-and-directories ::= \
	$(patsubst \
		./%,$\
		$(StatusBit-path)/%,$\
		$(shell \
			cd $(StatusBit-path); \
			find . -mindepth 1 -type f -regex '\.\(/[^./][^/]*\)*\.hpp' -or \
				-type d -regex '\.\(/[^./][^/]*\)*' \
		)$\
	)

StatusBit-header-files ::= $(filter %.hpp, $(StatusBit-header-files-and-directories))
StatusBit-directories ::= $(filter-out %.hpp, $(StatusBit-header-files-and-directories))

StatusBit-dependency-candidates ::= \
	$(shell sed -ne 's~\#include *<\(.*\)\.hpp>.*~\1~p' $(StatusBit-path)/include.hpp)

StatusBit-dependencies ::= $(filter \
	$(net-export-targets),$\
	$(StatusBit-dependency-candidates)$\
)

StatusBit-dependency-targets ::= $(foreach \
	StatusBit-dependency,$\
	$(StatusBit-dependencies),$\
	$($(StatusBit-dependency)-target)$\
)

StatusBit-dependency-install-targets ::= $(foreach \
	StatusBit-dependency,$\
	$(StatusBit-dependencies),$\
	$($(StatusBit-dependency)-install-target)$\
)

StatusBit-inc-dirs ::= $(net-inc-dir) $(net-reference-inc-dirs)
StatusBit-inc-dir-flags ::= $(StatusBit-inc-dirs:%=-I %)
StatusBit-include-flags ::= -I $(net-src-dir) $(StatusBit-inc-dir-flags)

StatusBit-top-file ::= $(StatusBit-path)/.build/StatusBit.hpp
StatusBit-build-file ::= $(StatusBit-path)/.build/StatusBit.hpp.gch

StatusBit-include-file ::= $(net-inc-dir)/StatusBit.hpp
StatusBit-include-path ::= $(net-inc-dir)/StatusBit
StatusBit-include-files ::= \
	$(StatusBit-header-files:$(StatusBit-path)/%=$(StatusBit-include-path)/%)
StatusBit-include-directories ::= \
	$(StatusBit-directories:$(StatusBit-path)/%=$(StatusBit-include-path)/%)

StatusBit-target ::= $(StatusBit-include-files) $(StatusBit-include-file)

StatusBit-install-file ::= $(net-header-install-dir)/StatusBit.hpp
StatusBit-install-path ::= $(net-header-install-dir)/StatusBit
StatusBit-install-files ::= \
	$(StatusBit-header-files:$(StatusBit-path)/%=$(StatusBit-install-path)/%)
StatusBit-install-directories ::= \
	$(StatusBit-directories:$(StatusBit-path)/%=$(StatusBit-install-path)/%)

StatusBit-install-target ::= $(StatusBit-install-files) $(StatusBit-install-file)

.PHONY : StatusBit
StatusBit : $(StatusBit-target)

.PHONY : StatusBit-clean
StatusBit-clean :
	rm -rf $(StatusBit-include-file)
	rm -rf $(StatusBit-include-files)
	rm -rf $(StatusBit-include-directories)
	rm -rf $(StatusBit-build-file)
	rm -rf $(StatusBit-top-file)

.PHONY : StatusBit-install
StatusBit-install : $(StatusBit-install-target)

.PHONY : StatusBit-uninstall
StatusBit-uninstall :
	rm -rf $(StatusBit-install-file)
	rm -rf $(StatusBit-install-files)
	rm -rf $(StatusBit-install-directories)

$(StatusBit-top-file) : $(StatusBit-header-files) $(StatusBit-directories)
	cliide header-include-file $(StatusBit-path) > $(@)

$(StatusBit-build-file) : $(StatusBit-top-file) $(StatusBit-header-files) $(StatusBit-dependency-targets)
	$(net-CPP) $(StatusBit-include-flags) $(net-CFLAGS) $(StatusBit-CFLAGS) -c -o $(@) $(<)

$(StatusBit-include-path)/%.hpp : $(StatusBit-path)/%.hpp $(StatusBit-build-file)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(StatusBit-include-file) : $(StatusBit-top-file) $(StatusBit-build-file)
	cp $(<) $(@)

$(StatusBit-install-path)/%.hpp : $(StatusBit-include-path)/%.hpp $(StatusBit-dependency-install-targets)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(StatusBit-install-file) : $(StatusBit-include-file)
	cp $(<) $(@)
