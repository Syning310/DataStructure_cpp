#include<iostream>
using namespace std;

typedef string ElemType;

struct BiTNode
{
	BiTNode(const ElemType &d = " ", BiTNode* lp = nullptr, BiTNode* rp = nullptr) : data(d), lchild(lp), rchild(rp) {  }
	ElemType data;      //数据域
	BiTNode *lchild;    //左结点
	BiTNode *rchild;    //右结点
};

//遵照前序遍历的方式输入数据
void CreateT(BiTNode *&t)    //递归实现二叉树
{
	ElemType s;
	cin >> s;
	if (s == "/")    //如果输入为 /  则认为是空结点
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
	cout << "delete 释放结点： " << t->data << endl;
	delete t;
}





void visit(ElemType e, int l)
{
	cout << e << " 位于第 " << l << " 层" << endl;
}

		//遍历
void PreOrderT(BiTNode *&t, int	level)
{
	if (t != nullptr)
	{
		////前序遍历
		//visit(t->data, level);
		//PreOrderT(t->lchild, level + 1);
		//PreOrderT(t->rchild, level + 1);
		//

		////中序遍历
		//PreOrderT(t->lchild, level + 1);
		//visit(t->data, level);
		//PreOrderT(t->rchild, level + 1);
		

		//后序遍历
		PreOrderT(t->lchild, level + 1);
		PreOrderT(t->rchild, level + 1);
		visit(t->data, level);
		
		//顺序遍历暂时不会


	}
}

void test00(void)
{
	BiTNode *head = new BiTNode;

	CreateT(head);
	//输入 A B / D / / C E / / /   第一层A，第二层B C，第三层D E

	//输入A   B D H / / I / / E / /   C F / / G / / 

	//输入A   B D G / / H / / /   C E / I / / F / / 

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