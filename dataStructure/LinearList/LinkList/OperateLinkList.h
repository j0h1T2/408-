#pragma once

typedef int Elemtype;
#include<stdbool.h>

typedef struct LNode
{
    Elemtype data;
    struct LNode *next;
}LNode, *LinkList;

typedef struct DNode
{
    Elemtype data;
    struct DNode *prior, *next;
}DNode, *DLinkList;



//带头结点的初始化
bool InitList(LinkList *L); //C语言不支持在函数定义中使用&L，应该用&
//不带头结点
bool InitListWithOutHead(LinkList *L);
//求表长
int Length(LinkList L);
//按序号查找
LNode *GetElem(LinkList *L, int i);
//按值查找
LNode *LocatElem(LinkList *L, Elemtype E);
//插入节点
bool ListInsert(LinkList *L, int i, Elemtype e);
//前插操作
bool ListAheadInsert(LinkList *L, int i, Elemtype e);
//删除节点
bool ListDelete(LinkList *L, int i, Elemtype *e);
//删除特定节点*p
bool ListDeleteSpeciaP(LinkList *L, LNode *p);
//头插法
LinkList List_headInsert(LinkList *L);
//尾插法
LinkList List_TailInsert(LinkList *L);


//双链表初始化
bool InitDList(DLinkList *L);
//双链表插入
bool DListInsert(DLinkList *L, int i, Elemtype e);
//双链表删除
bool DLinkDelete(DLinkList *L, int i, Elemtype *e);


bool InitCList(LinkList *L);

bool InitDList(DLinkList *L);


