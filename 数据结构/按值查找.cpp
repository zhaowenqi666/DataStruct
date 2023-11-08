
typedef int ElemType;
struct Node
{
	ElemType data;
	struct Node* next;
};
typedef Node* LinkList;
/// <summary>
/// 按值查找返回数据元素地址
/// </summary>
struct Node* findElem(LinkList L, ElemType& e) {
	Node* p = L->next;
	while (p&&p->data!=e)
	{
		p = p->next;
		return p;
	}
}
//按值查找返回数据位置序号
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