#define _CRT_SECURE_NO_WARNINGS 1
//一个只由小写字母组成的字符串s,接下来将字符串执行
//k次操作,，每次操作都会把中ASCII码最小的字母从s中删除，请返回k次操作之后的字符串x.
//比如：输入"caabeefa",2	输出："ceef"
#include <stdio.h>
#include <string.h>
int main() {
	int i = 0, k = 0, count = 0;
	char arr[100];//定义字符数组
	char* p = arr + 1;//定义指针p指向arr第二个元素，因为第一个arr[0]是 " 可以不用管
	while (1) {
		scanf("%c ", &arr[i]);
		count++;//记录输入的字符从'“ '到','的总长度
		if (arr[i] == ',') {
			break;
		}
		i++;
	}
	scanf("%d", &k);//读入k
	int min = arr[1];//假定最小值min为第一个字母
	for (i = 2; i < count - 2; i++) {//count是总长，还要去掉最后,和"两字符
		if (arr[i] < min) {//遍历数组找到ASCll最小的字母，赋给min
			int m = min;
			min = arr[i];
			arr[i] = m;
		}
	}
	for (i = 0; i < k; i++) {
		int j = 1;
		while (*p != ',') {//从第一个开始直到“，”是最小的字母就使其变成*最后不输出即可
			if (arr[j] == min) {
				*p = '*';
			}
			j++;
			p++;//每影响完指针向后移
		}
		//一轮完后由第二小字母继续判断，别忘了要让指针重新指向arr【1】
		min++;
		p = arr + 1;

	}
	for (i = 0; i < count - 1; i++) {
		if (arr[i] != '*') {
			printf("%c", arr[i]);
		}
	}

	return 0;
}