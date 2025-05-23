#pragma once

#define MaxSize 50
typedef int ElemType;
#include<stdbool.h>

typedef struct {
    ElemType *data;
    int length;
}SeqList;

void InitList (SeqList *L);

bool ListInsert (SeqList *L, int i, ElemType e);

bool ListDelete (SeqList *L, int i);

int LocalElem (SeqList *L, ElemType e);