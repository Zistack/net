NullOpt-moddepends =
NullOpt-CFLAGS =
NullOpt-LFLAGS =

NullOpt-moddepends-CFLAGS = $(foreach mod, $(NullOpt-moddepends), $($(mod)-export-CFLAGS))
NullOpt-moddepends-LFLAGS = $(foreach mod, $(NullOpt-moddepends), $($(mod)-export-LFLAGS))

NullOpt-export-CFLAGS = $(NullOpt-CFLAGS) $(NullOpt-moddepends-CFLAGS)
nodname-export-LFLAGS = $(NullOpt-LFLAGS) $(NullOpt-moddepends-LFLAGS)

NullOpt-path = $(srcdir)/NullOpt
NullOpt-files = $(shell find $(NullOpt-path) -type f -regex '\.\./\([^./][^/]*/\)*[^./][^/]*\.hpp')
NullOpt-include-files = $(NullOpt-files:$(srcdir)/%=$(incdir)/%)
NullOpt-install-files = $(NullOpt-files:$(srcdir)/%=/usr/include/%)
NullOpt-directories = $(shell find $(NullOpt-path) -type d -regex '\.\./\([^./][^/]*/\)*[^./][^/]*')
NullOpt-format-files = $(NullOpt-files:$(srcdir)/%=$(NullOpt-path)/.build/%.format)
NullOpt-install-moddepends = $(NullOpt-moddepends:%=%-install)

NullOpt : $(incdir)/NullOpt.hpp $(NullOpt-include-files)
	touch NullOpt

.PHONY : NullOpt-clean
NullOpt-clean :
	rm -rf $(NullOpt-include-files)
	rm -rf $(incdir)/NullOpt
	rm -rf $(incdir)/NullOpt.hpp
	rm -rf $(NullOpt-format-files)
	rm -rf $(NullOpt-path)/.build/NullOpt
	rm -rf $(NullOpt-path)/.build/NullOpt.hpp
	rm -rf $(NullOpt-path)/.build/NullOpt.hpp.gch
	rm -rf NullOpt

.PHONY : NullOpt-install
NullOpt-install : /usr/include/NullOpt.hpp $(NullOpt-install-files)

.PHONY : NullOpt-uninstall
NullOpt-uninstall :
	rm -rf /usr/include/NullOpt.hpp
	rm -rf /usr/include/NullOpt

.PHONY : NullOpt-format
NullOpt-format : $(NullOpt-format-files)

$(incdir)/NullOpt.hpp : $(NullOpt-path)/.build/NullOpt.hpp $(NullOpt-path)/.build/NullOpt.hpp.gch
	cp $(<) $(@)

$(incdir)/NullOpt/%.hpp : $(NullOpt-path)/%.hpp $(NullOpt-path)/.build/NullOpt.hpp.gch
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(NullOpt-path)/.build/NullOpt.hpp.gch : $(NullOpt-path)/.build/NullOpt.hpp $(NullOpt-moddepends)
	$(CPP) -I $(srcdir) $(CFLAGS) $(NullOpt-CFLAGS) $(NullOpt-moddepends-CFLAGS) -c -o $(@) $(<)

$(NullOpt-path)/.build/NullOpt.hpp : $(NullOpt-format-files) $(NullOpt-directories)
	./gen-hdr.sh $(srcdir) NullOpt | clang-format > $(@)

$(NullOpt-path)/.build/%.format : $(srcdir)/%
	./format.sh $(<)
	mkdir -p $(dir $(@))
	touch $(@)

/usr/include/%.hpp : $(incdir)/%.hpp $(NullOpt-install-moddepends)
	mkdir -p $(dir $(@))
	cp $(<) $(@)
