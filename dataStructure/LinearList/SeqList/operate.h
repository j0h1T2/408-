#pragma once

#define InitSize 50
typedef int ElemType;
#include<stdbool.h>

typedef struct {
    ElemType *data;
    int length;
    int MaxSize;
}SeqList;

void InitList (SeqList *L);

bool ListInsert (SeqList *L, int i, ElemType e);

bool ListDelete (SeqList *L, int i, ElemType *e);

int LocalElem (SeqList *L, ElemType e);

ElemType GetElem (SeqList *L, int i);

void IncreaseSize (SeqList *L, int len);