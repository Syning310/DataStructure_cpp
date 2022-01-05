#include<iostream>
using namespace std;
#include<string>

const int g_MaxSize = 50;

struct EdgeNode        //�߱���
{
	int adjvex;                    //�ڽӵ��򣬴洢���Ӷ����Ӧ���±�
	//int weight;             //���ڴ洢Ȩֵ�����ڷ���ͼ���Բ���Ҫ
	EdgeNode *next;         //ָ����ָ����һ���ڽӵ�
};

struct VertexNode     //�������
{
	string data;        //�����򣬴洢������Ϣ
	EdgeNode *firstEdge;  //�߱�ͷָ��
};


class GraphAdj
{
public:
	void Clear();
	~GraphAdj() { this->Clear(); }

	void CreateAdj();   //����
	VertexNode adjList[g_MaxSize];     //����� - ����
	int numVertexes;                   //������
	int numEdge;                       //����
};


//����ͼ�ڽӱ���
void GraphAdj::CreateAdj()
{
	EdgeNode *e = nullptr;
	cout << "���붥�����ͱ��� >: ";
	cin >> this->numVertexes >> this->numEdge;    //���붥�����ͱ���

	//���붥��data�����������
	for (int i = 0; i < this->numVertexes; ++i)  
	{
		cout << "�������" << i + 1 << "�������data" << endl;
		cin >> this->adjList[i].data;
		this->adjList[i].firstEdge = nullptr;    //�������еı߱���Ϊ��
	}

	
	//�����߱�
	int x = 0;
	int y = 0;
	for (int i = 0; i < this->numEdge; ++i)
	{
		cout << "�����(V1, V2)�ϵĶ������ >:" ;
		cin >> x >> y;     //����(V1, V2)�ϵĶ��� �������е��±�
		e = new EdgeNode;

		e->adjvex = y;    //�ڽӵ���±�Ϊj
		e->next = this->adjList[x].firstEdge;  //��e��ָ��ָ��ǰ����ָ��Ľ��
		adjList[x].firstEdge = e;              //����ǰ�����ָ��ָ��e


		e = new EdgeNode;  

		e->adjvex = x;    //�ڽӵ���±�Ϊi
		e->next = this->adjList[y].firstEdge;   //��e��ָ��ָ��ǰ����Ľ��
		adjList[y].firstEdge = e;               //����ǰ����ָ��ָ��e

	}
	//���ڶ�������ͼ��˵��һ���߶�Ӧ�����������㣬����ѭ���У����ξ����x��y�ֱ�����˲���


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