#include<iostream>
using namespace std;



const size_t g_MaxSize = 10;

typedef string ElemType;



//创建邻接表

struct GraNode   //链表
{
	int ArcHead;    //存储连接顶点的对应下标
	GraNode* next;  //指向顶点下一个连接的对应顶点的下标
};

struct VexNode  //顶点结点
{
	ElemType data;
	GraNode* first;
};

struct GraTable
{
	GraTable() : numVex(0), numArc(0)
	{
		for (int i = 0; i < g_MaxSize; ++i)
		{
			this->nodes[i].data = " ";
			this->nodes[i].first = nullptr;
		}
	}
	void Create_forward();     //创建有向图
	void Create_Nofd();        //创建无向图


	VexNode nodes[g_MaxSize];    //顶点数组
	int numVex;
	int numArc;
};

void GraTable::Create_forward()   //创建有向图
{
	int nV = 0;
	int nA = 0;
	cout << "输入顶点数和边数>: ";
	cin >> nV >> nA;

	this->numVex = nV;
	this->numArc = nA;

	//创建顶点
	string s;
	for (int i = 0; i < nV; ++i)
	{
		cout << "输入第" << i << "个顶点的data >: ";
		cin >> s;
		this->nodes[i].data = s;
	}


	//创建边

	int x = 0;
	int y = 0;
	GraNode* e = nullptr;    //创建一个链结点
	for (int i = 0; i < nA; ++i)
	{
		cout << "输入第" << i + 1 << "条边的序<Vx, Vj>的下标 >: ";
		cin >> x >> y;

		e = new GraNode;
		e->ArcHead = y;     //把弧头的下标赋值给结点
		e->next = nullptr;

		//把结点往链表后面接，而不是头插
		if (this->nodes[x].first != nullptr)
		{
			GraNode* tail = this->nodes[x].first;
			while (tail->next != nullptr)
			{
				tail = tail->next;
			}
			tail->next = e;    //找出链表中最后一个结点，然后指向新的边e

		}
		else
		{
			this->nodes[x].first = e;
		}

	}

}

void GraTable::Create_Nofd()        //创建无向图
{
	int nV = 0;
	int nA = 0;
	cout << "输入顶点数和边数>: ";
	cin >> nV >> nA;

	this->numVex = nV;
	this->numArc = nA;


	//创建顶点
	string s;
	for (int i = 0; i < nV; ++i)
	{
		cout << "输入第" << i << "个顶点的data >: ";
		cin >> s;
		this->nodes[i].data = s;
	}

	//创建边
	int x = 0;
	int y = 0;
	GraNode* e = nullptr;    //创建一个链结点
	for (int i = 0; i < nA; ++i)
	{
		cout << "输入第" << i + 1 << "条边的序(Vx, Vj)的下标 >: ";
		cin >> x >> y;

		e = new GraNode;
		e->ArcHead = y;
		e->next = nullptr;

		if (this->nodes[x].first != nullptr)
		{
			GraNode* tail = this->nodes[x].first;
			while (tail->next != nullptr)
			{
				tail = tail->next;
			}
			tail->next = e;
		}
		else
		{
			this->nodes[x].first = e;
		}


		//因为是无向边，所以是两个顶点都要存放指向
		e = new GraNode;
		e->ArcHead = x;
		e->next = nullptr;

		if (this->nodes[y].first != nullptr)
		{
			GraNode* tail = this->nodes[y].first;
			while (tail->next != nullptr)
			{
				tail = tail->next;
			}
			tail->next = e;
		}
		else
		{
			this->nodes[y].first = e;
		}

	}

}



int visit[g_MaxSize] = { 0 };
//广度优先遍历
void BFSL(GraTable gc, int v)
{
	int n = gc.numVex;
	if (v >= n || v < 0)
		throw string("位置错误");

	int front = -1;  //假设队列采用顺序存储且不会发生溢出
	int rear = -1;
	int Que[g_MaxSize] = { 0 };  //队列

	GraNode *p = nullptr;  //边结点
	cout << gc.nodes[v].data << "   ";
	visit[v] = 1;
	
	Que[++rear] = 1;    //被访问的顶点进队列
	int j = 0;

	while (front != rear)
	{
		v = Que[++front];    //队首元素出队列
		p = gc.nodes[v].first;  //边表中的工作指针赋值
		while (p != nullptr) 
		{
			j = p->ArcHead;    //顶点下标
			if (visit[j] == 0)
			{
				cout << gc.nodes[j].data << "   ";
				visit[j] = 1;
				Que[++rear] = j;   //被访问顶点进队列
			}
			p = p->next;
		}
	}



}



void test00(void)
{
	GraTable gt;
	//gt.Create_forward();  //创建有向
	/*
	  4 5
	  v0  v1  v2  v3
	  2 - 0    0 - 3    1 - 0    1 - 2    2 - 1
	*/

	gt.Create_Nofd();   //创建无向

	BFSL(gt, 3);




}

int main()
{
	test00();


	system("pause");
	return 0;
}