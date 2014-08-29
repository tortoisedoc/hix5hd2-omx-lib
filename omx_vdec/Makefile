
LIBS := libOMX.hisi.video.decoder
OBJS := omx_allocator.o omx_event_queue.o omx_vdec.o vdec_drv_ctx.o

MMZ_LIB_DIR := ../../hix5hd2-mmz-lib


#===============================================================================
# rules
#===============================================================================
.PHONY: all clean 

all: $(LIBS)

clean: 
	rm -rf $(OBJS)
	rm -rf $(LIBS).so

$(LIBS) : $(OBJS)
	$(CC) -shared  -Wl,--no-undefined -L$(MMZ_LIB_DIR) -lhi_mmz  -lpthread -o $@.so $^

