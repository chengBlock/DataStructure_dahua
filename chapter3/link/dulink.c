// dulink.c -- 循环表
#include <stdio.h>
#include "../list.h"

Status ListInsert(DuLinkList *L, int i, ElemType e);
Status ListDelete(DuLinkList *L, int i, ElemType *e);

int main(void)
{
}

Status ListInsert(DuLinkList *L, int i, ElemType e)
{
    int j;
    DuLinkList p, s;
    p = *L;
    j = 1;
    while (p && j < i)
    {
        p = p->next;
        ++j;
        // 还要判断循环
    }
    if (!p || j > 1)
    {
        return ERROR;
    }
    s = (DuLinkList)malloc(sizeof(DulNode));
    s->data = e;

    s->prior = p;
    s->next = p->next;
    p->next->prior = s;
    p->next = s;

    return OK;
}

Status ListDelete(DuLinkList *L, int i, ElemType *e)
{
    DuLinkList p,q;

    // 假如p就是要删除的节点
    p = *L;

    q = p;
    p->prior->next = p->next;
    p->next->prior = p->prior;

    free(q);

    return OK;
}