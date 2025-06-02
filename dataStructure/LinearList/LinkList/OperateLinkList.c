#include "OperateLinkList.h"
#include <stdio.h>
//带头结点的初始化
bool InitList(LinkList *L) //C语言不支持在函数定义中使用&L，应该用&
{
    *L = (LNode *)malloc(sizeof(LNode));
    (*L)->next = NULL;
    return true;
}
//不带头结点
bool InitListWithOutHead(LinkList *L)
{
    *L = NULL;
    return true;
}
//求表长
int Length(LinkList L)
{
    int len = 0;
    LNode *p = L;
    if(p == NULL) return 0;
    while(p->next != NULL) {
        p = p->next;
        len++;
    }
    return len;
}
//按序号查找
LNode *GetElem(LinkList L, int i) {
    LNode *p = L;
    int j = 0;  //记录当前节点，头结点是0节点
    while(p != NULL && j < i) {
        p = p->next;
        j++;
    }
    return p;
}
//按值查找
LNode *LocatElem(LinkList L, Elemtype E) {
    LNode *p = L->next;
    while (p != NULL && p->data != E) {
        p = p->next;
    }
    return p;
}
//插入节点
bool ListInsert(LinkList L, int i, Elemtype e) {
    LNode *p = L;
    int j = 0;
    while(p->next != NULL && j < i-1) {
        p = p->next;
        j++;
    }
    if(p == NULL)
    {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
//前插操作
bool ListAheadInsert(LinkList L, int i, Elemtype e){
    LNode *p = L;
    int j = 0;
    while(p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL) return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}
//删除节点
bool ListDelete(LinkList L, int i, Elemtype *e) {
    if (L == NULL || L->next == NULL) return false;
    LNode *p = L;
    int j = 0;
    while(p->next != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p->next == NULL || j == i-1) return false;
    LNode *q = p->next;
    p->next = q->next;
    *e = q->data; //将删除节点元素数据传出
    free(q);
    return true;
}
//删除特定节点*p
bool ListDeleteSpeciaP(LinkList L, LNode *p) {
    if (L == NULL || p == NULL) return false;
    // 如果 p 是头结点，不让删
    if (p == L) return false;
    if (p->next == NULL) {
        LNode *s = L->next;
        while(s->next != p) s = s->next;
        s->next = NULL;
        free(p);
        return true;
    }
    LNode *q = p->next;
    p->data = p->next->data;
    p->next = q->next;
    free(q);
    return true;
}
//头插法,此处并不对链表进行初始化，真实调用时需要先初始化，再调用此函数
LinkList List_headInsert(LinkList L, int len) {
    LNode *s;
    int x;
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    for (int i = 0; i < len; i++) {
        s = (LNode *)malloc(sizeof(LNode));
        scanf("%d", &x);
        s->data = x;
        s->next =L->next;
        L->next = s;
    }
    return L;
}
//尾插法
LinkList List_TailInsert(LinkList L, int len) {
    int x;
    L = (LNode *)malloc(sizeof(LNode));
    LNode *s, *r = L;
    for(int i = 0; i < len; i++) {
        s = (LNode *)malloc(sizeof(LNode));
        scanf("%d", &x);
        s->data = x;
        s->next = NULL;
        r->next = s;
        r = s;
    }
    r->next = NULL;
    return L;
}


//双链表初始化
bool InitDList(DLinkList *L){
    *L = (DNode *)malloc(sizeof(DNode));
    (*L)->next =NULL;
}
//双链表插入
bool DListInsert(DLinkList *L, int i, Elemtype e) {
    if (L == NULL || i < 0) return false;
    DNode *s;
    int j = 0;
    DNode *p;
    p = (*L)->next;
    while(p->next == NULL && j < i-1) {
        p = p->next;
        j++;
    }
    if(p->next ==NULL || j == i-1) return false;
    s = (DNode *)malloc(sizeof(DNode));
    s->data = e;
    s->next = p->next;
    s->prior = p;
    p->next->prior = s;
    p->next = s;
    return true;
}
//双链表删除
bool DLinkDelete(DLinkList *L, int i, Elemtype *e) {
    DNode *p = *L;
    int j = 0;
    while (p->next != NULL && j < i-1)
    {
        p = p->next;
        j++;
    }
    if (p->next == NULL || j > i-1) return false;
    DNode *q = p->next;
    p->next = q->next;
    if(q->next != NULL)
        q->next->prior = p;
    *e = q->data;
    free(q);
    return true;
}


bool InitCList(LinkList *L){
    *L = (LNode *)malloc(sizeof(LNode));
    (*L)->next = *L;
    return true;
}

bool InitDDList(DLinkList *L) {
    *L = (DNode *)malloc(sizeof(DNode));
    (*L)->next = *L;
    (*L)->prior = *L;
    return true;
}
