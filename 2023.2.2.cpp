#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
//判断能否被3,5,7整除
//int main() {
//	int n;
//	scanf("%d", &n);
//	if (n % 3 == 0 && n % 5 == 0 && n % 7 == 0) {
//		printf("3 5 7");
//	}
//	else if (n % 3 == 0 && n % 5 == 0 && n % 7 != 0) {
//		printf("3 5");
//	}
//	else if (n % 3 == 0 && n % 5 != 0 && n % 7 == 0) {
//		printf("3 7");
//	}
//	else if (n % 3 != 0 && n % 5 == 0 && n % 7 == 0) {
//		printf("5 7");
//	}
//	else if (n % 3 != 0 && n % 5 != 0 && n % 7 == 0) {
//		printf("7");
//	}
//	else if (n % 3 != 0 && n % 5 == 0 && n % 7 != 0) {
//		printf("5");
//	}
//	else if (n % 3 == 0 && n % 5 != 0 && n % 7 != 0) {
//		printf("3");
//	}
//	else {
//		printf("n");
//	}
//	return 0;
//}
//模拟实现strstr
char* my_strstr(char* str1, const char* str2) {
	assert(str1 && str2);
	const char* s1 = NULL;
	const char* s2 = NULL;
	const char* cp = str1;
	if (*str2 == '\0')
	{
		return (char*)str1;
	}
	while (*cp) {
		s1 = cp;
		s2 = str2;
		while (*s1 && *s2 && (*s1 == *s2)) {
			s1++;
			s2++;
		}
		if (!*s2) {
			return (char*)cp;
		}
		cp++;
	}
	return NULL;
}
int main() {
	char arr1[] = "abbbcdef";
	char arr2[] = "bbc";
	char* ret = my_strstr(arr1, arr2);
	if (ret == NULL)
	{
		printf("没找到\n");
	}
	else
	{
		printf("找到了：%s\n", ret);
	}
	return 0;
}