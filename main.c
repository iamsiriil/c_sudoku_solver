#include "src/ss_utils.c"
#include "src/ss_input_tester.c"
#include "src/ss_dmatrix.c"
#include "inc/sudoku_solver.h"

//ss_num	*ss_initialize_grid(ss_num *a, int gs) {
//
//	ss_grid *gr = malloc(sizeof(ss_grid));
//	if (!gr) {
//		perror("Failed to allocate memory for ss_grid");
//		free(a);
//		exit(1);	
//	}
//
//	gr->gx = gr->gy = (ss_num)gs;
//	gr->sx = gr->sy = (ss_num)SS_SQUR(gs);
//	gr->g = ss_create_grid(gr->gx, gr->gy, a)
//
//	return gr;
//}

int main(int ac, char **av) {

	char *buff2 = ss_argv_to_buffer(ac, av);

	t_grid *gr = ss_test_buffer(buff2);
	ss_print_grid(gr);
	ss_free_grid(gr);
}
