# CC = /*CC*/
LIBS = -lpthread 
CFLAGS = -O2 -w
SRCS = BasicIAController.c TimerPosix.c ConsoleLogger.c HeadlessDisplay.c BreakoutGamePosix.c test_cfg.c runtime.c
OBJS = BasicIAController.o TimerPosix.o ConsoleLogger.o HeadlessDisplay.o BreakoutGamePosix.o test_cfg.o runtime.o

all : test

.c.o :
	${CC} ${CFLAGS} -c $< 

.cpp.o :
	${CC} ${CFLAGS} -c $< 

test : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ test
