//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct Node {
//    int data;
//    struct Node *next;
//} Node;
//
//typedef struct {
//    Node *head;
//} LinkedList;
//
//// 初始化带头结点的单链表
//void initLinkedList(LinkedList *list) {
//    list->head = (Node *)malloc(sizeof(Node));
//    list->head->next = NULL;
//}
//
//// 在链表末尾插入一个新节点
//void append(LinkedList *list, int value) {
//    Node *newNode = (Node *)malloc(sizeof(Node));
//    newNode->data = value;
//    newNode->next = NULL;
//
//    Node *current = list->head;
//    while (current->next != NULL) {
//        current = current->next;
//    }
//    current->next = newNode;
//}
//
//// 获取第i个节点的内容
//int getIthNode(LinkedList *list, int i) {
//    Node *current = list->head->next;
//    int currentIndex = 1;
//
//    while (current != NULL) {
//        if (currentIndex == i) {
//            return current->data;
//        }
//        current = current->next;
//        currentIndex++;
//    }
//
//    // 如果i超出链表长度，返回一个特定值（例如-1）表示未找到
//    return -1;
//}
//
//// 释放链表的内存
//void freeLinkedList(LinkedList *list) {
//    Node *current = list->head;
//    while (current != NULL) {
//        Node *temp = current;
//        current = current->next;
//        free(temp);
//    }
//    list->head = NULL;
//}
//
//int main() {
//    LinkedList myList;
//    initLinkedList(&myList);
//
//    append(&myList, 10);
//    append(&myList, 20);
//    append(&myList, 30);
//    append(&myList, 40);
//
//    int i = 3; // 获取第3个节点的内容
//    int value = getIthNode(&myList, i);
//    
//    if (value != -1) {
//        printf("The value of the %dth node is: %d\n", i, value);
//    } else {
//        printf("Node not found.\n");
//    }
//
//    freeLinkedList(&myList); // 释放链表内存
//
//    return 0;
//}
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

struct Lnode {
    ElemType data;
    struct Lnode* next;
};

typedef struct Lnode* LinkList;

int GetElem(LinkList L, int i, ElemType* e) {
    if (i < 0) {
        fprintf(stderr, "Out of range\n");
        return 0;
    }

    struct Lnode* p = L->next;
    for (int j = 1; j < i + 1; ++j) {
        if (!p) {
            fprintf(stderr, "Out of range\n");
            return 0;
        }
        p = p->next;
    }

    *e = p->data;
    return 1;
}

int main() {
    LinkList myList = (LinkList)malloc(sizeof(struct Lnode));
    struct Lnode* newNode = (struct Lnode*)malloc(sizeof(struct Lnode));
    ElemType element;
    int index = 0;

    if (!myList || !newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    newNode->data = 'A';
    newNode->next = NULL;
    myList->next = newNode;

    if (GetElem(myList, index, &element)) {
        printf("Element at position %d is: %c\n", index, element);
    }
    else {
        fprintf(stderr, "Failed to get element.\n");
    }

    free(newNode);
    free(myList);

    return 0;
}
