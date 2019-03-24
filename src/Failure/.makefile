# User-configurable options

Failure-CFLAGS ::=
Failure-LFLAGS ::=

# Boilerplate that shouldn't be touched

Failure-path ::= $(net-src-dir)/Failure

Failure-header-files-and-directories ::= \
	$(patsubst \
		./%,$\
		$(Failure-path)/%,$\
		$(shell \
			cd $(Failure-path); \
			find . -mindepth 1 -type f -regex '\.\(/[^./][^/]*\)*\.hpp' -or \
				-type d -regex '\.\(/[^./][^/]*\)*' \
		)$\
	)

Failure-header-files ::= $(filter %.hpp, $(Failure-header-files-and-directories))
Failure-directories ::= $(filter-out %.hpp, $(Failure-header-files-and-directories))

Failure-dependency-candidates ::= \
	$(shell sed -ne 's~\#include *<\(.*\)\.hpp>.*~\1~p' $(Failure-path)/include.hpp)

Failure-dependencies ::= $(filter \
	$(net-export-targets),$\
	$(Failure-dependency-candidates)$\
)

Failure-dependency-targets ::= $(foreach \
	Failure-dependency,$\
	$(Failure-dependencies),$\
	$($(Failure-dependency)-target)$\
)

Failure-dependency-install-targets ::= $(foreach \
	Failure-dependency,$\
	$(Failure-dependencies),$\
	$($(Failure-dependency)-install-target)$\
)

Failure-inc-dirs ::= $(net-inc-dir) $(net-reference-inc-dirs)
Failure-inc-dir-flags ::= $(Failure-inc-dirs:%=-I %)
Failure-include-flags ::= -I $(net-src-dir) $(Failure-inc-dir-flags)

Failure-top-file ::= $(Failure-path)/.build/Failure.hpp
Failure-build-file ::= $(Failure-path)/.build/Failure.hpp.gch

Failure-include-file ::= $(net-inc-dir)/Failure.hpp
Failure-include-path ::= $(net-inc-dir)/Failure
Failure-include-files ::= \
	$(Failure-header-files:$(Failure-path)/%=$(Failure-include-path)/%)
Failure-include-directories ::= \
	$(Failure-directories:$(Failure-path)/%=$(Failure-include-path)/%)

Failure-target ::= $(Failure-include-files) $(Failure-include-file)

Failure-install-file ::= $(net-header-install-dir)/Failure.hpp
Failure-install-path ::= $(net-header-install-dir)/Failure
Failure-install-files ::= \
	$(Failure-header-files:$(Failure-path)/%=$(Failure-install-path)/%)
Failure-install-directories ::= \
	$(Failure-directories:$(Failure-path)/%=$(Failure-install-path)/%)

Failure-install-target ::= $(Failure-install-files) $(Failure-install-file)

.PHONY : Failure
Failure : $(Failure-target)

.PHONY : Failure-clean
Failure-clean :
	rm -rf $(Failure-include-file)
	rm -rf $(Failure-include-files)
	rm -rf $(Failure-include-directories)
	rm -rf $(Failure-build-file)
	rm -rf $(Failure-top-file)

.PHONY : Failure-install
Failure-install : $(Failure-install-target)

.PHONY : Failure-uninstall
Failure-uninstall :
	rm -rf $(Failure-install-file)
	rm -rf $(Failure-install-files)
	rm -rf $(Failure-install-directories)

$(Failure-top-file) : $(Failure-header-files) $(Failure-directories)
	cliide header-include-file $(Failure-path) > $(@)

$(Failure-build-file) : $(Failure-top-file) $(Failure-header-files) $(Failure-dependency-targets)
	$(net-CPP) $(Failure-include-flags) $(net-CFLAGS) $(Failure-CFLAGS) -c -o $(@) $(<)

$(Failure-include-path)/%.hpp : $(Failure-path)/%.hpp $(Failure-build-file)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(Failure-include-file) : $(Failure-top-file) $(Failure-build-file)
	cp $(<) $(@)

$(Failure-install-path)/%.hpp : $(Failure-include-path)/%.hpp $(Failure-dependency-install-targets)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(Failure-install-file) : $(Failure-include-file)
	cp $(<) $(@)
