#pragma once
#define  MAXLISTSIZE  100 //预设的存储空间最大容量 

# define TRUE 1
# define FALSE 0
# define OK 1
# define ERROR 0
# define INFEASIBLE -1
# define OVERFLOW -2

typedef int Status;
#include<stdio.h>
#include<stdlib.h>

# include<malloc.h>
typedef int  ElemType;
typedef struct {
    ElemType* elem;
    int length; 
    int listsize;
} SqList;


 Status InitList(SqList& L, int maxsize);  //　构造一个最大存储容量为 maxsize 的空的顺序表 L
void DestroyList(SqList& L);

Status InitList(SqList &L, int maxsize) {

    L.elem = (ElemType*)malloc(maxsize * sizeof(ElemType));
    if (!L.elem)
        exit(OVERFLOW);
    L.length = 0;
    L.listsize = maxsize;
    return OK;
}

void printflist(SqList &L) {
    int i;
    if (ListEmpty(L))
        printf("数组为空");


    for (int i = 0; i < 10; i++) {
        printf("%d", L.elem[i]);
    }



}

int Desteroy(SqList& L) {

    if (!L.elem) {
        return ERROR;
    }


    free(L.elem);

}
Status ListEmpty(SqList& L) {
    if (!L.elem) {

        return ERROR; 
    }
    if (L.length == 0)
        return TRUE;
    else
        return FALSE;



}//从顺序表L中查找第i个元素，由参数e返回其元素的值
Status GetElem(SqList L, int i, int& e)
{
    if (!L.elem) {
        return ERROR;

    }


    if (i<1 || i>L.length - 1) {
        return ERROR;
    }
    int* q = L.elem;
    e = *(q - 1 + i);
    return OK;
}

//在顺序表L中查找元素e的位置，不存在则返回0
int LocateElem(SqList L, int e)
{
    if (!L.elem) {
        return 0;
    }
    int i = 1;
    int* p= (L.elem);
    while (i < L.length && *p++ != e) {

        ++i;

    }
    if (i < L.length) {


        return i;
    }
    return 0;
}
Status Insertlist(SqList L,int i,int e)
{
    if (!L.elem) {
        return ERROR;

    }
    if (i<1 || i>L.length - 1) {

        return ERROR;

    }
    int j;
    for(j = L.length - 1;j>i;j--)
    {
        L.elem[j] = L.elem[j - 1];
    }
    L.elem[i] = e;
    L.length++;

}
Status Detelelist(SqList L, int i, int e) {
    if (i<1 || i>L.length - 1) {
        return ERROR;

    }
    e=L.elem[i-1];
    for (int j = i; j < L.length-1; j++)
    {
        L.elem[j] = L.elem[j + 1];

    }
    L.length--;

    return OK;
}
Status Createlist(SqList &L,int n) {
    L.length = 0;



    for (int i = 0; i < n; i++) {
        L.length++;
        scanf_s("%d", &L.elem[i]);
    }

    return OK;

}




