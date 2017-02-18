#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define TRUE 1
#define FALSE 0

int NMAX = 10000;
bool finished = FALSE;	/* found all solutions yet? */

bool is_a_solution(int a[], int k, int n) {
	return (k == n);
}

void process_solution(int a[], int k) {
	int i;
	int firstPrint = FALSE;
	for (i = 1; i <= k; i++) {
		printf(" %d", a[i]);
	}
	printf("\n");
}

void construct_candidates(int a[], int n, int k, int c[], int* ncandidates) {
	int i;
	bool in_perm[NMAX];	

	for (i = 1; i < NMAX; i++) in_perm[i] = FALSE;
	for (i = 1; i < k; i++) in_perm[ a[i] ] = TRUE; // Elements from 1 to k-1 are already in the permutation

	*ncandidates = 0;
	for (i = 1; i <= n; i++) {
		if (!in_perm[i]) {	/* Only consider candidates that do not appear in the partial solution */
			c[ *ncandidates ] = i;
			*ncandidates = *ncandidates + 1;
		}
	}
}
void backtrack(int a[], int k, int n) {
	int c[NMAX];			/* Candidates for next position */
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

void generate_permutations(int n) {
	int a[NMAX];
	backtrack(a, 0, n);
}


int main() {
	int n;
	while (scanf("%d", &n), n) {
		generate_permutations(n);
	}
	
	return 0;
}

