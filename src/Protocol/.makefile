Protocol-moddepends = Failure IO Shutdown
Protocol-CFLAGS =
Protocol-LFLAGS =

Protocol-moddepends-CFLAGS = $(foreach mod, $(Protocol-moddepends), $($(mod)-export-CFLAGS))
Protocol-moddepends-LFLAGS = $(foreach mod, $(Protocol-moddepends), $($(mod)-export-LFLAGS))

Protocol-export-CFLAGS = $(Protocol-CFLAGS) $(Protocol-moddepends-CFLAGS)
nodname-export-LFLAGS = $(Protocol-LFLAGS) $(Protocol-moddepends-LFLAGS)

Protocol-path = $(srcdir)/Protocol
Protocol-files = $(shell find $(Protocol-path) -type f -regex '\.\./\([^./][^/]*/\)*[^./][^/]*\.hpp')
Protocol-include-files = $(Protocol-files:$(srcdir)/%=$(incdir)/%)
Protocol-install-files = $(Protocol-files:$(srcdir)/%=/usr/include/%)
Protocol-directories = $(shell find $(Protocol-path) -type d -regex '\.\./\([^./][^/]*/\)*[^./][^/]*')
Protocol-format-files = $(Protocol-files:$(srcdir)/%=$(Protocol-path)/.build/%.format)
Protocol-install-moddepends = $(Protocol-moddepends:%=%-install)

Protocol : $(incdir)/Protocol.hpp $(Protocol-include-files)
	touch Protocol

.PHONY : Protocol-clean
Protocol-clean :
	rm -rf $(Protocol-include-files)
	rm -rf $(incdir)/Protocol
	rm -rf $(incdir)/Protocol.hpp
	rm -rf $(Protocol-format-files)
	rm -rf $(Protocol-path)/.build/Protocol
	rm -rf $(Protocol-path)/.build/Protocol.hpp
	rm -rf $(Protocol-path)/.build/Protocol.hpp.gch
	rm -rf Protocol

.PHONY : Protocol-install
Protocol-install : /usr/include/Protocol.hpp $(Protocol-install-files)

.PHONY : Protocol-uninstall
Protocol-uninstall :
	rm -rf /usr/include/Protocol.hpp
	rm -rf /usr/include/Protocol

.PHONY : Protocol-format
Protocol-format : $(Protocol-format-files)

$(incdir)/Protocol.hpp : $(Protocol-path)/.build/Protocol.hpp $(Protocol-path)/.build/Protocol.hpp.gch
	cp $(<) $(@)

$(incdir)/Protocol/%.hpp : $(Protocol-path)/%.hpp $(Protocol-path)/.build/Protocol.hpp.gch
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(Protocol-path)/.build/Protocol.hpp.gch : $(Protocol-path)/.build/Protocol.hpp $(Protocol-moddepends)
	$(CPP) -I $(srcdir) $(CFLAGS) $(Protocol-CFLAGS) $(Protocol-moddepends-CFLAGS) -c -o $(@) $(<)

$(Protocol-path)/.build/Protocol.hpp : $(Protocol-format-files) $(Protocol-directories)
	./gen-hdr.sh $(srcdir) Protocol | clang-format > $(@)

$(Protocol-path)/.build/%.format : $(srcdir)/%
	./format.sh $(<)
	mkdir -p $(dir $(@))
	touch $(@)

/usr/include/%.hpp : $(incdir)/%.hpp $(Protocol-install-moddepends)
	mkdir -p $(dir $(@))
	cp $(<) $(@)
