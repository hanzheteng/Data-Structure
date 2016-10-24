//    ���ݽṹ ˳���������� 2016.6.25
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
//˳���ṹ���Ͷ���
typedef struct
{
	datatype data[MAXSIZE];
	int last;
}SqList;


Status InitList(SqList *&L);        //��ʼ��˳���
Status CreatList(SqList *&L);       //����˳���  ����������*����
Status PrintList(SqList *L);        //���˳���


Status InitList(SqList *&L)
//��ʼ��˳���
{
	L=new SqList;       
	L->last=0;
	return OK;
}

Status CreatList(SqList *&L)
//����˳���  ����������*����
//�����������˳���ʱ����һ��������ɺ�Ҫ��ո��س�������س��ᱻ�����ַ�����ڶ���˳����У�getchar()���µ�
//�����C++�����������cin��cout��û��������� cin�����س��Ϳո��ֹͣ����
{
	L=new SqList;           
	L->last=0;
	char ch;
	while((ch=getchar())!='*')
	{
		L->data[L->last]=ch;
		L->last++;           //����Ϊlast ���һ����Ч���ݴ����L->last-1����
		if(L->last==MAXSIZE)
		{
			cout<<"˳���������"<<endl;
			return ERROR;
		}
	}
	return OK;
}

Status PrintList(SqList *L)
//���˳���
{
	for(int i=0;i<L->last;i++)
		cout<<L->data[i];
	cout<<endl;
	return OK;
}
