INCLUDEDIR=../include
ODIR=../obj
OUTPUTDIR=../bin
SRCDIR=../src
all:
        gcc -c -g -I ${INCLUDEDIR} ${SRCDIR}/main.c -o ${ODIR}/main.o
        gcc -c -g -I ${INCLUDEDIR} ${SRCDIR}/utilities.c -o ${ODIR}/utilities.o
        gcc ${ODIR}/main.o ${ODIR}/utilities.o -o ${OUTPUTDIR}/main.exe