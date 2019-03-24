# User-configurable options

Scope-CFLAGS ::=
Scope-LFLAGS ::=

# Boilerplate that shouldn't be touched

Scope-path ::= $(net-src-dir)/Scope

Scope-header-files-and-directories ::= \
	$(patsubst \
		./%,$\
		$(Scope-path)/%,$\
		$(shell \
			cd $(Scope-path); \
			find . -mindepth 1 -type f -regex '\.\(/[^./][^/]*\)*\.hpp' -or \
				-type d -regex '\.\(/[^./][^/]*\)*' \
		)$\
	)

Scope-header-files ::= $(filter %.hpp, $(Scope-header-files-and-directories))
Scope-directories ::= $(filter-out %.hpp, $(Scope-header-files-and-directories))

Scope-dependency-candidates ::= \
	$(shell sed -ne 's~\#include *<\(.*\)\.hpp>.*~\1~p' $(Scope-path)/include.hpp)

Scope-dependencies ::= $(filter \
	$(net-export-targets),$\
	$(Scope-dependency-candidates)$\
)

Scope-dependency-targets ::= $(foreach \
	Scope-dependency,$\
	$(Scope-dependencies),$\
	$($(Scope-dependency)-target)$\
)

Scope-dependency-install-targets ::= $(foreach \
	Scope-dependency,$\
	$(Scope-dependencies),$\
	$($(Scope-dependency)-install-target)$\
)

Scope-inc-dirs ::= $(net-inc-dir) $(net-reference-inc-dirs)
Scope-inc-dir-flags ::= $(Scope-inc-dirs:%=-I %)
Scope-include-flags ::= -I $(net-src-dir) $(Scope-inc-dir-flags)

Scope-top-file ::= $(Scope-path)/.build/Scope.hpp
Scope-build-file ::= $(Scope-path)/.build/Scope.hpp.gch

Scope-include-file ::= $(net-inc-dir)/Scope.hpp
Scope-include-path ::= $(net-inc-dir)/Scope
Scope-include-files ::= \
	$(Scope-header-files:$(Scope-path)/%=$(Scope-include-path)/%)
Scope-include-directories ::= \
	$(Scope-directories:$(Scope-path)/%=$(Scope-include-path)/%)

Scope-target ::= $(Scope-include-files) $(Scope-include-file)

Scope-install-file ::= $(net-header-install-dir)/Scope.hpp
Scope-install-path ::= $(net-header-install-dir)/Scope
Scope-install-files ::= \
	$(Scope-header-files:$(Scope-path)/%=$(Scope-install-path)/%)
Scope-install-directories ::= \
	$(Scope-directories:$(Scope-path)/%=$(Scope-install-path)/%)

Scope-install-target ::= $(Scope-install-files) $(Scope-install-file)

.PHONY : Scope
Scope : $(Scope-target)

.PHONY : Scope-clean
Scope-clean :
	rm -rf $(Scope-include-file)
	rm -rf $(Scope-include-files)
	rm -rf $(Scope-include-directories)
	rm -rf $(Scope-build-file)
	rm -rf $(Scope-top-file)

.PHONY : Scope-install
Scope-install : $(Scope-install-target)

.PHONY : Scope-uninstall
Scope-uninstall :
	rm -rf $(Scope-install-file)
	rm -rf $(Scope-install-files)
	rm -rf $(Scope-install-directories)

$(Scope-top-file) : $(Scope-header-files) $(Scope-directories)
	cliide header-include-file $(Scope-path) > $(@)

$(Scope-build-file) : $(Scope-top-file) $(Scope-header-files) $(Scope-dependency-targets)
	$(net-CPP) $(Scope-include-flags) $(net-CFLAGS) $(Scope-CFLAGS) -c -o $(@) $(<)

$(Scope-include-path)/%.hpp : $(Scope-path)/%.hpp $(Scope-build-file)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(Scope-include-file) : $(Scope-top-file) $(Scope-build-file)
	cp $(<) $(@)

$(Scope-install-path)/%.hpp : $(Scope-include-path)/%.hpp $(Scope-dependency-install-targets)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(Scope-install-file) : $(Scope-include-file)
	cp $(<) $(@)
