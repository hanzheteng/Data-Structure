//    ���ݽṹ ������������� 2016.6.25
//        LinkList.h
#ifndef _head_LinkList
	#define _head_LinkList 1
//	#include"LinkList.h"
#endif
#include<iostream>
using namespace std;
typedef int Status;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef char datatype;
//������ṹ���Ͷ���
typedef struct ListNode
{
	datatype data;
	struct ListNode *next;
}LinkList;


Status InitList(LinkList *&head);    //��ʼ��������
Status CreatList(LinkList *&head);   //����������  ����������*����  β�巨
Status PrintList(LinkList *head);    //���������
int ListLength(LinkList *head);      //��������
LinkList *Get(LinkList *head,int i); //����Ų��ң��õ��������i������λ�õ�ָ��  0<=i<=last
Status ListInsert(LinkList *L,int i,datatype e);  //�ڵ�����L�ĵ�i��λ��֮ǰ��������Ԫ��e  1<=i<=last
Status PrintCrList(LinkList *head);  //���ѭ������


Status InitList(LinkList *&head)
//��ʼ��������
{
	head=new LinkList;     
	head->next=NULL;
	return OK;
}

Status CreatList(LinkList *&head)
//����������  ����������*����  β�巨
{	datatype x;
	LinkList *r,*p;
	head=new LinkList;
	head->next=NULL;
	r=head;
	cin>>x;               //ע�⣺�˴�������getchar()
	while(x!='*')
	{
		p=new LinkList;
		p->data=x;       //ͷ���������򲻷�����
		r->next=p;
		r=p;
		cin>>x;
	}
	r->next=NULL;       //������βָ��Ϊ��
	return OK;
}    //ʱ�临�Ӷ�O(n)

Status PrintList(LinkList *head)
//���������
{  LinkList *p=head->next;
   while(p!=NULL)
   {  cout<<p->data;
      p=p->next;
   }
   cout<<endl;
   return OK;
}

int ListLength(LinkList *head)
//��������
{
	int n=0;
	LinkList *p=head;
	while(p->next!=NULL)
	{
		p=p->next;
		n++;
	}
	return n;
}

LinkList *Get(LinkList *head,int i)
//����Ų��ң��õ��������i������λ�õ�ָ�� 0<=i<=last
{
	LinkList *p=head;
	int j=0;
	while(p->next!=NULL&&j<i)
	{
		p=p->next;
		j++;
	}
	if(j!=i)
	{
		cout<<"��i����㲻����"<<endl;
		return NULL;
	}
	else return p;
}

Status ListInsert(LinkList *L,int i,datatype e)
//�ڵ�����L�ĵ�i��λ��֮ǰ��������Ԫ��e  1<=i<=last
{
	LinkList *p=L,*q;
	q=new LinkList;
	q->data=e;
	int j=1;
	while(p&&j<i)  
	{
		p=p->next;
		j++;          //�ҵ���i-1�����
	}
	q->next=p->next;
	p->next=q;
	return OK;
}

Status PrintCrList(LinkList *head)
//���ѭ������
{  LinkList *p=head->next;
   while(p!=head)
   {  cout<<p->data;
      p=p->next;
   }
   cout<<endl;
   return OK;
}
