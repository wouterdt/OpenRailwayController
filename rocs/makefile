# ------------------------------------------------------------
# Rocs - OS independent C library
# Copyright (C) 2002-2015 Robert Jan Versluis, Rocrail.net
# All rights reserved.
# ------------------------------------------------------------
# commandline:
#   make -f logon.mak AR=... PLATFORM=... DEBUG=... MOUNTPOINT=... OUTDIR=...
#
# commandline for i586-mingw32 cross compiling:
#   make PLATFORM=WIN32 clean
#   make TOOLPREFIX=i386-mingw32- PLATFORM=WIN32 all
#
# commandline for amd64-mingw32 cross compiling:
#   make PLATFORM=WIN64 clean
#   make all PLATFORM=WIN64 TOOLPREFIX=amd64-mingw32msvc- LIBSUFFIX=-amd64-mingw32msvc MINGWINSTALL=/usr/amd64-mingw32msv
#
# commandline for mingw native compiling:
#   make PLATFORM=WIN32 NATIVE=WIN32 clean
#   make TOOLPREFIX=i386-mingw32- PLATFORM=WIN32 NATIVE=WIN32 all
#
# commandline for osx compiling:
#   make PLATFORM=MACOSX clean all
#
FS=/
CS=;
COPY=cp
REMOVE=rm -f
GENSUFFIX=
MKDIR=mkdir -p

# --- link flags ---
LNK_FLAGS=
AR_FLAGS=

ifeq ($(NATIVE),WIN32)
	FS=$\\
	CS=&
	COPY=copy
	REMOVE=del /Q
	GENSUFFIX=.exe
	MKDIR=mkdir
endif


PLATFORM=LINUX
ARCH=
ifeq ($(PLATFORM),WIN32)
	LIBS=-liphlpapi -lmpr -lws2_32 -ladvapi32 -lwinmm
	COREDIR=win
	BINSUFFIX=.exe
	CC_EXTRA_FLAGS=-mthreads
	LNK_FLAGS=-mthreads -static
else
	COREDIR=unx
	BINSUFFIX=
	CC_EXTRA_FLAGS=-fPIC -Wno-format
endif
ifeq ($(PLATFORM),WIN64)
    LIBS=-liphlpapi -lmpr -lmswsock -lws2_32 -ladvapi32
    COREDIR=win
    BINSUFFIX=.exe
    CC_EXTRA_FLAGS=
endif 
ifeq ($(PLATFORM),LINUX)
	LIBS=-lpthread -ldl -lusb-1.0
endif
ifeq ($(PLATFORM),MACOSX)
	LIBS=-lpthread -ldl
	LNK_FLAGS=-L/usr/local/lib
  CC_EXTRA_FLAGS=-I/usr/local/include
endif
ifeq ($(PLATFORM),HP)
	LIBS=-lpthread -ldld
endif
ifeq ($(PLATFORM),SOLARIS)
	LIBS=-lsocket -lnsl -lpthread -ldl
endif
ifeq ($(PLATFORM),OPENBSD)
	LIBS=-pthread
endif

TOOLPREFIX=
SRCMOUNTPOINT=..
GENMOUNTPOINT=..$(FS)$(COREDIR)gen
OUTDIR=..$(FS)$(COREDIR)bin
TMPOUTDIR=$(GENMOUNTPOINT)$(FS)rocs$(FS)bin
DEBUG=-g
OPENSSL=
SSLLIBS=
AR=$(TOOLPREFIX)ar

CPP=$(TOOLPREFIX)gcc
LNK=$(TOOLPREFIX)gcc

# --- compile flags ---
CC_FLAGS=-c $(CC_EXTRA_FLAGS) $(DEBUG) $(OPENSSL) -I$(SRCMOUNTPOINT) -I$(GENMOUNTPOINT)


OBJS=$(patsubst impl/%.c,$(TMPOUTDIR)/%.o,$(wildcard impl/*.c))

COREOBJS=$(patsubst impl/$(COREDIR)/%.c,$(TMPOUTDIR)/%.o,$(wildcard impl/$(COREDIR)/*.c))

all: $(OUTDIR)$(FS)librocs.a $(OUTDIR)$(FS)wgen$(BINSUFFIX) $(OUTDIR)$(FS)ogen$(BINSUFFIX) $(OUTDIR)$(FS)xml2cstr$(BINSUFFIX) $(OUTDIR)$(FS)png2wx$(BINSUFFIX) \
$(OUTDIR)$(FS)addlang$(BINSUFFIX) $(OUTDIR)$(FS)mergelang$(BINSUFFIX) $(OUTDIR)$(FS)mdoc$(BINSUFFIX) $(OUTDIR)$(FS)lang2po$(BINSUFFIX) $(OUTDIR)$(FS)po2lang$(BINSUFFIX)

gen:
	bin$(FS)ogen$(GENSUFFIX) rocs.xml

$(OUTDIR)$(FS)librocs.a: $(OBJS) $(COREOBJS)
	$(AR) rcs $(OUTDIR)$(FS)librocs.a $(OBJS) $(COREOBJS)



$(OUTDIR)$(FS)wgen$(BINSUFFIX): $(TMPOUTDIR)$(FS)wgen.o $(OUTDIR)$(FS)librocs.a
	$(LNK) $(LNK_FLAGS) -o $(OUTDIR)$(FS)wgen$(BINSUFFIX) $(TMPOUTDIR)$(FS)wgen.o $(OUTDIR)$(FS)librocs.a $(LIBS) $(SSLLIBS)
	$(COPY) $(OUTDIR)$(FS)wgen$(BINSUFFIX) bin

$(OUTDIR)$(FS)ogen$(BINSUFFIX): $(TMPOUTDIR)$(FS)ogen.o $(OUTDIR)$(FS)librocs.a
	$(LNK) $(LNK_FLAGS) -o $(OUTDIR)$(FS)ogen$(BINSUFFIX) $(TMPOUTDIR)$(FS)ogen.o $(OUTDIR)$(FS)librocs.a $(LIBS) $(SSLLIBS)
	$(COPY) $(OUTDIR)$(FS)ogen$(BINSUFFIX) bin

$(OUTDIR)$(FS)xml2cstr$(BINSUFFIX): $(TMPOUTDIR)$(FS)xml2cstr.o $(OUTDIR)$(FS)librocs.a
	$(LNK) $(LNK_FLAGS) -o $(OUTDIR)$(FS)xml2cstr$(BINSUFFIX) $(TMPOUTDIR)$(FS)xml2cstr.o $(OUTDIR)$(FS)librocs.a $(LIBS) $(SSLLIBS)
	$(COPY) $(OUTDIR)$(FS)xml2cstr$(BINSUFFIX) bin

$(OUTDIR)$(FS)png2wx$(BINSUFFIX): $(TMPOUTDIR)$(FS)png2wx.o $(OUTDIR)$(FS)librocs.a
	$(LNK) $(LNK_FLAGS) -o $(OUTDIR)$(FS)png2wx$(BINSUFFIX) $(TMPOUTDIR)$(FS)png2wx.o $(OUTDIR)$(FS)librocs.a $(LIBS) $(SSLLIBS)
	$(COPY) $(OUTDIR)$(FS)png2wx$(BINSUFFIX) bin

$(OUTDIR)$(FS)addlang$(BINSUFFIX): $(TMPOUTDIR)$(FS)addlang.o $(OUTDIR)$(FS)librocs.a
	$(LNK) $(LNK_FLAGS) -o $(OUTDIR)$(FS)addlang$(BINSUFFIX) $(TMPOUTDIR)$(FS)addlang.o $(OUTDIR)$(FS)librocs.a $(LIBS) $(SSLLIBS)

$(OUTDIR)$(FS)mergelang$(BINSUFFIX): $(TMPOUTDIR)$(FS)mergelang.o $(OUTDIR)$(FS)librocs.a
	$(LNK) $(LNK_FLAGS) -o $(OUTDIR)$(FS)mergelang$(BINSUFFIX) $(TMPOUTDIR)$(FS)mergelang.o $(OUTDIR)$(FS)librocs.a $(LIBS) $(SSLLIBS)

$(OUTDIR)$(FS)mdoc$(BINSUFFIX): $(TMPOUTDIR)$(FS)mdoc.o $(OUTDIR)$(FS)librocs.a
	$(LNK) $(LNK_FLAGS) -o $(OUTDIR)$(FS)mdoc$(BINSUFFIX) $(TMPOUTDIR)$(FS)mdoc.o $(OUTDIR)$(FS)librocs.a $(LIBS) $(SSLLIBS)

$(OUTDIR)$(FS)lang2po$(BINSUFFIX): $(TMPOUTDIR)$(FS)lang2po.o $(OUTDIR)$(FS)librocs.a
	$(LNK) $(LNK_FLAGS) -o $(OUTDIR)$(FS)lang2po$(BINSUFFIX) $(TMPOUTDIR)$(FS)lang2po.o $(OUTDIR)$(FS)librocs.a $(LIBS) $(SSLLIBS)

$(OUTDIR)$(FS)po2lang$(BINSUFFIX): $(TMPOUTDIR)$(FS)po2lang.o $(OUTDIR)$(FS)librocs.a
	$(LNK) $(LNK_FLAGS) -o $(OUTDIR)$(FS)po2lang$(BINSUFFIX) $(TMPOUTDIR)$(FS)po2lang.o $(OUTDIR)$(FS)librocs.a $(LIBS) $(SSLLIBS)

$(TMPOUTDIR)/%.o: impl/%.c
	$(CPP) $(CC_FLAGS) $< -o $@

$(TMPOUTDIR)$(CF)%.o: gen$(CF)%.c
	$(CPP) $(CC_FLAGS) $< -o $@

$(TMPOUTDIR)/%.o: impl/$(COREDIR)/%.c
	$(CPP) $(CC_FLAGS) $< -o $@

clean:
	-$(MKDIR) $(GENMOUNTPOINT)$(FS)rocs
	-$(MKDIR) $(OUTDIR)
	-$(MKDIR) $(TMPOUTDIR)
	-$(REMOVE) $(TMPOUTDIR)$(FS)*.o
	-$(REMOVE) -f $(OUTDIR)$(FS)librocs.a
	cd $(GENMOUNTPOINT)$(FS)rocs$(CS) \
	..$(FS)..$(FS)rocs$(FS)bin$(FS)ogen$(GENSUFFIX) ..$(FS)..$(FS)rocs$(FS)rocs.xml
	-$(REMOVE) $(GENMOUNTPOINT)$(FS)rocs-gen.tar.gz
	cd $(GENMOUNTPOINT)$(CS) \
	tar -cf rocs-gen.tar rocs$(CS) gzip rocs-gen.tar$(CS) $(COPY) rocs-gen.tar.gz ..$(FS)rocs

fromtar:
	-$(MKDIR) $(OUTDIR)
	-$(MKDIR) $(TMPOUTDIR)
	-$(MKDIR) $(GENMOUNTPOINT)$(FS)rocs
	-$(REMOVE) $(TMPOUTDIR)$(FS)*.o
	-$(REMOVE) $(OUTDIR)$(FS)librocs.a
	cd $(GENMOUNTPOINT)$(CS) \
	$(COPY) ..$(FS)rocs$(FS)rocs-gen.tar.gz .$(CS) gzip -df rocs-gen.tar.gz$(CS) tar -xf rocs-gen.tar


ssl: OPENSSL=-D__OPENSSL__
ssl: SSLLIBS=-lssl
ssl: all
