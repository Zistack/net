FIFOProtocol-moddepends = IO Thread Failure Shutdown Protocol Scope SuppressingScope GetConfig
FIFOProtocol-CFLAGS =
FIFOProtocol-LFLAGS =

FIFOProtocol-moddepends-CFLAGS = $(foreach mod, $(FIFOProtocol-moddepends), $($(mod)-export-CFLAGS))
FIFOProtocol-moddepends-LFLAGS = $(foreach mod, $(FIFOProtocol-moddepends), $($(mod)-export-LFLAGS))

FIFOProtocol-export-CFLAGS = $(FIFOProtocol-CFLAGS) $(FIFOProtocol-moddepends-CFLAGS)
nodname-export-LFLAGS = $(FIFOProtocol-LFLAGS) $(FIFOProtocol-moddepends-LFLAGS)

FIFOProtocol-path = $(srcdir)/FIFOProtocol
FIFOProtocol-files = $(shell find $(FIFOProtocol-path) -type f -regex '\.\./\([^./][^/]*/\)*[^./][^/]*\.hpp')
FIFOProtocol-include-files = $(FIFOProtocol-files:$(srcdir)/%=$(incdir)/%)
FIFOProtocol-install-files = $(FIFOProtocol-files:$(srcdir)/%=/usr/include/%)
FIFOProtocol-directories = $(shell find $(FIFOProtocol-path) -type d -regex '\.\./\([^./][^/]*/\)*[^./][^/]*')
FIFOProtocol-format-files = $(FIFOProtocol-files:$(srcdir)/%=$(FIFOProtocol-path)/.build/%.format)
FIFOProtocol-install-moddepends = $(FIFOProtocol-moddepends:%=%-install)

FIFOProtocol : $(incdir)/FIFOProtocol.hpp $(FIFOProtocol-include-files)
	touch FIFOProtocol

.PHONY : FIFOProtocol-clean
FIFOProtocol-clean :
	rm -rf $(FIFOProtocol-include-files)
	rm -rf $(incdir)/FIFOProtocol
	rm -rf $(incdir)/FIFOProtocol.hpp
	rm -rf $(FIFOProtocol-format-files)
	rm -rf $(FIFOProtocol-path)/.build/FIFOProtocol
	rm -rf $(FIFOProtocol-path)/.build/FIFOProtocol.hpp
	rm -rf $(FIFOProtocol-path)/.build/FIFOProtocol.hpp.gch
	rm -rf FIFOProtocol

.PHONY : FIFOProtocol-install
FIFOProtocol-install : /usr/include/FIFOProtocol.hpp $(FIFOProtocol-install-files)

.PHONY : FIFOProtocol-uninstall
FIFOProtocol-uninstall :
	rm -rf /usr/include/FIFOProtocol.hpp
	rm -rf /usr/include/FIFOProtocol

.PHONY : FIFOProtocol-format
FIFOProtocol-format : $(FIFOProtocol-format-files)

$(incdir)/FIFOProtocol.hpp : $(FIFOProtocol-path)/.build/FIFOProtocol.hpp $(FIFOProtocol-path)/.build/FIFOProtocol.hpp.gch
	cp $(<) $(@)

$(incdir)/FIFOProtocol/%.hpp : $(FIFOProtocol-path)/%.hpp $(FIFOProtocol-path)/.build/FIFOProtocol.hpp.gch
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(FIFOProtocol-path)/.build/FIFOProtocol.hpp.gch : $(FIFOProtocol-path)/.build/FIFOProtocol.hpp $(FIFOProtocol-moddepends)
	$(CPP) -I $(srcdir) $(CFLAGS) $(FIFOProtocol-CFLAGS) $(FIFOProtocol-moddepends-CFLAGS) -c -o $(@) $(<)

$(FIFOProtocol-path)/.build/FIFOProtocol.hpp : $(FIFOProtocol-format-files) $(FIFOProtocol-directories)
	./gen-hdr.sh $(srcdir) FIFOProtocol | clang-format > $(@)

$(FIFOProtocol-path)/.build/%.format : $(srcdir)/%
	./format.sh $(<)
	mkdir -p $(dir $(@))
	touch $(@)

/usr/include/%.hpp : $(incdir)/%.hpp $(FIFOProtocol-install-moddepends)
	mkdir -p $(dir $(@))
	cp $(<) $(@)
