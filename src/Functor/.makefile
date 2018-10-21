Functor-moddepends =
Functor-CFLAGS =
Functor-LFLAGS =

Functor-moddepends-CFLAGS = $(foreach mod, $(Functor-moddepends), $($(mod)-export-CFLAGS))
Functor-moddepends-LFLAGS = $(foreach mod, $(Functor-moddepends), $($(mod)-export-LFLAGS))

Functor-export-CFLAGS = $(Functor-CFLAGS) $(Functor-moddepends-CFLAGS)
nodname-export-LFLAGS = $(Functor-LFLAGS) $(Functor-moddepends-LFLAGS)

Functor-path = $(srcdir)/Functor
Functor-files = $(shell find $(Functor-path) -type f -regex '\.\./\([^./][^/]*/\)*[^./][^/]*\.hpp')
Functor-include-files = $(Functor-files:$(srcdir)/%=$(incdir)/%)
Functor-install-files = $(Functor-files:$(srcdir)/%=/usr/include/%)
Functor-directories = $(shell find $(Functor-path) -type d -regex '\.\./\([^./][^/]*/\)*[^./][^/]*')
Functor-format-files = $(Functor-files:$(srcdir)/%=$(Functor-path)/.build/%.format)
Functor-install-moddepends = $(Functor-moddepends:%=%-install)

Functor : $(incdir)/Functor.hpp $(Functor-include-files)
	touch Functor

.PHONY : Functor-clean
Functor-clean :
	rm -rf $(Functor-include-files)
	rm -rf $(incdir)/Functor
	rm -rf $(incdir)/Functor.hpp
	rm -rf $(Functor-format-files)
	rm -rf $(Functor-path)/.build/Functor
	rm -rf $(Functor-path)/.build/Functor.hpp
	rm -rf $(Functor-path)/.build/Functor.hpp.gch
	rm -rf Functor

.PHONY : Functor-install
Functor-install : /usr/include/Functor.hpp $(Functor-install-files)

.PHONY : Functor-uninstall
Functor-uninstall :
	rm -rf /usr/include/Functor.hpp
	rm -rf /usr/include/Functor

.PHONY : Functor-format
Functor-format : $(Functor-format-files)

$(incdir)/Functor.hpp : $(Functor-path)/.build/Functor.hpp $(Functor-path)/.build/Functor.hpp.gch
	cp $(<) $(@)

$(incdir)/Functor/%.hpp : $(Functor-path)/%.hpp $(Functor-path)/.build/Functor.hpp.gch
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(Functor-path)/.build/Functor.hpp.gch : $(Functor-path)/.build/Functor.hpp $(Functor-moddepends)
	$(CPP) -I $(srcdir) $(CFLAGS) $(Functor-CFLAGS) $(Functor-moddepends-CFLAGS) -c -o $(@) $(<)

$(Functor-path)/.build/Functor.hpp : $(Functor-format-files) $(Functor-directories)
	./gen-hdr.sh $(srcdir) Functor | clang-format > $(@)

$(Functor-path)/.build/%.format : $(srcdir)/%
	./format.sh $(<)
	mkdir -p $(dir $(@))
	touch $(@)

/usr/include/%.hpp : $(incdir)/%.hpp $(Functor-install-moddepends)
	mkdir -p $(dir $(@))
	cp $(<) $(@)
