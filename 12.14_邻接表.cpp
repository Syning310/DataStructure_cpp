#include<iostream>
using namespace std;
#include<string>

const int g_MaxSize = 50;

struct EdgeNode        //边表结点
{
	int adjvex;                    //邻接点域，存储连接顶点对应的下标
	//int weight;             //用于存储权值，对于非网图可以不需要
	EdgeNode *next;         //指针域，指向下一个邻接点
};

struct VertexNode     //顶点表结点
{
	string data;        //顶点域，存储顶点信息
	EdgeNode *firstEdge;  //边表头指针
};


class GraphAdj
{
public:
	void Clear();
	~GraphAdj() { this->Clear(); }

	void CreateAdj();   //函数
	VertexNode adjList[g_MaxSize];     //顶点表 - 数组
	int numVertexes;                   //顶点数
	int numEdge;                       //边数
};


//无向图邻接表创建
void GraphAdj::CreateAdj()
{
	EdgeNode *e = nullptr;
	cout << "输入顶点数和边数 >: ";
	cin >> this->numVertexes >> this->numEdge;    //输入顶点数和边数

	//输入顶点data，建立顶点表
	for (int i = 0; i < this->numVertexes; ++i)  
	{
		cout << "请输入第" << i + 1 << "个顶点的data" << endl;
		cin >> this->adjList[i].data;
		this->adjList[i].firstEdge = nullptr;    //顶点结点中的边表置为空
	}

	
	//建立边表
	int x = 0;
	int y = 0;
	for (int i = 0; i < this->numEdge; ++i)
	{
		cout << "输入边(V1, V2)上的顶点序号 >:" ;
		cin >> x >> y;     //输入(V1, V2)上的顶点 在数组中的下标
		e = new EdgeNode;

		e->adjvex = y;    //邻接点的下标为j
		e->next = this->adjList[x].firstEdge;  //将e的指针指向当前顶点指向的结点
		adjList[x].firstEdge = e;              //将当前顶点的指针指向e


		e = new EdgeNode;  

		e->adjvex = x;    //邻接点的下标为i
		e->next = this->adjList[y].firstEdge;   //将e的指针指向当前顶点的结点
		adjList[y].firstEdge = e;               //将当前结点的指针指向e

	}
	//由于对于无向图来说，一条边对应都是两个顶点，所以循环中，依次就针对x，y分别进行了插入


}



void GraphAdj::Clear()
{
	EdgeNode *pd = nullptr;

	for (int i = 0; i < this->numVertexes; ++i)
	{
		pd = this->adjList[i].firstEdge;
		while (this->adjList[i].firstEdge != nullptr)
		{
			this->adjList[i].firstEdge = this->adjList[i].firstEdge->next;
			delete pd;
			pd = this->adjList[i].firstEdge;
		}
		delete pd;
		this->adjList[i].firstEdge = nullptr;
	}
	

}



void test00(void)
{
	GraphAdj gx;
	gx.CreateAdj();



}

int main()
{
	test00();


	system("pause");
	return 0;
}