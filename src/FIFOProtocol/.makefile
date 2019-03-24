# User-configurable options

FIFOProtocol-CFLAGS ::=
FIFOProtocol-LFLAGS ::=

# Boilerplate that shouldn't be touched

FIFOProtocol-path ::= $(net-src-dir)/FIFOProtocol

FIFOProtocol-header-files-and-directories ::= \
	$(patsubst \
		./%,$\
		$(FIFOProtocol-path)/%,$\
		$(shell \
			cd $(FIFOProtocol-path); \
			find -type f -regex '\(/[^./][^/]*\)*\.hpp' -or \
				-type d -regex '\(/[^./][^/]*\)*' \
		)$\
	)
#	$(shell cliide list-files-and-directories $(FIFOProtocol-path))

FIFOProtocol-header-files ::= $(filter %.hpp, $(FIFOProtocol-header-files-and-directories))
FIFOProtocol-directories ::= $(filter-out %.hpp, $(FIFOProtocol-header-files-and-directories))

FIFOProtocol-dependency-candidates ::= \
	$(shell sed -ne 's~\#include *<\(.*\)\.hpp>.*~\1~p' $(FIFOProtocol-path)/include.hpp)

FIFOProtocol-dependencies ::= $(filter \
	$(net-export-targets),$\
	$(FIFOProtocol-dependency-candidates)$\
)

FIFOProtocol-dependency-targets ::= $(foreach \
	FIFOProtocol-dependency,$\
	$(FIFOProtocol-dependencies),$\
	$($(FIFOProtocol-dependency)-target)$\
)

FIFOProtocol-dependency-install-targets ::= $(foreach \
	FIFOProtocol-dependency,$\
	$(FIFOProtocol-dependencies),$\
	$($(FIFOProtocol-dependency)-install-target)$\
)

FIFOProtocol-inc-dirs ::= $(net-inc-dir) $(net-reference-inc-dirs)
FIFOProtocol-inc-dir-flags ::= $(FIFOProtocol-inc-dirs:%=-I %)
FIFOProtocol-include-flags ::= -I $(net-src-dir) $(FIFOProtocol-inc-dir-flags)

FIFOProtocol-top-file ::= $(FIFOProtocol-path)/.build/FIFOProtocol.hpp
FIFOProtocol-build-file ::= $(FIFOProtocol-path)/.build/FIFOProtocol.hpp.gch

FIFOProtocol-include-file ::= $(net-inc-dir)/FIFOProtocol.hpp
FIFOProtocol-include-path ::= $(net-inc-dir)/FIFOProtocol
FIFOProtocol-include-files ::= \
	$(FIFOProtocol-header-files:$(FIFOProtocol-path)/%=$(FIFOProtocol-include-path)/%)
FIFOProtocol-include-directories ::= \
	$(FIFOProtocol-directories:$(FIFOProtocol-path)/%=$(FIFOProtocol-include-path)/%)

FIFOProtocol-target ::= $(FIFOProtocol-include-files) $(FIFOProtocol-include-file)

FIFOProtocol-install-file ::= $(net-header-install-dir)/FIFOProtocol.hpp
FIFOProtocol-install-path ::= $(net-header-install-dir)/FIFOProtocol
FIFOProtocol-install-files ::= \
	$(FIFOProtocol-header-files:$(FIFOProtocol-path)/%=$(FIFOProtocol-install-path)/%)
FIFOProtocol-install-directories ::= \
	$(FIFOProtocol-directories:$(FIFOProtocol-path)/%=$(FIFOProtocol-install-path)/%)

FIFOProtocol-install-target ::= $(FIFOProtocol-install-files) $(FIFOProtocol-install-file)

.PHONY : FIFOProtocol
FIFOProtocol : $(FIFOProtocol-target)

.PHONY : FIFOProtocol-clean
FIFOProtocol-clean :
	rm -rf $(FIFOProtocol-include-file)
	rm -rf $(FIFOProtocol-include-files)
	rm -rf $(FIFOProtocol-include-directories)
	rm -rf $(FIFOProtocol-build-file)
	rm -rf $(FIFOProtocol-top-file)

.PHONY : FIFOProtocol-install
FIFOProtocol-install : $(FIFOProtocol-install-target)

.PHONY : FIFOProtocol-uninstall
FIFOProtocol-uninstall :
	rm -rf $(FIFOProtocol-install-file)
	rm -rf $(FIFOProtocol-install-files)
	rm -rf $(FIFOProtocol-install-directories)

$(FIFOProtocol-top-file) : $(FIFOProtocol-header-files) $(FIFOProtocol-directories)
	cliide header-include-file $(FIFOProtocol-path) > $(@)

$(FIFOProtocol-build-file) : $(FIFOProtocol-top-file) $(FIFOProtocol-header-files) $(FIFOProtocol-dependency-targets)
	$(net-CPP) $(FIFOProtocol-include-flags) $(net-CFLAGS) $(FIFOProtocol-CFLAGS) -c -o $(@) $(<)

$(FIFOProtocol-include-path)/%.hpp : $(FIFOProtocol-path)/%.hpp $(FIFOProtocol-build-file)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(FIFOProtocol-include-file) : $(FIFOProtocol-top-file) $(FIFOProtocol-build-file)
	cp $(<) $(@)

$(FIFOProtocol-install-path)/%.hpp : $(FIFOProtocol-include-path)/%.hpp $(FIFOProtocol-dependency-install-targets)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(FIFOProtocol-install-file) : $(FIFOProtocol-include-file)
	cp $(<) $(@)
