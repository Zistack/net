Optional-moddepends =
Optional-CFLAGS =
Optional-LFLAGS =

Optional-moddepends-CFLAGS = $(foreach mod, $(Optional-moddepends), $($(mod)-export-CFLAGS))
Optional-moddepends-LFLAGS = $(foreach mod, $(Optional-moddepends), $($(mod)-export-LFLAGS))

Optional-export-CFLAGS = $(Optional-CFLAGS) $(Optional-moddepends-CFLAGS)
nodname-export-LFLAGS = $(Optional-LFLAGS) $(Optional-moddepends-LFLAGS)

Optional-path = $(srcdir)/Optional
Optional-files = $(shell find $(Optional-path) -type f -regex '\.\./\([^./][^/]*/\)*[^./][^/]*\.hpp')
Optional-include-files = $(Optional-files:$(srcdir)/%=$(incdir)/%)
Optional-install-files = $(Optional-files:$(srcdir)/%=/usr/include/%)
Optional-directories = $(shell find $(Optional-path) -type d -regex '\.\./\([^./][^/]*/\)*[^./][^/]*')
Optional-format-files = $(Optional-files:$(srcdir)/%=$(Optional-path)/.build/%.format)
Optional-install-moddepends = $(Optional-moddepends:%=%-install)

Optional : $(incdir)/Optional.hpp $(Optional-include-files)
	touch Optional

.PHONY : Optional-clean
Optional-clean :
	rm -rf $(Optional-include-files)
	rm -rf $(incdir)/Optional
	rm -rf $(incdir)/Optional.hpp
	rm -rf $(Optional-format-files)
	rm -rf $(Optional-path)/.build/Optional
	rm -rf $(Optional-path)/.build/Optional.hpp
	rm -rf $(Optional-path)/.build/Optional.hpp.gch
	rm -rf Optional

.PHONY : Optional-install
Optional-install : /usr/include/Optional.hpp $(Optional-install-files)

.PHONY : Optional-uninstall
Optional-uninstall :
	rm -rf /usr/include/Optional.hpp
	rm -rf /usr/include/Optional

.PHONY : Optional-format
Optional-format : $(Optional-format-files)

$(incdir)/Optional.hpp : $(Optional-path)/.build/Optional.hpp $(Optional-path)/.build/Optional.hpp.gch
	cp $(<) $(@)

$(incdir)/Optional/%.hpp : $(Optional-path)/%.hpp $(Optional-path)/.build/Optional.hpp.gch
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(Optional-path)/.build/Optional.hpp.gch : $(Optional-path)/.build/Optional.hpp $(Optional-moddepends)
	$(CPP) -I $(srcdir) $(CFLAGS) $(Optional-CFLAGS) $(Optional-moddepends-CFLAGS) -c -o $(@) $(<)

$(Optional-path)/.build/Optional.hpp : $(Optional-format-files) $(Optional-directories)
	./gen-hdr.sh $(srcdir) Optional | clang-format > $(@)

$(Optional-path)/.build/%.format : $(srcdir)/%
	./format.sh $(<)
	mkdir -p $(dir $(@))
	touch $(@)

/usr/include/%.hpp : $(incdir)/%.hpp $(Optional-install-moddepends)
	mkdir -p $(dir $(@))
	cp $(<) $(@)
