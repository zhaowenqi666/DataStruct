#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// 创建新节点
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 头插法插入节点
void insertAtHead(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = (*head)->next;
    (*head)->next = newNode;
}

int main() {
    // 创建头结点
    struct Node* head = createNode(0);

    // 头插法插入新节点
    insertAtHead(&head, 1);
    insertAtHead(&head, 2);
    insertAtHead(&head, 3);

    // 打印链表
    struct Node* temp = head->next;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}