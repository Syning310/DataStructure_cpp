#include<iostream>
using namespace std;


const int g_MaxVex = 100;
const int g_Init = 65535;

class SGraph
{
public:

	char Vexs[g_MaxVex];    //�����
	int arc[g_MaxVex][g_MaxVex];      //�ڽӾ��󣬿ɿ����߱�

	int numVertexes;    //��ǰ������
	int numEdges;       //��ǰ����

};


void CreateSGraph(SGraph *gc)
{
	cout << "���붥�����ͱ��� >: " ;
	cin >> gc->numVertexes;  //�������
	cin >> gc->numEdges;     //�ߵ���

	for (int i = 0; i < gc->numVertexes; ++i)
	{
		cout << "�����" << i + 1 << "�������data >:";
		cin >> gc->Vexs[i];
	}


	for (int i = 0; i < gc->numVertexes; ++i)
	{
		for (int j = 0; j < gc->numVertexes; ++j)
		{
			gc->arc[i][j] = g_Init;  //�ڽӾ����ʼ��
		}
	}


	int x = 0;
	int y = 0;
	int w = 0;
	for (int k = 0; k < gc->numEdges; ++k)
	{
		cout << "�����(vx, vj)�ϵ��±�x���±�j��Ȩw>:" << endl;
		cin >> x >> y >> w;    //�����±�x��y�ϵ�Ȩw
		gc->arc[x][y] = w;
		gc->arc[y][x] = gc->arc[x][y];    //��Ϊ������ͼ������Գ�
	}

}


bool visited[g_MaxVex];
void DFS(SGraph &gc, int i)
{

	 visited[i] = true;
	 cout << gc.Vexs[i] << endl;     //��ӡ����

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
		visited[i] = false;    //��ʼ�����ж���״̬������δ���ʵ�
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