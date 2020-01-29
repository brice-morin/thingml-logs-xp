# CC = /*CC*/
LIBS = -lpthread 
CFLAGS = -O2 -w
SRCS = TimerPosix.c BasicIAController.c HeadlessDisplay.c ConsoleLogger.c BreakoutGamePosix.c test_cfg.c runtime.c
OBJS = TimerPosix.o BasicIAController.o HeadlessDisplay.o ConsoleLogger.o BreakoutGamePosix.o test_cfg.o runtime.o

all : test

.c.o :
	${CC} ${CFLAGS} -c $< 

.cpp.o :
	${CC} ${CFLAGS} -c $< 

test : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ test
