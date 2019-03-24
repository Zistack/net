# User-configurable options

URI-CFLAGS ::=
URI-LFLAGS ::=

# Boilerplate that shouldn't be touched

URI-path ::= $(net-src-dir)/URI

URI-header-files-and-directories ::= \
	$(patsubst \
		./%,$\
		$(URI-path)/%,$\
		$(shell \
			cd $(URI-path); \
			find -type f -regex '\(/[^./][^/]*\)*\.hpp' -or \
				-type d -regex '\(/[^./][^/]*\)*' \
		)$\
	)
#	$(shell cliide list-files-and-directories $(URI-path))

URI-header-files ::= $(filter %.hpp, $(URI-header-files-and-directories))
URI-directories ::= $(filter-out %.hpp, $(URI-header-files-and-directories))

URI-dependency-candidates ::= \
	$(shell sed -ne 's~\#include *<\(.*\)\.hpp>.*~\1~p' $(URI-path)/include.hpp)

URI-dependencies ::= $(filter \
	$(net-export-targets),$\
	$(URI-dependency-candidates)$\
)

URI-dependency-targets ::= $(foreach \
	URI-dependency,$\
	$(URI-dependencies),$\
	$($(URI-dependency)-target)$\
)

URI-dependency-install-targets ::= $(foreach \
	URI-dependency,$\
	$(URI-dependencies),$\
	$($(URI-dependency)-install-target)$\
)

URI-inc-dirs ::= $(net-inc-dir) $(net-reference-inc-dirs)
URI-inc-dir-flags ::= $(URI-inc-dirs:%=-I %)
URI-include-flags ::= -I $(net-src-dir) $(URI-inc-dir-flags)

URI-top-file ::= $(URI-path)/.build/URI.hpp
URI-build-file ::= $(URI-path)/.build/URI.hpp.gch

URI-include-file ::= $(net-inc-dir)/URI.hpp
URI-include-path ::= $(net-inc-dir)/URI
URI-include-files ::= \
	$(URI-header-files:$(URI-path)/%=$(URI-include-path)/%)
URI-include-directories ::= \
	$(URI-directories:$(URI-path)/%=$(URI-include-path)/%)

URI-target ::= $(URI-include-files) $(URI-include-file)

URI-install-file ::= $(net-header-install-dir)/URI.hpp
URI-install-path ::= $(net-header-install-dir)/URI
URI-install-files ::= \
	$(URI-header-files:$(URI-path)/%=$(URI-install-path)/%)
URI-install-directories ::= \
	$(URI-directories:$(URI-path)/%=$(URI-install-path)/%)

URI-install-target ::= $(URI-install-files) $(URI-install-file)

.PHONY : URI
URI : $(URI-target)

.PHONY : URI-clean
URI-clean :
	rm -rf $(URI-include-file)
	rm -rf $(URI-include-files)
	rm -rf $(URI-include-directories)
	rm -rf $(URI-build-file)
	rm -rf $(URI-top-file)

.PHONY : URI-install
URI-install : $(URI-install-target)

.PHONY : URI-uninstall
URI-uninstall :
	rm -rf $(URI-install-file)
	rm -rf $(URI-install-files)
	rm -rf $(URI-install-directories)

$(URI-top-file) : $(URI-header-files) $(URI-directories)
	cliide header-include-file $(URI-path) > $(@)

$(URI-build-file) : $(URI-top-file) $(URI-header-files) $(URI-dependency-targets)
	$(net-CPP) $(URI-include-flags) $(net-CFLAGS) $(URI-CFLAGS) -c -o $(@) $(<)

$(URI-include-path)/%.hpp : $(URI-path)/%.hpp $(URI-build-file)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(URI-include-file) : $(URI-top-file) $(URI-build-file)
	cp $(<) $(@)

$(URI-install-path)/%.hpp : $(URI-include-path)/%.hpp $(URI-dependency-install-targets)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(URI-install-file) : $(URI-include-file)
	cp $(<) $(@)
