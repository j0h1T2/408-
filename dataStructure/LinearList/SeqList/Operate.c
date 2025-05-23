#include "operate.h"

//初始化
void InitList (SeqList *L) {
    L->data = (ElemType *)malloc(sizeof(ElemType) * MaxSize);
    L->length = 0;
}

//插入元素
bool ListInsert (SeqList *L, int i, ElemType e) {
    if (i < 1 || i > L->length + 1) 
        return false;
    if (L->length > MaxSize)
        return false;
    for (int j = L->length; j >= i; j--) 
        L->data[j] = L->data[j-1];
    L->data[i] = e;
    L->length++;
    return true;
}

//删除元素
bool ListDelete (SeqList *L, int i, ElemType *e) {
    if (i < 1 || i > L->length + 1) 
        return false;
    *e = L->data[i-1];  //将删除的值赋给e，从而可以使得被删元素可以通过参数返回
    for (int j = i; j < L->length; j++)
        L->data[j-1] = L->data[j];
    L->length--;
    return true;
}

//查找元素
int LocateElem (SeqList *L, ElemType e) {
    for (int i = 0; i < L->length; i++)
        if (L->data[i] == e) 
            return i+1;
    return 0;
}

