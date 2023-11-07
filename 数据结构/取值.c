#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} LinkedList;

// ��ʼ����ͷ���ĵ�����
void initLinkedList(LinkedList* list) {
    list->head = (Node*)malloc(sizeof(Node));
    list->head->next = NULL;
}

// ������ĩβ����һ���½ڵ�
void append(LinkedList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    Node* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// ��ȡ��i���ڵ������
int getIthNode(LinkedList* list, int i) {
    Node* current = list->head->next;
    int currentIndex = 1;

    while (current != NULL) {
        if (currentIndex == i) {
            return current->data;
        }
        current = current->next;
        currentIndex++;
    }

    // ���i���������ȣ�����һ���ض�ֵ������-1����ʾδ�ҵ�
    return -1;
}

// �ͷ�������ڴ�
void freeLinkedList(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
}

int main() {
    LinkedList myList;
    initLinkedList(&myList);

    append(&myList, 10);
    append(&myList, 20);
    append(&myList, 30);
    append(&myList, 40);

    int i = 3; // ��ȡ��3���ڵ������
    int value = getIthNode(&myList, i);

    if (value != -1) {
        printf("The value of the %dth node is: %d\n", i, value);
    }
    else {
        printf("Node not found.\n");
    }

    freeLinkedList(&myList); // �ͷ������ڴ�

    return 0;
}
