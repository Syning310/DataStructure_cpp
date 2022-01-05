//#include<iostream>
//using namespace std;
//
//
//
//
////双亲表示法
//
//const size_t g_maxSize = 100;
//
//typedef string ElemType;
//
//struct PTNote
//{
//	PTNote() 
//	{
//	    this->data = " ";
//	    this->parent = -1;
//	}
//	PTNote(ElemType d, int pare) : data(d), parent(pare) {  }
//	ElemType data;       //结点数据
//	int parent;          //双亲位置
//};
//
//
//struct PTree
//{
//	PTree()
//	{  
//		this->root = 0;
//		this->n = 0;
//	}
//	void CreatePTree();
//	PTNote nodes[g_maxSize];  
//	int root;    //根的位置
//	int n;       //结点的数目
//};
//
//
////顺序空间存储
//void PTree::CreatePTree()
//{
//	int num = 0;
//	cout << "输入结点数量： " ;
//	cin >>num;
//
//	string s;
//	int pa = 0;
//
//	while (num-- != 0)
//	{
//		cout << "输入第" << n << "个结点的data和双亲>: ";
//		cin >> s >> pa;
//		this->nodes[this->n] = PTNote(s, pa);
//		++this->n;    //更新树结点的数目
//	}
//
//}
//
//
//
//void test00(void)
//{
//	PTree pt;
//	pt.CreatePTree();
//
//
//
//}
//
//
//
//int main()
//{
//	test00();
//
//
//	return 0;
//}