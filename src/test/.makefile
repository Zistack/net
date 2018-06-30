test-moddepends =
test-CFLAGS =
test-LFLAGS =

test-path = $(srcdir)/test
test-files = $(shell find $(test-path) -type f -regex '\.\./\([^./][^/]*/\)*[^./][^/]*\.hpp')
test-directories = $(shell find $(test-path) -type f -regex '\.\./\([^./][^/]*/\)*[^./][^/]*')
test-format-files = $(test-files:$(srcdir)/%=$(test-path)/.build/%.format)
test-install-moddepends = $(test-moddepends:%=%-install)

test : $(bindir)/test
	touch test

.PHONY : test-clean
test-clean :
	rm -rf $(bindir)/test
	rm -rf $(test-path)/.build/main.o
	rm -rf $(test-path)/.build/main.cpp
	rm -rf $(test-format-files)
	rm -rf $(test-path)/.build/test
	rm -rf test

.PHONY : test-install
test-install : /usr/bin/test

.PHONY : test-uninstall
test-uninstall :
	rm -rf /usr/bin/test

.PHONY : test-format
test-format : $(test-format-files)

$(bindir)/test : $(test-path)/.build/main.o
	$(CPP) $(LFLAGS) $(test-LFLAGS) -o $(@) $(<)

$(test-path)/.build/main.o : $(test-path)/.build/main.cpp $(test-moddepends)
	$(CPP) $(CFLAGS) $(test-CFLAGS) -I $(test-path) -c -o $(@) $(<)

$(test-path)/.build/main.cpp : $(test-format-files) $(test-directories)
	./gen-bin.sh $(test-path) | clang-format > $(@)

$(test-path)/.build/%.format : $(srcdir)/%
	./format.sh $(<)
	mkdir -p $(dir $(@))
	touch $(@)

/usr/bin/test : $(bindir)/test $(test-install-moddepends)
	cp $(<) $(@)
