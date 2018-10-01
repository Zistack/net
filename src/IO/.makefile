IO-moddepends = Failure Thread
IO-CFLAGS =
IO-LFLAGS =

IO-moddepends-CFLAGS = $(foreach mod, $(IO-moddepends), $($(mod)-export-CFLAGS))
IO-moddepends-LFLAGS = $(foreach mod, $(IO-moddepends), $($(mod)-export-LFLAGS))

IO-export-CFLAGS = $(IO-CFLAGS) $(IO-moddepends-CFLAGS)
nodname-export-LFLAGS = $(IO-LFLAGS) $(IO-moddepends-LFLAGS)

IO-path = $(srcdir)/IO
IO-files = $(shell find $(IO-path) -type f -regex '\.\./\([^./][^/]*/\)*[^./][^/]*\.hpp')
IO-include-files = $(IO-files:$(srcdir)/%=$(incdir)/%)
IO-install-files = $(IO-files:$(srcdir)/%=/usr/include/%)
IO-directories = $(shell find $(IO-path) -type d -regex '\.\./\([^./][^/]*/\)*[^./][^/]*')
IO-format-files = $(IO-files:$(srcdir)/%=$(IO-path)/.build/%.format)
IO-install-moddepends = $(IO-moddepends:%=%-install)

IO : $(incdir)/IO.hpp $(IO-include-files)
	touch IO

.PHONY : IO-clean
IO-clean :
	rm -rf $(IO-include-files)
	rm -rf $(incdir)/IO
	rm -rf $(incdir)/IO.hpp
	rm -rf $(IO-format-files)
	rm -rf $(IO-path)/.build/IO
	rm -rf $(IO-path)/.build/IO.hpp
	rm -rf $(IO-path)/.build/IO.hpp.gch
	rm -rf IO

.PHONY : IO-install
IO-install : /usr/include/IO.hpp $(IO-install-files)

.PHONY : IO-uninstall
IO-uninstall :
	rm -rf /usr/include/IO.hpp
	rm -rf /usr/include/IO

.PHONY : IO-format
IO-format : $(IO-format-files)

$(incdir)/IO.hpp : $(IO-path)/.build/IO.hpp $(IO-path)/.build/IO.hpp.gch
	cp $(<) $(@)

$(incdir)/IO/%.hpp : $(IO-path)/%.hpp $(IO-path)/.build/IO.hpp.gch
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(IO-path)/.build/IO.hpp.gch : $(IO-path)/.build/IO.hpp $(IO-moddepends)
	$(CPP) -I $(srcdir) $(CFLAGS) $(IO-CFLAGS) $(IO-moddepends-CFLAGS) -c -o $(@) $(<)

$(IO-path)/.build/IO.hpp : $(IO-format-files) $(IO-directories)
	./gen-hdr.sh $(srcdir) IO | clang-format > $(@)

$(IO-path)/.build/%.format : $(srcdir)/%
	./format.sh $(<)
	mkdir -p $(dir $(@))
	touch $(@)

/usr/include/%.hpp : $(incdir)/%.hpp $(IO-install-moddepends)
	mkdir -p $(dir $(@))
	cp $(<) $(@)
