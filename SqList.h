//    数据结构 顺序表基本运算 2016.6.25
//        SqList.h
#ifndef _head_SqList
	#define _head_SqList 1
//	#include"SqList.h"
#endif
#include<iostream>
using namespace std;
typedef int Status;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 1024

typedef char datatype;
//顺序表结构类型定义
typedef struct
{
	datatype data[MAXSIZE];
	int last;
}SqList;


Status InitList(SqList *&L);        //初始化顺序表
Status CreatList(SqList *&L);       //建立顺序表  键盘输入以*结束
Status PrintList(SqList *L);        //输出顺序表


Status InitList(SqList *&L)
//初始化顺序表
{
	L=new SqList;       
	L->last=0;
	return OK;
}

Status CreatList(SqList *&L)
//建立顺序表  键盘输入以*结束
//连续建立多个顺序表时，第一个输入完成后不要输空格或回车，否则回车会被算作字符计入第二个顺序表中，getchar()导致的
//如果用C++的输入输出流cin和cout就没有这个问题 cin遇到回车和空格会停止输入
{
	L=new SqList;           
	L->last=0;
	char ch;
	while((ch=getchar())!='*')
	{
		L->data[L->last]=ch;
		L->last++;           //表长度为last 最后一个有效数据存放在L->last-1里面
		if(L->last==MAXSIZE)
		{
			cout<<"顺序表已满！"<<endl;
			return ERROR;
		}
	}
	return OK;
}

Status PrintList(SqList *L)
//输出顺序表
{
	for(int i=0;i<L->last;i++)
		cout<<L->data[i];
	cout<<endl;
	return OK;
}
