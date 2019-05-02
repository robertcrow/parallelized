#include <mpi.h>
#include <stdio.h>
#include <string.h>
int main (int argc, char *argv[]) {
	int rank, size, src;
	int message;
	int tag = 42;
	MPI_Status status;

	MPI_Init (&argc, &argv);
	MPI_Comm_rank (MPI_COMM_WORLD, &rank);
	MPI_Comm_size (MPI_COMM_WORLD, &size);

	if (rank != 0) {
		//sprintf (message, "%d\n", rank);
		MPI_Send (&rank, 1, MPI_INT, 0, tag, MPI_COMM_WORLD); /* dlaczego strlen + 1? */
	} else {
		for (int src = 1; src < size; src++) {
			MPI_Recv (&message, 1, MPI_INT, MPI_ANY_SOURCE, tag, MPI_COMM_WORLD, &status);
			/*MPI_Recv (message, 50, MPI_CHAR, src, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE); */
			printf ("%i\n", message);
		}
	}		
	MPI_Finalize ();
	return 0;
}
