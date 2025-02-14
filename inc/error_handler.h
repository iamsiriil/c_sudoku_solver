#ifndef ERROR_HANDLER_H
# define ERROR_HANDLER_H

# define ERR_ALLOC "Failed to allocate memory"
# define ERR_OFILE "Failed to open file"
# define ERR_RFILE "Failed to read file"
# define ERR_NARGS "Invalid number of arguments"
# define ERR_RANGE "Value out of range"
# define ERR_NVALS "Invalid number of values"

void	error_handler(void *p1, void *p2, char *m);

#endif
