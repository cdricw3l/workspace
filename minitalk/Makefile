CC= cc 
CFLAGS= -Werror -Wextra -Wall -fsanitize=address -g
NAME_S= serveur
NAME_C= client 
NAME= minitalk
SERVEURSRC = serveur.c
CLIENTSRC =	client.c

SERVEURIBJS = ${SERVEURSRC:*.c=.o}

CLIENTOBJS = ${CLIENTSRC:*.c=.o}

all: ${NAME}

$(NAME_S) : $(SERVEURIBJS)
	${CC} ${CFLAGS} ${SERVEURIBJS} -o ${NAME_S}

$(NAME_C) : $(CLIENTOBJS)
	${CC} ${CFLAGS} ${CLIENTOBJS} -o ${NAME_C}

$(NAME) : ${NAME_C} ${NAME_S}

clean:
	rm -f *.o
	rm -f ${NAME_C}
	rm -f ${NAME_S}

re: clean all

gdev:
	cd .. && git add . && git commit -m minitalk && git push

