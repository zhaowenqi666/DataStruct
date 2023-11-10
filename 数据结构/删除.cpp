#include <iostream>

typedef int ElemType;
struct Lnode {
    ElemType data;
    struct Lnode* next;
};
typedef Lnode* LinkList;

// �����Ա�L�е�i������Ԫ��ɾ��
bool ListDelete(LinkList& L, int i, ElemType& e) {
    Lnode* p = L;
    int j = 0;

    // Ѱ�ҵ�i-1���ڵ�
    while (p->next && j < i - 1) {
        p = p->next;
        ++j;
    }

    // ���λ��i�����������Ȼ�������Ϊ��
    if (!(p->next) || j > i - 1) {
        return false; // ɾ��ʧ��
    }

    Lnode* q = p->next; // ָ���i���ڵ�
    p->next = q->next; // ɾ����i���ڵ�
    e = q->data; // ���汻ɾ���ڵ������
    delete q; // �ͷű�ɾ���ڵ���ڴ�

    return true; // ɾ���ɹ�
}

int main() {
    // ʾ���÷�
    LinkList L = new Lnode; // ����ͷ�ڵ�
    L->next = nullptr;

    // ����һЩ����
    for (int i = 1; i <= 5; ++i) {
        Lnode* newNode = new Lnode;
        newNode->data = i;
        newNode->next = L->next;
        L->next = newNode;
    }

    // ���ԭʼ��������
    Lnode* current = L->next;
    std::cout << "ԭʼ�������ݣ�";
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // ɾ����3���ڵ�
    ElemType deletedData;
    if (ListDelete(L, 3, deletedData)) {
        std::cout << "�ɹ�ɾ����3���ڵ㣬��ɾ���ڵ������Ϊ��" << deletedData << std::endl;

        // ���ɾ���ڵ�����������
        current = L->next;
        std::cout << "ɾ���ڵ����������ݣ�";
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "ɾ��ʧ�ܣ�λ�ó��������Ȼ�����Ϊ�ա�" << std::endl;
    }

    // �ͷ������ڴ�
    current = L->next;
    while (current) {
        Lnode* temp = current;
        current = current->next;
        delete temp;
    }
    delete L;

    return 0;
}
