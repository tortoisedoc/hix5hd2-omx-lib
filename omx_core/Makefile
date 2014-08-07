
LIBS := libOMX_Core
OBJS := omx_core.o

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

