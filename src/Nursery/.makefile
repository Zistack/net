Nursery-moddepends =
Nursery-CFLAGS =
Nursery-LFLAGS =

Nursery-path = $(srcdir)/Nursery
Nursery-files = $(shell find $(Nursery-path) -type f -regex '\.\./\([^./][^/]*/\)*[^./][^/]*\.hpp')
Nursery-include-files = $(Nursery-files:$(srcdir)/%=$(incdir)/%)
Nursery-install-files = $(Nursery-files:$(srcdir)/%=/usr/include/%)
Nursery-directories = $(shell find $(Nursery-path) -type f -regex '\.\./\([^./][^/]*/\)*[^./][^/]*')
Nursery-format-files = $(Nursery-files:$(srcdir)/%=$(Nursery-path)/.build/%.format)
Nursery-install-moddepends = $(Nursery-moddepends:%=%-install)

Nursery : $(incdir)/Nursery.hpp $(Nursery-include-files)
	touch Nursery

.PHONY : Nursery-clean
Nursery-clean :
	rm -rf $(incdir)/Nursery.hpp
	rm -rf $(Nursery-include-files)
	rm -rf $(incdir)/Nursery
	rm -rf $(Nursery-format-files)
	rm -rf $(Nursery-path)/.build/Nursery
	rm -rf Nursery

.PHONY : Nursery-install
Nursery-install : /usr/include/Nursery.hpp $(Nursery-install-files)

.PHONY : Nursery-uninstall
Nursery-uninstall :
	rm -rf /usr/include/Nursery.hpp
	rm -rf /usr/include/Nursery

.PHONY : Nursery-format
Nursery-format : $(Nursery-format-files)

$(incdir)/Nursery.hpp : $(Nursery-path)/.build/Nursery.hpp $(Nursery-path)/.build/Nursery.hpp.gch
	cp $(<) $(@)

$(incdir)/%.hpp : $(srcdir)/%.hpp $(Nursery-path)/.build/Nursery.hpp.gch
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(Nursery-path)/.build/Nursery.hpp.gch : $(Nursery-path)/.build/Nursery.hpp
	$(CPP) $(CFLAGS) $(Nursery-CFLAGS) -I $(srcdir) -c -o $(@) $(<)

$(Nursery-path)/.build/Nursery.hpp : $(Nursery-format-files) $(Nursery-directories)
	./gen-hdr.sh $(srcdir) Nursery | clang-format > $(@)

$(Nursery-path)/.build/%.format : $(srcdir)/%
	./format.sh $(<)
	mkdir -p $(dir $(@))
	touch $(@)

/usr/include/%.hpp : $(incdir)/%.hpp $(Nursery-install-moddepends)
	mkdir -p $(dir $(@))
	cp $(<) $(@)
