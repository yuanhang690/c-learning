#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
//通讯录-静态版本
//1.通讯录中能存放1000人的信息
//信息：
//名字+年龄+性别+电话+住址
//2.增加人的信息
//3.删除指定人的信息
//4.修改指定人的信息
//5.查找指定人的信息
//6.排序通讯录的信息
//
//版本2：动态增长版本
//1.开始通讯录初始化后，能存放3个人信息
//2.当空间放满的时候，增加两个信息




//版本3：文件操作
//通讯录退出时，把信息保存到文件
//通讯录打开时，把信息从文件中加载
void menu() {
	printf("************************************\n");
	printf("*****  1.add      2.del     ********\n");
	printf("*****  3.search   4.modify  ********\n");
	printf("*****  5.sort     6.print   ********\n");
	printf("**********  0. exit   **************\n");
	printf("************************************\n");
	
	
}
enum Option {
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	PRINT,
};
//创建通讯录
//

int main() {
	int input = 0;
	Contact Con;
	//初始化通讯录
	//给data申请一块连续的空间再堆区上
	//sz=0
	//capacity 初始化为当前的最大的容量
	InitContact(&Con);
	do {
		menu();
		printf("请选择>:");
		scanf("%d", &input);
		switch (input) {
		case ADD:
			AddContact(&Con);
			break;
		case DEL:
			DelContact(&Con); 
			break;
		case SEARCH:
			SearchContact(&Con);
			break;
		case MODIFY:
			ModifyContact(&Con);
			break;
		case SORT:
			//待完善
			break;
		case PRINT:
			PrintContact(&Con);
			break;
		case EXIT:
			//保存通讯录（写入文件）
			SaveContact(&Con);
			//销毁
			DestoryContact(&Con);
			printf("退出程序\n");
			break;
		}

	} while (input);
	return 0;
}
