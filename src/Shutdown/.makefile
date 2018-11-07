Shutdown-moddepends = IO Scope
Shutdown-CFLAGS =
Shutdown-LFLAGS =

Shutdown-moddepends-CFLAGS = $(foreach mod, $(Shutdown-moddepends), $($(mod)-export-CFLAGS))
Shutdown-moddepends-LFLAGS = $(foreach mod, $(Shutdown-moddepends), $($(mod)-export-LFLAGS))

Shutdown-export-CFLAGS = $(Shutdown-CFLAGS) $(Shutdown-moddepends-CFLAGS)
nodname-export-LFLAGS = $(Shutdown-LFLAGS) $(Shutdown-moddepends-LFLAGS)

Shutdown-path = $(srcdir)/Shutdown
Shutdown-files = $(shell find $(Shutdown-path) -type f -regex '\.\./\([^./][^/]*/\)*[^./][^/]*\.hpp')
Shutdown-include-files = $(Shutdown-files:$(srcdir)/%=$(incdir)/%)
Shutdown-install-files = $(Shutdown-files:$(srcdir)/%=/usr/include/%)
Shutdown-directories = $(shell find $(Shutdown-path) -type d -regex '\.\./\([^./][^/]*/\)*[^./][^/]*')
Shutdown-format-files = $(Shutdown-files:$(srcdir)/%=$(Shutdown-path)/.build/%.format)
Shutdown-install-moddepends = $(Shutdown-moddepends:%=%-install)

Shutdown : $(incdir)/Shutdown.hpp $(Shutdown-include-files)
	touch Shutdown

.PHONY : Shutdown-clean
Shutdown-clean :
	rm -rf $(Shutdown-include-files)
	rm -rf $(incdir)/Shutdown
	rm -rf $(incdir)/Shutdown.hpp
	rm -rf $(Shutdown-format-files)
	rm -rf $(Shutdown-path)/.build/Shutdown
	rm -rf $(Shutdown-path)/.build/Shutdown.hpp
	rm -rf $(Shutdown-path)/.build/Shutdown.hpp.gch
	rm -rf Shutdown

.PHONY : Shutdown-install
Shutdown-install : /usr/include/Shutdown.hpp $(Shutdown-install-files)

.PHONY : Shutdown-uninstall
Shutdown-uninstall :
	rm -rf /usr/include/Shutdown.hpp
	rm -rf /usr/include/Shutdown

.PHONY : Shutdown-format
Shutdown-format : $(Shutdown-format-files)

$(incdir)/Shutdown.hpp : $(Shutdown-path)/.build/Shutdown.hpp $(Shutdown-path)/.build/Shutdown.hpp.gch
	cp $(<) $(@)

$(incdir)/Shutdown/%.hpp : $(Shutdown-path)/%.hpp $(Shutdown-path)/.build/Shutdown.hpp.gch
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(Shutdown-path)/.build/Shutdown.hpp.gch : $(Shutdown-path)/.build/Shutdown.hpp $(Shutdown-moddepends)
	$(CPP) -I $(srcdir) $(CFLAGS) $(Shutdown-CFLAGS) $(Shutdown-moddepends-CFLAGS) -c -o $(@) $(<)

$(Shutdown-path)/.build/Shutdown.hpp : $(Shutdown-format-files) $(Shutdown-directories)
	./gen-hdr.sh $(srcdir) Shutdown | clang-format > $(@)

$(Shutdown-path)/.build/%.format : $(srcdir)/%
	./format.sh $(<)
	mkdir -p $(dir $(@))
	touch $(@)

/usr/include/%.hpp : $(incdir)/%.hpp $(Shutdown-install-moddepends)
	mkdir -p $(dir $(@))
	cp $(<) $(@)
