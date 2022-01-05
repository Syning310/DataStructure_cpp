#include<iostream>
using namespace std;


const int g_MaxVex = 100;
const int g_Init = 65535;

class SGraph
{
public:

	char Vexs[g_MaxVex];    //顶点表
	int arc[g_MaxVex][g_MaxVex];      //邻接矩阵，可看作边表

	int numVertexes;    //当前顶点数
	int numEdges;       //当前边数

};


void CreateSGraph(SGraph *gc)
{
	cout << "输入顶点数和边数 >: " ;
	cin >> gc->numVertexes;  //顶点的数
	cin >> gc->numEdges;     //边的数

	for (int i = 0; i < gc->numVertexes; ++i)
	{
		cout << "输入第" << i + 1 << "个顶点的data >:";
		cin >> gc->Vexs[i];
	}


	for (int i = 0; i < gc->numVertexes; ++i)
	{
		for (int j = 0; j < gc->numVertexes; ++j)
		{
			gc->arc[i][j] = g_Init;  //邻接矩阵初始化
		}
	}


	int x = 0;
	int y = 0;
	int w = 0;
	for (int k = 0; k < gc->numEdges; ++k)
	{
		cout << "输入边(vx, vj)上的下标x，下标j和权w>:" << endl;
		cin >> x >> y >> w;    //输入下标x，y上的权w
		gc->arc[x][y] = w;
		gc->arc[y][x] = gc->arc[x][y];    //因为是无向图，矩阵对称
	}

}


bool visited[g_MaxVex];
void DFS(SGraph &gc, int i)
{

	 visited[i] = true;
	 cout << gc.Vexs[i] << endl;     //打印顶点

	for (int j = 0; j < gc.numVertexes; ++j)
	{
		if (gc.arc[i][j] == true && !visited[j])
			DFS(gc, j);
	}


}


void DFSTraver(SGraph& gc)
{
	for (int i = 0; i < gc.numVertexes; ++i)
	{
		visited[i] = false;    //初始化所有顶点状态，都是未访问的
	}

	for (int i = 0; i < gc.numVertexes; ++i)
	{
		if (!visited[i])
			DFS(gc, i);
	}
}



void test00(void)
{
    SGraph s;
	CreateSGraph(&s);

	DFS(s, 0);
	DFSTraver(s);


}

int main()
{
	test00();


	system("pause");
	return 0;
}