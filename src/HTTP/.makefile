# User-configurable options

HTTP-CFLAGS ::=
HTTP-LFLAGS ::=

# Boilerplate that shouldn't be touched

HTTP-path ::= $(net-src-dir)/HTTP

HTTP-header-files-and-directories ::= \
	$(patsubst \
		./%,$\
		$(HTTP-path)/%,$\
		$(shell \
			cd $(HTTP-path); \
			find -type f -regex '\(/[^./][^/]*\)*\.hpp' -or \
				-type d -regex '\(/[^./][^/]*\)*' \
		)$\
	)
#	$(shell cliide list-files-and-directories $(HTTP-path))

HTTP-header-files ::= $(filter %.hpp, $(HTTP-header-files-and-directories))
HTTP-directories ::= $(filter-out %.hpp, $(HTTP-header-files-and-directories))

HTTP-dependency-candidates ::= \
	$(shell sed -ne 's~\#include *<\(.*\)\.hpp>.*~\1~p' $(HTTP-path)/include.hpp)

HTTP-dependencies ::= $(filter \
	$(net-export-targets),$\
	$(HTTP-dependency-candidates)$\
)

HTTP-dependency-targets ::= $(foreach \
	HTTP-dependency,$\
	$(HTTP-dependencies),$\
	$($(HTTP-dependency)-target)$\
)

HTTP-dependency-install-targets ::= $(foreach \
	HTTP-dependency,$\
	$(HTTP-dependencies),$\
	$($(HTTP-dependency)-install-target)$\
)

HTTP-inc-dirs ::= $(net-inc-dir) $(net-reference-inc-dirs)
HTTP-inc-dir-flags ::= $(HTTP-inc-dirs:%=-I %)
HTTP-include-flags ::= -I $(net-src-dir) $(HTTP-inc-dir-flags)

HTTP-top-file ::= $(HTTP-path)/.build/HTTP.hpp
HTTP-build-file ::= $(HTTP-path)/.build/HTTP.hpp.gch

HTTP-include-file ::= $(net-inc-dir)/HTTP.hpp
HTTP-include-path ::= $(net-inc-dir)/HTTP
HTTP-include-files ::= \
	$(HTTP-header-files:$(HTTP-path)/%=$(HTTP-include-path)/%)
HTTP-include-directories ::= \
	$(HTTP-directories:$(HTTP-path)/%=$(HTTP-include-path)/%)

HTTP-target ::= $(HTTP-include-files) $(HTTP-include-file)

HTTP-install-file ::= $(net-header-install-dir)/HTTP.hpp
HTTP-install-path ::= $(net-header-install-dir)/HTTP
HTTP-install-files ::= \
	$(HTTP-header-files:$(HTTP-path)/%=$(HTTP-install-path)/%)
HTTP-install-directories ::= \
	$(HTTP-directories:$(HTTP-path)/%=$(HTTP-install-path)/%)

HTTP-install-target ::= $(HTTP-install-files) $(HTTP-install-file)

.PHONY : HTTP
HTTP : $(HTTP-target)

.PHONY : HTTP-clean
HTTP-clean :
	rm -rf $(HTTP-include-file)
	rm -rf $(HTTP-include-files)
	rm -rf $(HTTP-include-directories)
	rm -rf $(HTTP-build-file)
	rm -rf $(HTTP-top-file)

.PHONY : HTTP-install
HTTP-install : $(HTTP-install-target)

.PHONY : HTTP-uninstall
HTTP-uninstall :
	rm -rf $(HTTP-install-file)
	rm -rf $(HTTP-install-files)
	rm -rf $(HTTP-install-directories)

$(HTTP-top-file) : $(HTTP-header-files) $(HTTP-directories)
	cliide header-include-file $(HTTP-path) > $(@)

$(HTTP-build-file) : $(HTTP-top-file) $(HTTP-header-files) $(HTTP-dependency-targets)
	$(net-CPP) $(HTTP-include-flags) $(net-CFLAGS) $(HTTP-CFLAGS) -c -o $(@) $(<)

$(HTTP-include-path)/%.hpp : $(HTTP-path)/%.hpp $(HTTP-build-file)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(HTTP-include-file) : $(HTTP-top-file) $(HTTP-build-file)
	cp $(<) $(@)

$(HTTP-install-path)/%.hpp : $(HTTP-include-path)/%.hpp $(HTTP-dependency-install-targets)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(HTTP-install-file) : $(HTTP-include-file)
	cp $(<) $(@)
