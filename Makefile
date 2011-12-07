PREFIX ?= .
CFLAGS := -ansi -pedantic -Wall -Wextra -Werror ${CFLAGS}

mac-cel: mac-cel.c
	${CC} ${CFLAGS} \
		-framework CoreFoundation \
		-framework CoreServices \
		-framework IOKit \
		-o mac-cel mac-cel.c

install:
	install -m755 mac-cel ${PREFIX}
