#include<iostream>
using namespace std;

typedef string ElemType;

struct BiTNode
{
	BiTNode(const ElemType &d = " ", BiTNode* lp = nullptr, BiTNode* rp = nullptr) : data(d), lchild(lp), rchild(rp) {  }
	ElemType data;      //������
	BiTNode *lchild;    //����
	BiTNode *rchild;    //�ҽ��
};

//����ǰ������ķ�ʽ��������
void CreateT(BiTNode *&t)    //�ݹ�ʵ�ֶ�����
{
	ElemType s;
	cin >> s;
	if (s == "/")    //�������Ϊ /  ����Ϊ�ǿս��
		return;

	t = new BiTNode(s);
	CreateT(t->lchild);
	CreateT(t->rchild);
}


void ClearBT(BiTNode *&t)
{
	if (t == nullptr)
		return;

	ClearBT(t->lchild);
	ClearBT(t->rchild);
	cout << "delete �ͷŽ�㣺 " << t->data << endl;
	delete t;
}





void visit(ElemType e, int l)
{
	cout << e << " λ�ڵ� " << l << " ��" << endl;
}

		//����
void PreOrderT(BiTNode *&t, int	level)
{
	if (t != nullptr)
	{
		////ǰ�����
		//visit(t->data, level);
		//PreOrderT(t->lchild, level + 1);
		//PreOrderT(t->rchild, level + 1);
		//

		////�������
		//PreOrderT(t->lchild, level + 1);
		//visit(t->data, level);
		//PreOrderT(t->rchild, level + 1);
		

		//�������
		PreOrderT(t->lchild, level + 1);
		PreOrderT(t->rchild, level + 1);
		visit(t->data, level);
		
		//˳�������ʱ����


	}
}

void test00(void)
{
	BiTNode *head = new BiTNode;

	CreateT(head);
	//���� A B / D / / C E / / /   ��һ��A���ڶ���B C��������D E

	//����A   B D H / / I / / E / /   C F / / G / / 

	//����A   B D G / / H / / /   C E / I / / F / / 

	int level = 1;

	PreOrderT(head, level);
	
	ClearBT(head);

}

int main()
{
	test00();



	system("pause");
	return 0;
}