#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

// ͷ�巨����ڵ�
void insertAtHead(Node*& head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head->next;
    head->next = newNode;
}

int main() {
    // ����ͷ���
    Node* head = new Node(0);

    // ͷ�巨�����½ڵ�
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);

    // ��ӡ����
    Node* temp = head->next;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
