# CC = /*CC*/
LIBS = -lpthread 
CFLAGS = -O2 -w
SRCS = TimerPosix.c BasicIAController.c HeadlessDisplay.c Binary2StringLogger.c BreakoutGamePosix.c test_cfg.c runtime.c
OBJS = TimerPosix.o BasicIAController.o HeadlessDisplay.o Binary2StringLogger.o BreakoutGamePosix.o test_cfg.o runtime.o

all : test

.c.o :
	${CC} ${CFLAGS} -c $< 

.cpp.o :
	${CC} ${CFLAGS} -c $< 

test : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ test
