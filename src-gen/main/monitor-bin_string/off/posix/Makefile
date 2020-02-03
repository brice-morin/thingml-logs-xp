# CC = /*CC*/
LIBS = -lpthread 
CFLAGS = -O2 -w
SRCS = HeadlessDisplay.c BreakoutGamePosix.c TimerPosix.c BasicIAController.c Binary2StringLogger.c test_cfg.c runtime.c
OBJS = HeadlessDisplay.o BreakoutGamePosix.o TimerPosix.o BasicIAController.o Binary2StringLogger.o test_cfg.o runtime.o

all : test

.c.o :
	${CC} ${CFLAGS} -c $< 

.cpp.o :
	${CC} ${CFLAGS} -c $< 

test : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ test
