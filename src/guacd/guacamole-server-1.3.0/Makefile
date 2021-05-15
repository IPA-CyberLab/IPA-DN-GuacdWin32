# by dnobori

.PHONY: all build clean FORCE
FORCE:

.DEFAULT_GOAL := all

CFLAGS := -g -O2 -I/usr/i686-w64-mingw32/sys-root/mingw/include/gstreamer-1.0/ -I/usr/include/pango-1.0/ -I/usr/include/glib-2.0/ -I/lib/glib-2.0/include/ -I/usr/include/cairo/ -I./ -I./src/pulse/ -I./src/common/ -I./src/libguac/ -I./src/protocols/rdp/ -I./src/common-ssh/ -I./src/terminal/ -I./src/FreeRDP-2.0.0/ -I./src/FreeRDP-2.0.0/include/ -I./src/FreeRDP-2.0.0/winpr/include/ -I./src/FreeRDP-2.0.0/channels/audin/client/ -I./src/FreeRDP-2.0.0/channels/rdpei/ -I./src/FreeRDP-2.0.0/channels/rdpgfx/ -I./src/FreeRDP-2.0.0/channels/rdpsnd/client/ -I./src/FreeRDP-2.0.0/channels/rdpsnd/common/ -I./src/FreeRDP-2.0.0/channels/tsmf/client/ -I./src/FreeRDP-2.0.0/channels/urbdrc/common/ -I./src/FreeRDP-2.0.0/resources/ -I./src/FreeRDP-2.0.0/rdtk/include/ -I./src/FreeRDP-2.0.0/winpr/libwinpr/sspi/ -I./src/FreeRDP-2.0.0/winpr/libwinpr/utils/trio/ -I./src/FreeRDP-2.0.0/winpr/libwinpr/utils/ -DHAVE_CONFIG_FREERDP_H -DWITH_OPENSSL

LDLIBS := /usr/local/lib/libuuid.a /usr/local/lib/libavcodec.a /usr/local/lib/libavutil.a /usr/local/lib/libswresample.a /lib/libmp3lame.a /lib/libz.a /lib/libiconv.a /cygdrive/c/git/IPA-DN-GuacdWin32/src/libx264/libx264.a -ldl -lm -lcairo -ljpeg -lpango-1.0 -lpangocairo-1.0 -lgobject-2.0 -lglib-2.0 -lintl -lpng -lrt -lpthread -lpulse -lssh2 -lssl -lcrypto -lvncclient -logg -lvorbis -lvorbisenc -lwebp -lX11 /usr/i686-w64-mingw32/sys-root/mingw/lib/libgstreamer-1.0.dll.a /usr/i686-w64-mingw32/sys-root/mingw/lib/libgstvideo-1.0.dll.a /usr/i686-w64-mingw32/sys-root/mingw/lib/libgstapp-1.0.dll.a /usr/i686-w64-mingw32/sys-root/mingw/lib/libgstbase-1.0.dll.a -pthread 

LDFLAGS := -g

h_all := $(shell /bin/find ./ -type f -name '*.h')
c_all := $(shell /bin/find ./ -type f -name '*.c' | grep -F -v -e ./src/common/tests/ -e ./src/common-ssh/tests/ -e ./src/libguac/tests/ -e ./src/protocols/kubernetes/ -e ./src/protocols/rdp/tests/ -e ./src/protocols/telnet/ -e ./src/guacenc/ -e ./src/guaclog/ -e /FreeRDP-2.0.0/channels/audin/client/alsa/ -e ./src/FreeRDP-2.0.0/channels/rdpsnd/client/alsa/ -e ./src/FreeRDP-2.0.0/channels/audin/client/mac/ -e ./src/FreeRDP-2.0.0/channels/audin/client/opensles/ -e ./src/FreeRDP-2.0.0/channels/audin/client/winmm/ -e ./src/FreeRDP-2.0.0/channels/printer/client/cups/ -e ./src/FreeRDP-2.0.0/channels/printer/client/win/ -e ./src/FreeRDP-2.0.0/channels/rdpsnd/client/ios/ -e ./src/FreeRDP-2.0.0/channels/rdpsnd/client/opensles/ -e ./src/FreeRDP-2.0.0/channels/rdpsnd/client/winmm/ -e /src/FreeRDP-2.0.0/channels/tsmf/client/alsa/ -e ./src/FreeRDP-2.0.0/channels/urbdrc/client/libusb/ -e ./src/FreeRDP-2.0.0/client/Android/ -e ./src/FreeRDP-2.0.0/client/Wayland/ -e ./src/FreeRDP-2.0.0/client/Windows/ -e ./src/FreeRDP-2.0.0/libfreerdp/codec/h264_mf.c -e ./src/FreeRDP-2.0.0/libfreerdp/codec/h264_openh264.c -e ./src/FreeRDP-2.0.0/libfreerdp/codec/h264_x264.c -e ./src/FreeRDP-2.0.0/libfreerdp/codec/include/bitmap.c -e ./src/FreeRDP-2.0.0/libfreerdp/codec/nsc_sse2.c -e ./src/FreeRDP-2.0.0/libfreerdp/codec/rfx_sse2.c -e ./src/FreeRDP-2.0.0/libfreerdp/core/test/ -e ./src/FreeRDP-2.0.0/libfreerdp/gdi/test/ -e ./src/FreeRDP-2.0.0/libfreerdp/primitives/prim_YUV_neon.c -e ./src/FreeRDP-2.0.0/libfreerdp/primitives/prim_YUV_opencl.c -e ./src/FreeRDP-2.0.0/libfreerdp/primitives/prim_YUV_ssse3.c -e ./src/FreeRDP-2.0.0/scripts/ -e ./src/FreeRDP-2.0.0/server/ -e ./src/FreeRDP-2.0.0/uwac/ -e ./src/FreeRDP-2.0.0/winpr/libwinpr/comm/test/ -e ./src/FreeRDP-2.0.0/winpr/libwinpr/crt/casing.c -e ./src/FreeRDP-2.0.0/winpr/libwinpr/path/include/ -e ./src/FreeRDP-2.0.0/winpr/libwinpr/sspi/test/ -e ./src/FreeRDP-2.0.0/winpr/libwinpr/sysinfo/cpufeatures/ -e ./src/FreeRDP-2.0.0/winpr/libwinpr/utils/test/ -e ./src/FreeRDP-2.0.0/winpr/libwinpr/utils/wlog/JournaldAppender.c -e ./src/FreeRDP-2.0.0/winpr/libwinpr/wtsapi/wtsapi_win32.c -e ./src/FreeRDP-2.0.0/client/X11/ -e ./src/FreeRDP-2.0.0/rdtk/sample/ -e ./src/FreeRDP-2.0.0/client/Sample/ -e ./src/FreeRDP-2.0.0/winpr/libwinpr/library/test/ -e ./src/FreeRDP-2.0.0/winpr/libwinpr/wnd/test/ -e ./src/FreeRDP-2.0.0/winpr/tools/makecert-cli/ -e ./src/FreeRDP-2.0.0/winpr/tools/hash-cli/ -e ./src/FreeRDP-2.0.0/winpr/libwinpr/crt/test/)
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


