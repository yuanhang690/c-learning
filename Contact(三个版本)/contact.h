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
//���Ͷ���
typedef struct PeoInfo {

	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;
//��̬�汾��
//typedef struct Contact {
//	PeoInfo data[MAX];
//	int sz;
//}Contact;
// 
// 
//��̬�汾:
typedef struct Contact {
	PeoInfo* data;//ָ��̬����Ŀռ䣬���������ϵ�˵���Ϣ
	int sz;//��¼��ǰͨѶ¼����Ч��Ϣ�ĸ���
	int capacity;//��¼��ǰͨѶ¼���������
}Contact;
//
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
//����ͨѶ¼����̬�棩
void DestoryContact(Contact* pc);
//����ͨѶ¼��д���ļ���
void SaveContact(Contact* pc);
//����ͨѶ¼
void LoadContact(Contact* pc);
//��������
void CheckContact(Contact* pc);

