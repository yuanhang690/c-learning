#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int main() {
	int i = 0,k=0,j=1,count=0;
	char arr[100],m='a';
	char* p = arr + 1;
	while (1) {
		scanf("%c ", &arr[i]);
		count++;
		if (arr[i] == ',') {
			break;
		}
		i++;
	}
	scanf("%d", &k);
	for (i = 0; i < k; i++) {
		while (*p != '"') {
			if (arr[j] == m) {
				*p = '*';
				j++;
				p++;
			}
		}
		m++;
	}
	for (i = 0; i < count; i++) {
		if (arr[i] != '*') {
			printf("%c", arr[i]);
		}
	}

	return 0;
}