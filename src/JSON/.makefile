JSON-moddepends = Failure IO
JSON-CFLAGS =
JSON-LFLAGS =

JSON-path = $(srcdir)/JSON
JSON-files = $(shell find $(JSON-path) -type f -regex '\.\./\([^./][^/]*/\)*[^./][^/]*\.hpp')
JSON-include-files = $(JSON-files:$(srcdir)/%=$(incdir)/%)
JSON-install-files = $(JSON-files:$(srcdir)/%=/usr/include/%)
JSON-directories = $(shell find $(JSON-path) -type f -regex '\.\./\([^./][^/]*/\)*[^./][^/]*')
JSON-format-files = $(JSON-files:$(srcdir)/%=$(JSON-path)/.build/%.format)
JSON-install-moddepends = $(JSON-moddepends:%=%-install)

JSON : $(incdir)/JSON.hpp $(JSON-include-files)
	touch JSON

.PHONY : JSON-clean
JSON-clean :
	rm -rf $(JSON-include-files)
	rm -rf $(incdir)/JSON
	rm -rf $(incdir)/JSON.hpp
	rm -rf $(JSON-format-files)
	rm -rf $(JSON-path)/.build/JSON
	rm -rf $(JSON-path)/.build/JSON.hpp
	rm -rf $(JSON-path)/.build/JSON.hpp.gch
	rm -rf JSON

.PHONY : JSON-install
JSON-install : /usr/include/JSON.hpp $(JSON-install-files)

.PHONY : JSON-uninstall
JSON-uninstall :
	rm -rf /usr/include/JSON.hpp
	rm -rf /usr/include/JSON

.PHONY : JSON-format
JSON-format : $(JSON-format-files)

$(incdir)/JSON.hpp : $(JSON-path)/.build/JSON.hpp $(JSON-path)/.build/JSON.hpp.gch
	cp $(<) $(@)

$(incdir)/JSON/%.hpp : $(JSON-path)/%.hpp $(JSON-path)/.build/JSON.hpp.gch
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(JSON-path)/.build/JSON.hpp.gch : $(JSON-path)/.build/JSON.hpp $(JSON-moddepends)
	$(CPP) -I $(srcdir) $(CFLAGS) $(JSON-CFLAGS) -c -o $(@) $(<)

$(JSON-path)/.build/JSON.hpp : $(JSON-format-files) $(JSON-directories)
	./gen-hdr.sh $(srcdir) JSON | clang-format > $(@)

$(JSON-path)/.build/%.format : $(srcdir)/%
	./format.sh $(<)
	mkdir -p $(dir $(@))
	touch $(@)

/usr/include/%.hpp : $(incdir)/%.hpp $(JSON-install-moddepends)
	mkdir -p $(dir $(@))
	cp $(<) $(@)
