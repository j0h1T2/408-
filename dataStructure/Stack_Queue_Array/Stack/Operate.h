#pragma once
#include<stdbool.h>
#define Maxsize 50

typedef int ElemType;
//定义顺序栈结构体
typedef struct {
    ElemType data[Maxsize];
    int top;
}SqStack;

//定义共享栈结构体
typedef struct 
{
    ElemType data[Maxsize];
    int top1, top2;
}ShareSqStack;

//定义链栈
typedef struct StackNode{
    ElemType data;
    struct LiStack *next;
}StackNode, *LiStack;

/*
顺序栈
*/
//初始化顺序栈
bool InitStack(SqStack *S);
//判断是否为空；
bool IsEmpty(SqStack S);
//入栈
bool Push(SqStack *S, ElemType x);
//出栈
bool Pop(SqStack *S, ElemType *x);
//读栈顶元素
bool GetTop(SqStack S, ElemType *x);
//销毁栈
bool DestroyStack(SqStack *S);


/*共享栈*/
bool InitShareStack(ShareSqStack *S);
bool IsShare_StackEmpty(ShareSqStack S);
bool PushShare_Stack(ShareSqStack *S, int stackNum, ElemType x);
bool PopShare_Stack(ShareSqStack *S, int stackNum, ElemType *x);
bool GetTopShare_stack(ShareSqStack S, int stackNum, ElemType *x);

/*链栈*/
bool InitLiStack(LiStack *S);
bool IsLiStackEmpty(LiStack S);
bool PushLiStack(LiStack *S, ElemType x);
bool PopLiStack(LiStack *S, ElemType *x);
bool GetTopLiStack(LiStack S, ElemType *x);