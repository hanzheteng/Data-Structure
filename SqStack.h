//      数据结构 顺序栈基本运算 2016.6.25
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
//顺序栈的结构类型定义
typedef struct
{
	datatype data[MAXSIZE];
	int Top;
}SqStack;


Status InitStack(SqStack *&S);             //顺序栈的初始化
Status isEmpty(SqStack *S);                //判断顺序栈是否为空，是则返回1，否则返回0
Status Push(SqStack *S,datatype e);        //顺序栈入栈
Status Pop(SqStack *S,datatype &e);        //顺序栈出栈
datatype GetTop(SqStack *S);               //顺序栈，取栈顶元素，但不删除元素
Status PrintStack(SqStack *S);             //顺序栈，由栈顶到栈底显示全部数据元素
Status ClearStack(SqStack *S);             //顺序栈，栈置空
Status StackReverse(SqStack *S);           //顺序栈逆置
Status StackTest(SqStack *S);              //输入1时入栈 2出栈 同时显示出入栈字符及此时的全部栈元素 输入0结束


Status InitStack(SqStack *&S)
//顺序栈的初始化
{
	S=new SqStack;
	S->Top=0;
	return OK;
}

Status isEmpty(SqStack *S)
//判断顺序栈是否为空，是则返回1，否则返回0
{
	if(S->Top==0)return TRUE;
	else return FALSE;
}


Status Push(SqStack *S,datatype e)
//顺序栈入栈
{
	if(S->Top>=MAXSIZE)
	{
		cout<<"顺序栈上溢！"<<endl;
		return ERROR;
	}
	S->Top++;
	S->data[S->Top]=e;
	return OK;
}

Status Pop(SqStack *S,datatype &e)
//顺序栈出栈
{
	if(isEmpty(S))
	{
		cout<<"顺序栈下溢！"<<endl;
		return ERROR;
	}
	e=S->data[S->Top];
	S->Top--;
	return OK;
}

datatype GetTop(SqStack *S)
//顺序栈，取栈顶元素，但不删除元素
{
	if(isEmpty(S))
	{
		cout<<"顺序栈为空！"<<endl;
		return ERROR;
	}
	return S->data[S->Top];
}

Status PrintStack(SqStack *S)
//顺序栈，由栈顶到栈底显示全部数据元素
{
	for(int i=S->Top;i>0;i--)
	{
		cout<<S->data[i];
	}
	cout<<endl;
	return OK;
}

Status ClearStack(SqStack *S)
//顺序栈，栈置空
{
	S->Top=0;
	return OK;
}

Status StackReverse(SqStack *S)
//顺序栈逆置
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
//输入1时入栈 2出栈 同时显示出入栈字符及此时的全部栈元素 输入0结束 
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

