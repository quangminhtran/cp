#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define TRUE 1
#define FALSE 0

int MAXCANDIDATES = 2;
bool finished = FALSE;	/* found all solutions yet? */

bool is_a_solution(int a[], int k, int n) {
	return (k == n);
}

void process_solution(int a[], int k) {
	int i;
	printf("{");
	int firstPrint = FALSE;
	for (i = 1; i <= k;i++) {
		if (!a[i]) continue;
		if (!firstPrint) {
			printf("%d", i);
			firstPrint = TRUE;
		}
		else printf(",%d", i);
	}
	printf("}\n");
}


void construct_candidates(int a[], int k, int c[], int* ncandidates) {
	c[0] = TRUE;
	c[1] = FALSE;
	*ncandidates = 2;
}


void backtrack(int a[], int k, int n) {
	int c[MAXCANDIDATES];	/* Candidates for next position */
	int ncandidates;		/* Next position candidate count */
	int i;

	if (is_a_solution(a, k, n)) {
		process_solution(a, k);
	} else {
		k++;
		construct_candidates(a, k, c, &ncandidates);
		for (i = 0; i < ncandidates; i++) {
			a[k] = c[i];
			backtrack(a, k, n);
			if (finished) return;	/* Terminate early if all solutions are found */					
		}
	}
}

void generate_subsets(int n) {
	int* a = malloc(sizeof(int)*n);
	int k = 0;
	backtrack(a, k, n);
}


int main() {
	int n;
	while (scanf("%d", &n), n) {
		generate_subsets(n);
	}
	
	return 0;
}

