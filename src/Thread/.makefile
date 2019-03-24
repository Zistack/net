# User-configurable options

Thread-CFLAGS ::=
Thread-LFLAGS ::=

# Boilerplate that shouldn't be touched

Thread-path ::= $(net-src-dir)/Thread

Thread-header-files-and-directories ::= \
	$(patsubst \
		./%,$\
		$(Thread-path)/%,$\
		$(shell \
			cd $(Thread-path); \
			find -type f -regex '\(/[^./][^/]*\)*\.hpp' -or \
				-type d -regex '\(/[^./][^/]*\)*' \
		)$\
	)
#	$(shell cliide list-files-and-directories $(Thread-path))

Thread-header-files ::= $(filter %.hpp, $(Thread-header-files-and-directories))
Thread-directories ::= $(filter-out %.hpp, $(Thread-header-files-and-directories))

Thread-dependency-candidates ::= \
	$(shell sed -ne 's~\#include *<\(.*\)\.hpp>.*~\1~p' $(Thread-path)/include.hpp)

Thread-dependencies ::= $(filter \
	$(net-export-targets),$\
	$(Thread-dependency-candidates)$\
)

Thread-dependency-targets ::= $(foreach \
	Thread-dependency,$\
	$(Thread-dependencies),$\
	$($(Thread-dependency)-target)$\
)

Thread-dependency-install-targets ::= $(foreach \
	Thread-dependency,$\
	$(Thread-dependencies),$\
	$($(Thread-dependency)-install-target)$\
)

Thread-inc-dirs ::= $(net-inc-dir) $(net-reference-inc-dirs)
Thread-inc-dir-flags ::= $(Thread-inc-dirs:%=-I %)
Thread-include-flags ::= -I $(net-src-dir) $(Thread-inc-dir-flags)

Thread-top-file ::= $(Thread-path)/.build/Thread.hpp
Thread-build-file ::= $(Thread-path)/.build/Thread.hpp.gch

Thread-include-file ::= $(net-inc-dir)/Thread.hpp
Thread-include-path ::= $(net-inc-dir)/Thread
Thread-include-files ::= \
	$(Thread-header-files:$(Thread-path)/%=$(Thread-include-path)/%)
Thread-include-directories ::= \
	$(Thread-directories:$(Thread-path)/%=$(Thread-include-path)/%)

Thread-target ::= $(Thread-include-files) $(Thread-include-file)

Thread-install-file ::= $(net-header-install-dir)/Thread.hpp
Thread-install-path ::= $(net-header-install-dir)/Thread
Thread-install-files ::= \
	$(Thread-header-files:$(Thread-path)/%=$(Thread-install-path)/%)
Thread-install-directories ::= \
	$(Thread-directories:$(Thread-path)/%=$(Thread-install-path)/%)

Thread-install-target ::= $(Thread-install-files) $(Thread-install-file)

.PHONY : Thread
Thread : $(Thread-target)

.PHONY : Thread-clean
Thread-clean :
	rm -rf $(Thread-include-file)
	rm -rf $(Thread-include-files)
	rm -rf $(Thread-include-directories)
	rm -rf $(Thread-build-file)
	rm -rf $(Thread-top-file)

.PHONY : Thread-install
Thread-install : $(Thread-install-target)

.PHONY : Thread-uninstall
Thread-uninstall :
	rm -rf $(Thread-install-file)
	rm -rf $(Thread-install-files)
	rm -rf $(Thread-install-directories)

$(Thread-top-file) : $(Thread-header-files) $(Thread-directories)
	cliide header-include-file $(Thread-path) > $(@)

$(Thread-build-file) : $(Thread-top-file) $(Thread-header-files) $(Thread-dependency-targets)
	$(net-CPP) $(Thread-include-flags) $(net-CFLAGS) $(Thread-CFLAGS) -c -o $(@) $(<)

$(Thread-include-path)/%.hpp : $(Thread-path)/%.hpp $(Thread-build-file)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(Thread-include-file) : $(Thread-top-file) $(Thread-build-file)
	cp $(<) $(@)

$(Thread-install-path)/%.hpp : $(Thread-include-path)/%.hpp $(Thread-dependency-install-targets)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(Thread-install-file) : $(Thread-include-file)
	cp $(<) $(@)
