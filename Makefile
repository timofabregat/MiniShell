CFlags = -Wall -Wextra -std=gnu99 -ggdb -fsanitize=signed-integer-overflow -fsanitize=undefined
mainshell: builtin_cd.o builtin_dir.o builtin_exit.o builtin_getenv.o builtin_gid.o builtin_help.o builtin_history.o builtin_lookup.o builtin_pid.o builtin_setenv.o builtin_status.o builtin_uid.o builtin_unsetenv.o ejecutar.o externo.o linea2argv.o list_func.o
builtin_cd.o: minish.h
builtin_dir.o: minish.h
builtin_exit.o: minish.h
builtin_getenv.o: minish.h
builtin_help.o: minish.h
builtin_history.o: minish.h
builtin_lookup.o: minish.h
builtin_pid.o: minish.h
builtin_setenv.o: minish.h
builtin_status.o: minish.h
builtin_uid.o: minish.h
ejecutar.o: minish.h
externo.o: minish.h
linea2argv.o: minish.h
list_func.o: minish.h