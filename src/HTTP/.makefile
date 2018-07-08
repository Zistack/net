HTTP-moddepends =
HTTP-CFLAGS =
HTTP-LFLAGS =

HTTP-path = $(srcdir)/HTTP
HTTP-files = $(shell find $(HTTP-path) -type f -regex '\.\./\([^./][^/]*/\)*[^./][^/]*\.hpp')
HTTP-include-files = $(HTTP-files:$(srcdir)/%=$(incdir)/%)
HTTP-install-files = $(HTTP-files:$(srcdir)/%=/usr/include/%)
HTTP-directories = $(shell find $(HTTP-path) -type f -regex '\.\./\([^./][^/]*/\)*[^./][^/]*')
HTTP-format-files = $(HTTP-files:$(srcdir)/%=$(HTTP-path)/.build/%.format)
HTTP-install-moddepends = $(HTTP-moddepends:%=%-install)

HTTP : $(incdir)/HTTP.hpp $(HTTP-include-files)
	touch HTTP

.PHONY : HTTP-clean
HTTP-clean :
	rm -rf $(HTTP-include-files)
	rm -rf $(incdir)/HTTP
	rm -rf $(incdir)/HTTP.hpp
	rm -rf $(HTTP-format-files)
	rm -rf $(HTTP-path)/.build/HTTP
	rm -rf $(HTTP-path)/.build/HTTP.hpp
	rm -rf $(HTTP-path)/.build/HTTP.hpp.gch
	rm -rf HTTP

.PHONY : HTTP-install
HTTP-install : /usr/include/HTTP.hpp $(HTTP-install-files)

.PHONY : HTTP-uninstall
HTTP-uninstall :
	rm -rf /usr/include/HTTP.hpp
	rm -rf /usr/include/HTTP

.PHONY : HTTP-format
HTTP-format : $(HTTP-format-files)

$(incdir)/HTTP.hpp : $(HTTP-path)/.build/HTTP.hpp $(HTTP-path)/.build/HTTP.hpp.gch
	cp $(<) $(@)

$(incdir)/HTTP/%.hpp : $(HTTP-path)/%.hpp $(HTTP-path)/.build/HTTP.hpp.gch
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(HTTP-path)/.build/HTTP.hpp.gch : $(HTTP-path)/.build/HTTP.hpp $(HTTP-moddepends)
	$(CPP) -I $(srcdir) $(CFLAGS) $(HTTP-CFLAGS) -c -o $(@) $(<)

$(HTTP-path)/.build/HTTP.hpp : $(HTTP-format-files) $(HTTP-directories)
	./gen-hdr.sh $(srcdir) HTTP | clang-format > $(@)

$(HTTP-path)/.build/%.format : $(srcdir)/%
	./format.sh $(<)
	mkdir -p $(dir $(@))
	touch $(@)

/usr/include/%.hpp : $(incdir)/%.hpp $(HTTP-install-moddepends)
	mkdir -p $(dir $(@))
	cp $(<) $(@)
