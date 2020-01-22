CC = clang
LIBS = -lpthread 
CFLAGS = -O2 -w
SRCS = BreakoutGamePosix.c TimerPosix.c HeadlessDisplay.c BasicIAController.c test_cfg.c runtime.c
OBJS = BreakoutGamePosix.o TimerPosix.o HeadlessDisplay.o BasicIAController.o test_cfg.o runtime.o

all : test

.c.o :
	${CC} ${CFLAGS} -c $< 

.cpp.o :
	${CC} ${CFLAGS} -c $< 

test : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ test
