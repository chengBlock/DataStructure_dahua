#define MAXSIZE 20 /*存储空间初始分配量*/

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

typedef int ElemType;
typedef struct
{
    // 因为数组本身就是顺序存储结构，所以直接使用数组存储元素
    ElemType data[MAXSIZE]; // 数组存储数据元素
    int length;             // 线性表当前长度
} SqList;

// 线性表的单链表(一个指针域)存储结构
typedef struct Node
{

    ElemType data;     // 数据域
    struct Node *next; //指针域
} Node;                //如果不加Node，则提示{警告：空声明中指定存储类无用 [默认启用]}

typedef struct Node *LinkList; // 定义LinkList

// 线性表的双向链表存储结构(循环表)
typedef struct DulNode
{
    ElemType data;
    struct DulNode *prior; // 直接前驱指针
    struct DulNode *next;  // 直接后继指针
} DulNode, *DuLinkList;