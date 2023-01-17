#define _CRT_SECURE_NO_WARNINGS 1
#include <string.h>
#include <stdio.h>
//指针和数组笔试题
//一维数组
//重点知识：1.sizeof(数组名)数组名单独出现在括号里时，计算的是整个数组大小，单位是字节
//			2.&数组名--取出的是整个数组的地址
//除了这两个其余情况数组名单独出现表示的是首元素地址
//		对于strlen（）括号里接受的需要是地址，参数一般为char*，传递为别的会报错
//注意区分算得是地址大小（4/8）还是地址里元素的大小
int main() {
	int a[] = { 1,2,3,4 };
	printf("%d\n", sizeof(a));//单独出现-->16
	printf("%d\n", sizeof(a + 0));//a+0不算单独出现，这里是首元素地址地址-->为4（32位）/8（64位）
	printf("%d\n", sizeof(*a));//类似上面这里是首元素解引用-->4（4个字节）
	printf("%d\n", sizeof(a + 1));//同2行，4/8
	printf("%d\n", sizeof(a[1]));//4(第二个元素大小)
	printf("%d\n", sizeof(&a));//4/8-->(算整个数组地址)
	printf("%d\n", sizeof(*&a));//16-->计算数组整个大小
	printf("%d\n", sizeof(&a + 1));//4/8-->计算这个数组下一个空间的地址
	printf("%d\n", sizeof(&a[0]));//4/8
	printf("%d\n", sizeof(&a[0] + 1));//4/8-->也是地址


	//字符数组
	char arr[] = { 'a','b','c','d','e','f' };//注意：这初始化是没有'\0'的
	printf("%d\n", sizeof(arr));//6-->整个数组大小（1元素一字节）
	printf("%d\n", sizeof(arr + 0));//4/8-->首元素地址
	printf("%d\n", sizeof(*arr));//1-->首元素地址解引用就是‘a’所占大小
	printf("%d\n", sizeof(arr[1]));//1（同上）
	printf("%d\n", sizeof(&arr));//4/8
	printf("%d\n", sizeof(&arr + 1));//4/8
	printf("%d\n", sizeof(&arr[0] + 1));//4/8（这三个为地址）



	printf("%d\n", strlen(arr));//随机值-->strlen停止的标志是找到'\0'这里是没有的，会往后走
	printf("%d\n", strlen(arr + 0));//同上
	printf("%d\n", strlen(*arr));//error	传递的是值而不是地址，报错
	printf("%d\n", strlen(arr[1]));//同上
	printf("%d\n", strlen(&arr));//随机值		一直向后直到找到0为止
	printf("%d\n", strlen(&arr + 1));//随机值-6		整个数组地址加1，跨过了一整个数组（6元素）
	printf("%d\n", strlen(&arr[0] + 1));//随机值-1	同上



	char arr[] = "abcdef";//注意：这样的初始化有'\0'思想与上题差不多
	printf("%d\n", sizeof(arr));//7-->这里把‘\0’也算就进来了
	printf("%d\n", sizeof(arr + 0));//4/8	地址
	printf("%d\n", sizeof(*arr));//1	首元素大小
	printf("%d\n", sizeof(arr[1]));//1	同上
	printf("%d\n", sizeof(&arr));//4/8
	printf("%d\n", sizeof(&arr + 1));//4/8
	printf("%d\n", sizeof(&arr[0] + 1));//4/8
	printf("%d\n", strlen(arr));//6-->找到了‘\0’
	printf("%d\n", strlen(arr + 0));//6
	printf("%d\n", strlen(*arr));//error		不是地址
	printf("%d\n", strlen(arr[1]));//error
	printf("%d\n", strlen(&arr));//6
	printf("%d\n", strlen(&arr + 1));//随机值，跨过了这个数组
	printf("%d\n", strlen(&arr[0] + 1));//5		从b开始

	char* p = "abcdef";
	printf("%d\n", sizeof(p));//4/8
	printf("%d\n", sizeof(p + 1));//4/8
	printf("%d\n", sizeof(*p));//1		首元素大小
	printf("%d\n", sizeof(p[0]));//1	与上面相同p[0]== *(p+0)
	printf("%d\n", sizeof(&p));//4/8
	printf("%d\n", sizeof(&p + 1));//4/8
	printf("%d\n", sizeof(&p[0] + 1));//4/8


	printf("%d\n", strlen(p));//6	首元素地址		
	printf("%d\n", strlen(p + 1));//5	
	printf("%d\n", strlen(*p));//error
	printf("%d\n", strlen(p[0]));//error
	printf("%d\n", strlen(&p));//随机值		这里是p自己本身拥有的地址不知道是否有'\0'
	printf("%d\n", strlen(&p + 1));//随机值
	printf("%d\n", strlen(&p[0] + 1));//5
	return 0;
}