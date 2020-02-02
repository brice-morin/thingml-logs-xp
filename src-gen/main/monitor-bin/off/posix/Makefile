# CC = /*CC*/
LIBS = -lpthread 
CFLAGS = -O2 -w
SRCS = BreakoutGamePosix.c HeadlessDisplay.c ConsoleLogger.c TimerPosix.c BasicIAController.c test_cfg.c runtime.c
OBJS = BreakoutGamePosix.o HeadlessDisplay.o ConsoleLogger.o TimerPosix.o BasicIAController.o test_cfg.o runtime.o

all : test

.c.o :
	${CC} ${CFLAGS} -c $< 

.cpp.o :
	${CC} ${CFLAGS} -c $< 

test : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ test
