#include<iostream>
using namespace std;



const size_t g_MaxSize = 10;

typedef string ElemType;



//�����ڽӱ�

struct GraNode   //����
{
	int ArcHead;    //�洢���Ӷ���Ķ�Ӧ�±�
	GraNode* next;  //ָ�򶥵���һ�����ӵĶ�Ӧ������±�
};

struct VexNode  //������
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
	void Create_forward();     //��������ͼ
	void Create_Nofd();        //��������ͼ


	VexNode nodes[g_MaxSize];    //��������
	int numVex;
	int numArc;
};

void GraTable::Create_forward()   //��������ͼ
{
	int nV = 0;
	int nA = 0;
	cout << "���붥�����ͱ���>: ";
	cin >> nV >> nA;

	this->numVex = nV;
	this->numArc = nA;

	//��������
	string s;
	for (int i = 0; i < nV; ++i)
	{
		cout << "�����" << i << "�������data >: ";
		cin >> s;
		this->nodes[i].data = s;
	}


	//������

	int x = 0;
	int y = 0;
	GraNode* e = nullptr;    //����һ�������
	for (int i = 0; i < nA; ++i)
	{
		cout << "�����" << i + 1 << "���ߵ���<Vx, Vj>���±� >: ";
		cin >> x >> y;

		e = new GraNode;
		e->ArcHead = y;     //�ѻ�ͷ���±긳ֵ�����
		e->next = nullptr;

		//�ѽ�����������ӣ�������ͷ��
		if (this->nodes[x].first != nullptr)
		{
			GraNode* tail = this->nodes[x].first;
			while (tail->next != nullptr)
			{
				tail = tail->next;
			}
			tail->next = e;    //�ҳ����������һ����㣬Ȼ��ָ���µı�e

		}
		else
		{
			this->nodes[x].first = e;
		}

	}

}

void GraTable::Create_Nofd()        //��������ͼ
{
	int nV = 0;
	int nA = 0;
	cout << "���붥�����ͱ���>: ";
	cin >> nV >> nA;

	this->numVex = nV;
	this->numArc = nA;


	//��������
	string s;
	for (int i = 0; i < nV; ++i)
	{
		cout << "�����" << i << "�������data >: ";
		cin >> s;
		this->nodes[i].data = s;
	}

	//������
	int x = 0;
	int y = 0;
	GraNode* e = nullptr;    //����һ�������
	for (int i = 0; i < nA; ++i)
	{
		cout << "�����" << i + 1 << "���ߵ���(Vx, Vj)���±� >: ";
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


		//��Ϊ������ߣ��������������㶼Ҫ���ָ��
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
//������ȱ���
void BFSL(GraTable gc, int v)
{
	int n = gc.numVex;
	if (v >= n || v < 0)
		throw string("λ�ô���");

	int front = -1;  //������в���˳��洢�Ҳ��ᷢ�����
	int rear = -1;
	int Que[g_MaxSize] = { 0 };  //����

	GraNode *p = nullptr;  //�߽��
	cout << gc.nodes[v].data << "   ";
	visit[v] = 1;
	
	Que[++rear] = 1;    //�����ʵĶ��������
	int j = 0;

	while (front != rear)
	{
		v = Que[++front];    //����Ԫ�س�����
		p = gc.nodes[v].first;  //�߱��еĹ���ָ�븳ֵ
		while (p != nullptr) 
		{
			j = p->ArcHead;    //�����±�
			if (visit[j] == 0)
			{
				cout << gc.nodes[j].data << "   ";
				visit[j] = 1;
				Que[++rear] = j;   //�����ʶ��������
			}
			p = p->next;
		}
	}



}



void test00(void)
{
	GraTable gt;
	//gt.Create_forward();  //��������
	/*
	  4 5
	  v0  v1  v2  v3
	  2 - 0    0 - 3    1 - 0    1 - 2    2 - 1
	*/

	gt.Create_Nofd();   //��������

	BFSL(gt, 3);




}

int main()
{
	test00();


	system("pause");
	return 0;
}