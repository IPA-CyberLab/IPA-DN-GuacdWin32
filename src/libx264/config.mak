SRCPATH=.
prefix=/usr
exec_prefix=${prefix}
bindir=${exec_prefix}/bin
libdir=${exec_prefix}/lib
includedir=${prefix}/include
SYS_ARCH=X86
SYS=CYGWIN
CC=gcc
CFLAGS=-Wno-maybe-uninitialized -Wshadow -O3 -ffast-math -m32  -Wall -I. -I$(SRCPATH) -D_POSIX_C_SOURCE=200112L -march=i686 -mfpmath=sse -msse -msse2 -std=gnu99 -D_GNU_SOURCE -mpreferred-stack-boundary=6 -fomit-frame-pointer -fno-tree-vectorize
COMPILER=GNU
COMPILER_STYLE=GNU
DEPMM=-MM -g0
DEPMT=-MT
LD=gcc -o 
LDFLAGS=-m32   -Wl,--large-address-aware -Wl,--dynamicbase,--nxcompat,--tsaware -lpthread 
LIBX264=libx264.a
AR=gcc-ar rc 
RANLIB=gcc-ranlib
STRIP=strip
INSTALL=install
AS=nasm
ASFLAGS= -I. -I$(SRCPATH) -DARCH_X86_64=0 -I$(SRCPATH)/common/x86/ -f win32 -DPREFIX -DSTACK_ALIGNMENT=64
RC=
RCFLAGS=--target=pe-i386 
EXE=.exe
HAVE_GETOPT_LONG=1
DEVNULL=/dev/null
PROF_GEN_CC=-fprofile-generate
PROF_GEN_LD=-fprofile-generate
PROF_USE_CC=-fprofile-use
PROF_USE_LD=-fprofile-use
HAVE_OPENCL=yes
CC_O=-o $@
default: cli
install: install-cli
SONAME=libx264-155.dll
IMPLIBNAME=libx264.dll.a
SOFLAGS=-shared -Wl,--out-implib,$(IMPLIBNAME) 
default: lib-shared
install: install-lib-shared
LDFLAGSCLI = 
CLI_LIBX264 = $(LIBX264)
