#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

struct Lnode {
    ElemType data;
    struct Lnode* next;
};

typedef struct Lnode* LinkList;

// �����Ա�L�е�i������Ԫ��ɾ��
int ListDelete(LinkList* L, int i, ElemType* e) {
    struct Lnode* p = *L;
    int j = 0;

    // Ѱ�ҵ�i-1���ڵ�
    while (p->next && j < i - 1) {
        p = p->next;
        ++j;
    }

    // ���λ��i�����������Ȼ�������Ϊ��
    if (!(p->next) || j > i - 1) {
        return 0; // ɾ��ʧ��
    }

    struct Lnode* q = p->next; // ָ���i���ڵ�
    p->next = q->next; // ɾ����i���ڵ�
    *e = q->data; // ���汻ɾ���ڵ������
    free(q); // �ͷű�ɾ���ڵ���ڴ�

    return 1; // ɾ���ɹ�
}

int main() {
    // ʾ���÷�
    LinkList L = (struct Lnode*)malloc(sizeof(struct Lnode)); // ����ͷ�ڵ�
    L->next = NULL;

    // ����һЩ����
    for (int i = 1; i <= 5; ++i) {
        struct Lnode* newNode = (struct Lnode*)malloc(sizeof(struct Lnode));
        newNode->data = i;
        newNode->next = L->next;
        L->next = newNode;
    }

    // ���ԭʼ��������
    struct Lnode* current = L->next;
    printf("ԭʼ�������ݣ�");
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // ɾ����3���ڵ�
    ElemType deletedData;
    if (ListDelete(&L, 3, &deletedData)) {
        printf("�ɹ�ɾ����3���ڵ㣬��ɾ���ڵ������Ϊ��%d\n", deletedData);

        // ���ɾ���ڵ�����������
        current = L->next;
        printf("ɾ���ڵ����������ݣ�");
        while (current) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
    else {
        printf("ɾ��ʧ�ܣ�λ�ó��������Ȼ�����Ϊ�ա�\n");
    }

    // �ͷ������ڴ�
    current = L->next;
    while (current) {
        struct Lnode* temp = current;
        current = current->next;
        free(temp);
    }
    free(L);

    return 0;
}
