//#include<iostream>
//using namespace std;
//
//const size_t g_maxSize = 20;
//typedef string ElemType;
//
//struct CTNode
//{
//	CTNode(int ch = -1, CTNode *pn = nullptr) : child(ch), next(pn) {  }
//	int child;     //孩子结点的下标
//	CTNode *next;  //指向下一个孩子的指针
//};
//
//struct PTBox
//{
//	PTBox(ElemType da = " ", int pare = -1, CTNode* fir = nullptr) : data(da), parent(pare), first(fir){  }
//	ElemType data;   //结点的数据
//	int parent;      //双亲的下标
//	CTNode *first;   //指向第一个孩子
//};
//
//
//
//
//class PTree
//{
//public:
//	PTree() : r(0), n(0)  {  }
//	~PTree()
//	{
//		this->ClearPTree();
//	}
//	void ClearPTree()
//	{
//		int pi = r;
//
//		for (int i = 0; i < this->n; ++i)
//		{
//			if (this->nodes[pi].first == nullptr)    //如果是叶子结点，直接continue
//				continue;
//
//			CTNode* pd = this->nodes[pi].first;
//
//			while (this->nodes[pi].first->next != nullptr)
//			{
//				this->nodes[pi].first = this->nodes[pi].first->next;
//				delete pd;
//				pd = this->nodes[pi].first;
//			}
//			delete pd;
//			this->nodes[pi].first = nullptr;
//			++pi;  //一维数组，查看下一个下标的first
//		}
//	
//
//	}
//
//	bool SetData(const int &index, const string &s);      //设置结点data，传入下标和data
//	bool SetParent(const int &index, const int &parent);  //设置双亲，传入下标和双亲的下标
//	bool SetChild(const int &index, const int &child);    //设置子结点，传入下标和子结点的下标
//	
//
//	PTBox nodes[g_maxSize];    //结点数组
//	int r;  //根结点
//	int n;  //结点数目
//};
//
//
//bool PTree::SetData(const int& index, const string& s)//设置结点data，传入下标和data
//{
//	if (index >= g_maxSize || n >= g_maxSize)
//		return false;
//	if (index < 0)
//		return false;
//
//	this->nodes[index].data = s;
//	++n;
//	return true;
//}
//
//
//bool PTree::SetParent(const int& index, const int& parent)  //设置双亲，传入下标和双亲的下标
//{
//	if (index >= g_maxSize || parent >= g_maxSize)
//		return false;
//
//	this->nodes[index].parent = parent;
//
//	SetChild(parent, index);   //传入父亲，传入子结点，设置完双亲关系之后，顺便设置亲子关系
//
//	return true;
//}
//
//bool PTree::SetChild(const int& index, const int& child)    //设置子结点，传入下标和子结点的下标
//{
//	if (index >= g_maxSize || child >= g_maxSize)
//		return false;
//	if (index == -1)  //不能给-1设置子结点
//		return false;
//
//
//	CTNode *cs = new CTNode(child, this->nodes[index].first);
//	this->nodes[index].first = cs;
//	return true;
//}
//
//
//
//
//void InitPTree(PTree& pc)  //初始化空树
//{
//	for (int i = 0; i < g_maxSize; ++i)
//	{
//		pc.nodes[i].data = " ";
//		pc.nodes[i].parent = -1;
//		pc.nodes[i].first = nullptr;
//	}
//}
//
//
//
//
//void test00(void)
//{
//	PTree pt;
//	InitPTree(pt);
//
//	//插入 A B C 数据
//	pt.SetData(0, "A");
//	pt.SetData(1, "B");
//	pt.SetData(2, "C");
//
//	//给 B C 设置双亲，函数会顺便设置亲子关系
//	pt.SetParent(1, 0);   
//	pt.SetParent(2, 0);
//
//
//	//插入 D E 数据
//	pt.SetData(3, "D");
//	pt.SetData(4, "E");
//
//	//给 D E 设置双亲，函数会顺便设置亲子关系
//	pt.SetParent(3, 1);
//	pt.SetParent(4, 1);
//
//
//}
//
//int main()
//{
//	test00();
//
//	system("pause");
//	return 0;
//}
//
//
