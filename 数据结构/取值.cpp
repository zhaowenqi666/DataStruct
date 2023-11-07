#include <iostream>
using namespace std;

typedef char ElemType;

struct Lnode {
    ElemType data;
    Lnode* next;
};

typedef Lnode* LinkList;

bool GetElem( LinkList L,  int i, ElemType& e) {
    if (i < 0) {
        cerr << "Out of range" << endl;
        return false;
    }
    Lnode* p = L->next;
    for (int j = 1; j < i + 1; ++j) {
        p = p->next;
        if (!p) {
            cerr << "Out of range" << endl;
            return false;
        }
    }
    e = p->data;
    return true;
}

int main() {
    LinkList myList = new Lnode;
    Lnode* newNode = new Lnode;
    newNode->data = 'A';
    newNode->next = NULL;
    myList->next = newNode;

    ElemType element;
    int index = 0;

    if (GetElem(myList, index, element)) {
        cout << "Element at position " << index << " is: " << element << endl;
    }
    else {
        cout << "Failed to get element." << endl;
    }

    return 0;
}
