//#include<iostream>
//using namespace std;
//
//
//
//
////˫�ױ�ʾ��
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
//	ElemType data;       //�������
//	int parent;          //˫��λ��
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
//	int root;    //����λ��
//	int n;       //������Ŀ
//};
//
//
////˳��ռ�洢
//void PTree::CreatePTree()
//{
//	int num = 0;
//	cout << "������������ " ;
//	cin >>num;
//
//	string s;
//	int pa = 0;
//
//	while (num-- != 0)
//	{
//		cout << "�����" << n << "������data��˫��>: ";
//		cin >> s >> pa;
//		this->nodes[this->n] = PTNote(s, pa);
//		++this->n;    //������������Ŀ
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