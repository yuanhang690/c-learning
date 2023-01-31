#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
char* my_strcat(char* dest, const char* src) {
	char* ret = dest;
	assert(dest && src);
	while (*dest) {//找到目标字符串中的\0
		dest++;
	}
	while (*dest++ = *src++) {
		//追加字符串，包含\0
	}
	return ret;//返回目标的起始地址
}
int my_strcmp(const char* s1, const char* s2) {
	while (*s1 == *s2) {
		if (*s1 == '\0')
			return 0;
		s1++;
		s2++;
	}
	if (*s1 > *s2) {
		return 1;
	}
	else {
		return -1;
	}
}

int main() {

	return 0;
}