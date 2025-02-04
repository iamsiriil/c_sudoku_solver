#include "../inc/cns_ssolver.h"

void	cns_error_handler(void *p1, void *p2, char *m) {

	if (p1 != NULL) free(p1);
	if (p2 != NULL) free(p2);
	perror(m);
	exit(1);
}

