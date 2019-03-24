# User-configurable options

TCP-CFLAGS ::=
TCP-LFLAGS ::=

# Boilerplate that shouldn't be touched

TCP-path ::= $(net-src-dir)/TCP

TCP-header-files-and-directories ::= \
	$(patsubst \
		./%,$\
		$(TCP-path)/%,$\
		$(shell \
			cd $(TCP-path); \
			find -type f -regex '\(/[^./][^/]*\)*\.hpp' -or \
				-type d -regex '\(/[^./][^/]*\)*' \
		)$\
	)
#	$(shell cliide list-files-and-directories $(TCP-path))

TCP-header-files ::= $(filter %.hpp, $(TCP-header-files-and-directories))
TCP-directories ::= $(filter-out %.hpp, $(TCP-header-files-and-directories))

TCP-dependency-candidates ::= \
	$(shell sed -ne 's~\#include *<\(.*\)\.hpp>.*~\1~p' $(TCP-path)/include.hpp)

TCP-dependencies ::= $(filter \
	$(net-export-targets),$\
	$(TCP-dependency-candidates)$\
)

TCP-dependency-targets ::= $(foreach \
	TCP-dependency,$\
	$(TCP-dependencies),$\
	$($(TCP-dependency)-target)$\
)

TCP-dependency-install-targets ::= $(foreach \
	TCP-dependency,$\
	$(TCP-dependencies),$\
	$($(TCP-dependency)-install-target)$\
)

TCP-inc-dirs ::= $(net-inc-dir) $(net-reference-inc-dirs)
TCP-inc-dir-flags ::= $(TCP-inc-dirs:%=-I %)
TCP-include-flags ::= -I $(net-src-dir) $(TCP-inc-dir-flags)

TCP-top-file ::= $(TCP-path)/.build/TCP.hpp
TCP-build-file ::= $(TCP-path)/.build/TCP.hpp.gch

TCP-include-file ::= $(net-inc-dir)/TCP.hpp
TCP-include-path ::= $(net-inc-dir)/TCP
TCP-include-files ::= \
	$(TCP-header-files:$(TCP-path)/%=$(TCP-include-path)/%)
TCP-include-directories ::= \
	$(TCP-directories:$(TCP-path)/%=$(TCP-include-path)/%)

TCP-target ::= $(TCP-include-files) $(TCP-include-file)

TCP-install-file ::= $(net-header-install-dir)/TCP.hpp
TCP-install-path ::= $(net-header-install-dir)/TCP
TCP-install-files ::= \
	$(TCP-header-files:$(TCP-path)/%=$(TCP-install-path)/%)
TCP-install-directories ::= \
	$(TCP-directories:$(TCP-path)/%=$(TCP-install-path)/%)

TCP-install-target ::= $(TCP-install-files) $(TCP-install-file)

.PHONY : TCP
TCP : $(TCP-target)

.PHONY : TCP-clean
TCP-clean :
	rm -rf $(TCP-include-file)
	rm -rf $(TCP-include-files)
	rm -rf $(TCP-include-directories)
	rm -rf $(TCP-build-file)
	rm -rf $(TCP-top-file)

.PHONY : TCP-install
TCP-install : $(TCP-install-target)

.PHONY : TCP-uninstall
TCP-uninstall :
	rm -rf $(TCP-install-file)
	rm -rf $(TCP-install-files)
	rm -rf $(TCP-install-directories)

$(TCP-top-file) : $(TCP-header-files) $(TCP-directories)
	cliide header-include-file $(TCP-path) > $(@)

$(TCP-build-file) : $(TCP-top-file) $(TCP-header-files) $(TCP-dependency-targets)
	$(net-CPP) $(TCP-include-flags) $(net-CFLAGS) $(TCP-CFLAGS) -c -o $(@) $(<)

$(TCP-include-path)/%.hpp : $(TCP-path)/%.hpp $(TCP-build-file)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(TCP-include-file) : $(TCP-top-file) $(TCP-build-file)
	cp $(<) $(@)

$(TCP-install-path)/%.hpp : $(TCP-include-path)/%.hpp $(TCP-dependency-install-targets)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(TCP-install-file) : $(TCP-include-file)
	cp $(<) $(@)
