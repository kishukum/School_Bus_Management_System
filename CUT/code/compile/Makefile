##########################################################
# Created by: Kishu Kumar                           #
# Created on: Wednesday 10 dec 2022 11:07:22 AM IST #
##########################################################

SRCDIR = ../src
INCLUDEDIR = ../include
OBJDIR = ../obj
BINDIR = ../bin
CFLAGS = -c -g -Wall -I${INCLUDEDIR}



all:

	gcc ${CFLAGS}  ${SRCDIR}/main.c  
	gcc ${CFLAGS}  ${SRCDIR}/stutility.c   
	gcc ${CFLAGS}  ${SRCDIR}/brutility.c   
	gcc ${CFLAGS}  ${SRCDIR}/brlinkedlist.c  
	gcc ${CFLAGS}  ${SRCDIR}/stlinkedlist.c   
	gcc ${OBJDIR}/main.o ${OBJDIR}/stlinkedlist.o ${OBJDIR}/brlinkedlist.o ${OBJDIR}/brutility.o ${OBJDIR}/stutility.o -o ${BINDIR}/bus.bin

clean:

	rm ${OBJDIR}/main.o ${OBJDIR}/stlinkedlist.o ${OBJDIR}/brlinkedlist.o ${OBJDIR}/brutility.o ${OBJDIR}/stutility.o -o ${BINDIR}/bus.bin


#################### End of Makefile #####################


