#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

// 头插法插入节点
void insertAtHead(Node*& head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head->next;
    head->next = newNode;
}

int main() {
    // 创建头结点
    Node* head = new Node(0);

    // 头插法插入新节点
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);

    // 打印链表
    Node* temp = head->next;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
