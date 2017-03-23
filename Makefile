all: build

CC = g++
TARGET = 09001Color
OUTPUT = output

RM = rm -fr
MV = mv -f
CP = cp -R
MKDIR = mkdir -p
CHMOD = chmod 0755
STRIP = strip

SRC  = src/main/native
DIRS = . base bodymark calcPeople comment display imageControl imageProc keyboard measure patient periDevice probe res sysMan

CPPFLAGS = -Wall -ggdb3 -DEMP_355 -DREPORTPICS_6 -D_IPP_PRIVATE_STRUCTURES
CPPFLAGS += -I$(SRC) -I$(SRC)/../include
CPPFLAGS += -Ithirdparty/include -Ithirdparty/include/hal
CPPFLAGS += `pkg-config --cflags dbus-glib-1 goocanvas opencv`

LDFLAGS = -lpthread -lm -lcups -lcrypto -lssl -lpng -ltiff -lsqlite3 -lX11 -lXft -lXtst
LDFLAGS += -Lthirdparty/lib/hal -lhal
LDFLAGS += -Lthirdparty/lib -ldicom -lDSC -lDSP -lEmpRegister -lhasp_linux_106877 -lImageFile -lIniFile -lIMT -lUIS4DReceiveInterface
LDFLAGS += -Lthirdparty/lib/dcm -ldcmdata -ldcmdsig -ldcmimage -ldcmimgle -ldcmjpeg -ldcmnet -ldcmpstat -ldcmqrdb -ldcmsr -ldcmtls -ldcmwlm -lijg12 -lijg16 -lijg8 -lofstd
LDFLAGS += -lavcodec -lavformat -lavutil -ljpeg -lswscale -lwrap -lx264 -lxml2
LDFLAGS += -Lthirdparty/lib -Lthirdparty/bin -lcgos -limf -lintlc -liomp5 -lippcore -lippi -lippiv8 -lippm -lipps -lippsv8 -lirc -lsvml
LDFLAGS += `pkg-config --libs dbus-glib-1 goocanvas opencv`

FILES = $(foreach dir, $(DIRS), $(wildcard $(SRC)/$(dir)/*.cpp))
OBJS = $(patsubst %.cpp, %.o, $(FILES))

build: $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)

install: build
	${MKDIR} $(OUTPUT)/lib
	$(MV) $(TARGET) $(OUTPUT)/
	$(STRIP) $(OUTPUT)/$(TARGET)
	$(CHMOD) $(OUTPUT)/*.sh $(OUTPUT)/$(TARGET)
	$(CP) $(SRC)/../../assembly/* $(OUTPUT)/
	$(CP) thirdparty/bin/* $(OUTPUT)/lib/

clean:
	-$(RM) $(OBJS) $(OUTPUT)
