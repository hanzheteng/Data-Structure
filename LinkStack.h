//      数据结构 链栈基本运算 2016.6.25
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
//链栈的结构类型定义
typedef struct StackNode
{
	datatype data;
	struct StackNode *next;
}StackNode;
typedef struct
{
	struct StackNode *Top;
}LinkStack;


Status InitStack(LinkStack *&S);       //链栈的初始化
Status isEmpty(LinkStack *S);          //判断链栈是否为空，是则返回1，否则返回0
Status Push(LinkStack *S,datatype e);  //链栈入栈
Status Pop(LinkStack *S,datatype &e);  //链栈出栈
datatype GetTop(LinkStack *S);         //链栈，取栈顶元素，但不删除元素
Status PrintStack(LinkStack *S);       //链栈，由栈顶到栈底显示全部数据元素
Status StackTest(LinkStack *S);        //输入1时入栈 2出栈 同时显示出入栈字符及此时的全部栈元素 输入0结束 


Status InitStack(LinkStack *&S)       //指针的引用
//链栈的初始化
{
	S=new LinkStack;
	S->Top=NULL;
	return OK;
}


Status isEmpty(LinkStack *S)
//判断链栈是否为空，是则返回1，否则返回0
{
	if(S->Top==NULL)return TRUE;
	else return FALSE;
}


Status Push(LinkStack *S,datatype e)
//链栈入栈
{
	StackNode *p;
	p=new StackNode;
	p->data=e;
	p->next=S->Top;
	S->Top=p;
	return OK;
}

Status Pop(LinkStack *S,datatype &e)
//链栈出栈
{
	if(isEmpty(S))
	{
		cout<<"链栈下溢！"<<endl;
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
//链栈，取栈顶元素，但不删除元素
{
	if(isEmpty(S))
	{
		cout<<"链栈为空！"<<endl;
		return ERROR;
	}
	return S->Top->data;
}


Status PrintStack(LinkStack *S)
//链栈，由栈顶到栈底显示全部数据元素
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
//输入1时入栈 2出栈 同时显示出入栈字符及此时的全部栈元素 输入0结束 
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

