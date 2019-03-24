# User-configurable options

TLS-CFLAGS ::=
TLS-LFLAGS ::=

# Boilerplate that shouldn't be touched

TLS-path ::= $(net-src-dir)/TLS

TLS-header-files-and-directories ::= \
	$(patsubst \
		./%,$\
		$(TLS-path)/%,$\
		$(shell \
			cd $(TLS-path); \
			find -type f -regex '\(/[^./][^/]*\)*\.hpp' -or \
				-type d -regex '\(/[^./][^/]*\)*' \
		)$\
	)
#	$(shell cliide list-files-and-directories $(TLS-path))

TLS-header-files ::= $(filter %.hpp, $(TLS-header-files-and-directories))
TLS-directories ::= $(filter-out %.hpp, $(TLS-header-files-and-directories))

TLS-dependency-candidates ::= \
	$(shell sed -ne 's~\#include *<\(.*\)\.hpp>.*~\1~p' $(TLS-path)/include.hpp)

TLS-dependencies ::= $(filter \
	$(net-export-targets),$\
	$(TLS-dependency-candidates)$\
)

TLS-dependency-targets ::= $(foreach \
	TLS-dependency,$\
	$(TLS-dependencies),$\
	$($(TLS-dependency)-target)$\
)

TLS-dependency-install-targets ::= $(foreach \
	TLS-dependency,$\
	$(TLS-dependencies),$\
	$($(TLS-dependency)-install-target)$\
)

TLS-inc-dirs ::= $(net-inc-dir) $(net-reference-inc-dirs)
TLS-inc-dir-flags ::= $(TLS-inc-dirs:%=-I %)
TLS-include-flags ::= -I $(net-src-dir) $(TLS-inc-dir-flags)

TLS-top-file ::= $(TLS-path)/.build/TLS.hpp
TLS-build-file ::= $(TLS-path)/.build/TLS.hpp.gch

TLS-include-file ::= $(net-inc-dir)/TLS.hpp
TLS-include-path ::= $(net-inc-dir)/TLS
TLS-include-files ::= \
	$(TLS-header-files:$(TLS-path)/%=$(TLS-include-path)/%)
TLS-include-directories ::= \
	$(TLS-directories:$(TLS-path)/%=$(TLS-include-path)/%)

TLS-target ::= $(TLS-include-files) $(TLS-include-file)

TLS-install-file ::= $(net-header-install-dir)/TLS.hpp
TLS-install-path ::= $(net-header-install-dir)/TLS
TLS-install-files ::= \
	$(TLS-header-files:$(TLS-path)/%=$(TLS-install-path)/%)
TLS-install-directories ::= \
	$(TLS-directories:$(TLS-path)/%=$(TLS-install-path)/%)

TLS-install-target ::= $(TLS-install-files) $(TLS-install-file)

.PHONY : TLS
TLS : $(TLS-target)

.PHONY : TLS-clean
TLS-clean :
	rm -rf $(TLS-include-file)
	rm -rf $(TLS-include-files)
	rm -rf $(TLS-include-directories)
	rm -rf $(TLS-build-file)
	rm -rf $(TLS-top-file)

.PHONY : TLS-install
TLS-install : $(TLS-install-target)

.PHONY : TLS-uninstall
TLS-uninstall :
	rm -rf $(TLS-install-file)
	rm -rf $(TLS-install-files)
	rm -rf $(TLS-install-directories)

$(TLS-top-file) : $(TLS-header-files) $(TLS-directories)
	cliide header-include-file $(TLS-path) > $(@)

$(TLS-build-file) : $(TLS-top-file) $(TLS-header-files) $(TLS-dependency-targets)
	$(net-CPP) $(TLS-include-flags) $(net-CFLAGS) $(TLS-CFLAGS) -c -o $(@) $(<)

$(TLS-include-path)/%.hpp : $(TLS-path)/%.hpp $(TLS-build-file)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(TLS-include-file) : $(TLS-top-file) $(TLS-build-file)
	cp $(<) $(@)

$(TLS-install-path)/%.hpp : $(TLS-include-path)/%.hpp $(TLS-dependency-install-targets)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(TLS-install-file) : $(TLS-include-file)
	cp $(<) $(@)
