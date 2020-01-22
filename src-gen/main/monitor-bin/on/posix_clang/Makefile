CC = clang
LIBS = -lpthread 
CFLAGS = -O2 -w
SRCS = ConsoleLogger.c BreakoutGamePosix.c BasicIAController.c TimerPosix.c HeadlessDisplay.c test_cfg.c runtime.c
OBJS = ConsoleLogger.o BreakoutGamePosix.o BasicIAController.o TimerPosix.o HeadlessDisplay.o test_cfg.o runtime.o

all : test

.c.o :
	${CC} ${CFLAGS} -c $< 

.cpp.o :
	${CC} ${CFLAGS} -c $< 

test : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ test
