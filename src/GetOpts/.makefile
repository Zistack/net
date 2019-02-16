GetOpts-moddepends = Failure IO
GetOpts-CFLAGS =
GetOpts-LFLAGS =

GetOpts-moddepends-CFLAGS = $(foreach mod, $(GetOpts-moddepends), $($(mod)-export-CFLAGS))
GetOpts-moddepends-LFLAGS = $(foreach mod, $(GetOpts-moddepends), $($(mod)-export-LFLAGS))

GetOpts-export-CFLAGS = $(GetOpts-CFLAGS) $(GetOpts-moddepends-CFLAGS)
nodname-export-LFLAGS = $(GetOpts-LFLAGS) $(GetOpts-moddepends-LFLAGS)

GetOpts-path = $(srcdir)/GetOpts
GetOpts-files = $(shell find $(GetOpts-path) -type f -regex '\.\./\([^./][^/]*/\)*[^./][^/]*\.hpp')
GetOpts-include-files = $(GetOpts-files:$(srcdir)/%=$(incdir)/%)
GetOpts-install-files = $(GetOpts-files:$(srcdir)/%=/usr/include/%)
GetOpts-directories = $(shell find $(GetOpts-path) -type d -regex '\.\./\([^./][^/]*/\)*[^./][^/]*')
GetOpts-format-files = $(GetOpts-files:$(srcdir)/%=$(GetOpts-path)/.build/%.format)
GetOpts-install-moddepends = $(GetOpts-moddepends:%=%-install)

GetOpts : $(incdir)/GetOpts.hpp $(GetOpts-include-files)
	touch GetOpts

.PHONY : GetOpts-clean
GetOpts-clean :
	rm -rf $(GetOpts-include-files)
	rm -rf $(incdir)/GetOpts
	rm -rf $(incdir)/GetOpts.hpp
	rm -rf $(GetOpts-format-files)
	rm -rf $(GetOpts-path)/.build/GetOpts
	rm -rf $(GetOpts-path)/.build/GetOpts.hpp
	rm -rf $(GetOpts-path)/.build/GetOpts.hpp.gch
	rm -rf GetOpts

.PHONY : GetOpts-install
GetOpts-install : /usr/include/GetOpts.hpp $(GetOpts-install-files)

.PHONY : GetOpts-uninstall
GetOpts-uninstall :
	rm -rf /usr/include/GetOpts.hpp
	rm -rf /usr/include/GetOpts

.PHONY : GetOpts-format
GetOpts-format : $(GetOpts-format-files)

$(incdir)/GetOpts.hpp : $(GetOpts-path)/.build/GetOpts.hpp $(GetOpts-path)/.build/GetOpts.hpp.gch
	cp $(<) $(@)

$(incdir)/GetOpts/%.hpp : $(GetOpts-path)/%.hpp $(GetOpts-path)/.build/GetOpts.hpp.gch
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(GetOpts-path)/.build/GetOpts.hpp.gch : $(GetOpts-path)/.build/GetOpts.hpp $(GetOpts-moddepends)
	$(CPP) -I $(srcdir) $(CFLAGS) $(GetOpts-CFLAGS) $(GetOpts-moddepends-CFLAGS) -c -o $(@) $(<)

$(GetOpts-path)/.build/GetOpts.hpp : $(GetOpts-format-files) $(GetOpts-directories)
	./gen-hdr.sh $(srcdir) GetOpts | clang-format > $(@)

$(GetOpts-path)/.build/%.format : $(srcdir)/%
	./format.sh $(<)
	mkdir -p $(dir $(@))
	touch $(@)

/usr/include/%.hpp : $(incdir)/%.hpp $(GetOpts-install-moddepends)
	mkdir -p $(dir $(@))
	cp $(<) $(@)
