//#include<iostream>
//using namespace std;
//
//const size_t g_maxSize = 20;
//typedef string ElemType;
//
//struct CTNode
//{
//	CTNode(int ch = -1, CTNode *pn = nullptr) : child(ch), next(pn) {  }
//	int child;     //���ӽ����±�
//	CTNode *next;  //ָ����һ�����ӵ�ָ��
//};
//
//struct PTBox
//{
//	PTBox(ElemType da = " ", int pare = -1, CTNode* fir = nullptr) : data(da), parent(pare), first(fir){  }
//	ElemType data;   //��������
//	int parent;      //˫�׵��±�
//	CTNode *first;   //ָ���һ������
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
//			if (this->nodes[pi].first == nullptr)    //�����Ҷ�ӽ�㣬ֱ��continue
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
//			++pi;  //һά���飬�鿴��һ���±��first
//		}
//	
//
//	}
//
//	bool SetData(const int &index, const string &s);      //���ý��data�������±��data
//	bool SetParent(const int &index, const int &parent);  //����˫�ף������±��˫�׵��±�
//	bool SetChild(const int &index, const int &child);    //�����ӽ�㣬�����±���ӽ����±�
//	
//
//	PTBox nodes[g_maxSize];    //�������
//	int r;  //�����
//	int n;  //�����Ŀ
//};
//
//
//bool PTree::SetData(const int& index, const string& s)//���ý��data�������±��data
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
//bool PTree::SetParent(const int& index, const int& parent)  //����˫�ף������±��˫�׵��±�
//{
//	if (index >= g_maxSize || parent >= g_maxSize)
//		return false;
//
//	this->nodes[index].parent = parent;
//
//	SetChild(parent, index);   //���븸�ף������ӽ�㣬������˫�׹�ϵ֮��˳���������ӹ�ϵ
//
//	return true;
//}
//
//bool PTree::SetChild(const int& index, const int& child)    //�����ӽ�㣬�����±���ӽ����±�
//{
//	if (index >= g_maxSize || child >= g_maxSize)
//		return false;
//	if (index == -1)  //���ܸ�-1�����ӽ��
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
//void InitPTree(PTree& pc)  //��ʼ������
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
//	//���� A B C ����
//	pt.SetData(0, "A");
//	pt.SetData(1, "B");
//	pt.SetData(2, "C");
//
//	//�� B C ����˫�ף�������˳���������ӹ�ϵ
//	pt.SetParent(1, 0);   
//	pt.SetParent(2, 0);
//
//
//	//���� D E ����
//	pt.SetData(3, "D");
//	pt.SetData(4, "E");
//
//	//�� D E ����˫�ף�������˳���������ӹ�ϵ
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
