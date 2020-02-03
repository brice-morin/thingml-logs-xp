# CC = /*CC*/
LIBS = -lpthread 
CFLAGS = -O2 -w
SRCS = BreakoutGamePosix.c BasicIAController.c ConsoleLogger.c HeadlessDisplay.c TimerPosix.c test_cfg.c runtime.c
OBJS = BreakoutGamePosix.o BasicIAController.o ConsoleLogger.o HeadlessDisplay.o TimerPosix.o test_cfg.o runtime.o

all : test

.c.o :
	${CC} ${CFLAGS} -c $< 

.cpp.o :
	${CC} ${CFLAGS} -c $< 

test : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ test
