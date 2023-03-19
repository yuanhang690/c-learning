#pragma once
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 20
#define MAX_ADDR 30
#define MAX 1000
#include <stdio.h>
#include <string.h>
//���Ͷ���
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
//��ʼ��
void InitContact(Contact* pc);
//���
void AddContact(Contact* pc);
//��ӡ
void PrintContact(Contact* pc);
//ɾ����ϵ��
void DelContact(Contact* pc);
//��ָ����
int FindByName(Contact* pc, char name[]); \
//����
void SearchContact(Contact* pc);
//�޸�
void ModifyContact(Contact* pc);