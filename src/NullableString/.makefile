# User-configurable options

NullableString-CFLAGS ::=
NullableString-LFLAGS ::=

# Boilerplate that shouldn't be touched

NullableString-path ::= $(net-src-dir)/NullableString

NullableString-header-files-and-directories ::= \
	$(patsubst \
		./%,$\
		$(NullableString-path)/%,$\
		$(shell \
			cd $(NullableString-path); \
			find . -mindepth 1 -type f -regex '\.\(/[^./][^/]*\)*\.hpp' -or \
				-type d -regex '\.\(/[^./][^/]*\)*' \
		)$\
	)

NullableString-header-files ::= $(filter %.hpp, $(NullableString-header-files-and-directories))
NullableString-directories ::= $(filter-out %.hpp, $(NullableString-header-files-and-directories))

NullableString-dependency-candidates ::= \
	$(shell sed -ne 's~\#include *<\(.*\)\.hpp>.*~\1~p' $(NullableString-path)/include.hpp)

NullableString-dependencies ::= $(filter \
	$(net-export-targets),$\
	$(NullableString-dependency-candidates)$\
)

NullableString-dependency-targets ::= $(foreach \
	NullableString-dependency,$\
	$(NullableString-dependencies),$\
	$($(NullableString-dependency)-target)$\
)

NullableString-dependency-install-targets ::= $(foreach \
	NullableString-dependency,$\
	$(NullableString-dependencies),$\
	$($(NullableString-dependency)-install-target)$\
)

NullableString-inc-dirs ::= $(net-inc-dir) $(net-reference-inc-dirs)
NullableString-inc-dir-flags ::= $(NullableString-inc-dirs:%=-I %)
NullableString-include-flags ::= -I $(net-src-dir) $(NullableString-inc-dir-flags)

NullableString-top-file ::= $(NullableString-path)/.build/NullableString.hpp
NullableString-build-file ::= $(NullableString-path)/.build/NullableString.hpp.gch

NullableString-include-file ::= $(net-inc-dir)/NullableString.hpp
NullableString-include-path ::= $(net-inc-dir)/NullableString
NullableString-include-files ::= \
	$(NullableString-header-files:$(NullableString-path)/%=$(NullableString-include-path)/%)
NullableString-include-directories ::= \
	$(NullableString-directories:$(NullableString-path)/%=$(NullableString-include-path)/%)

NullableString-target ::= $(NullableString-include-files) $(NullableString-include-file)

NullableString-install-file ::= $(net-header-install-dir)/NullableString.hpp
NullableString-install-path ::= $(net-header-install-dir)/NullableString
NullableString-install-files ::= \
	$(NullableString-header-files:$(NullableString-path)/%=$(NullableString-install-path)/%)
NullableString-install-directories ::= \
	$(NullableString-directories:$(NullableString-path)/%=$(NullableString-install-path)/%)

NullableString-install-target ::= $(NullableString-install-files) $(NullableString-install-file)

.PHONY : NullableString
NullableString : $(NullableString-target)

.PHONY : NullableString-clean
NullableString-clean :
	rm -rf $(NullableString-include-file)
	rm -rf $(NullableString-include-files)
	rm -rf $(NullableString-include-directories)
	rm -rf $(NullableString-build-file)
	rm -rf $(NullableString-top-file)

.PHONY : NullableString-install
NullableString-install : $(NullableString-install-target)

.PHONY : NullableString-uninstall
NullableString-uninstall :
	rm -rf $(NullableString-install-file)
	rm -rf $(NullableString-install-files)
	rm -rf $(NullableString-install-directories)

$(NullableString-top-file) : $(NullableString-header-files) $(NullableString-directories)
	cliide header-include-file $(NullableString-path) > $(@)

$(NullableString-build-file) : $(NullableString-top-file) $(NullableString-header-files) $(NullableString-dependency-targets)
	$(net-CPP) $(NullableString-include-flags) $(net-CFLAGS) $(NullableString-CFLAGS) -c -o $(@) $(<)

$(NullableString-include-path)/%.hpp : $(NullableString-path)/%.hpp $(NullableString-build-file)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(NullableString-include-file) : $(NullableString-top-file) $(NullableString-build-file)
	cp $(<) $(@)

$(NullableString-install-path)/%.hpp : $(NullableString-include-path)/%.hpp $(NullableString-dependency-install-targets)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(NullableString-install-file) : $(NullableString-include-file)
	cp $(<) $(@)
