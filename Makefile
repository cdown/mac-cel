# vim: noexpandtab :

PREFIX ?= .
CFLAGS := -ansi -pedantic -Wall -Wextra -Werror \
          -Wformat=2 -Wswitch-default -Wswitch-enum -Wcast-align \
		  -Wpointer-arith -Wbad-function-cast -Wstrict-overflow=5 \
		  -Wstrict-prototypes -Winline -Wundef -Wnested-externs -Wcast-qual \
		  -Wshadow -Wunreachable-code -Wlogical-op -Wfloat-equal \
		  -Wstrict-aliasing=2 -Wredundant-decls -Wold-style-definition \
          ${CFLAGS}

mac-cel: mac-cel.c
	${CC} ${CFLAGS} -framework CoreFoundation -framework CoreServices -framework IOKit -o mac-cel mac-cel.c

install:
	install -m755 mac-cel ${PREFIX}
