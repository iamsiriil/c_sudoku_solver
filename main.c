#include "src/ss_utils.c"
#include "inc/sudoku_solver.h"

int	ss_get_n_vals(char *b) {

	int ct = 0;
	while (*b) {
		if (isdigit(*b)) {
			ct++;
			for (; isdigit(*b); b++) ;
		} else b++;
	}
	return ct;
}
int main(int ac, char **av) {

	//(void)ac, (void)av;
	//char path[] = "./tests/test_files/puzzles/easy_9x9/tp_es_000.txt";
	//char *buff1 = ss_file_to_buffer(path);
	char *buff2 = ss_argv_to_buffer(ac, av);

	printf("nvals : %d\n", ss_get_n_vals(buff2));
	//printf("file :\n%s\n", buff1);
	printf("argv :\n%s\n", buff2);
	free(buff2);
}
