#include <stdio.h>
void printarr2(int(*p)[5], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%d ", *(*(p+i)+j));
		}
		printf("\n");
	}
}
int main()
{
	int arr[3][5] = { {1,2,3,4,5,},{2,3,4,5,6 },{3,4,5,6,7} };
	printarr2(arr, 3, 5);
	return 0;
}

