/*
Most naive solution: 
Enumerate all combinations of 8 different cells out of 8 x 8 = 64 possible cells
There are 64_C_8 ~~ 4B

Better still naive solution;
Enumerate 8^8 ~~17M possibilities to put one queen in each column

Even better:
8! ~~ 40K possibilities since no two queens can occupy the same column or row

More:
No two queens can share any of the two diagonal lines:
Queen A at (i, j), queen B at (k, l). They attack each other diagonally iff abs(i-j) = abs(k-l)
*/

#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

int row[8], TC, a, b, lineCounter;

bool place(int r, int c) {
	for (int prev = 0; prev < c; prev++) {	// check previously placed queens
		if ((row[prev] == r) || (abs(c - prev) == abs(r - row[prev])))	// share same row or same diagonal
			return false;
	}
	return true;
}

void backtrack(int c) {
	if (c == 8) {	// Found a solution
		printf("%2d		%d", ++lineCounter, row[0] + 1);	// Switch to 1-based indexing in the output
		for (int j = 1; j < 8; j++) 
			printf(" %d", row[j] + 1);
		printf("\n");
	} else {
		for (int r = 0; r < 8; r++) {
			if ((c == b) && (r != a)) continue;	//Skip if current column = b but r is not a
			if (place(r, c)) {	// It is possible to place a queen at (r, c)	
				row[c] = r;
				backtrack(c+1);
			}
		}
	}
}

int main() {
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d %d", &a, &b);
		a--;b--; // switch to 0-based indexing
		memset(row, 0, sizeof row); 
		lineCounter = 0;
		printf("SOLN		COLUMN\n");	
		printf(" #		1 2 3 4 5 6 7 8\n\n");
		backtrack(0);
		if (TC) printf("\n");	// Space between test cases except the last test case
	}
}
