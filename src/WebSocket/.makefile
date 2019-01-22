WebSocket-moddepends = IO Failure SuppressingScope Thread HTTP Protocol
WebSocket-CFLAGS =
WebSocket-LFLAGS =

WebSocket-moddepends-CFLAGS = $(foreach mod, $(WebSocket-moddepends), $($(mod)-export-CFLAGS))
WebSocket-moddepends-LFLAGS = $(foreach mod, $(WebSocket-moddepends), $($(mod)-export-LFLAGS))

WebSocket-export-CFLAGS = $(WebSocket-CFLAGS) $(WebSocket-moddepends-CFLAGS)
nodname-export-LFLAGS = $(WebSocket-LFLAGS) $(WebSocket-moddepends-LFLAGS)

WebSocket-path = $(srcdir)/WebSocket
WebSocket-files = $(shell find $(WebSocket-path) -type f -regex '\.\./\([^./][^/]*/\)*[^./][^/]*\.hpp')
WebSocket-include-files = $(WebSocket-files:$(srcdir)/%=$(incdir)/%)
WebSocket-install-files = $(WebSocket-files:$(srcdir)/%=/usr/include/%)
WebSocket-directories = $(shell find $(WebSocket-path) -type d -regex '\.\./\([^./][^/]*/\)*[^./][^/]*')
WebSocket-format-files = $(WebSocket-files:$(srcdir)/%=$(WebSocket-path)/.build/%.format)
WebSocket-install-moddepends = $(WebSocket-moddepends:%=%-install)

WebSocket : $(incdir)/WebSocket.hpp $(WebSocket-include-files)
	touch WebSocket

.PHONY : WebSocket-clean
WebSocket-clean :
	rm -rf $(WebSocket-include-files)
	rm -rf $(incdir)/WebSocket
	rm -rf $(incdir)/WebSocket.hpp
	rm -rf $(WebSocket-format-files)
	rm -rf $(WebSocket-path)/.build/WebSocket
	rm -rf $(WebSocket-path)/.build/WebSocket.hpp
	rm -rf $(WebSocket-path)/.build/WebSocket.hpp.gch
	rm -rf WebSocket

.PHONY : WebSocket-install
WebSocket-install : /usr/include/WebSocket.hpp $(WebSocket-install-files)

.PHONY : WebSocket-uninstall
WebSocket-uninstall :
	rm -rf /usr/include/WebSocket.hpp
	rm -rf /usr/include/WebSocket

.PHONY : WebSocket-format
WebSocket-format : $(WebSocket-format-files)

$(incdir)/WebSocket.hpp : $(WebSocket-path)/.build/WebSocket.hpp $(WebSocket-path)/.build/WebSocket.hpp.gch
	cp $(<) $(@)

$(incdir)/WebSocket/%.hpp : $(WebSocket-path)/%.hpp $(WebSocket-path)/.build/WebSocket.hpp.gch
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(WebSocket-path)/.build/WebSocket.hpp.gch : $(WebSocket-path)/.build/WebSocket.hpp $(WebSocket-moddepends)
	$(CPP) -I $(srcdir) $(CFLAGS) $(WebSocket-CFLAGS) $(WebSocket-moddepends-CFLAGS) -c -o $(@) $(<)

$(WebSocket-path)/.build/WebSocket.hpp : $(WebSocket-format-files) $(WebSocket-directories)
	./gen-hdr.sh $(srcdir) WebSocket | clang-format > $(@)

$(WebSocket-path)/.build/%.format : $(srcdir)/%
	./format.sh $(<)
	mkdir -p $(dir $(@))
	touch $(@)

/usr/include/%.hpp : $(incdir)/%.hpp $(WebSocket-install-moddepends)
	mkdir -p $(dir $(@))
	cp $(<) $(@)
