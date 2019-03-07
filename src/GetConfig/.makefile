GetConfig-moddepends = Failure IO NullOpt
GetConfig-CFLAGS =
GetConfig-LFLAGS =

GetConfig-moddepends-CFLAGS = $(foreach mod, $(GetConfig-moddepends), $($(mod)-export-CFLAGS))
GetConfig-moddepends-LFLAGS = $(foreach mod, $(GetConfig-moddepends), $($(mod)-export-LFLAGS))

GetConfig-export-CFLAGS = $(GetConfig-CFLAGS) $(GetConfig-moddepends-CFLAGS)
nodname-export-LFLAGS = $(GetConfig-LFLAGS) $(GetConfig-moddepends-LFLAGS)

GetConfig-path = $(srcdir)/GetConfig
GetConfig-files = $(shell find $(GetConfig-path) -type f -regex '\.\./\([^./][^/]*/\)*[^./][^/]*\.hpp')
GetConfig-include-files = $(GetConfig-files:$(srcdir)/%=$(incdir)/%)
GetConfig-install-files = $(GetConfig-files:$(srcdir)/%=/usr/include/%)
GetConfig-directories = $(shell find $(GetConfig-path) -type d -regex '\.\./\([^./][^/]*/\)*[^./][^/]*')
GetConfig-format-files = $(GetConfig-files:$(srcdir)/%=$(GetConfig-path)/.build/%.format)
GetConfig-install-moddepends = $(GetConfig-moddepends:%=%-install)

GetConfig : $(incdir)/GetConfig.hpp $(GetConfig-include-files)
	touch GetConfig

.PHONY : GetConfig-clean
GetConfig-clean :
	rm -rf $(GetConfig-include-files)
	rm -rf $(incdir)/GetConfig
	rm -rf $(incdir)/GetConfig.hpp
	rm -rf $(GetConfig-format-files)
	rm -rf $(GetConfig-path)/.build/GetConfig
	rm -rf $(GetConfig-path)/.build/GetConfig.hpp
	rm -rf $(GetConfig-path)/.build/GetConfig.hpp.gch
	rm -rf GetConfig

.PHONY : GetConfig-install
GetConfig-install : /usr/include/GetConfig.hpp $(GetConfig-install-files)

.PHONY : GetConfig-uninstall
GetConfig-uninstall :
	rm -rf /usr/include/GetConfig.hpp
	rm -rf /usr/include/GetConfig

.PHONY : GetConfig-format
GetConfig-format : $(GetConfig-format-files)

$(incdir)/GetConfig.hpp : $(GetConfig-path)/.build/GetConfig.hpp $(GetConfig-path)/.build/GetConfig.hpp.gch
	cp $(<) $(@)

$(incdir)/GetConfig/%.hpp : $(GetConfig-path)/%.hpp $(GetConfig-path)/.build/GetConfig.hpp.gch
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(GetConfig-path)/.build/GetConfig.hpp.gch : $(GetConfig-path)/.build/GetConfig.hpp $(GetConfig-moddepends)
	$(CPP) -I $(srcdir) $(CFLAGS) $(GetConfig-CFLAGS) $(GetConfig-moddepends-CFLAGS) -c -o $(@) $(<)

$(GetConfig-path)/.build/GetConfig.hpp : $(GetConfig-format-files) $(GetConfig-directories)
	./gen-hdr.sh $(srcdir) GetConfig | clang-format > $(@)

$(GetConfig-path)/.build/%.format : $(srcdir)/%
	./format.sh $(<)
	mkdir -p $(dir $(@))
	touch $(@)

/usr/include/%.hpp : $(incdir)/%.hpp $(GetConfig-install-moddepends)
	mkdir -p $(dir $(@))
	cp $(<) $(@)
