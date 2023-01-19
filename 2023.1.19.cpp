#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() {
	const char* c[] = { "ENTER","NEW","POINT","FIRST" };
	const char** cp[] = { c + 3,c + 2,c + 1,c };
	const char*** cpp = cp;
	printf("%s\n", **++cpp);
	printf("%s\n", *-- * ++cpp + 3);
	printf("%s\n", *cpp[-2] + 3);
	printf("%s\n", cpp[-1][-1] + 1);
	return 0;
}
//第一段：printf("%s\n", **++cpp);
//先执行了++，此时cpp指向了c + 2这的地址，解引用指向第三行的char * 地址，再解引用找到P的地址，输出POINT：
//第二段：+3的优先级比较低，在这里最后算，先算cpp前面的，++cpp指向了c+1这行的地址
//* ++cpp找到了c+1然后 -- * ++cpp，此时c+1就变成了c（同时指向了第一行的char*）
//然后解引用找到ENTER首地址，最后加三指向E，然后输出的就是ER：
//第三段：*cpp[-2]等价于*(*(cpp-2))+3;于是cpp-2指向了c+3的地址，解引用*(cpp-2)找到最后一行char*地址。
//再解引用*(*(cpp-2))找到“FIRST”F的地址最后加三找到S，所以输出的是ST
//第四段：cpp[-1] [-1] +1等价于*(*(cpp-1)-1)+1。所以cpp-1指向了c+2的地址，解引用*(cpp-1)找到了c+2，
//在减一*(cpp-1)-1变成了c+1（此时指向第二行char*地址），然后解引用找到NEW中N地址，
//最后+1指向了E，所以最后输出EW
