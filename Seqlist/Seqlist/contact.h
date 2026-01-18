#pragma once

#define NAME_MAX 20
#define GENDER_MAX 10
#define TEL_MAX 12
#define ADDR_MAX 30


typedef struct personInfo
{
	char name[NAME_MAX];
	char gerder[GENDER_MAX];
	int age;
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}peoInfo;

//给顺序表改个名字

typedef struct SeqList Contact;
//顺序表的初始化
void ContactInit(Contact* ps);
//顺序表的销毁
void ContactDesTory(Contact* ps);
//顺序表的增加
void ContactAdd(Contact* ps);
//修改联系人信息
void ContactModify(Contact* ps);
//删除联系人信息
void ContactDel(Contact* ps);
//查找联系人信息	
void ContactFind(Contact* ps);
//打印联系人信息
void ContactShow(Contact *ps);

