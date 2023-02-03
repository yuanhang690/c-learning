#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int main() {
	//strtok函数的使用
	const char* p = "abcdefgh.adada@qwertr";
	const char* sep = "@.";
	char arr[40];
	char* str = NULL;
	strcpy(arr, p);
	for (str = strtok(arr, sep); str != NULL; str = strtok(NULL, sep)) {
		printf("%s\n", str);
	}

	return 0;
}