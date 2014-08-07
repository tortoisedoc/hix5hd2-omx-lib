
CROSS_COMPILE=arm-hisiv200-linux-

CC=${CROSS_COMPILE}gcc
AR=${CROSS_COMPILE}ar

CFLAGS += -march=armv7-a -mcpu=cortex-a9 -mfloat-abi=softfp -mfpu=vfpv3-d16 -c -O2 -Wall -DUSE_AEC -D_GNU_SOURCE -D_XOPEN_SOURCE=600 -fPIC
CFLAGS += -I${CURDIR}/include 

export CC AR CFLAGS
#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#	  rules
#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

.PHONY: all clean 

all: 
	make -C omx_core
	make -C omx_vdec

clean: 
	make -C omx_core clean
	make -C omx_vdec clean
