URI-moddepends = Failure IO NullableString
URI-CFLAGS =
URI-LFLAGS =

URI-moddepends-CFLAGS = $(foreach mod, $(URI-moddepends), $($(mod)-export-CFLAGS))
URI-moddepends-LFLAGS = $(foreach mod, $(URI-moddepends), $($(mod)-export-LFLAGS))

URI-export-CFLAGS = $(URI-CFLAGS) $(URI-moddepends-CFLAGS)
nodname-export-LFLAGS = $(URI-LFLAGS) $(URI-moddepends-LFLAGS)

URI-path = $(srcdir)/URI
URI-files = $(shell find $(URI-path) -type f -regex '\.\./\([^./][^/]*/\)*[^./][^/]*\.hpp')
URI-include-files = $(URI-files:$(srcdir)/%=$(incdir)/%)
URI-install-files = $(URI-files:$(srcdir)/%=/usr/include/%)
URI-directories = $(shell find $(URI-path) -type d -regex '\.\./\([^./][^/]*/\)*[^./][^/]*')
URI-format-files = $(URI-files:$(srcdir)/%=$(URI-path)/.build/%.format)
URI-install-moddepends = $(URI-moddepends:%=%-install)

URI : $(incdir)/URI.hpp $(URI-include-files)
	touch URI

.PHONY : URI-clean
URI-clean :
	rm -rf $(URI-include-files)
	rm -rf $(incdir)/URI
	rm -rf $(incdir)/URI.hpp
	rm -rf $(URI-format-files)
	rm -rf $(URI-path)/.build/URI
	rm -rf $(URI-path)/.build/URI.hpp
	rm -rf $(URI-path)/.build/URI.hpp.gch
	rm -rf URI

.PHONY : URI-install
URI-install : /usr/include/URI.hpp $(URI-install-files)

.PHONY : URI-uninstall
URI-uninstall :
	rm -rf /usr/include/URI.hpp
	rm -rf /usr/include/URI

.PHONY : URI-format
URI-format : $(URI-format-files)

$(incdir)/URI.hpp : $(URI-path)/.build/URI.hpp $(URI-path)/.build/URI.hpp.gch
	cp $(<) $(@)

$(incdir)/URI/%.hpp : $(URI-path)/%.hpp $(URI-path)/.build/URI.hpp.gch
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(URI-path)/.build/URI.hpp.gch : $(URI-path)/.build/URI.hpp $(URI-moddepends)
	$(CPP) -I $(srcdir) $(CFLAGS) $(URI-CFLAGS) $(URI-moddepends-CFLAGS) -c -o $(@) $(<)

$(URI-path)/.build/URI.hpp : $(URI-format-files) $(URI-directories)
	./gen-hdr.sh $(srcdir) URI | clang-format > $(@)

$(URI-path)/.build/%.format : $(srcdir)/%
	./format.sh $(<)
	mkdir -p $(dir $(@))
	touch $(@)

/usr/include/%.hpp : $(incdir)/%.hpp $(URI-install-moddepends)
	mkdir -p $(dir $(@))
	cp $(<) $(@)
