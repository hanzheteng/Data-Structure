//    ���ݽṹ ������������� 2016.6.25
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
//��ʽ���еĽṹ���Ͷ���
typedef struct QueueNode
{
	datatype data;
	QueueNode *next;
}QueueNode;
typedef struct
{
	QueueNode *front,*rear;
}LinkQueue;


Status InitQueue(LinkQueue *&Q);           //�����г�ʼ��
Status isEmpty(LinkQueue *Q);              //�ж��������Ƿ�Ϊ��  ���򷵻�1  ���򷵻�0
Status EnQueue(LinkQueue *Q,datatype e);   //�����У���ӣ�β�巨
Status DeQueue(LinkQueue *Q,datatype &e);  //�����У����ӣ�ͷ��㲻������ͷ����
datatype GetFront(LinkQueue *Q);           //�����У�ȡ��ͷԪ�أ���������
Status PrintQueue(LinkQueue *Q);           //�����У���ʾ����ȫ������Ԫ��
Status QueueTest(LinkQueue *Q);            //����1ʱ��� 2���� ͬʱ��ʾ������ַ�����ʱ��ȫ������Ԫ�� ����0���� 
Status ClearQueue(LinkQueue *Q);           //��ն���


Status InitQueue(LinkQueue *&Q)
//�����г�ʼ��
{
	Q=new LinkQueue;
	Q->front=Q->rear=new QueueNode;        //����ͷ���  ���������ӳ��ӵȲ���
	Q->rear->next=NULL;
	return OK;
}

Status isEmpty(LinkQueue *Q)
//�ж��������Ƿ�Ϊ��  ���򷵻�1  ���򷵻�0
{
	if(Q->front==Q->rear)
		return TRUE;
	else
		return FALSE;
}

Status EnQueue(LinkQueue *Q,datatype e)
//�����У���ӣ�β�巨
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
//�����У����ӣ�ͷ��㲻������ͷ����
{
	if(isEmpty(Q))
	{
		cout<<"������Ϊ�գ�"<<endl;
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
//�����У�ȡ��ͷԪ�أ���������
{
	if(isEmpty(Q))
	{
		cout<<"������Ϊ�գ�"<<endl;
		return ERROR;
	}
	return Q->front->next->data;
}

Status PrintQueue(LinkQueue *Q)
//�����У���ʾ����ȫ������Ԫ��
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
//����1ʱ��� 2���� ͬʱ��ʾ������ַ�����ʱ��ȫ������Ԫ�� ����0���� 
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
//��ն���
{
	datatype x;
	while(!isEmpty(Q))
		DeQueue(Q,x);
	return OK;
}





