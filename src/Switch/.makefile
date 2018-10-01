Switch-moddepends = IO
Switch-CFLAGS =
Switch-LFLAGS =

Switch-moddepends-CFLAGS = $(foreach mod, $(Switch-moddepends), $($(mod)-export-CFLAGS))
Switch-moddepends-LFLAGS = $(foreach mod, $(Switch-moddepends), $($(mod)-export-LFLAGS))

Switch-export-CFLAGS = $(Switch-CFLAGS) $(Switch-moddepends-CFLAGS)
nodname-export-LFLAGS = $(Switch-LFLAGS) $(Switch-moddepends-LFLAGS)

Switch-path = $(srcdir)/Switch
Switch-files = $(shell find $(Switch-path) -type f -regex '\.\./\([^./][^/]*/\)*[^./][^/]*\.hpp')
Switch-include-files = $(Switch-files:$(srcdir)/%=$(incdir)/%)
Switch-install-files = $(Switch-files:$(srcdir)/%=/usr/include/%)
Switch-directories = $(shell find $(Switch-path) -type d -regex '\.\./\([^./][^/]*/\)*[^./][^/]*')
Switch-format-files = $(Switch-files:$(srcdir)/%=$(Switch-path)/.build/%.format)
Switch-install-moddepends = $(Switch-moddepends:%=%-install)

Switch : $(incdir)/Switch.hpp $(Switch-include-files)
	touch Switch

.PHONY : Switch-clean
Switch-clean :
	rm -rf $(Switch-include-files)
	rm -rf $(incdir)/Switch
	rm -rf $(incdir)/Switch.hpp
	rm -rf $(Switch-format-files)
	rm -rf $(Switch-path)/.build/Switch
	rm -rf $(Switch-path)/.build/Switch.hpp
	rm -rf $(Switch-path)/.build/Switch.hpp.gch
	rm -rf Switch

.PHONY : Switch-install
Switch-install : /usr/include/Switch.hpp $(Switch-install-files)

.PHONY : Switch-uninstall
Switch-uninstall :
	rm -rf /usr/include/Switch.hpp
	rm -rf /usr/include/Switch

.PHONY : Switch-format
Switch-format : $(Switch-format-files)

$(incdir)/Switch.hpp : $(Switch-path)/.build/Switch.hpp $(Switch-path)/.build/Switch.hpp.gch
	cp $(<) $(@)

$(incdir)/Switch/%.hpp : $(Switch-path)/%.hpp $(Switch-path)/.build/Switch.hpp.gch
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(Switch-path)/.build/Switch.hpp.gch : $(Switch-path)/.build/Switch.hpp $(Switch-moddepends)
	$(CPP) -I $(srcdir) $(CFLAGS) $(Switch-CFLAGS) $(Switch-moddepends-CFLAGS) -c -o $(@) $(<)

$(Switch-path)/.build/Switch.hpp : $(Switch-format-files) $(Switch-directories)
	./gen-hdr.sh $(srcdir) Switch | clang-format > $(@)

$(Switch-path)/.build/%.format : $(srcdir)/%
	./format.sh $(<)
	mkdir -p $(dir $(@))
	touch $(@)

/usr/include/%.hpp : $(incdir)/%.hpp $(Switch-install-moddepends)
	mkdir -p $(dir $(@))
	cp $(<) $(@)
