# by dnobori

.PHONY: all build clean FORCE
FORCE:

.DEFAULT_GOAL := all

CFLAGS := -g -O2 -I/usr/include/freerdp2/ -I/usr/include/winpr2/ -I/usr/include/pango-1.0/ -I/usr/include/glib-2.0/ -I/lib/glib-2.0/include/ -I/usr/include/cairo/ -I./ -I./src/pulse/ -I./src/common/ -I./src/libguac/ -I./src/protocols/rdp/ -I./src/common-ssh/ -I./src/terminal/

LDLIBS := -ldl -lm -lcairo -ljpeg -lpango-1.0 -lpangocairo-1.0 -lgobject-2.0 -lglib-2.0 -lintl -lpng -lrt -lpthread -lpulse -lssh2 -lssl -lcrypto -lvncclient -logg -lvorbis -lvorbisenc -lwebp -pthread /usr/local/lib/libuuid.a

LDFLAGS := -g

h_all := $(shell /bin/find ./ -type f -name '*.h')
c_all := $(shell /bin/find ./ -type f -name '*.c' | grep -F -v -e ./src/common/tests/ -e ./src/common-ssh/tests/ -e ./src/libguac/tests/ -e ./src/protocols/kubernetes/ -e ./src/protocols/rdp/tests/ -e ./src/protocols/telnet/ -e ./src/guacenc/ -e ./src/guaclog/)
o_all := $(addprefix tmp_build/,$(patsubst %.c,%.o,$(c_all)))

# $(warning test = $(o_all))

# s_libguac := $(wildcard src/libguac/*.c)
# o_libguac := $(addprefix tmp/libguac/,$(addsuffix .o,$(sort $(basename $(s_libguac)))))

# o_all := $(o_libguac)

# tmp/libguac/%.o: src/libguac/%.c $(h_all)
# 	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
# 	$(CC) $(CFLAGS) -o $@ -c $<

#$(o_all): $(patsubst tmp_build/%.o,%.c,$@) $(h_all) aaa

$(o_all): tmp_build/%.o: %.c $(h_all)
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
	$(CC) $(CFLAGS) -o $@ -c $<

all:	build

build:	out.exe

out.exe:	$(o_all)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

clean:
	-rm -fr tmp_build/
	-rm -f out.exe


