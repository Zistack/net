# User-configurable options

Functor-CFLAGS ::=
Functor-LFLAGS ::=

# Boilerplate that shouldn't be touched

Functor-path ::= $(net-src-dir)/Functor

Functor-header-files-and-directories ::= \
	$(patsubst \
		./%,$\
		$(Functor-path)/%,$\
		$(shell \
			cd $(Functor-path); \
			find -type f -regex '\(/[^./][^/]*\)*\.hpp' -or \
				-type d -regex '\(/[^./][^/]*\)*' \
		)$\
	)
#	$(shell cliide list-files-and-directories $(Functor-path))

Functor-header-files ::= $(filter %.hpp, $(Functor-header-files-and-directories))
Functor-directories ::= $(filter-out %.hpp, $(Functor-header-files-and-directories))

Functor-dependency-candidates ::= \
	$(shell sed -ne 's~\#include *<\(.*\)\.hpp>.*~\1~p' $(Functor-path)/include.hpp)

Functor-dependencies ::= $(filter \
	$(net-export-targets),$\
	$(Functor-dependency-candidates)$\
)

Functor-dependency-targets ::= $(foreach \
	Functor-dependency,$\
	$(Functor-dependencies),$\
	$($(Functor-dependency)-target)$\
)

Functor-dependency-install-targets ::= $(foreach \
	Functor-dependency,$\
	$(Functor-dependencies),$\
	$($(Functor-dependency)-install-target)$\
)

Functor-inc-dirs ::= $(net-inc-dir) $(net-reference-inc-dirs)
Functor-inc-dir-flags ::= $(Functor-inc-dirs:%=-I %)
Functor-include-flags ::= -I $(net-src-dir) $(Functor-inc-dir-flags)

Functor-top-file ::= $(Functor-path)/.build/Functor.hpp
Functor-build-file ::= $(Functor-path)/.build/Functor.hpp.gch

Functor-include-file ::= $(net-inc-dir)/Functor.hpp
Functor-include-path ::= $(net-inc-dir)/Functor
Functor-include-files ::= \
	$(Functor-header-files:$(Functor-path)/%=$(Functor-include-path)/%)
Functor-include-directories ::= \
	$(Functor-directories:$(Functor-path)/%=$(Functor-include-path)/%)

Functor-target ::= $(Functor-include-files) $(Functor-include-file)

Functor-install-file ::= $(net-header-install-dir)/Functor.hpp
Functor-install-path ::= $(net-header-install-dir)/Functor
Functor-install-files ::= \
	$(Functor-header-files:$(Functor-path)/%=$(Functor-install-path)/%)
Functor-install-directories ::= \
	$(Functor-directories:$(Functor-path)/%=$(Functor-install-path)/%)

Functor-install-target ::= $(Functor-install-files) $(Functor-install-file)

.PHONY : Functor
Functor : $(Functor-target)

.PHONY : Functor-clean
Functor-clean :
	rm -rf $(Functor-include-file)
	rm -rf $(Functor-include-files)
	rm -rf $(Functor-include-directories)
	rm -rf $(Functor-build-file)
	rm -rf $(Functor-top-file)

.PHONY : Functor-install
Functor-install : $(Functor-install-target)

.PHONY : Functor-uninstall
Functor-uninstall :
	rm -rf $(Functor-install-file)
	rm -rf $(Functor-install-files)
	rm -rf $(Functor-install-directories)

$(Functor-top-file) : $(Functor-header-files) $(Functor-directories)
	cliide header-include-file $(Functor-path) > $(@)

$(Functor-build-file) : $(Functor-top-file) $(Functor-header-files) $(Functor-dependency-targets)
	$(net-CPP) $(Functor-include-flags) $(net-CFLAGS) $(Functor-CFLAGS) -c -o $(@) $(<)

$(Functor-include-path)/%.hpp : $(Functor-path)/%.hpp $(Functor-build-file)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(Functor-include-file) : $(Functor-top-file) $(Functor-build-file)
	cp $(<) $(@)

$(Functor-install-path)/%.hpp : $(Functor-include-path)/%.hpp $(Functor-dependency-install-targets)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(Functor-install-file) : $(Functor-include-file)
	cp $(<) $(@)
