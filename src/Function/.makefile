Function-moddepends = Failure
Function-CFLAGS =
Function-LFLAGS =

Function-moddepends-CFLAGS = $(foreach mod, $(Function-moddepends), $($(mod)-export-CFLAGS))
Function-moddepends-LFLAGS = $(foreach mod, $(Function-moddepends), $($(mod)-export-LFLAGS))

Function-export-CFLAGS = $(Function-CFLAGS) $(Function-moddepends-CFLAGS)
nodname-export-LFLAGS = $(Function-LFLAGS) $(Function-moddepends-LFLAGS)

Function-path = $(srcdir)/Function
Function-files = $(shell find $(Function-path) -type f -regex '\.\./\([^./][^/]*/\)*[^./][^/]*\.hpp')
Function-include-files = $(Function-files:$(srcdir)/%=$(incdir)/%)
Function-install-files = $(Function-files:$(srcdir)/%=/usr/include/%)
Function-directories = $(shell find $(Function-path) -type d -regex '\.\./\([^./][^/]*/\)*[^./][^/]*')
Function-format-files = $(Function-files:$(srcdir)/%=$(Function-path)/.build/%.format)
Function-install-moddepends = $(Function-moddepends:%=%-install)

Function : $(incdir)/Function.hpp $(Function-include-files)
	touch Function

.PHONY : Function-clean
Function-clean :
	rm -rf $(Function-include-files)
	rm -rf $(incdir)/Function
	rm -rf $(incdir)/Function.hpp
	rm -rf $(Function-format-files)
	rm -rf $(Function-path)/.build/Function
	rm -rf $(Function-path)/.build/Function.hpp
	rm -rf $(Function-path)/.build/Function.hpp.gch
	rm -rf Function

.PHONY : Function-install
Function-install : /usr/include/Function.hpp $(Function-install-files)

.PHONY : Function-uninstall
Function-uninstall :
	rm -rf /usr/include/Function.hpp
	rm -rf /usr/include/Function

.PHONY : Function-format
Function-format : $(Function-format-files)

$(incdir)/Function.hpp : $(Function-path)/.build/Function.hpp $(Function-path)/.build/Function.hpp.gch
	cp $(<) $(@)

$(incdir)/Function/%.hpp : $(Function-path)/%.hpp $(Function-path)/.build/Function.hpp.gch
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(Function-path)/.build/Function.hpp.gch : $(Function-path)/.build/Function.hpp $(Function-moddepends)
	$(CPP) -I $(srcdir) $(CFLAGS) $(Function-CFLAGS) $(Function-moddepends-CFLAGS) -c -o $(@) $(<)

$(Function-path)/.build/Function.hpp : $(Function-format-files) $(Function-directories)
	./gen-hdr.sh $(srcdir) Function | clang-format > $(@)

$(Function-path)/.build/%.format : $(srcdir)/%
	./format.sh $(<)
	mkdir -p $(dir $(@))
	touch $(@)

/usr/include/%.hpp : $(incdir)/%.hpp $(Function-install-moddepends)
	mkdir -p $(dir $(@))
	cp $(<) $(@)
