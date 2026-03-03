#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <errno.h>
#include <limits.h>
#include <time.h>

static char counter[10] = {0};

char hasRepeats(long num) {
	memset(&counter, 0, sizeof(counter));
	char decimal = 0;
	while ((decimal = num % 10) != 0) {
		if (++counter[decimal] > 1)
			return 1;
		num /= 10;
	}
	return 0;
}

int main(int argc, char* argv[])	//argv - pointers to strings
{

	if (argc >= 2) {
		char* p;
		const long converted = strtol(argv[1], &p, 10);	//10 - base
		if (errno != 0 || *p != '\0' || converted > INT_MAX || converted < INT_MIN) {
			printf("Incorrect command line argument for array size: %ld", converted);
			return -1;
		}
		const unsigned int n = converted;
		printf("%d\n\n", n);
		if (n <= 0)
			return -1;

		int* arr = calloc(n, sizeof(int));
		srand(time(NULL));
		for (unsigned int i = 0; i < n; i++) {
			arr[i] = rand() % 10000;
			printf("%d ", arr[i]);
		}

		int amount = 0;
		for (unsigned int i = 0; i < n; i++) {
			if (!hasRepeats(arr[i] > 0 ? arr[i] : -arr[i])) {
				amount++;
			}
		}
		printf("\n%d", amount);
		free(arr);
	}
	else {
		printf("Incorrect number of arguments.");
		return -1;
	}
}
