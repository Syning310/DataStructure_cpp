#include<iostream>
using namespace std;



const size_t g_MaxSize = 10;

typedef string ElemType;



//创建邻接表

struct GraNode   //链表
{
	int ArcHead;    //存储连接顶点的对应下标
	GraNode *next;  //指向顶点下一个连接的对应顶点的下标
};

struct VexNode  //顶点结点
{
	ElemType data;
	GraNode *first;
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
	GraNode *e = nullptr;    //创建一个链结点
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
			GraNode *tail = this->nodes[x].first;
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
			GraNode *tail = this->nodes[y].first;
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




//深度遍历
int visited[g_MaxSize];

void Dfs(GraTable*& g, int i)
{
	int j = 0;
	GraNode *p = nullptr;
	int w = 0;

	cout << g->nodes[i].data << endl;    //输出当前顶点
	visited[i] = 1;  //将当前顶点标记成以访问结点

	p = g->nodes[i].first;
	while (p != nullptr)
	{
		w = p->ArcHead;    //w是邻接点的坐标
		if (visited[w] == 0)
		{
			Dfs(g, w);
		}
		p = p->next;   //查找完之后向后推一位
	}
}

void DfsTraver(GraTable* g)
{
	int i = 0;

	for (i = 0; i < g->numVex; ++i)
	{
		visited[i] = 0;
	}

	for (i = 0; i < g->numVex; ++i)
	{
		if (visited[i] == 0)
		{
			Dfs(g, i);
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


	DfsTraver(&gt);



}

int main()
{
	test00();


	system("pause");
	return 0;
}