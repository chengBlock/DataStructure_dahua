/**linklist.c -- 单链表的存储结构**/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../list.h"

Status GetElem(LinkList L, int i, ElemType *e);
Status ListInsert(LinkList *L, int i, ElemType e);
Status ListDelete(LinkList *L, int i, ElemType *e);
void CreateListTail(LinkList *L, int n);

int main(void)
{
    LinkList L;
    int i, data, n = 10;
    CreateListTail(&L, n);
    for (i = 0; i < n; i++)
    {
        GetElem(L, n, &data);
        printf("%d\n", data);
    }
    return 0;
}

// LinkList是{struct Node *}类型，指向Node节点
Status GetElem(LinkList L, int i, ElemType *e)
{
    int j;
    LinkList p;
    // L指向头结点
    p = L->next; // p指向链表L的第一个节点
    j = 1;
    while (p && j < i)
    {
        p = p->next; //指向下一节点
        j++;
    }
    if (!p || j > i)
    {
        return ERROR;
    }
    *e = p->data;
    return OK;
}

// 头指针具有标识作用,所以常用头指针冠以链表的名字

// 先决条件:声明一个节点p指向链表第一个节点(这里链表有头结点)

// 反正记得一点,只要是需要改变值的就用指针类型参数
Status ListInsert(LinkList *L, int i, ElemType e)
{
    int j;
    LinkList p, s;
    p = *L;
    j = 1;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i) //第i个元素不存在
    {
        return ERROR;
    }
    s = (LinkList)malloc(sizeof(Node)); //生成新节点
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

// 需要改变原值的一定要使用指针类型参数,否则形参会新建内存空间存放参数
Status ListDelete(LinkList *L, int i, ElemType *e)
{
    int j;
    LinkList p, q;
    p = *L;
    j = 1;
    while (p->next && j < i)
    {
        p = p->next;
        j++;
    }
    if (!(p->next) || j > i)
    {
        return ERROR; //第i个元素不存在
    }
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q); //回收节点
    return OK;
}

// L是指整个单链表
// r是指向尾节点的变量
// 随机产生n个元素的值,建立代表头节点的单链线性表(尾插法)
void CreateListTail(LinkList *L, int n)
{
    LinkList p, r;
    int i;
    srand(time(0));                      //初始化随机数种子
    *L = (LinkList)malloc(sizeof(Node)); //头结点,*L标识整个线性表
    r = *L;                              //r指向尾部的节点
    for (i = 0; i < n; i++)
    {
        p = (LinkList)malloc(sizeof(Node)); //生成新节点
        p->data = rand() % 100 + i;
        r->next = p;
        r = p; //将当前的新节点定义为表尾终端节点
    }
    r->next = NULL;
}

// 将L重置为空表
Status ClearList(LinkList *L)
{
    // 从前往后释放
    LinkList p, q;
    // p指向第一个节点
    p = (*L)->next;
    while (p)
    {
        // q往后移动
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL; //头结点指针域为空
    return OK;
}