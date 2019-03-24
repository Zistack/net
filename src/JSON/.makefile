# User-configurable options

JSON-CFLAGS ::=
JSON-LFLAGS ::=

# Boilerplate that shouldn't be touched

JSON-path ::= $(net-src-dir)/JSON

JSON-header-files-and-directories ::= \
	$(patsubst \
		./%,$\
		$(JSON-path)/%,$\
		$(shell \
			cd $(JSON-path); \
			find -type f -regex '\(/[^./][^/]*\)*\.hpp' -or \
				-type d -regex '\(/[^./][^/]*\)*' \
		)$\
	)
#	$(shell cliide list-files-and-directories $(JSON-path))

JSON-header-files ::= $(filter %.hpp, $(JSON-header-files-and-directories))
JSON-directories ::= $(filter-out %.hpp, $(JSON-header-files-and-directories))

JSON-dependency-candidates ::= \
	$(shell sed -ne 's~\#include *<\(.*\)\.hpp>.*~\1~p' $(JSON-path)/include.hpp)

JSON-dependencies ::= $(filter \
	$(net-export-targets),$\
	$(JSON-dependency-candidates)$\
)

JSON-dependency-targets ::= $(foreach \
	JSON-dependency,$\
	$(JSON-dependencies),$\
	$($(JSON-dependency)-target)$\
)

JSON-dependency-install-targets ::= $(foreach \
	JSON-dependency,$\
	$(JSON-dependencies),$\
	$($(JSON-dependency)-install-target)$\
)

JSON-inc-dirs ::= $(net-inc-dir) $(net-reference-inc-dirs)
JSON-inc-dir-flags ::= $(JSON-inc-dirs:%=-I %)
JSON-include-flags ::= -I $(net-src-dir) $(JSON-inc-dir-flags)

JSON-top-file ::= $(JSON-path)/.build/JSON.hpp
JSON-build-file ::= $(JSON-path)/.build/JSON.hpp.gch

JSON-include-file ::= $(net-inc-dir)/JSON.hpp
JSON-include-path ::= $(net-inc-dir)/JSON
JSON-include-files ::= \
	$(JSON-header-files:$(JSON-path)/%=$(JSON-include-path)/%)
JSON-include-directories ::= \
	$(JSON-directories:$(JSON-path)/%=$(JSON-include-path)/%)

JSON-target ::= $(JSON-include-files) $(JSON-include-file)

JSON-install-file ::= $(net-header-install-dir)/JSON.hpp
JSON-install-path ::= $(net-header-install-dir)/JSON
JSON-install-files ::= \
	$(JSON-header-files:$(JSON-path)/%=$(JSON-install-path)/%)
JSON-install-directories ::= \
	$(JSON-directories:$(JSON-path)/%=$(JSON-install-path)/%)

JSON-install-target ::= $(JSON-install-files) $(JSON-install-file)

.PHONY : JSON
JSON : $(JSON-target)

.PHONY : JSON-clean
JSON-clean :
	rm -rf $(JSON-include-file)
	rm -rf $(JSON-include-files)
	rm -rf $(JSON-include-directories)
	rm -rf $(JSON-build-file)
	rm -rf $(JSON-top-file)

.PHONY : JSON-install
JSON-install : $(JSON-install-target)

.PHONY : JSON-uninstall
JSON-uninstall :
	rm -rf $(JSON-install-file)
	rm -rf $(JSON-install-files)
	rm -rf $(JSON-install-directories)

$(JSON-top-file) : $(JSON-header-files) $(JSON-directories)
	cliide header-include-file $(JSON-path) > $(@)

$(JSON-build-file) : $(JSON-top-file) $(JSON-header-files) $(JSON-dependency-targets)
	$(net-CPP) $(JSON-include-flags) $(net-CFLAGS) $(JSON-CFLAGS) -c -o $(@) $(<)

$(JSON-include-path)/%.hpp : $(JSON-path)/%.hpp $(JSON-build-file)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(JSON-include-file) : $(JSON-top-file) $(JSON-build-file)
	cp $(<) $(@)

$(JSON-install-path)/%.hpp : $(JSON-include-path)/%.hpp $(JSON-dependency-install-targets)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(JSON-install-file) : $(JSON-include-file)
	cp $(<) $(@)
