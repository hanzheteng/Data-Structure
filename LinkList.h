//    数据结构 单链表基本运算 2016.6.25
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
//单链表结构类型定义
typedef struct ListNode
{
	datatype data;
	struct ListNode *next;
}LinkList;


Status InitList(LinkList *&head);    //初始化单链表
Status CreatList(LinkList *&head);   //建立单链表  键盘输入以*结束  尾插法
Status PrintList(LinkList *head);    //输出单链表
int ListLength(LinkList *head);      //求单链表长度
LinkList *Get(LinkList *head,int i); //按序号查找，得到单链表第i个数据位置的指针  0<=i<=last
Status ListInsert(LinkList *L,int i,datatype e);  //在单链表L的第i个位置之前插入数据元素e  1<=i<=last
Status PrintCrList(LinkList *head);  //输出循环链表


Status InitList(LinkList *&head)
//初始化单链表
{
	head=new LinkList;     
	head->next=NULL;
	return OK;
}

Status CreatList(LinkList *&head)
//建立单链表  键盘输入以*结束  尾插法
{	datatype x;
	LinkList *r,*p;
	head=new LinkList;
	head->next=NULL;
	r=head;
	cin>>x;               //注意：此处不能用getchar()
	while(x!='*')
	{
		p=new LinkList;
		p->data=x;       //头结点的数据域不放数据
		r->next=p;
		r=p;
		cin>>x;
	}
	r->next=NULL;       //单链表尾指针为空
	return OK;
}    //时间复杂度O(n)

Status PrintList(LinkList *head)
//输出单链表
{  LinkList *p=head->next;
   while(p!=NULL)
   {  cout<<p->data;
      p=p->next;
   }
   cout<<endl;
   return OK;
}

int ListLength(LinkList *head)
//求单链表长度
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
//按序号查找，得到单链表第i个数据位置的指针 0<=i<=last
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
		cout<<"第i个结点不存在"<<endl;
		return NULL;
	}
	else return p;
}

Status ListInsert(LinkList *L,int i,datatype e)
//在单链表L的第i个位置之前插入数据元素e  1<=i<=last
{
	LinkList *p=L,*q;
	q=new LinkList;
	q->data=e;
	int j=1;
	while(p&&j<i)  
	{
		p=p->next;
		j++;          //找到第i-1个结点
	}
	q->next=p->next;
	p->next=q;
	return OK;
}

Status PrintCrList(LinkList *head)
//输出循环链表
{  LinkList *p=head->next;
   while(p!=head)
   {  cout<<p->data;
      p=p->next;
   }
   cout<<endl;
   return OK;
}
