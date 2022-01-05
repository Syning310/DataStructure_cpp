#include<iostream>
using namespace std;



typedef string ElemType;

const size_t g_maxSize = 40;

struct GraVexLst
{
	int tailVex;           //存放弧尾的下标
	int headVex;           //存放弧头的下标
	GraVexLst *headLink;   //指向下一个入度的结点
	GraVexLst *tailLink;   //指向下一个出度的结点
};

struct GraNode
{
	ElemType data;          //结点存放的数据
	GraVexLst *firstOut;    //指向第一个出度的结点
	GraVexLst* firstIn;     //指向第一个入度的结点
};

struct CrossList
{
	CrossList() : numVex(0), numArc(0) {  }

	void Create();     //创造函数，传入顶点数，传入边数
	void SetReative(); //设置弧头弧尾关系



	GraNode nodes[g_maxSize];    //存放顶点的数组

	int numVex;    //当前顶点数
	int numArc;    //当前边数
};

void CrossList::Create()
{
	int nv = 0;
	int nb = 0;
	cout << "输入顶点数和边数 >: ";     //4  5
	cin >> nv >> nb;

	ElemType s;
	for (int i = 0; i < nv; ++i)
	{
		cout << "输入第" << i + 1 << "个顶点的data >: ";
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
		cout << "输入弧尾、弧头下标，有偶序<Vx, Vy> : ";
		cin >> x >> y;
		ns = new GraVexLst;  //在堆区开辟空间
		ns->tailVex = x;     //弧尾下标
		ns->headVex = y;     //弧头下标

		ns->tailLink = this->nodes[x].firstOut;   //把弧尾的指向结点给它

		ns->headLink = this->nodes[y].firstIn;    //把弧头的指向结点给他

		this->nodes[x].firstOut = ns;             //指向出度的结点地址

		this->nodes[y].firstIn = ns;              //指向入度的结点地址
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