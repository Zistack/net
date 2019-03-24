# User-configurable options

GetConfig-CFLAGS ::=
GetConfig-LFLAGS ::=

# Boilerplate that shouldn't be touched

GetConfig-path ::= $(net-src-dir)/GetConfig

GetConfig-header-files-and-directories ::= \
	$(patsubst \
		./%,$\
		$(GetConfig-path)/%,$\
		$(shell \
			cd $(GetConfig-path); \
			find -type f -regex '\(/[^./][^/]*\)*\.hpp' -or \
				-type d -regex '\(/[^./][^/]*\)*' \
		)$\
	)
#	$(shell cliide list-files-and-directories $(GetConfig-path))

GetConfig-header-files ::= $(filter %.hpp, $(GetConfig-header-files-and-directories))
GetConfig-directories ::= $(filter-out %.hpp, $(GetConfig-header-files-and-directories))

GetConfig-dependency-candidates ::= \
	$(shell sed -ne 's~\#include *<\(.*\)\.hpp>.*~\1~p' $(GetConfig-path)/include.hpp)

GetConfig-dependencies ::= $(filter \
	$(net-export-targets),$\
	$(GetConfig-dependency-candidates)$\
)

GetConfig-dependency-targets ::= $(foreach \
	GetConfig-dependency,$\
	$(GetConfig-dependencies),$\
	$($(GetConfig-dependency)-target)$\
)

GetConfig-dependency-install-targets ::= $(foreach \
	GetConfig-dependency,$\
	$(GetConfig-dependencies),$\
	$($(GetConfig-dependency)-install-target)$\
)

GetConfig-inc-dirs ::= $(net-inc-dir) $(net-reference-inc-dirs)
GetConfig-inc-dir-flags ::= $(GetConfig-inc-dirs:%=-I %)
GetConfig-include-flags ::= -I $(net-src-dir) $(GetConfig-inc-dir-flags)

GetConfig-top-file ::= $(GetConfig-path)/.build/GetConfig.hpp
GetConfig-build-file ::= $(GetConfig-path)/.build/GetConfig.hpp.gch

GetConfig-include-file ::= $(net-inc-dir)/GetConfig.hpp
GetConfig-include-path ::= $(net-inc-dir)/GetConfig
GetConfig-include-files ::= \
	$(GetConfig-header-files:$(GetConfig-path)/%=$(GetConfig-include-path)/%)
GetConfig-include-directories ::= \
	$(GetConfig-directories:$(GetConfig-path)/%=$(GetConfig-include-path)/%)

GetConfig-target ::= $(GetConfig-include-files) $(GetConfig-include-file)

GetConfig-install-file ::= $(net-header-install-dir)/GetConfig.hpp
GetConfig-install-path ::= $(net-header-install-dir)/GetConfig
GetConfig-install-files ::= \
	$(GetConfig-header-files:$(GetConfig-path)/%=$(GetConfig-install-path)/%)
GetConfig-install-directories ::= \
	$(GetConfig-directories:$(GetConfig-path)/%=$(GetConfig-install-path)/%)

GetConfig-install-target ::= $(GetConfig-install-files) $(GetConfig-install-file)

.PHONY : GetConfig
GetConfig : $(GetConfig-target)

.PHONY : GetConfig-clean
GetConfig-clean :
	rm -rf $(GetConfig-include-file)
	rm -rf $(GetConfig-include-files)
	rm -rf $(GetConfig-include-directories)
	rm -rf $(GetConfig-build-file)
	rm -rf $(GetConfig-top-file)

.PHONY : GetConfig-install
GetConfig-install : $(GetConfig-install-target)

.PHONY : GetConfig-uninstall
GetConfig-uninstall :
	rm -rf $(GetConfig-install-file)
	rm -rf $(GetConfig-install-files)
	rm -rf $(GetConfig-install-directories)

$(GetConfig-top-file) : $(GetConfig-header-files) $(GetConfig-directories)
	cliide header-include-file $(GetConfig-path) > $(@)

$(GetConfig-build-file) : $(GetConfig-top-file) $(GetConfig-header-files) $(GetConfig-dependency-targets)
	$(net-CPP) $(GetConfig-include-flags) $(net-CFLAGS) $(GetConfig-CFLAGS) -c -o $(@) $(<)

$(GetConfig-include-path)/%.hpp : $(GetConfig-path)/%.hpp $(GetConfig-build-file)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(GetConfig-include-file) : $(GetConfig-top-file) $(GetConfig-build-file)
	cp $(<) $(@)

$(GetConfig-install-path)/%.hpp : $(GetConfig-include-path)/%.hpp $(GetConfig-dependency-install-targets)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(GetConfig-install-file) : $(GetConfig-include-file)
	cp $(<) $(@)
