#include"sqlist.h"
int main() {

    SqList *head;
    int n,e,k;
    scanf_s("%d", &n);
    InitList(*head, 100);
    Createlist(*head,10);
    printflist(*head);
    printf("请插入元素：");
    scanf_s("%d", &e);
    printflist(*head);
    if(LocateElem(*head, e))
    Insertlist(*head,  2, e);
      printf("请查找第k个元素：");
    scanf_s("%d", &k);
    int h;
    if (GetElem(*head, k, h)) {
        printf("查找到了%d", h);
    }
    else {
        printf("未查找到");
    }
    int p;
    printf("请删除第几位元素：");
    scanf_s("%d", &p);
    if (LocateElem(*head, p)) {
        Detelelist(*head, p, p);

    }



}
