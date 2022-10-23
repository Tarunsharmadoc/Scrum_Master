SRCDIR = ../src
EXTDIR = ../external
INCLUDEDIR = ../include
OBJDIR = ../obj
BINDIR = ../bin
REPORTDIR = ../reports
CFLAGS = -c -g -Wall -I${INCLUDEDIR} -I../external/include -DLOG_USE_COLOR




all:

	gcc ${CFLAGS}  ${SRCDIR}/main.c -o ${OBJDIR}/main.o
	gcc ${CFLAGS}  ${SRCDIR}/utilities.c -o ${OBJDIR}/utilities.o
	gcc ${CFLAGS}  ${SRCDIR}/userStoriesLinkedList.c -o ${OBJDIR}/userStoriesLinkedList.o
	gcc ${CFLAGS}  ${SRCDIR}/tasksLinkedList.c -o ${OBJDIR}/tasksLinkedList.o
	gcc ${OBJDIR}/main.o ${OBJDIR}/utilities.o ${OBJDIR}/userStoriesLinkedList.o ${OBJDIR}/tasksLinkedList.o -o  ${BINDIR}/main.bin