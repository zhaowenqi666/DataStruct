#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

struct Lnode {
    ElemType data;
    struct Lnode* next;
};

typedef struct Lnode* LinkList;

// 将线性表L中第i个数据元素删除
int ListDelete(LinkList* L, int i, ElemType* e) {
    struct Lnode* p = *L;
    int j = 0;

    // 寻找第i-1个节点
    while (p->next && j < i - 1) {
        p = p->next;
        ++j;
    }

    // 如果位置i超出了链表长度或者链表为空
    if (!(p->next) || j > i - 1) {
        return 0; // 删除失败
    }

    struct Lnode* q = p->next; // 指向第i个节点
    p->next = q->next; // 删除第i个节点
    *e = q->data; // 保存被删除节点的数据
    free(q); // 释放被删除节点的内存

    return 1; // 删除成功
}

int main() {
    // 示例用法
    LinkList L = (struct Lnode*)malloc(sizeof(struct Lnode)); // 创建头节点
    L->next = NULL;

    // 插入一些数据
    for (int i = 1; i <= 5; ++i) {
        struct Lnode* newNode = (struct Lnode*)malloc(sizeof(struct Lnode));
        newNode->data = i;
        newNode->next = L->next;
        L->next = newNode;
    }

    // 输出原始链表内容
    struct Lnode* current = L->next;
    printf("原始链表内容：");
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // 删除第3个节点
    ElemType deletedData;
    if (ListDelete(&L, 3, &deletedData)) {
        printf("成功删除第3个节点，被删除节点的数据为：%d\n", deletedData);

        // 输出删除节点后的链表内容
        current = L->next;
        printf("删除节点后的链表内容：");
        while (current) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
    else {
        printf("删除失败，位置超出链表长度或链表为空。\n");
    }

    // 释放链表内存
    current = L->next;
    while (current) {
        struct Lnode* temp = current;
        current = current->next;
        free(temp);
    }
    free(L);

    return 0;
}
