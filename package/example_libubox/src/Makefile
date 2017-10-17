#
# @author lg0491986@qq.com
# @date 2017-10-11
#

BIN =  example_libubox

SRCS += $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

LDFLAGS += -lubox

RM = -rm -fr

all:$(BIN)

%.d: %.c
	@set -e: rm -f $@; \
	$(CC) -M $(CFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

sinclude $(DEPS)

$(BIN): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

clean: 
	$(RM) $(BIN) $(OBJS) $(DEPS) *.o *.d *.d.*

.PHONY: all clean
