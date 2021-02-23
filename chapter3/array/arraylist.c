/* arraylist.c -- 顺序存储结构代码 */
#include <stdio.h>
#include "../list.h"

Status GetElem(SqList L, int i, ElemType *e);
Status ListInsert(SqList *L, int i, ElemType e);
Status ListDelete(SqList *L, int i, ElemType *e);
Status SetElem(SqList *L, int i, ElemType e);

int main(void)
{
    SqList sqlist = {{1, 2, 3, 4, 5}, 5};
    ElemType *e;
    Status status = ERROR;
    SetElem(&sqlist, 1, 3);

    status = GetElem(sqlist, 1, e);

    printf("status: %d\n*e: %d\n", status, *e);
}

/**
 * @brief Get the Elem object
 * 
 * @param L 顺序线性表
 * @param i 指定返回元素序号
 * @param e 保存返回的第i个数据元素的值
 * @return ** Status 函数结果状态代码
 * 
 */
Status GetElem(SqList L, int i, ElemType *e)
{
    if (L.length == 0 || i < 1 || i > L.length)
    {
        return ERROR;
    }
    // e是指针变量，*e指代e指向的变量内存
    *e = L.data[i - 1];
    return OK;
}

/**
 * @brief 修改指定元素的值
 * 
 * @param L 
 * @param i 
 * @param e 
 * @return ** Status 
 */
Status SetElem(SqList *L, int i, ElemType e)
{
    if (L->length == 0) //表为空
    {
        return ERROR;
    }
    if (i < 1 || i > L->length) //i不在范围内
    {
        return ERROR;
    }
    L->data[i - 1] = e;
    return OK;
}

/**
 * @brief 插入元素
 * 
 * @param L 顺序表
 * @param i 指定插入位置
 * @param e 插入值
 * @return ** Status OK or ERROR 
 */
Status ListInsert(SqList *L, int i, ElemType e)
{
    // C90标准，变量声明放在函数头
    int k;
    if (L->length == MAXSIZE) //线性表已满
    {
        return ERROR;
    }
    if (i < 1 || i > L->length + 1) //i不在范围内
    {
        return ERROR;
    }
    if (i <= L->length) //若插入元素不在表尾(因为表尾可以直接插入)
    {
        // k指定为要移动的元素数组下标，元素向后平移
        for (k = L->length - 1; k >= i - 1; k--)
        {
            L->data[k + 1] = L->data[k];
        }
    }
    // 数组下标减一
    L->data[i - 1] = e; //新元素插入
    L->length++;
    return OK;
}

/**
 * @brief 删除指定序号元素
 * 
 * @param L 
 * @param i 
 * @param e 
 * @return ** Status 
 */
Status ListDelete(SqList *L, int i, ElemType *e)
{
    int k;
    if (L->length == 0) // 线性表为空
    {
        return ERROR;
    }
    if (i < 1 || i > L->length) // i不在范围
    {
        return ERROR;
    }
    *e = L->data[i - 1];
    if (i < L->length - 1) // i不在表尾
    {
        // 把循环的索引设置成要改变的那些数组元素，更容易计算个数
        for (k = i; k < L->length; k++)
        {
            L->data[k - 1] = L->data[k];
        }
    }
}