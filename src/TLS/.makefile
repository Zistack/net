TLS-moddepends = Failure IO JSON
TLS-CFLAGS =
TLS-LFLAGS =

TLS-path = $(srcdir)/TLS
TLS-files = $(shell find $(TLS-path) -type f -regex '\.\./\([^./][^/]*/\)*[^./][^/]*\.hpp')
TLS-include-files = $(TLS-files:$(srcdir)/%=$(incdir)/%)
TLS-install-files = $(TLS-files:$(srcdir)/%=/usr/include/%)
TLS-directories = $(shell find $(TLS-path) -type f -regex '\.\./\([^./][^/]*/\)*[^./][^/]*')
TLS-format-files = $(TLS-files:$(srcdir)/%=$(TLS-path)/.build/%.format)
TLS-install-moddepends = $(TLS-moddepends:%=%-install)

TLS : $(incdir)/TLS.hpp $(TLS-include-files)
	touch TLS

.PHONY : TLS-clean
TLS-clean :
	rm -rf $(TLS-include-files)
	rm -rf $(incdir)/TLS
	rm -rf $(incdir)/TLS.hpp
	rm -rf $(TLS-format-files)
	rm -rf $(TLS-path)/.build/TLS
	rm -rf $(TLS-path)/.build/TLS.hpp
	rm -rf $(TLS-path)/.build/TLS.hpp.gch
	rm -rf TLS

.PHONY : TLS-install
TLS-install : /usr/include/TLS.hpp $(TLS-install-files)

.PHONY : TLS-uninstall
TLS-uninstall :
	rm -rf /usr/include/TLS.hpp
	rm -rf /usr/include/TLS

.PHONY : TLS-format
TLS-format : $(TLS-format-files)

$(incdir)/TLS.hpp : $(TLS-path)/.build/TLS.hpp $(TLS-path)/.build/TLS.hpp.gch
	cp $(<) $(@)

$(incdir)/TLS/%.hpp : $(TLS-path)/%.hpp $(TLS-path)/.build/TLS.hpp.gch
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(TLS-path)/.build/TLS.hpp.gch : $(TLS-path)/.build/TLS.hpp $(TLS-moddepends)
	$(CPP) -I $(srcdir) $(CFLAGS) $(TLS-CFLAGS) -c -o $(@) $(<)

$(TLS-path)/.build/TLS.hpp : $(TLS-format-files) $(TLS-directories)
	./gen-hdr.sh $(srcdir) TLS | clang-format > $(@)

$(TLS-path)/.build/%.format : $(srcdir)/%
	./format.sh $(<)
	mkdir -p $(dir $(@))
	touch $(@)

/usr/include/%.hpp : $(incdir)/%.hpp $(TLS-install-moddepends)
	mkdir -p $(dir $(@))
	cp $(<) $(@)
