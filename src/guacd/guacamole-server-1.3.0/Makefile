# by dnobori

.PHONY: all build clean

.DEFAULT_GOAL := all

CFLAGS := -g -O2 -I./ -I./src/libguac/

LDLIBS := -ldl -lm -lcairo -ljpeg -lpango-1.0 -lgobject-2.0 -lglib-2.0 -lintl -lpng -lrt -lpthread -lpulse -lfreerdp2 -lfreerdp-client2 -lwinpr2 -lssh2 -lssl -lcrypto -lvncclient -logg -lvorbis -lvorbisenc -lwebp  -pthread $(CROSSLIBS_FULLPATH)

LDFLAGS := -g

h_all := $(shell /bin/find ./ -type f -name '*.h')
c_all := $(shell /bin/find ./ -type f -name '*.c')
o_all := $(addprefix tmp_build/,$(patsubst %.c,%.o,$(c_all)))

# $(warning test = $(o_all))

# s_libguac := $(wildcard src/libguac/*.c)
# o_libguac := $(addprefix tmp/libguac/,$(addsuffix .o,$(sort $(basename $(s_libguac)))))

# o_all := $(o_libguac)

# tmp/libguac/%.o: src/libguac/%.c $(h_all)
# 	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
# 	$(CC) $(CFLAGS) -o $@ -c $<

$(o_all): $(h_all)
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
	$(CC) $(CFLAGS) -o $@ -c $(patsubst tmp_build/%.o,%.c,$@)

all:	build

build:	out.exe

out.exe:	$(o_all)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

clean:
	-rm -fr tmp_build/
	-rm -f out.exe


