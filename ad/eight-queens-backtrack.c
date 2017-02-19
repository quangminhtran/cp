#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define TRUE 1
#define FALSE 0

int MAXCANDIDATES = 8;
bool finished = FALSE;	/* found all solutions yet? */
int num_solutions = 0;

bool is_a_solution(int a[], int k, int n) {
	if (k == n-1) {
		num_solutions++;
		return TRUE;
	}
	return FALSE;
}

void process_solution(int a[], int k) {
	printf("Solution: ");
	int i;
	for (i = 0; i <= k;i++) {
		printf(" %d", a[i]);
	}
	printf("\n");
}

bool attacked(int a[], int n, int k, int y) {
	int i;
	// Any queen on the same row or horiziontal line
	for (i = 0; i <k; i++) {
		if ((a[i] == y) || (abs(k-i) == abs(y-a[i]))) return TRUE;
	}
	return FALSE;
}

void construct_candidates(int a[], int n, int k, int c[], int* ncandidates) {
	int y;
	*ncandidates = 0;
	for (y = 0; y < n; y++) {
		if (!attacked(a, n, k, y)) {
			c[ *ncandidates ] = y;
			*ncandidates = *ncandidates + 1;
		}
	}
}


void backtrack(int a[], int k, int n) {
	int c[MAXCANDIDATES];	/* Candidates for next position */
	int ncandidates;		/* Next position candidate count */
	int i;

	if (is_a_solution(a, k, n)) {
		process_solution(a, k);
	} else {
		k++;
		construct_candidates(a, n, k, c, &ncandidates);
		for (i = 0; i < ncandidates; i++) {
			a[k] = c[i];
			backtrack(a, k, n);
			if (finished) return;	/* Terminate early if all solutions are found */					
		}
	}
}

void eight_queens(int n) {
	
	int* a = malloc(sizeof(int)*n);
	printf("Start backtracking...\n");	
	backtrack(a, -1, n);
	printf("There are %d solutions\n", num_solutions);
}


int main() {
	eight_queens(8);	
	return 0;
}

