common_sources := AppOpsManager.cpp
common_sources += Binder.cpp
common_sources += BpBinder.cpp
common_sources += BufferedTextOutput.cpp
common_sources += Debug.cpp
common_sources += IAppOpsCallback.cpp
common_sources += IAppOpsService.cpp
common_sources += IBatteryStats.cpp
common_sources += IInterface.cpp
common_sources += IMemory.cpp
common_sources += IPCThreadState.cpp
common_sources += IPermissionController.cpp
common_sources += IProcessInfoService.cpp
common_sources += ProcessInfoService.cpp
common_sources += IServiceManager.cpp
common_sources += MemoryDealer.cpp
common_sources += MemoryBase.cpp
common_sources += MemoryHeapBase.cpp
common_sources += Parcel.cpp
common_sources += PermissionCache.cpp
common_sources += ProcessState.cpp
common_sources += Static.cpp
common_sources += TextOutput.cpp
common_sources += Value.cpp
common_sources += Status.cpp


AM_CPPFLAGS := \
        -I. \
        -USE_GLIB \
        -I$(WORKSPACE)/frameworks/binder/include \
        -I$(WORKSPACE)/system/core/base/include \
        -I$(WORKSPACE)/system/core/include \
        -D_ANDROID_HOST_ \
        -D_ANDROID_ \
        -std=c++11


AM_CFLAGS := -Wundef \
        -Wstrict-prototypes \
        -Wno-trigraphs \
        -g -O0 \
        -fno-inline \
        -fno-short-enums \
        -fpic \
        -D_GNU_SOURCE


lib_LTLIBRARIES = libbinderstreaming.la
libbinderstreaming_la_SOURCES = $(common_sources)
libbinderstreaming_la_CPPFLAGS := -I$(top_srcdir)/include
libbinderstreaming_la_CPPFLAGS += -I$(WORKSPACE)/system/core/base/include
libbinderstreaming_la_CPPFLAGS += -I$(WORKSPACE)/system/core/include

if IPC_32BIT
libbinderstreaming_la_CPPFLAGS += -DBINDER_IPC_32BIT=1
endif
libbinderstreaming_la_CPPFLAGS += -DUSE_GLIB -D__linux__
libbinderstreaming_la_CPPFLAGS += -DDEBUG_REFS_CALLSTACK_ENABLED=0

if USE_GLIB
libbinderstreaming_la_CFLAGS := $(AM_CFLAGS) -DUSE_GLIB @GLIB_CFLAGS@
libbinderstreaming_la_CPPFLAGS += -std=c++11 -DHAVE_PTHREADS -DHAVE_ANDROID_OS -DUSE_GLIB -Dstrlcat=g_strlcat @GLIB_CFLAGS@ -include glib.h
libbinderstreaming_la_LDFLAGS := -llog -lcutils -lpthread -lutils -lbase $(GLIB_LIBS)
else
libbinderstreaming_la_CFLAGS := $(AM_CFLAGS)
libbinderstreaming_la_CPPFLAGS += -std=c++11 -DHAVE_PTHREADS -DHAVE_ANDROID_OS
libbinderstreaming_la_LDFLAGS := -llog -lcutils -lpthread -lutils -lbase
endif

# Export headers
pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libbinderstreaming.pc
EXTRA_DIST = $(pkgconfig_DATA)
