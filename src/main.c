#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	if (/*argc >= 1*/ 1) {
		//const unsigned int n = argv[0];
		const unsigned int n = 10;
		int* arr = calloc(n, sizeof(int));
		srand(time(NULL));
		for (unsigned int i = 0; i < n; i++) {
			arr[i] = rand() % 100;
			printf("%d ", arr[i]);
		}
	}
	else {
		printf("Incorrect number of arguments.");
		return -1;
	}
}
