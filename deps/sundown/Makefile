results.mk:
	wget https://github.com/vmg/sundown/archive/refs/heads/master.zip
	unzip master.zip
	cd sundown-master && gcc -c -Isrc -Ihtml src/*.c html/*.c
	echo "LIB_CFLAGS += -I$(CURDIR)/sundown-master/html -I$(CURDIR)/sundown-master/src" >> results.mk
	echo "LIB_LDFLAGS += $(CURDIR)/sundown-master/*.o" >> results.mk
