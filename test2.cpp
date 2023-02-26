#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <string.h>
void* my_memmove(void* dest, const void* src, size_t num) {
	void* ret = dest;
	assert(dest && src);
	if (dest < src) {
		//前到后
		while (num--) {
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
			{
				//后->前
				while (num--)//19
				{
					*((char*)dest + num) = *((char*)src + num);
				}
			}
			return ret;
}
int main() {
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//              1 2 1 2 3 4 5 8 9 10
	my_memmove(arr1+2, arr1, 20);
	printf("%d", arr1[3]);
	return 0;
}
