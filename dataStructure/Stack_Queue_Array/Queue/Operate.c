#include"Operate.h"
#include<stdio.h>

/*顺序存储队列*/
/*因为普通顺序存储的队列会出现假溢出的问题，故下文使用循环队列*/
//初始化
bool InitSqQueue(SqQueue *S){
    S->front = S->rear = 0;
    S->size = 0;
    return true;
}
//插入
bool InsertSqQueue(SqQueue *S, ElemType x){
    if (S->size == MaxSize) return false;
    S->data[S->rear] = x;
    S->rear = (S->rear + 1) % MaxSize;
    S->size++;
    return true;
}
//删除
bool DeSqQueue(SqQueue *S, ElemType *x){
    if (S->size == 0) return false;
    *x = S->data[S->front];
    S->front = (S->front + 1) % MaxSize;
    S->size--;
    return true;
}
//判断为空
bool IsSqempty(SqQueue *S){
    return S->size == 0;
}
//读队列头元素
bool Getfront(SqQueue *S, ElemType *x) {
    if (IsSqempty(S)) return false;
    *x = S->data[S->front];
    return true;
}

/*队列的链式存储*/
//初始化
void InitLiQueue (LinkQueue *Q) {
    Q->front = Q->rear = (LNode *)malloc(sizeof(LNode));
    Q->front->next = NULL;
}
//判队空
bool IsLiQEmpty (LinkQueue Q){
    if(Q.front == Q.rear) return true;
    return false;
}
//入队
void EnQueue (LinkQueue *Q, ElemType x){
    LNode *p = (LNode *)malloc(sizeof(LNode));
    p->data = x;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
}
//出队
bool DeQueue (LinkQueue *Q, ElemType *x){
    if (IsLiQEmpty(*Q)) return false;
    *x = Q->front->next->data;
    LNode *p = Q->front->next;
    if(p == Q->rear) Q->rear = Q->front;
    Q->front->next = p->next;
    free(p);
    return true;
}
//销毁队列
void DestroyQue(LinkQueue *Q){
    LNode *p = Q->front;
    //从头结点开始释放
    while(p) {
        LNode *temp =  p;
        p = p->next;
        free(temp);
    }
    Q->front = Q->rear = NULL;  //防止野指针
}