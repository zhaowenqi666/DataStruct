
typedef int ElemType;
struct Node
{
	ElemType data;
	struct Node* next;
};
typedef Node* LinkList;
/// <summary>
/// ��ֵ���ҷ�������Ԫ�ص�ַ
/// </summary>
struct Node* findElem(LinkList L, ElemType& e) {
	Node* p = L->next;
	while (p&&p->data!=e)
	{
		p = p->next;
		return p;
	}
}
//��ֵ���ҷ�������λ�����
int findElem1(LinkList L, ElemType e) {
	Node* p = L->next;
	int j = 1;
	while (p && p->data != e) {
		p = p->next;
		j++;
	}
	if (p) return j;
	else
	{
		return -1;
	}
}