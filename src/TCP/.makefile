TCP-moddepends = Failure IO GetConfig NullableString Protocol Shutdown SuppressingScope
TCP-CFLAGS =
TCP-LFLAGS =

TCP-moddepends-CFLAGS = $(foreach mod, $(TCP-moddepends), $($(mod)-export-CFLAGS))
TCP-moddepends-LFLAGS = $(foreach mod, $(TCP-moddepends), $($(mod)-export-LFLAGS))

TCP-export-CFLAGS = $(TCP-CFLAGS) $(TCP-moddepends-CFLAGS)
nodname-export-LFLAGS = $(TCP-LFLAGS) $(TCP-moddepends-LFLAGS)

TCP-path = $(srcdir)/TCP
TCP-files = $(shell find $(TCP-path) -type f -regex '\.\./\([^./][^/]*/\)*[^./][^/]*\.hpp')
TCP-include-files = $(TCP-files:$(srcdir)/%=$(incdir)/%)
TCP-install-files = $(TCP-files:$(srcdir)/%=/usr/include/%)
TCP-directories = $(shell find $(TCP-path) -type d -regex '\.\./\([^./][^/]*/\)*[^./][^/]*')
TCP-format-files = $(TCP-files:$(srcdir)/%=$(TCP-path)/.build/%.format)
TCP-install-moddepends = $(TCP-moddepends:%=%-install)

TCP : $(incdir)/TCP.hpp $(TCP-include-files)
	touch TCP

.PHONY : TCP-clean
TCP-clean :
	rm -rf $(TCP-include-files)
	rm -rf $(incdir)/TCP
	rm -rf $(incdir)/TCP.hpp
	rm -rf $(TCP-format-files)
	rm -rf $(TCP-path)/.build/TCP
	rm -rf $(TCP-path)/.build/TCP.hpp
	rm -rf $(TCP-path)/.build/TCP.hpp.gch
	rm -rf TCP

.PHONY : TCP-install
TCP-install : /usr/include/TCP.hpp $(TCP-install-files)

.PHONY : TCP-uninstall
TCP-uninstall :
	rm -rf /usr/include/TCP.hpp
	rm -rf /usr/include/TCP

.PHONY : TCP-format
TCP-format : $(TCP-format-files)

$(incdir)/TCP.hpp : $(TCP-path)/.build/TCP.hpp $(TCP-path)/.build/TCP.hpp.gch
	cp $(<) $(@)

$(incdir)/TCP/%.hpp : $(TCP-path)/%.hpp $(TCP-path)/.build/TCP.hpp.gch
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(TCP-path)/.build/TCP.hpp.gch : $(TCP-path)/.build/TCP.hpp $(TCP-moddepends)
	$(CPP) -I $(srcdir) $(CFLAGS) $(TCP-CFLAGS) $(TCP-moddepends-CFLAGS) -c -o $(@) $(<)

$(TCP-path)/.build/TCP.hpp : $(TCP-format-files) $(TCP-directories)
	./gen-hdr.sh $(srcdir) TCP | clang-format > $(@)

$(TCP-path)/.build/%.format : $(srcdir)/%
	./format.sh $(<)
	mkdir -p $(dir $(@))
	touch $(@)

/usr/include/%.hpp : $(incdir)/%.hpp $(TCP-install-moddepends)
	mkdir -p $(dir $(@))
	cp $(<) $(@)
