Status-moddepends = Thread
Status-CFLAGS =
Status-LFLAGS =

Status-moddepends-CFLAGS = $(foreach mod, $(Status-moddepends), $($(mod)-export-CFLAGS))
Status-moddepends-LFLAGS = $(foreach mod, $(Status-moddepends), $($(mod)-export-LFLAGS))

Status-export-CFLAGS = $(Status-CFLAGS) $(Status-moddepends-CFLAGS)
nodname-export-LFLAGS = $(Status-LFLAGS) $(Status-moddepends-LFLAGS)

Status-path = $(srcdir)/Status
Status-files = $(shell find $(Status-path) -type f -regex '\.\./\([^./][^/]*/\)*[^./][^/]*\.hpp')
Status-include-files = $(Status-files:$(srcdir)/%=$(incdir)/%)
Status-install-files = $(Status-files:$(srcdir)/%=/usr/include/%)
Status-directories = $(shell find $(Status-path) -type d -regex '\.\./\([^./][^/]*/\)*[^./][^/]*')
Status-format-files = $(Status-files:$(srcdir)/%=$(Status-path)/.build/%.format)
Status-install-moddepends = $(Status-moddepends:%=%-install)

Status : $(incdir)/Status.hpp $(Status-include-files)
	touch Status

.PHONY : Status-clean
Status-clean :
	rm -rf $(Status-include-files)
	rm -rf $(incdir)/Status
	rm -rf $(incdir)/Status.hpp
	rm -rf $(Status-format-files)
	rm -rf $(Status-path)/.build/Status
	rm -rf $(Status-path)/.build/Status.hpp
	rm -rf $(Status-path)/.build/Status.hpp.gch
	rm -rf Status

.PHONY : Status-install
Status-install : /usr/include/Status.hpp $(Status-install-files)

.PHONY : Status-uninstall
Status-uninstall :
	rm -rf /usr/include/Status.hpp
	rm -rf /usr/include/Status

.PHONY : Status-format
Status-format : $(Status-format-files)

$(incdir)/Status.hpp : $(Status-path)/.build/Status.hpp $(Status-path)/.build/Status.hpp.gch
	cp $(<) $(@)

$(incdir)/Status/%.hpp : $(Status-path)/%.hpp $(Status-path)/.build/Status.hpp.gch
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(Status-path)/.build/Status.hpp.gch : $(Status-path)/.build/Status.hpp $(Status-moddepends)
	$(CPP) -I $(srcdir) $(CFLAGS) $(Status-CFLAGS) $(Status-moddepends-CFLAGS) -c -o $(@) $(<)

$(Status-path)/.build/Status.hpp : $(Status-format-files) $(Status-directories)
	./gen-hdr.sh $(srcdir) Status | clang-format > $(@)

$(Status-path)/.build/%.format : $(srcdir)/%
	./format.sh $(<)
	mkdir -p $(dir $(@))
	touch $(@)

/usr/include/%.hpp : $(incdir)/%.hpp $(Status-install-moddepends)
	mkdir -p $(dir $(@))
	cp $(<) $(@)
