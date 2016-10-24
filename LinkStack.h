//      ���ݽṹ ��ջ�������� 2016.6.25
//         LinkStack.h
#ifndef _head_LinkStack
	#define _head_LinkStack 1
//	#include"LinkStack.h"
#endif
#include<iostream>
using namespace std;
typedef int Status;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef char datatype;
//��ջ�Ľṹ���Ͷ���
typedef struct StackNode
{
	datatype data;
	struct StackNode *next;
}StackNode;
typedef struct
{
	struct StackNode *Top;
}LinkStack;


Status InitStack(LinkStack *&S);       //��ջ�ĳ�ʼ��
Status isEmpty(LinkStack *S);          //�ж���ջ�Ƿ�Ϊ�գ����򷵻�1�����򷵻�0
Status Push(LinkStack *S,datatype e);  //��ջ��ջ
Status Pop(LinkStack *S,datatype &e);  //��ջ��ջ
datatype GetTop(LinkStack *S);         //��ջ��ȡջ��Ԫ�أ�����ɾ��Ԫ��
Status PrintStack(LinkStack *S);       //��ջ����ջ����ջ����ʾȫ������Ԫ��
Status StackTest(LinkStack *S);        //����1ʱ��ջ 2��ջ ͬʱ��ʾ����ջ�ַ�����ʱ��ȫ��ջԪ�� ����0���� 


Status InitStack(LinkStack *&S)       //ָ�������
//��ջ�ĳ�ʼ��
{
	S=new LinkStack;
	S->Top=NULL;
	return OK;
}


Status isEmpty(LinkStack *S)
//�ж���ջ�Ƿ�Ϊ�գ����򷵻�1�����򷵻�0
{
	if(S->Top==NULL)return TRUE;
	else return FALSE;
}


Status Push(LinkStack *S,datatype e)
//��ջ��ջ
{
	StackNode *p;
	p=new StackNode;
	p->data=e;
	p->next=S->Top;
	S->Top=p;
	return OK;
}

Status Pop(LinkStack *S,datatype &e)
//��ջ��ջ
{
	if(isEmpty(S))
	{
		cout<<"��ջ���磡"<<endl;
		return ERROR;
	}
	e=S->Top->data;
	StackNode *p;
	p=S->Top;
	S->Top=S->Top->next;
	delete(p);
	return OK;
}

datatype GetTop(LinkStack *S)
//��ջ��ȡջ��Ԫ�أ�����ɾ��Ԫ��
{
	if(isEmpty(S))
	{
		cout<<"��ջΪ�գ�"<<endl;
		return ERROR;
	}
	return S->Top->data;
}


Status PrintStack(LinkStack *S)
//��ջ����ջ����ջ����ʾȫ������Ԫ��
{
	StackNode *p;
	p=S->Top;
	while(p!=NULL)
	{
		cout<<p->data;
		p=p->next;
	}
	cout<<endl;
	return OK;
}

Status StackTest(LinkStack *S)
//����1ʱ��ջ 2��ջ ͬʱ��ʾ����ջ�ַ�����ʱ��ȫ��ջԪ�� ����0���� 
{
	char ch='3';
	datatype x;
	while(ch!='0')
	{
		ch=getchar();
		if(ch=='1')
		{
			cin>>x;
			Push(S,x);
			PrintStack(S);
		}
		if(ch=='2')
		{
			if(Pop(S,x))
				cout<<x<<endl;
			PrintStack(S);
		}
	}
	return OK;
}

