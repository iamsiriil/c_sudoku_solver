#ifndef LOGGER_H
# define LOGGER_H

# include <stdio.h>

extern int	log_count;

# ifdef DEBUG
# define LOG_MESSAGE(format, ...) 				  		 \
	do {			  						 \
		printf("%03d: in %s: in %s: ", ++log_count, __FILE__, __func__); \
		printf(format, ##__VA_ARGS__); 					 \
		printf("\n");							 \
		fflush(stdout);							 \
	} while (0)
# else
# define LOG_MESSAGE(format, ...);
# endif
#endif

