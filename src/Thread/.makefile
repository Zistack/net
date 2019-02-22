Thread-moddepends = Failure Scope
Thread-CFLAGS =
Thread-LFLAGS = -lpthread

Thread-moddepends-CFLAGS = $(foreach mod, $(Thread-moddepends), $($(mod)-export-CFLAGS))
Thread-moddepends-LFLAGS = $(foreach mod, $(Thread-moddepends), $($(mod)-export-LFLAGS))

Thread-export-CFLAGS = $(Thread-CFLAGS) $(Thread-moddepends-CFLAGS)
nodname-export-LFLAGS = $(Thread-LFLAGS) $(Thread-moddepends-LFLAGS)

Thread-path = $(srcdir)/Thread
Thread-files = $(shell find $(Thread-path) -type f -regex '\.\./\([^./][^/]*/\)*[^./][^/]*\.hpp')
Thread-include-files = $(Thread-files:$(srcdir)/%=$(incdir)/%)
Thread-install-files = $(Thread-files:$(srcdir)/%=/usr/include/%)
Thread-directories = $(shell find $(Thread-path) -type d -regex '\.\./\([^./][^/]*/\)*[^./][^/]*')
Thread-format-files = $(Thread-files:$(srcdir)/%=$(Thread-path)/.build/%.format)
Thread-install-moddepends = $(Thread-moddepends:%=%-install)

Thread : $(incdir)/Thread.hpp $(Thread-include-files)
	touch Thread

.PHONY : Thread-clean
Thread-clean :
	rm -rf $(Thread-include-files)
	rm -rf $(incdir)/Thread
	rm -rf $(incdir)/Thread.hpp
	rm -rf $(Thread-format-files)
	rm -rf $(Thread-path)/.build/Thread
	rm -rf $(Thread-path)/.build/Thread.hpp
	rm -rf $(Thread-path)/.build/Thread.hpp.gch
	rm -rf Thread

.PHONY : Thread-install
Thread-install : /usr/include/Thread.hpp $(Thread-install-files)

.PHONY : Thread-uninstall
Thread-uninstall :
	rm -rf /usr/include/Thread.hpp
	rm -rf /usr/include/Thread

.PHONY : Thread-format
Thread-format : $(Thread-format-files)

$(incdir)/Thread.hpp : $(Thread-path)/.build/Thread.hpp $(Thread-path)/.build/Thread.hpp.gch
	cp $(<) $(@)

$(incdir)/Thread/%.hpp : $(Thread-path)/%.hpp $(Thread-path)/.build/Thread.hpp.gch
	mkdir -p $(dir $(@))
	cp $(<) $(@)

$(Thread-path)/.build/Thread.hpp.gch : $(Thread-path)/.build/Thread.hpp $(Thread-moddepends)
	$(CPP) -I $(srcdir) $(CFLAGS) $(Thread-CFLAGS) $(Thread-moddepends-CFLAGS) -c -o $(@) $(<)

$(Thread-path)/.build/Thread.hpp : $(Thread-format-files) $(Thread-directories)
	./gen-hdr.sh $(srcdir) Thread | clang-format > $(@)

$(Thread-path)/.build/%.format : $(srcdir)/%
	./format.sh $(<)
	mkdir -p $(dir $(@))
	touch $(@)

/usr/include/%.hpp : $(incdir)/%.hpp $(Thread-install-moddepends)
	mkdir -p $(dir $(@))
	cp $(<) $(@)
