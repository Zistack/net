# User-configurable options

Status-CFLAGS ::=
Status-LFLAGS ::=

# Boilerplate that shouldn't be touched

Status-path ::= $(net-src-dir)/Status

Status-header-files-and-directories ::= \
	$(patsubst \
		./%,$\
		$(Status-path)/%,$\
		$(shell \
			cd $(Status-path); \
			find . -mindepth 1 -type f -regex '\.\(/[^./][^/]*\)*\.hpp' -or \
				-type d -regex '\.\(/[^./][^/]*\)*' \
		)$\
	)

Status-header-files ::= $(filter %.hpp, $(Status-header-files-and-directories))
Status-directories ::= $(filter-out %.hpp, $(Status-header-files-and-directories))

Status-dependency-candidates ::= \
	$(shell sed -ne 's~\#include *<\(.*\)\.hpp>.*~\1~p' $(Status-path)/include.hpp)

Status-dependencies ::= $(filter \
	$(net-export-targets),$\
	$(Status-dependency-candidates)$\
)

Status-dependency-targets ::= $(foreach \
	Status-dependency,$\
	$(Status-dependencies),$\
	$($(Status-dependency)-target)$\
)

Status-dependency-install-targets ::= $(foreach \
	Status-dependency,$\
	$(Status-dependencies),$\
	$($(Status-dependency)-install-target)$\
)

Status-inc-dirs ::= $(net-inc-dir) $(net-reference-inc-dirs)
Status-inc-dir-flags ::= $(Status-inc-dirs:%=-I %)
Status-include-flags ::= -I $(net-src-dir) $(Status-inc-dir-flags)

Status-top-file ::= $(Status-path)/.build/Status.hpp
Status-build-file ::= $(Status-path)/.build/Status.hpp.gch

Status-include-file ::= $(net-inc-dir)/Status.hpp
Status-include-path ::= $(net-inc-dir)/Status
Status-include-files ::= \
	$(Status-header-files:$(Status-path)/%=$(Status-include-path)/%)
Status-include-directories ::= \
	$(Status-directories:$(Status-path)/%=$(Status-include-path)/%)

Status-target ::= $(Status-include-files) $(Status-include-file)

Status-install-file ::= $(net-header-install-dir)/Status.hpp
Status-install-path ::= $(net-header-install-dir)/Status
Status-install-files ::= \
	$(Status-header-files:$(Status-path)/%=$(Status-install-path)/%)
Status-install-directories ::= \
	$(Status-directories:$(Status-path)/%=$(Status-install-path)/%)

Status-install-target ::= $(Status-install-files) $(Status-install-file)

.PHONY : Status
Status : $(Status-target)

.PHONY : Status-clean
Status-clean :
	rm -rf $(Status-include-file)
	rm -rf $(Status-include-files)
	rm -rf $(Status-include-directories)
	rm -rf $(Status-build-file)
	rm -rf $(Status-top-file)

.PHONY : Status-install
Status-install : $(Status-install-target)

.PHONY : Status-uninstall
Status-uninstall :
	rm -rf $(Status-install-file)
	rm -rf $(Status-install-files)
	rm -rf $(Status-install-directories)

$(Status-top-file) : $(Status-header-files) $(Status-directories)
	cliide header-include-file $(Status-path) > $(@)

$(Status-build-file) : $(Status-top-file) $(Status-header-files) $(Status-dependency-targets)
	$(net-CPP) $(Status-include-flags) $(net-CFLAGS) $(Status-CFLAGS) -c -o $(@) $(<)

$(Status-include-path)/%.hpp : $(Status-path)/%.hpp $(Status-build-file)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(Status-include-file) : $(Status-top-file) $(Status-build-file)
	cp $(<) $(@)

$(Status-install-path)/%.hpp : $(Status-include-path)/%.hpp $(Status-dependency-install-targets)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(Status-install-file) : $(Status-include-file)
	cp $(<) $(@)
