Scope-moddepends =
Scope-CFLAGS =
Scope-LFLAGS =

Scope-moddepends-CFLAGS = $(foreach mod, $(Scope-moddepends), $($(mod)-export-CFLAGS))
Scope-moddepends-LFLAGS = $(foreach mod, $(Scope-moddepends), $($(mod)-export-LFLAGS))

Scope-export-CFLAGS = $(Scope-CFLAGS) $(Scope-moddepends-CFLAGS)
nodname-export-LFLAGS = $(Scope-LFLAGS) $(Scope-moddepends-LFLAGS)

Scope-path = $(srcdir)/Scope
Scope-files = $(shell find $(Scope-path) -type f -regex '\.\./\([^./][^/]*/\)*[^./][^/]*\.hpp')
Scope-include-files = $(Scope-files:$(srcdir)/%=$(incdir)/%)
Scope-install-files = $(Scope-files:$(srcdir)/%=/usr/include/%)
Scope-directories = $(shell find $(Scope-path) -type d -regex '\.\./\([^./][^/]*/\)*[^./][^/]*')
Scope-format-files = $(Scope-files:$(srcdir)/%=$(Scope-path)/.build/%.format)
Scope-install-moddepends = $(Scope-moddepends:%=%-install)

Scope : $(incdir)/Scope.hpp $(Scope-include-files)
	touch Scope

.PHONY : Scope-clean
Scope-clean :
	rm -rf $(Scope-include-files)
	rm -rf $(incdir)/Scope
	rm -rf $(incdir)/Scope.hpp
	rm -rf $(Scope-format-files)
	rm -rf $(Scope-path)/.build/Scope
	rm -rf $(Scope-path)/.build/Scope.hpp
	rm -rf $(Scope-path)/.build/Scope.hpp.gch
	rm -rf Scope

.PHONY : Scope-install
Scope-install : /usr/include/Scope.hpp $(Scope-install-files)

.PHONY : Scope-uninstall
Scope-uninstall :
	rm -rf /usr/include/Scope.hpp
	rm -rf /usr/include/Scope

.PHONY : Scope-format
Scope-format : $(Scope-format-files)

$(incdir)/Scope.hpp : $(Scope-path)/.build/Scope.hpp $(Scope-path)/.build/Scope.hpp.gch
	cp $(<) $(@)

$(incdir)/Scope/%.hpp : $(Scope-path)/%.hpp $(Scope-path)/.build/Scope.hpp.gch
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(Scope-path)/.build/Scope.hpp.gch : $(Scope-path)/.build/Scope.hpp $(Scope-moddepends)
	$(CPP) -I $(srcdir) $(CFLAGS) $(Scope-CFLAGS) $(Scope-moddepends-CFLAGS) -c -o $(@) $(<)

$(Scope-path)/.build/Scope.hpp : $(Scope-format-files) $(Scope-directories)
	./gen-hdr.sh $(srcdir) Scope | clang-format > $(@)

$(Scope-path)/.build/%.format : $(srcdir)/%
	./format.sh $(<)
	mkdir -p $(dir $(@))
	touch $(@)

/usr/include/%.hpp : $(incdir)/%.hpp $(Scope-install-moddepends)
	mkdir -p $(dir $(@))
	cp $(<) $(@)
