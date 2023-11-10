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
//在L中第i个元素之前插入数据元素e
bool insertFront(Node* L, int i, int e) {
    Node* p = L; int j = 0;
    while (p && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1) return false;
    Node* s = new Node(e);
    s->data = e;
    s->next = p->next;
    p->next = s;
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
