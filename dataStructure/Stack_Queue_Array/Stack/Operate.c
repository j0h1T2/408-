#include"Operate.h"
#include<stdio.h>
//初始化顺序栈
bool InitStack(SqStack *S){
    S->top = -1;
    return true;
}
//判断是否为空；
bool IsEmpty(SqStack S){
    // if (S.top == -1)
    // {
    //     return true;
    // }
    // return false;
    return S.top == -1;
}
//入栈
bool Push(SqStack *S, ElemType x){
    if(S->top == Maxsize-1) return false;
    (*S).data[++(*S).top] = x;
    return true;
}
//出栈
bool Pop(SqStack *S, ElemType *x){
    if(IsEmpty(*S)) return false;
    *x = (*S).data[(*S).top--];
    return true;
}
//读栈顶元素
bool GetTop(SqStack S, ElemType *x)
{
    if(IsEmpty(S)) return false;
    *x = S.data[S.top];
    return true;
}
//销毁栈
bool DestroyStack(SqStack *S){
    (*S).top = -1;
    return true;
}

/*共享栈*/
bool InitShareStack(ShareSqStack *S){
    S->top1 = -1;
    S->top2 = Maxsize;
    return true;
}
bool IsShare_StackEmpty(ShareSqStack S)
{
    return (S.top1 == -1 && S.top2 == Maxsize);
}
bool PushShare_Stack(ShareSqStack *S, int stackNum, ElemType x){
    if(S->top1 == S->top2-1) return false;
    if(stackNum == 1){
        S->data[++S->top1] = x;
    }
    if(stackNum == 2){
        S->data[--S->top2] = x;
    }
    return true;
}
bool PopShare_Stack(ShareSqStack *S, int stackNum, ElemType *x){
    if(stackNum == 1){
        if(S->top1 == -1) return false;
        *x = S->data[S->top1--];
    }
    else if(stackNum == 2){
        if (S->top2 == Maxsize) return false;
        *x = S->data[S->top2++];
    }
    return true;
}
bool GetTopShare_stack(ShareSqStack S, int stackNum, ElemType *x){
    if(stackNum == 1){
        if(S.top1 == -1) return false;
        *x = S.data[S.top1];
    }
    else if(stackNum == 2){
        if (S.top2 == Maxsize) return false;
        *x = S.data[S.top2];
    }
    return true;
}


/*链栈*/
bool InitLiStack(LiStack *S){  //此处由于LiStack带有*，再加上一个*，使得*S指向结构体的内部
    *S = NULL;
    return true;
}
bool IsLiStackEmpty(LiStack S){
    return S == NULL;  //直接指向结构体，不能使用*S，会造成访问非法内存
}
bool PushLiStack(LiStack *S, ElemType x){
    StackNode *s = (StackNode *)malloc(sizeof(StackNode));
    s->data = x;
    s->next = *S;
    *S = s;  //更新栈顶指针
    return true;
}
bool PopLiStack(LiStack *S, ElemType *x){
    if (*S == NULL) return false;
    StackNode *p = *S;
    *S = (*S)->next;
    *x = p->data;
    free(p);
    return true;
}
bool GetTopLiStack(LiStack S, ElemType *x){
    if (IsLiStackEmpty(S)) return false;
    *x = S->data;
    return true;
}