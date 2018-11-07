SuppressingScope-moddepends =
SuppressingScope-CFLAGS =
SuppressingScope-LFLAGS =

SuppressingScope-moddepends-CFLAGS = $(foreach mod, $(SuppressingScope-moddepends), $($(mod)-export-CFLAGS))
SuppressingScope-moddepends-LFLAGS = $(foreach mod, $(SuppressingScope-moddepends), $($(mod)-export-LFLAGS))

SuppressingScope-export-CFLAGS = $(SuppressingScope-CFLAGS) $(SuppressingScope-moddepends-CFLAGS)
nodname-export-LFLAGS = $(SuppressingScope-LFLAGS) $(SuppressingScope-moddepends-LFLAGS)

SuppressingScope-path = $(srcdir)/SuppressingScope
SuppressingScope-files = $(shell find $(SuppressingScope-path) -type f -regex '\.\./\([^./][^/]*/\)*[^./][^/]*\.hpp')
SuppressingScope-include-files = $(SuppressingScope-files:$(srcdir)/%=$(incdir)/%)
SuppressingScope-install-files = $(SuppressingScope-files:$(srcdir)/%=/usr/include/%)
SuppressingScope-directories = $(shell find $(SuppressingScope-path) -type d -regex '\.\./\([^./][^/]*/\)*[^./][^/]*')
SuppressingScope-format-files = $(SuppressingScope-files:$(srcdir)/%=$(SuppressingScope-path)/.build/%.format)
SuppressingScope-install-moddepends = $(SuppressingScope-moddepends:%=%-install)

SuppressingScope : $(incdir)/SuppressingScope.hpp $(SuppressingScope-include-files)
	touch SuppressingScope

.PHONY : SuppressingScope-clean
SuppressingScope-clean :
	rm -rf $(SuppressingScope-include-files)
	rm -rf $(incdir)/SuppressingScope
	rm -rf $(incdir)/SuppressingScope.hpp
	rm -rf $(SuppressingScope-format-files)
	rm -rf $(SuppressingScope-path)/.build/SuppressingScope
	rm -rf $(SuppressingScope-path)/.build/SuppressingScope.hpp
	rm -rf $(SuppressingScope-path)/.build/SuppressingScope.hpp.gch
	rm -rf SuppressingScope

.PHONY : SuppressingScope-install
SuppressingScope-install : /usr/include/SuppressingScope.hpp $(SuppressingScope-install-files)

.PHONY : SuppressingScope-uninstall
SuppressingScope-uninstall :
	rm -rf /usr/include/SuppressingScope.hpp
	rm -rf /usr/include/SuppressingScope

.PHONY : SuppressingScope-format
SuppressingScope-format : $(SuppressingScope-format-files)

$(incdir)/SuppressingScope.hpp : $(SuppressingScope-path)/.build/SuppressingScope.hpp $(SuppressingScope-path)/.build/SuppressingScope.hpp.gch
	cp $(<) $(@)

$(incdir)/SuppressingScope/%.hpp : $(SuppressingScope-path)/%.hpp $(SuppressingScope-path)/.build/SuppressingScope.hpp.gch
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(SuppressingScope-path)/.build/SuppressingScope.hpp.gch : $(SuppressingScope-path)/.build/SuppressingScope.hpp $(SuppressingScope-moddepends)
	$(CPP) -I $(srcdir) $(CFLAGS) $(SuppressingScope-CFLAGS) $(SuppressingScope-moddepends-CFLAGS) -c -o $(@) $(<)

$(SuppressingScope-path)/.build/SuppressingScope.hpp : $(SuppressingScope-format-files) $(SuppressingScope-directories)
	./gen-hdr.sh $(srcdir) SuppressingScope | clang-format > $(@)

$(SuppressingScope-path)/.build/%.format : $(srcdir)/%
	./format.sh $(<)
	mkdir -p $(dir $(@))
	touch $(@)

/usr/include/%.hpp : $(incdir)/%.hpp $(SuppressingScope-install-moddepends)
	mkdir -p $(dir $(@))
	cp $(<) $(@)
