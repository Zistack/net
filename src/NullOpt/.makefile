# User-configurable options

NullOpt-CFLAGS ::=
NullOpt-LFLAGS ::=

# Boilerplate that shouldn't be touched

NullOpt-path ::= $(net-src-dir)/NullOpt

NullOpt-header-files-and-directories ::= \
	$(patsubst \
		./%,$\
		$(NullOpt-path)/%,$\
		$(shell \
			cd $(NullOpt-path); \
			find -type f -regex '\(/[^./][^/]*\)*\.hpp' -or \
				-type d -regex '\(/[^./][^/]*\)*' \
		)$\
	)
#	$(shell cliide list-files-and-directories $(NullOpt-path))

NullOpt-header-files ::= $(filter %.hpp, $(NullOpt-header-files-and-directories))
NullOpt-directories ::= $(filter-out %.hpp, $(NullOpt-header-files-and-directories))

NullOpt-dependency-candidates ::= \
	$(shell sed -ne 's~\#include *<\(.*\)\.hpp>.*~\1~p' $(NullOpt-path)/include.hpp)

NullOpt-dependencies ::= $(filter \
	$(net-export-targets),$\
	$(NullOpt-dependency-candidates)$\
)

NullOpt-dependency-targets ::= $(foreach \
	NullOpt-dependency,$\
	$(NullOpt-dependencies),$\
	$($(NullOpt-dependency)-target)$\
)

NullOpt-dependency-install-targets ::= $(foreach \
	NullOpt-dependency,$\
	$(NullOpt-dependencies),$\
	$($(NullOpt-dependency)-install-target)$\
)

NullOpt-inc-dirs ::= $(net-inc-dir) $(net-reference-inc-dirs)
NullOpt-inc-dir-flags ::= $(NullOpt-inc-dirs:%=-I %)
NullOpt-include-flags ::= -I $(net-src-dir) $(NullOpt-inc-dir-flags)

NullOpt-top-file ::= $(NullOpt-path)/.build/NullOpt.hpp
NullOpt-build-file ::= $(NullOpt-path)/.build/NullOpt.hpp.gch

NullOpt-include-file ::= $(net-inc-dir)/NullOpt.hpp
NullOpt-include-path ::= $(net-inc-dir)/NullOpt
NullOpt-include-files ::= \
	$(NullOpt-header-files:$(NullOpt-path)/%=$(NullOpt-include-path)/%)
NullOpt-include-directories ::= \
	$(NullOpt-directories:$(NullOpt-path)/%=$(NullOpt-include-path)/%)

NullOpt-target ::= $(NullOpt-include-files) $(NullOpt-include-file)

NullOpt-install-file ::= $(net-header-install-dir)/NullOpt.hpp
NullOpt-install-path ::= $(net-header-install-dir)/NullOpt
NullOpt-install-files ::= \
	$(NullOpt-header-files:$(NullOpt-path)/%=$(NullOpt-install-path)/%)
NullOpt-install-directories ::= \
	$(NullOpt-directories:$(NullOpt-path)/%=$(NullOpt-install-path)/%)

NullOpt-install-target ::= $(NullOpt-install-files) $(NullOpt-install-file)

.PHONY : NullOpt
NullOpt : $(NullOpt-target)

.PHONY : NullOpt-clean
NullOpt-clean :
	rm -rf $(NullOpt-include-file)
	rm -rf $(NullOpt-include-files)
	rm -rf $(NullOpt-include-directories)
	rm -rf $(NullOpt-build-file)
	rm -rf $(NullOpt-top-file)

.PHONY : NullOpt-install
NullOpt-install : $(NullOpt-install-target)

.PHONY : NullOpt-uninstall
NullOpt-uninstall :
	rm -rf $(NullOpt-install-file)
	rm -rf $(NullOpt-install-files)
	rm -rf $(NullOpt-install-directories)

$(NullOpt-top-file) : $(NullOpt-header-files) $(NullOpt-directories)
	cliide header-include-file $(NullOpt-path) > $(@)

$(NullOpt-build-file) : $(NullOpt-top-file) $(NullOpt-header-files) $(NullOpt-dependency-targets)
	$(net-CPP) $(NullOpt-include-flags) $(net-CFLAGS) $(NullOpt-CFLAGS) -c -o $(@) $(<)

$(NullOpt-include-path)/%.hpp : $(NullOpt-path)/%.hpp $(NullOpt-build-file)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(NullOpt-include-file) : $(NullOpt-top-file) $(NullOpt-build-file)
	cp $(<) $(@)

$(NullOpt-install-path)/%.hpp : $(NullOpt-include-path)/%.hpp $(NullOpt-dependency-install-targets)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(NullOpt-install-file) : $(NullOpt-include-file)
	cp $(<) $(@)
