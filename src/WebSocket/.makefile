# User-configurable options

WebSocket-CFLAGS ::=
WebSocket-LFLAGS ::=

# Boilerplate that shouldn't be touched

WebSocket-path ::= $(net-src-dir)/WebSocket

WebSocket-header-files-and-directories ::= \
	$(patsubst \
		./%,$\
		$(WebSocket-path)/%,$\
		$(shell \
			cd $(WebSocket-path); \
			find -type f -regex '\(/[^./][^/]*\)*\.hpp' -or \
				-type d -regex '\(/[^./][^/]*\)*' \
		)$\
	)
#	$(shell cliide list-files-and-directories $(WebSocket-path))

WebSocket-header-files ::= $(filter %.hpp, $(WebSocket-header-files-and-directories))
WebSocket-directories ::= $(filter-out %.hpp, $(WebSocket-header-files-and-directories))

WebSocket-dependency-candidates ::= \
	$(shell sed -ne 's~\#include *<\(.*\)\.hpp>.*~\1~p' $(WebSocket-path)/include.hpp)

WebSocket-dependencies ::= $(filter \
	$(net-export-targets),$\
	$(WebSocket-dependency-candidates)$\
)

WebSocket-dependency-targets ::= $(foreach \
	WebSocket-dependency,$\
	$(WebSocket-dependencies),$\
	$($(WebSocket-dependency)-target)$\
)

WebSocket-dependency-install-targets ::= $(foreach \
	WebSocket-dependency,$\
	$(WebSocket-dependencies),$\
	$($(WebSocket-dependency)-install-target)$\
)

WebSocket-inc-dirs ::= $(net-inc-dir) $(net-reference-inc-dirs)
WebSocket-inc-dir-flags ::= $(WebSocket-inc-dirs:%=-I %)
WebSocket-include-flags ::= -I $(net-src-dir) $(WebSocket-inc-dir-flags)

WebSocket-top-file ::= $(WebSocket-path)/.build/WebSocket.hpp
WebSocket-build-file ::= $(WebSocket-path)/.build/WebSocket.hpp.gch

WebSocket-include-file ::= $(net-inc-dir)/WebSocket.hpp
WebSocket-include-path ::= $(net-inc-dir)/WebSocket
WebSocket-include-files ::= \
	$(WebSocket-header-files:$(WebSocket-path)/%=$(WebSocket-include-path)/%)
WebSocket-include-directories ::= \
	$(WebSocket-directories:$(WebSocket-path)/%=$(WebSocket-include-path)/%)

WebSocket-target ::= $(WebSocket-include-files) $(WebSocket-include-file)

WebSocket-install-file ::= $(net-header-install-dir)/WebSocket.hpp
WebSocket-install-path ::= $(net-header-install-dir)/WebSocket
WebSocket-install-files ::= \
	$(WebSocket-header-files:$(WebSocket-path)/%=$(WebSocket-install-path)/%)
WebSocket-install-directories ::= \
	$(WebSocket-directories:$(WebSocket-path)/%=$(WebSocket-install-path)/%)

WebSocket-install-target ::= $(WebSocket-install-files) $(WebSocket-install-file)

.PHONY : WebSocket
WebSocket : $(WebSocket-target)

.PHONY : WebSocket-clean
WebSocket-clean :
	rm -rf $(WebSocket-include-file)
	rm -rf $(WebSocket-include-files)
	rm -rf $(WebSocket-include-directories)
	rm -rf $(WebSocket-build-file)
	rm -rf $(WebSocket-top-file)

.PHONY : WebSocket-install
WebSocket-install : $(WebSocket-install-target)

.PHONY : WebSocket-uninstall
WebSocket-uninstall :
	rm -rf $(WebSocket-install-file)
	rm -rf $(WebSocket-install-files)
	rm -rf $(WebSocket-install-directories)

$(WebSocket-top-file) : $(WebSocket-header-files) $(WebSocket-directories)
	cliide header-include-file $(WebSocket-path) > $(@)

$(WebSocket-build-file) : $(WebSocket-top-file) $(WebSocket-header-files) $(WebSocket-dependency-targets)
	$(net-CPP) $(WebSocket-include-flags) $(net-CFLAGS) $(WebSocket-CFLAGS) -c -o $(@) $(<)

$(WebSocket-include-path)/%.hpp : $(WebSocket-path)/%.hpp $(WebSocket-build-file)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(WebSocket-include-file) : $(WebSocket-top-file) $(WebSocket-build-file)
	cp $(<) $(@)

$(WebSocket-install-path)/%.hpp : $(WebSocket-include-path)/%.hpp $(WebSocket-dependency-install-targets)
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(WebSocket-install-file) : $(WebSocket-include-file)
	cp $(<) $(@)
