# User-configurable options

IO-CFLAGS ::=
IO-LFLAGS ::=

# Boilerplate that shouldn't be touched

IO-path ::= $(net-src-dir)/IO

IO-header-files-and-directories ::= \
	$(patsubst \
		./%,$\
		$(IO-path)/%,$\
		$(shell \
			cd $(IO-path); \
			find -type f -regex '\(/[^./][^/]*\)*\.hpp' -or \
				-type d -regex '\(/[^./][^/]*\)*' \
		)$\
	)
#	$(shell cliide list-files-and-directories $(IO-path))

IO-header-files ::= $(filter %.hpp, $(IO-header-files-and-directories))
IO-directories ::= $(filter-out %.hpp, $(IO-header-files-and-directories))

IO-dependency-candidates ::= \
	$(shell sed -ne 's~\#include *<\(.*\)\.hpp>.*~\1~p' $(IO-path)/include.hpp)

IO-dependencies ::= $(filter \
	$(net-export-targets),$\
	$(IO-dependency-candidates)$\
)

IO-dependency-targets ::= $(foreach \
	IO-dependency,$\
	$(IO-dependencies),$\
	$($(IO-dependency)-target)$\
)

IO-dependency-install-targets ::= $(foreach \
	IO-dependency,$\
	$(IO-dependencies),$\
	$($(IO-dependency)-install-target)$\
)

IO-inc-dirs ::= $(net-inc-dir) $(net-reference-inc-dirs)
IO-inc-dir-flags ::= $(IO-inc-dirs:%=-I %)
IO-include-flags ::= -I $(net-src-dir) $(IO-inc-dir-flags)

IO-top-file ::= $(IO-path)/.build/IO.hpp
IO-build-file ::= $(IO-path)/.build/IO.hpp.gch

IO-include-file ::= $(net-inc-dir)/IO.hpp
IO-include-path ::= $(net-inc-dir)/IO
IO-include-files ::= \
	$(IO-header-files:$(IO-path)/%=$(IO-include-path)/%)
IO-include-directories ::= \
	$(IO-directories:$(IO-path)/%=$(IO-include-path)/%)

IO-target ::= $(IO-include-files) $(IO-include-file)

IO-install-file ::= $(net-header-install-dir)/IO.hpp
IO-install-path ::= $(net-header-install-dir)/IO
IO-install-files ::= \
	$(IO-header-files:$(IO-path)/%=$(IO-install-path)/%)
IO-install-directories ::= \
	$(IO-directories:$(IO-path)/%=$(IO-install-path)/%)

IO-install-target ::= $(IO-install-files) $(IO-install-file)

.PHONY : IO
IO : $(IO-target)

.PHONY : IO-clean
IO-clean :
	rm -rf $(IO-include-file)
	rm -rf $(IO-include-files)
	rm -rf $(IO-include-directories)
	rm -rf $(IO-build-file)
	rm -rf $(IO-top-file)

.PHONY : IO-install
IO-install : $(IO-install-target)

.PHONY : IO-uninstall
IO-uninstall :
	rm -rf $(IO-install-file)
	rm -rf $(IO-install-files)
	rm -rf $(IO-install-directories)

$(IO-top-file) : $(IO-header-files) $(IO-directories)
	cliide header-include-file $(IO-path) > $(@)

$(IO-build-file) : $(IO-top-file) $(IO-header-files) $(IO-dependency-targets)
	$(net-CPP) $(IO-include-flags) $(net-CFLAGS) $(IO-CFLAGS) -c -o $(@) $(<)

$(IO-include-path)/%.hpp : $(IO-path)/%.hpp $(IO-build-file)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(IO-include-file) : $(IO-top-file) $(IO-build-file)
	cp $(<) $(@)

$(IO-install-path)/%.hpp : $(IO-include-path)/%.hpp $(IO-dependency-install-targets)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(IO-install-file) : $(IO-include-file)
	cp $(<) $(@)
