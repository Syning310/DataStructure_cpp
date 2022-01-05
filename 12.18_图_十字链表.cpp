#include<iostream>
using namespace std;



typedef string ElemType;

const size_t g_maxSize = 40;

struct GraVexLst
{
	int tailVex;           //��Ż�β���±�
	int headVex;           //��Ż�ͷ���±�
	GraVexLst *headLink;   //ָ����һ����ȵĽ��
	GraVexLst *tailLink;   //ָ����һ�����ȵĽ��
};

struct GraNode
{
	ElemType data;          //����ŵ�����
	GraVexLst *firstOut;    //ָ���һ�����ȵĽ��
	GraVexLst* firstIn;     //ָ���һ����ȵĽ��
};

struct CrossList
{
	CrossList() : numVex(0), numArc(0) {  }

	void Create();     //���캯�������붥�������������
	void SetReative(); //���û�ͷ��β��ϵ



	GraNode nodes[g_maxSize];    //��Ŷ��������

	int numVex;    //��ǰ������
	int numArc;    //��ǰ����
};

void CrossList::Create()
{
	int nv = 0;
	int nb = 0;
	cout << "���붥�����ͱ��� >: ";     //4  5
	cin >> nv >> nb;

	ElemType s;
	for (int i = 0; i < nv; ++i)
	{
		cout << "�����" << i + 1 << "�������data >: ";
		cin >> s;
		this->nodes[i].data = s;
		this->nodes[i].firstIn = nullptr;
		this->nodes[i].firstOut = nullptr;
	}
	this->numVex = nv;
	this->numArc = nb;
}

void CrossList::SetReative()
{
	int x = 0;
	int y = 0;
	GraVexLst *ns = nullptr;

	for (int i = 0; i < numArc; ++i)
	{
		cout << "���뻡β����ͷ�±꣬��ż��<Vx, Vy> : ";
		cin >> x >> y;
		ns = new GraVexLst;  //�ڶ������ٿռ�
		ns->tailVex = x;     //��β�±�
		ns->headVex = y;     //��ͷ�±�

		ns->tailLink = this->nodes[x].firstOut;   //�ѻ�β��ָ�������

		ns->headLink = this->nodes[y].firstIn;    //�ѻ�ͷ��ָ�������

		this->nodes[x].firstOut = ns;             //ָ����ȵĽ���ַ

		this->nodes[y].firstIn = ns;              //ָ����ȵĽ���ַ
	}

}


/*
    v0  v1  v2  v3  
  0 - 3
  1 - 0
  2 - 0
  2 - 1
  1 - 2
*/


int main()
{
	CrossList cl;
	cl.Create();
	cl.SetReative();

	


	system("pause");
	return 0;
}