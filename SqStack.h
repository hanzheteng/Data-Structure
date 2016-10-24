//      ���ݽṹ ˳��ջ�������� 2016.6.25
//          SqStack.h
#ifndef _head_SqStack
	#define _head_SqStack 1
//	#include"SqStack.h"
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
//˳��ջ�Ľṹ���Ͷ���
typedef struct
{
	datatype data[MAXSIZE];
	int Top;
}SqStack;


Status InitStack(SqStack *&S);             //˳��ջ�ĳ�ʼ��
Status isEmpty(SqStack *S);                //�ж�˳��ջ�Ƿ�Ϊ�գ����򷵻�1�����򷵻�0
Status Push(SqStack *S,datatype e);        //˳��ջ��ջ
Status Pop(SqStack *S,datatype &e);        //˳��ջ��ջ
datatype GetTop(SqStack *S);               //˳��ջ��ȡջ��Ԫ�أ�����ɾ��Ԫ��
Status PrintStack(SqStack *S);             //˳��ջ����ջ����ջ����ʾȫ������Ԫ��
Status ClearStack(SqStack *S);             //˳��ջ��ջ�ÿ�
Status StackReverse(SqStack *S);           //˳��ջ����
Status StackTest(SqStack *S);              //����1ʱ��ջ 2��ջ ͬʱ��ʾ����ջ�ַ�����ʱ��ȫ��ջԪ�� ����0����


Status InitStack(SqStack *&S)
//˳��ջ�ĳ�ʼ��
{
	S=new SqStack;
	S->Top=0;
	return OK;
}

Status isEmpty(SqStack *S)
//�ж�˳��ջ�Ƿ�Ϊ�գ����򷵻�1�����򷵻�0
{
	if(S->Top==0)return TRUE;
	else return FALSE;
}


Status Push(SqStack *S,datatype e)
//˳��ջ��ջ
{
	if(S->Top>=MAXSIZE)
	{
		cout<<"˳��ջ���磡"<<endl;
		return ERROR;
	}
	S->Top++;
	S->data[S->Top]=e;
	return OK;
}

Status Pop(SqStack *S,datatype &e)
//˳��ջ��ջ
{
	if(isEmpty(S))
	{
		cout<<"˳��ջ���磡"<<endl;
		return ERROR;
	}
	e=S->data[S->Top];
	S->Top--;
	return OK;
}

datatype GetTop(SqStack *S)
//˳��ջ��ȡջ��Ԫ�أ�����ɾ��Ԫ��
{
	if(isEmpty(S))
	{
		cout<<"˳��ջΪ�գ�"<<endl;
		return ERROR;
	}
	return S->data[S->Top];
}

Status PrintStack(SqStack *S)
//˳��ջ����ջ����ջ����ʾȫ������Ԫ��
{
	for(int i=S->Top;i>0;i--)
	{
		cout<<S->data[i];
	}
	cout<<endl;
	return OK;
}

Status ClearStack(SqStack *S)
//˳��ջ��ջ�ÿ�
{
	S->Top=0;
	return OK;
}

Status StackReverse(SqStack *S)
//˳��ջ����
{
	SqStack *temp1,*temp2;
	InitStack(temp1);
	InitStack(temp2);
	datatype e;
	while(!isEmpty(S))
	{
		Pop(S,e);
		Push(temp1,e);
	} 
	while(!isEmpty(temp1))
	{
		Pop(temp1,e);
		Push(temp2,e);
	}
	while(!isEmpty(temp2))
	{
		Pop(temp2,e);
		Push(S,e);
	}
	return OK;
}

Status StackTest(SqStack *S)
//����1ʱ��ջ 2��ջ ͬʱ��ʾ����ջ�ַ�����ʱ��ȫ��ջԪ�� ����0���� 
{
	char ch='3',x;
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

