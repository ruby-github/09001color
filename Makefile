all: build

CC = g++
TARGET = 09001Color

SRC  = src/main/native
DIRS = . base bodymark calcPeople comment display imageControl imageProc keyboard measure patient periDevice probe res sysMan

CPPFLAGS = -Wall -ggdb3 -DEMP_355 -DREPORTPICS_6 -D_IPP_PRIVATE_STRUCTURES
CPPFLAGS += -I$(SRC) -I$(SRC)/../include
CPPFLAGS += -Ithirdparty/include -Ithirdparty/include/hal
CPPFLAGS += `pkg-config --cflags dbus-glib-1 goocanvas opencv`

LIBS = -lpthread -lm -lcups -lcrypto -lssl -lpng -ltiff -lsqlite3 -lX11 -lXft -lXtst
LIBS += -Lthirdparty/lib/hal -lhal
LIBS += -Lthirdparty/lib -ldicom -lDSC -lDSP -lEmpRegister -lhasp_linux_106877 -lImageFile -lIniFile -lIMT -lUIS4DReceiveInterface
LIBS += -Lthirdparty/lib/dcm -ldcmdata -ldcmdsig -ldcmimage -ldcmimgle -ldcmjpeg -ldcmnet -ldcmpstat -ldcmqrdb -ldcmsr -ldcmtls -ldcmwlm -lijg12 -lijg16 -lijg8 -lofstd
LIBS += -lavcodec -lavformat -lavutil -ljpeg -lswscale -lwrap -lx264 -lxml2
LIBS += -Lthirdparty/lib -Lthirdparty/bin -lcgos -limf -lintlc -liomp5 -lippcore -lippi -lippiv8 -lippm -lipps -lippsv8 -lirc -lsvml
LIBS += `pkg-config --libs dbus-glib-1 goocanvas opencv`

FILES = $(foreach dir, $(DIRS), $(wildcard $(SRC)/$(dir)/*.cpp))
OBJS = $(patsubst %.cpp, %.o, $(FILES))

build:$(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

install:

clean:
	-$(RM) $(OBJS)
	-$(RM) objs output
