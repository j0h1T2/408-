#pragma once
#include<stdbool.h>
#include"LinearList/LinkList/OperateLinkList.h"

/*队列的顺序存储*/
#define MaxSize 50
typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int front, rear, size;
}SqQueue;

//初始化
bool InitSqQueue(SqQueue *S);
//插入
bool InsertSqQueue(SqQueue *S, ElemType x);
//删除
bool DeSqQueue(SqQueue *S, ElemType *x);
//判断为空
bool IsSqempty(SqQueue *S);  //此处和下方传指针可以避免在调用函数时再次复制一个队列，直接取地址更节省空间
//读队列头元素
bool Getfront(SqQueue *S, ElemType *x);

/*队列的链式存储*/
typedef struct {
    LNode *front, *rear;
}LinkQueue;
//初始化
void InitLiQueue (LinkQueue *Q);
//判队空
bool IsLiQEmpty (LinkQueue Q);
//入队
void EnQueue (LinkQueue *Q, ElemType x);
//出队
bool DeQueue (LinkQueue *Q, ElemType *x);
//销毁队列
void DestroyQue(LinkQueue *Q);
