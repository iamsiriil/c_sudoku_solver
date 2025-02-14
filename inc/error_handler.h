#ifndef ERROR_HANDLER_H
# define ERROR_HANDLER_H

# include <stslib.h>

# define ERR_ALLOC "Failed to allocate memory"
# define ERR_OFILE "Failed to open file"
# define ERR_RFILE "Failed to read file"
# define ERR_NARGS "Invalid number of arguments"

void	cns_error_handler(void *p1, void *p2, char *m) {

	if (p1 != NULL) free(p1);
	if (p2 != NULL) free(p2);
	perror(m);
	exit(EXIT_FAILURE);
}

#endif
