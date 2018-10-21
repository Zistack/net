NullableString-moddepends = Optional
NullableString-CFLAGS =
NullableString-LFLAGS =

NullableString-moddepends-CFLAGS = $(foreach mod, $(NullableString-moddepends), $($(mod)-export-CFLAGS))
NullableString-moddepends-LFLAGS = $(foreach mod, $(NullableString-moddepends), $($(mod)-export-LFLAGS))

NullableString-export-CFLAGS = $(NullableString-CFLAGS) $(NullableString-moddepends-CFLAGS)
nodname-export-LFLAGS = $(NullableString-LFLAGS) $(NullableString-moddepends-LFLAGS)

NullableString-path = $(srcdir)/NullableString
NullableString-files = $(shell find $(NullableString-path) -type f -regex '\.\./\([^./][^/]*/\)*[^./][^/]*\.hpp')
NullableString-include-files = $(NullableString-files:$(srcdir)/%=$(incdir)/%)
NullableString-install-files = $(NullableString-files:$(srcdir)/%=/usr/include/%)
NullableString-directories = $(shell find $(NullableString-path) -type d -regex '\.\./\([^./][^/]*/\)*[^./][^/]*')
NullableString-format-files = $(NullableString-files:$(srcdir)/%=$(NullableString-path)/.build/%.format)
NullableString-install-moddepends = $(NullableString-moddepends:%=%-install)

NullableString : $(incdir)/NullableString.hpp $(NullableString-include-files)
	touch NullableString

.PHONY : NullableString-clean
NullableString-clean :
	rm -rf $(NullableString-include-files)
	rm -rf $(incdir)/NullableString
	rm -rf $(incdir)/NullableString.hpp
	rm -rf $(NullableString-format-files)
	rm -rf $(NullableString-path)/.build/NullableString
	rm -rf $(NullableString-path)/.build/NullableString.hpp
	rm -rf $(NullableString-path)/.build/NullableString.hpp.gch
	rm -rf NullableString

.PHONY : NullableString-install
NullableString-install : /usr/include/NullableString.hpp $(NullableString-install-files)

.PHONY : NullableString-uninstall
NullableString-uninstall :
	rm -rf /usr/include/NullableString.hpp
	rm -rf /usr/include/NullableString

.PHONY : NullableString-format
NullableString-format : $(NullableString-format-files)

$(incdir)/NullableString.hpp : $(NullableString-path)/.build/NullableString.hpp $(NullableString-path)/.build/NullableString.hpp.gch
	cp $(<) $(@)

$(incdir)/NullableString/%.hpp : $(NullableString-path)/%.hpp $(NullableString-path)/.build/NullableString.hpp.gch
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(NullableString-path)/.build/NullableString.hpp.gch : $(NullableString-path)/.build/NullableString.hpp $(NullableString-moddepends)
	$(CPP) -I $(srcdir) $(CFLAGS) $(NullableString-CFLAGS) $(NullableString-moddepends-CFLAGS) -c -o $(@) $(<)

$(NullableString-path)/.build/NullableString.hpp : $(NullableString-format-files) $(NullableString-directories)
	./gen-hdr.sh $(srcdir) NullableString | clang-format > $(@)

$(NullableString-path)/.build/%.format : $(srcdir)/%
	./format.sh $(<)
	mkdir -p $(dir $(@))
	touch $(@)

/usr/include/%.hpp : $(incdir)/%.hpp $(NullableString-install-moddepends)
	mkdir -p $(dir $(@))
	cp $(<) $(@)
