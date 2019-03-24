# User-configurable options

SuppressingScope-CFLAGS ::=
SuppressingScope-LFLAGS ::=

# Boilerplate that shouldn't be touched

SuppressingScope-path ::= $(net-src-dir)/SuppressingScope

SuppressingScope-header-files-and-directories ::= \
	$(patsubst \
		./%,$\
		$(SuppressingScope-path)/%,$\
		$(shell \
			cd $(SuppressingScope-path); \
			find -type f -regex '\(/[^./][^/]*\)*\.hpp' -or \
				-type d -regex '\(/[^./][^/]*\)*' \
		)$\
	)
#	$(shell cliide list-files-and-directories $(SuppressingScope-path))

SuppressingScope-header-files ::= $(filter %.hpp, $(SuppressingScope-header-files-and-directories))
SuppressingScope-directories ::= $(filter-out %.hpp, $(SuppressingScope-header-files-and-directories))

SuppressingScope-dependency-candidates ::= \
	$(shell sed -ne 's~\#include *<\(.*\)\.hpp>.*~\1~p' $(SuppressingScope-path)/include.hpp)

SuppressingScope-dependencies ::= $(filter \
	$(net-export-targets),$\
	$(SuppressingScope-dependency-candidates)$\
)

SuppressingScope-dependency-targets ::= $(foreach \
	SuppressingScope-dependency,$\
	$(SuppressingScope-dependencies),$\
	$($(SuppressingScope-dependency)-target)$\
)

SuppressingScope-dependency-install-targets ::= $(foreach \
	SuppressingScope-dependency,$\
	$(SuppressingScope-dependencies),$\
	$($(SuppressingScope-dependency)-install-target)$\
)

SuppressingScope-inc-dirs ::= $(net-inc-dir) $(net-reference-inc-dirs)
SuppressingScope-inc-dir-flags ::= $(SuppressingScope-inc-dirs:%=-I %)
SuppressingScope-include-flags ::= -I $(net-src-dir) $(SuppressingScope-inc-dir-flags)

SuppressingScope-top-file ::= $(SuppressingScope-path)/.build/SuppressingScope.hpp
SuppressingScope-build-file ::= $(SuppressingScope-path)/.build/SuppressingScope.hpp.gch

SuppressingScope-include-file ::= $(net-inc-dir)/SuppressingScope.hpp
SuppressingScope-include-path ::= $(net-inc-dir)/SuppressingScope
SuppressingScope-include-files ::= \
	$(SuppressingScope-header-files:$(SuppressingScope-path)/%=$(SuppressingScope-include-path)/%)
SuppressingScope-include-directories ::= \
	$(SuppressingScope-directories:$(SuppressingScope-path)/%=$(SuppressingScope-include-path)/%)

SuppressingScope-target ::= $(SuppressingScope-include-files) $(SuppressingScope-include-file)

SuppressingScope-install-file ::= $(net-header-install-dir)/SuppressingScope.hpp
SuppressingScope-install-path ::= $(net-header-install-dir)/SuppressingScope
SuppressingScope-install-files ::= \
	$(SuppressingScope-header-files:$(SuppressingScope-path)/%=$(SuppressingScope-install-path)/%)
SuppressingScope-install-directories ::= \
	$(SuppressingScope-directories:$(SuppressingScope-path)/%=$(SuppressingScope-install-path)/%)

SuppressingScope-install-target ::= $(SuppressingScope-install-files) $(SuppressingScope-install-file)

.PHONY : SuppressingScope
SuppressingScope : $(SuppressingScope-target)

.PHONY : SuppressingScope-clean
SuppressingScope-clean :
	rm -rf $(SuppressingScope-include-file)
	rm -rf $(SuppressingScope-include-files)
	rm -rf $(SuppressingScope-include-directories)
	rm -rf $(SuppressingScope-build-file)
	rm -rf $(SuppressingScope-top-file)

.PHONY : SuppressingScope-install
SuppressingScope-install : $(SuppressingScope-install-target)

.PHONY : SuppressingScope-uninstall
SuppressingScope-uninstall :
	rm -rf $(SuppressingScope-install-file)
	rm -rf $(SuppressingScope-install-files)
	rm -rf $(SuppressingScope-install-directories)

$(SuppressingScope-top-file) : $(SuppressingScope-header-files) $(SuppressingScope-directories)
	cliide header-include-file $(SuppressingScope-path) > $(@)

$(SuppressingScope-build-file) : $(SuppressingScope-top-file) $(SuppressingScope-header-files) $(SuppressingScope-dependency-targets)
	$(net-CPP) $(SuppressingScope-include-flags) $(net-CFLAGS) $(SuppressingScope-CFLAGS) -c -o $(@) $(<)

$(SuppressingScope-include-path)/%.hpp : $(SuppressingScope-path)/%.hpp $(SuppressingScope-build-file)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(SuppressingScope-include-file) : $(SuppressingScope-top-file) $(SuppressingScope-build-file)
	cp $(<) $(@)

$(SuppressingScope-install-path)/%.hpp : $(SuppressingScope-include-path)/%.hpp $(SuppressingScope-dependency-install-targets)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(SuppressingScope-install-file) : $(SuppressingScope-include-file)
	cp $(<) $(@)
