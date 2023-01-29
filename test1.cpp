#define _CRT_SECURE_NO_WARNINGS 1
////一个只由小写字母组成的字符串s,接下来将字符串执行
////k次操作,，每次操作都会把中ASCII码最小的字母从s中删除，请返回k次操作之后的字符串x.
////比如：输入"caabeefa",2	输出："ceef"
//#include <stdio.h>
//#include <string.h>
//int main() {
//	int i = 0,k=0,count=0;
//	char arr[100];//定义字符数组
//	char* p = arr + 1;//定义指针p指向arr第二个元素，因为第一个arr[0]是 " 可以不用管
//	while (1) {
//		scanf("%c ", &arr[i]);
//		count++;//记录输入的字符从'“ '到','的总长度
//		if (arr[i] == ',') {
//			break;
//		}
//		i++;
//	}
//	scanf("%d", &k);//读入k
//	int min = arr[1];//假定最小值min为第一个字母
//	for (i = 2; i < count - 2; i++) {//count是总长，还要去掉最后,和"两字符
//		if (arr[i] < min) {//遍历数组找到ASCll最小的字母，赋给min
//			int m = min;
//			min = arr[i];
//			arr[i] = m;
//		}
//	}
//	for (i = 0; i < k; i++) {
//		int j = 1;
//		while (*p != ',') {//从第一个开始直到“，”是最小的字母就使其变成*最后不输出即可
//			if (arr[j] == min) {
//				*p = '*';
//			}
//			j++;
//			p++;//每影响完指针向后移
//		}
//		//一轮完后由第二小字母继续判断，别忘了要让指针重新指向arr【1】
//		min++;
//		p = arr + 1;
//		
//	}
//	for (i = 0; i < count-1; i++) {
//		if (arr[i] != '*') {
//			printf("%c", arr[i]);
//		}
//	}
//
//	return 0;
//}
//#include <stdio.h>
//int main() {
//	int m, n, sum = 0,  i = 0;
//	scanf("%d%d", &m, &n);
//	for (i = m; i <= n; i++) {
//		if (i % 2 != 0)
//			sum += i;
//	}
//	printf("%d", sum);
//	return 0;
//}
//#include <stdio.h>
//a^b的末3位数是多少？
//两个正整数a，b;从高位到低位输出幂的末三位数字
//int main() {
//	
//	int a, b,i,k=1;
//	scanf("%d%d", &a, &b);
//	for (i = 1; i <= b; i++) {
//		k *= a;
//		k %= 1000;
//	}
//	if (k < 10)
//		printf("00%d", k);
//	else if (k >= 10 && k <= 100)
//		printf("0%d", k);
//	else
//		printf("%d", k);
//
//	return 0;
//
//}
//int main() {
//	printf("%d", 1/0);
//	return 0;
//}
#include <stdio.h>
int main() {
	 int arr[100][100] = { 0 }, len[10000], wid[10000], a[10000], b[10000];
	int i = 0, j = 0, k = 0, n, x, y;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d%d%d%d", &a[i], &b[i], &len[i], &wid[i]);
	}
	scanf("%d%d", &x, &y);
	for (i = 0; i < n; i++) {
		for (j = a[i]; j <= len[i]; j++) {
			for (k = b[i]; k <= wid[i]; k++) {
				arr[j][k]++;
			}
		}
	}
	if (arr[x][y] == 0)
		printf("-1");
	else
		printf("%d", arr[x][y]);
	return 0;
}