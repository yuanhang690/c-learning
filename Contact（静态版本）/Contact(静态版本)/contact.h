#pragma once
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 20
#define MAX_ADDR 30
#define MAX 1000
#include <stdio.h>
#include <string.h>
//类型定义
typedef struct PeoInfo {

	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;
//
typedef struct Contact {
	PeoInfo data[MAX];
	int sz;
}Contact;
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