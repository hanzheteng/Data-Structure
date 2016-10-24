//    数据结构 链队列相关运算 2016.6.25
//         LinkQueue.h
#ifndef _head_LinkQueue
	#define _head_LinkQueue 1
//	#include"LinkQueue.h"
#endif
#include<iostream>
using namespace std;
typedef int Status;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef char datatype;
//链式队列的结构类型定义
typedef struct QueueNode
{
	datatype data;
	QueueNode *next;
}QueueNode;
typedef struct
{
	QueueNode *front,*rear;
}LinkQueue;


Status InitQueue(LinkQueue *&Q);           //链队列初始化
Status isEmpty(LinkQueue *Q);              //判断链队列是否为空  是则返回1  否则返回0
Status EnQueue(LinkQueue *Q,datatype e);   //链队列，入队，尾插法
Status DeQueue(LinkQueue *Q,datatype &e);  //链队列，出队，头结点不动，队头出队
datatype GetFront(LinkQueue *Q);           //链队列，取队头元素，但不出队
Status PrintQueue(LinkQueue *Q);           //链队列，显示队列全部数据元素
Status QueueTest(LinkQueue *Q);            //输入1时入队 2出队 同时显示出入队字符及此时的全部队列元素 输入0结束 
Status ClearQueue(LinkQueue *Q);           //清空队列


Status InitQueue(LinkQueue *&Q)
//链队列初始化
{
	Q=new LinkQueue;
	Q->front=Q->rear=new QueueNode;        //设置头结点  方便进行入队出队等操作
	Q->rear->next=NULL;
	return OK;
}

Status isEmpty(LinkQueue *Q)
//判断链队列是否为空  是则返回1  否则返回0
{
	if(Q->front==Q->rear)
		return TRUE;
	else
		return FALSE;
}

Status EnQueue(LinkQueue *Q,datatype e)
//链队列，入队，尾插法
{
	QueueNode *p;
	p=new QueueNode;
	p->data=e;
	p->next=NULL;
	Q->rear->next=p;
	Q->rear=p;
	return OK;
}

Status DeQueue(LinkQueue *Q,datatype &e)
//链队列，出队，头结点不动，队头出队
{
	if(isEmpty(Q))
	{
		cout<<"链队列为空！"<<endl;
		return ERROR;
	}
	e=Q->front->next->data;
	QueueNode *p;
	p=Q->front->next;
	Q->front->next=p->next;
	if(p->next==NULL)
		Q->rear=Q->front;
	delete(p);
	return OK;
}

datatype GetFront(LinkQueue *Q)
//链队列，取队头元素，但不出队
{
	if(isEmpty(Q))
	{
		cout<<"链队列为空！"<<endl;
		return ERROR;
	}
	return Q->front->next->data;
}

Status PrintQueue(LinkQueue *Q)
//链队列，显示队列全部数据元素
{
	QueueNode *p;
	p=Q->front;
	while(p->next!=NULL)   
	{
		p=p->next;
		cout<<p->data;
	}
	cout<<endl;
	return OK;
}

Status QueueTest(LinkQueue *Q)
//输入1时入队 2出队 同时显示出入队字符及此时的全部队列元素 输入0结束 
{
	char ch='3';
	datatype x;
	while(ch!='0')
	{
		x=NULL;
		ch=getchar();
		if(ch=='1')
		{
			cin>>x;
			EnQueue(Q,x);
			PrintQueue(Q);
		}
		if(ch=='2')
		{
			if(DeQueue(Q,x))
				cout<<x<<endl;
			PrintQueue(Q);
		}
	}
	return OK;
}

Status ClearQueue(LinkQueue *Q)
//清空队列
{
	datatype x;
	while(!isEmpty(Q))
		DeQueue(Q,x);
	return OK;
}





