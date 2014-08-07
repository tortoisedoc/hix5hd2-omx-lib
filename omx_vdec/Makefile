
LIBS := libOMX.hisi.video.decoder
OBJS := omx_allocator.o omx_event_queue.o omx_vdec.o vdec_drv_ctx.o

#===============================================================================
# rules
#===============================================================================
.PHONY: all clean 

all: $(LIBS)

clean: 
	rm -rf $(OBJS)
	rm -rf $(LIBS).so

$(LIBS) : $(OBJS)
	$(CC) -shared -o $@.so $^

