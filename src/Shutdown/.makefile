# User-configurable options

Shutdown-CFLAGS ::=
Shutdown-LFLAGS ::=

# Boilerplate that shouldn't be touched

Shutdown-path ::= $(net-src-dir)/Shutdown

Shutdown-header-files-and-directories ::= \
	$(patsubst \
		./%,$\
		$(Shutdown-path)/%,$\
		$(shell \
			cd $(Shutdown-path); \
			find -type f -regex '\(/[^./][^/]*\)*\.hpp' -or \
				-type d -regex '\(/[^./][^/]*\)*' \
		)$\
	)
#	$(shell cliide list-files-and-directories $(Shutdown-path))

Shutdown-header-files ::= $(filter %.hpp, $(Shutdown-header-files-and-directories))
Shutdown-directories ::= $(filter-out %.hpp, $(Shutdown-header-files-and-directories))

Shutdown-dependency-candidates ::= \
	$(shell sed -ne 's~\#include *<\(.*\)\.hpp>.*~\1~p' $(Shutdown-path)/include.hpp)

Shutdown-dependencies ::= $(filter \
	$(net-export-targets),$\
	$(Shutdown-dependency-candidates)$\
)

Shutdown-dependency-targets ::= $(foreach \
	Shutdown-dependency,$\
	$(Shutdown-dependencies),$\
	$($(Shutdown-dependency)-target)$\
)

Shutdown-dependency-install-targets ::= $(foreach \
	Shutdown-dependency,$\
	$(Shutdown-dependencies),$\
	$($(Shutdown-dependency)-install-target)$\
)

Shutdown-inc-dirs ::= $(net-inc-dir) $(net-reference-inc-dirs)
Shutdown-inc-dir-flags ::= $(Shutdown-inc-dirs:%=-I %)
Shutdown-include-flags ::= -I $(net-src-dir) $(Shutdown-inc-dir-flags)

Shutdown-top-file ::= $(Shutdown-path)/.build/Shutdown.hpp
Shutdown-build-file ::= $(Shutdown-path)/.build/Shutdown.hpp.gch

Shutdown-include-file ::= $(net-inc-dir)/Shutdown.hpp
Shutdown-include-path ::= $(net-inc-dir)/Shutdown
Shutdown-include-files ::= \
	$(Shutdown-header-files:$(Shutdown-path)/%=$(Shutdown-include-path)/%)
Shutdown-include-directories ::= \
	$(Shutdown-directories:$(Shutdown-path)/%=$(Shutdown-include-path)/%)

Shutdown-target ::= $(Shutdown-include-files) $(Shutdown-include-file)

Shutdown-install-file ::= $(net-header-install-dir)/Shutdown.hpp
Shutdown-install-path ::= $(net-header-install-dir)/Shutdown
Shutdown-install-files ::= \
	$(Shutdown-header-files:$(Shutdown-path)/%=$(Shutdown-install-path)/%)
Shutdown-install-directories ::= \
	$(Shutdown-directories:$(Shutdown-path)/%=$(Shutdown-install-path)/%)

Shutdown-install-target ::= $(Shutdown-install-files) $(Shutdown-install-file)

.PHONY : Shutdown
Shutdown : $(Shutdown-target)

.PHONY : Shutdown-clean
Shutdown-clean :
	rm -rf $(Shutdown-include-file)
	rm -rf $(Shutdown-include-files)
	rm -rf $(Shutdown-include-directories)
	rm -rf $(Shutdown-build-file)
	rm -rf $(Shutdown-top-file)

.PHONY : Shutdown-install
Shutdown-install : $(Shutdown-install-target)

.PHONY : Shutdown-uninstall
Shutdown-uninstall :
	rm -rf $(Shutdown-install-file)
	rm -rf $(Shutdown-install-files)
	rm -rf $(Shutdown-install-directories)

$(Shutdown-top-file) : $(Shutdown-header-files) $(Shutdown-directories)
	cliide header-include-file $(Shutdown-path) > $(@)

$(Shutdown-build-file) : $(Shutdown-top-file) $(Shutdown-header-files) $(Shutdown-dependency-targets)
	$(net-CPP) $(Shutdown-include-flags) $(net-CFLAGS) $(Shutdown-CFLAGS) -c -o $(@) $(<)

$(Shutdown-include-path)/%.hpp : $(Shutdown-path)/%.hpp $(Shutdown-build-file)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(Shutdown-include-file) : $(Shutdown-top-file) $(Shutdown-build-file)
	cp $(<) $(@)

$(Shutdown-install-path)/%.hpp : $(Shutdown-include-path)/%.hpp $(Shutdown-dependency-install-targets)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(Shutdown-install-file) : $(Shutdown-include-file)
	cp $(<) $(@)
