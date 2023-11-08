#include <cstddef>
typedef int ElemType;
struct Lnode {
    ElemType data;
    struct Lnode* next;
};

typedef struct Lnode* LinkList;

//��ֵ���ҷ�������Ԫ�ص�ַ
int searchNode( LinkList L, ElemType e) {
    struct Lnode* temp = L->next;
    while (temp != NULL) {
        if (temp->data == e) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
//��ֵ���ҷ�������λ�����
int searchNodeAddress(LinkList L, ElemType e) {
    struct Lnode* p = L->next;
    int index = 1;
    while(p&&p->data!=e){
        p = p->next;
        index++;
    }
    if (p) return index;
    else
        return -1;
}