#pragma once
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 20
#define MAX_ADDR 30
#define MAX 1000
#define DEFAULT_SZ 3
#define INC_SZ 2


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//类型定义
typedef struct PeoInfo {

	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;
//静态版本：
//typedef struct Contact {
//	PeoInfo data[MAX];
//	int sz;
//}Contact;
// 
// 
//动态版本:
typedef struct Contact {
	PeoInfo* data;//指向动态申请的空间，用来存放联系人的信息
	int sz;//记录当前通讯录中有效信息的个数
	int capacity;//记录当前通讯录中最大容量
}Contact;
//
//初始化
void InitContact(Contact* pc);
//添加
void AddContact(Contact* pc);
//打印
void PrintContact(Contact* pc);
//删除联系人
void DelContact(Contact* pc);
//找指定人
int FindByName(Contact* pc, char name[]); \
//查找
void SearchContact(Contact* pc);
//修改
void ModifyContact(Contact* pc);
//销毁通讯录（动态版）
void DestoryContact(Contact* pc);
//保存通讯录（写入文件）
void SaveContact(Contact* pc);
//加载通讯录
void LoadContact(Contact* pc);
//考虑增容
void CheckContact(Contact* pc);

