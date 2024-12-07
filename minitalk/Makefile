CC= cc 
CFLAGS= -Werror -Wextra -Wall -fsanitize=address -g
NAME_S= serveur
NAME_c= client 

SERVEURSRC =	serveur.c
CLIENTSRC =		client.c

SERVEURIBJS = ${SERVEURSRC:.c=*.o}
CLIENTOBJS = ${CLIENTOBJS:.c=*.o}


$(NAME_S) : $(SERVEURIBJS)
	${CC} ${CFLAGS} ${SERVEURIBJS} -o ${NAME_c}

clean:
	rm -f *.o
	rm -rf * .dSYM

cclean:
	rm -f CLIENTSRC

sclean:
	rm -f SERVEURSRC

gdev:
	cd .. && git add . && git commit -m minitalk && git push

