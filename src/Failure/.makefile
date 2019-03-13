Failure-moddepends = Scope
Failure-CFLAGS =
Failure-LFLAGS =

Failure-path = $(srcdir)/Failure
Failure-files = $(shell find $(Failure-path) -type f -regex '\.\./\([^./][^/]*/\)*[^./][^/]*\.hpp')
Failure-include-files = $(Failure-files:$(srcdir)/%=$(incdir)/%)
Failure-install-files = $(Failure-files:$(srcdir)/%=/usr/include/%)
Failure-directories = $(shell find $(Failure-path) -type d -regex '\.\./\([^./][^/]*/\)*[^./][^/]*')
Failure-format-files = $(Failure-files:$(srcdir)/%=$(Failure-path)/.build/%.format)
Failure-install-moddepends = $(Failure-moddepends:%=%-install)

Failure : $(incdir)/Failure.hpp $(Failure-include-files)
	touch Failure

.PHONY : Failure-clean
Failure-clean :
	rm -rf $(Failure-include-files)
	rm -rf $(incdir)/Failure
	rm -rf $(incdir)/Failure.hpp
	rm -rf $(Failure-format-files)
	rm -rf $(Failure-path)/.build/Failure
	rm -rf $(Failure-path)/.build/Failure.hpp
	rm -rf $(Failure-path)/.build/Failure.hpp.gch
	rm -rf Failure

.PHONY : Failure-install
Failure-install : /usr/include/Failure.hpp $(Failure-install-files)

.PHONY : Failure-uninstall
Failure-uninstall :
	rm -rf /usr/include/Failure.hpp
	rm -rf /usr/include/Failure

.PHONY : Failure-format
Failure-format : $(Failure-format-files)

$(incdir)/Failure.hpp : $(Failure-path)/.build/Failure.hpp $(Failure-path)/.build/Failure.hpp.gch
	cp $(<) $(@)

$(incdir)/Failure/%.hpp : $(Failure-path)/%.hpp $(Failure-path)/.build/Failure.hpp.gch
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(Failure-path)/.build/Failure.hpp.gch : $(Failure-path)/.build/Failure.hpp $(Failure-moddepends)
	$(CPP) $(CFLAGS) $(Failure-CFLAGS) -I $(srcdir) -c -o $(@) $(<)

$(Failure-path)/.build/Failure.hpp : $(Failure-format-files) $(Failure-directories)
	./gen-hdr.sh $(srcdir) Failure | clang-format > $(@)

$(Failure-path)/.build/%.format : $(srcdir)/%
	./format.sh $(<)
	mkdir -p $(dir $(@))
	touch $(@)

/usr/include/%.hpp : $(incdir)/%.hpp $(Failure-install-moddepends)
	mkdir -p $(dir $(@))
	cp $(<) $(@)
