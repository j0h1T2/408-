#include "operate.h"
#include<stdlib.h>
//初始化
void InitList (SeqList *L) {
    L->data = (ElemType *)malloc(sizeof(ElemType) * InitSize);
    L->length = 0;
    L->MaxSize = InitSize;
}

//插入元素
bool ListInsert (SeqList *L, int i, ElemType e) {
    if (i < 1 || i > L->length + 1) 
        return false;
    if (L->length > L->MaxSize)
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

//取出第i个元素
ElemType GetElem (SeqList *L, int i) {
    return L->data[i-1];
}

//增加动态数组的长度
void IncreaseSize (SeqList *L, int len) {
    int *p = L->data;   //把顺序表赋给p
    L->data = (ElemType *)malloc((L->MaxSize+len) *sizeof(ElemType));   //为顺序表重新分配内存空间
    for (int i = 0; i < L->length; i++) {
        L->data[i] = p[i];  //重新代入
    }
    L->MaxSize += len;
    free(p);  //释放内存空间
}