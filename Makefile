CC	=ccache gcc -std=gnu99 -pipe
CFLAGS	:=$(shell pkg-config --cflags	gtk+-3.0 gmodule-2.0)
LDFLAGS	:=$(shell pkg-config --libs	gtk+-3.0 gmodule-2.0)

all::	rokuremote

rokuremote:: rokuremote.c
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ rokuremote.c ${LDFLAGS}

clean::
	${RM} *.o core.* lint tags

distclean clobber:: clean
	${RM} rokuremote
