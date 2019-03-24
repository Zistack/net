# User-configurable options

GetOpts-CFLAGS ::=
GetOpts-LFLAGS ::=

# Boilerplate that shouldn't be touched

GetOpts-path ::= $(net-src-dir)/GetOpts

GetOpts-header-files-and-directories ::= \
	$(patsubst \
		./%,$\
		$(GetOpts-path)/%,$\
		$(shell \
			cd $(GetOpts-path); \
			find -type f -regex '\(/[^./][^/]*\)*\.hpp' -or \
				-type d -regex '\(/[^./][^/]*\)*' \
		)$\
	)
#	$(shell cliide list-files-and-directories $(GetOpts-path))

GetOpts-header-files ::= $(filter %.hpp, $(GetOpts-header-files-and-directories))
GetOpts-directories ::= $(filter-out %.hpp, $(GetOpts-header-files-and-directories))

GetOpts-dependency-candidates ::= \
	$(shell sed -ne 's~\#include *<\(.*\)\.hpp>.*~\1~p' $(GetOpts-path)/include.hpp)

GetOpts-dependencies ::= $(filter \
	$(net-export-targets),$\
	$(GetOpts-dependency-candidates)$\
)

GetOpts-dependency-targets ::= $(foreach \
	GetOpts-dependency,$\
	$(GetOpts-dependencies),$\
	$($(GetOpts-dependency)-target)$\
)

GetOpts-dependency-install-targets ::= $(foreach \
	GetOpts-dependency,$\
	$(GetOpts-dependencies),$\
	$($(GetOpts-dependency)-install-target)$\
)

GetOpts-inc-dirs ::= $(net-inc-dir) $(net-reference-inc-dirs)
GetOpts-inc-dir-flags ::= $(GetOpts-inc-dirs:%=-I %)
GetOpts-include-flags ::= -I $(net-src-dir) $(GetOpts-inc-dir-flags)

GetOpts-top-file ::= $(GetOpts-path)/.build/GetOpts.hpp
GetOpts-build-file ::= $(GetOpts-path)/.build/GetOpts.hpp.gch

GetOpts-include-file ::= $(net-inc-dir)/GetOpts.hpp
GetOpts-include-path ::= $(net-inc-dir)/GetOpts
GetOpts-include-files ::= \
	$(GetOpts-header-files:$(GetOpts-path)/%=$(GetOpts-include-path)/%)
GetOpts-include-directories ::= \
	$(GetOpts-directories:$(GetOpts-path)/%=$(GetOpts-include-path)/%)

GetOpts-target ::= $(GetOpts-include-files) $(GetOpts-include-file)

GetOpts-install-file ::= $(net-header-install-dir)/GetOpts.hpp
GetOpts-install-path ::= $(net-header-install-dir)/GetOpts
GetOpts-install-files ::= \
	$(GetOpts-header-files:$(GetOpts-path)/%=$(GetOpts-install-path)/%)
GetOpts-install-directories ::= \
	$(GetOpts-directories:$(GetOpts-path)/%=$(GetOpts-install-path)/%)

GetOpts-install-target ::= $(GetOpts-install-files) $(GetOpts-install-file)

.PHONY : GetOpts
GetOpts : $(GetOpts-target)

.PHONY : GetOpts-clean
GetOpts-clean :
	rm -rf $(GetOpts-include-file)
	rm -rf $(GetOpts-include-files)
	rm -rf $(GetOpts-include-directories)
	rm -rf $(GetOpts-build-file)
	rm -rf $(GetOpts-top-file)

.PHONY : GetOpts-install
GetOpts-install : $(GetOpts-install-target)

.PHONY : GetOpts-uninstall
GetOpts-uninstall :
	rm -rf $(GetOpts-install-file)
	rm -rf $(GetOpts-install-files)
	rm -rf $(GetOpts-install-directories)

$(GetOpts-top-file) : $(GetOpts-header-files) $(GetOpts-directories)
	cliide header-include-file $(GetOpts-path) > $(@)

$(GetOpts-build-file) : $(GetOpts-top-file) $(GetOpts-header-files) $(GetOpts-dependency-targets)
	$(net-CPP) $(GetOpts-include-flags) $(net-CFLAGS) $(GetOpts-CFLAGS) -c -o $(@) $(<)

$(GetOpts-include-path)/%.hpp : $(GetOpts-path)/%.hpp $(GetOpts-build-file)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(GetOpts-include-file) : $(GetOpts-top-file) $(GetOpts-build-file)
	cp $(<) $(@)

$(GetOpts-install-path)/%.hpp : $(GetOpts-include-path)/%.hpp $(GetOpts-dependency-install-targets)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(GetOpts-install-file) : $(GetOpts-include-file)
	cp $(<) $(@)
