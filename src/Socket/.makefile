Socket-moddepends = Failure IO Protocol Thread
Socket-CFLAGS =
Socket-LFLAGS =

Socket-moddepends-CFLAGS = $(foreach mod, $(Socket-moddepends), $($(mod)-export-CFLAGS))
Socket-moddepends-LFLAGS = $(foreach mod, $(Socket-moddepends), $($(mod)-export-LFLAGS))

Socket-export-CFLAGS = $(Socket-CFLAGS) $(Socket-moddepends-CFLAGS)
nodname-export-LFLAGS = $(Socket-LFLAGS) $(Socket-moddepends-LFLAGS)

Socket-path = $(srcdir)/Socket
Socket-files = $(shell find $(Socket-path) -type f -regex '\.\./\([^./][^/]*/\)*[^./][^/]*\.hpp')
Socket-include-files = $(Socket-files:$(srcdir)/%=$(incdir)/%)
Socket-install-files = $(Socket-files:$(srcdir)/%=/usr/include/%)
Socket-directories = $(shell find $(Socket-path) -type d -regex '\.\./\([^./][^/]*/\)*[^./][^/]*')
Socket-format-files = $(Socket-files:$(srcdir)/%=$(Socket-path)/.build/%.format)
Socket-install-moddepends = $(Socket-moddepends:%=%-install)

Socket : $(incdir)/Socket.hpp $(Socket-include-files)
	touch Socket

.PHONY : Socket-clean
Socket-clean :
	rm -rf $(Socket-include-files)
	rm -rf $(incdir)/Socket
	rm -rf $(incdir)/Socket.hpp
	rm -rf $(Socket-format-files)
	rm -rf $(Socket-path)/.build/Socket
	rm -rf $(Socket-path)/.build/Socket.hpp
	rm -rf $(Socket-path)/.build/Socket.hpp.gch
	rm -rf Socket

.PHONY : Socket-install
Socket-install : /usr/include/Socket.hpp $(Socket-install-files)

.PHONY : Socket-uninstall
Socket-uninstall :
	rm -rf /usr/include/Socket.hpp
	rm -rf /usr/include/Socket

.PHONY : Socket-format
Socket-format : $(Socket-format-files)

$(incdir)/Socket.hpp : $(Socket-path)/.build/Socket.hpp $(Socket-path)/.build/Socket.hpp.gch
	cp $(<) $(@)

$(incdir)/Socket/%.hpp : $(Socket-path)/%.hpp $(Socket-path)/.build/Socket.hpp.gch
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(Socket-path)/.build/Socket.hpp.gch : $(Socket-path)/.build/Socket.hpp $(Socket-moddepends)
	$(CPP) -I $(srcdir) $(CFLAGS) $(Socket-CFLAGS) $(Socket-moddepends-CFLAGS) -c -o $(@) $(<)

$(Socket-path)/.build/Socket.hpp : $(Socket-format-files) $(Socket-directories)
	./gen-hdr.sh $(srcdir) Socket | clang-format > $(@)

$(Socket-path)/.build/%.format : $(srcdir)/%
	./format.sh $(<)
	mkdir -p $(dir $(@))
	touch $(@)

/usr/include/%.hpp : $(incdir)/%.hpp $(Socket-install-moddepends)
	mkdir -p $(dir $(@))
	cp $(<) $(@)
