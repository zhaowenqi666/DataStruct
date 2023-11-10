#include <iostream>

typedef int ElemType;
struct Lnode {
    ElemType data;
    struct Lnode* next;
};
typedef Lnode* LinkList;

// 将线性表L中第i个数据元素删除
bool ListDelete(LinkList& L, int i, ElemType& e) {
    Lnode* p = L;
    int j = 0;

    // 寻找第i-1个节点
    while (p->next && j < i - 1) {
        p = p->next;
        ++j;
    }

    // 如果位置i超出了链表长度或者链表为空
    if (!(p->next) || j > i - 1) {
        return false; // 删除失败
    }

    Lnode* q = p->next; // 指向第i个节点
    p->next = q->next; // 删除第i个节点
    e = q->data; // 保存被删除节点的数据
    delete q; // 释放被删除节点的内存

    return true; // 删除成功
}

int main() {
    // 示例用法
    LinkList L = new Lnode; // 创建头节点
    L->next = nullptr;

    // 插入一些数据
    for (int i = 1; i <= 5; ++i) {
        Lnode* newNode = new Lnode;
        newNode->data = i;
        newNode->next = L->next;
        L->next = newNode;
    }

    // 输出原始链表内容
    Lnode* current = L->next;
    std::cout << "原始链表内容：";
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // 删除第3个节点
    ElemType deletedData;
    if (ListDelete(L, 3, deletedData)) {
        std::cout << "成功删除第3个节点，被删除节点的数据为：" << deletedData << std::endl;

        // 输出删除节点后的链表内容
        current = L->next;
        std::cout << "删除节点后的链表内容：";
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "删除失败，位置超出链表长度或链表为空。" << std::endl;
    }

    // 释放链表内存
    current = L->next;
    while (current) {
        Lnode* temp = current;
        current = current->next;
        delete temp;
    }
    delete L;

    return 0;
}
