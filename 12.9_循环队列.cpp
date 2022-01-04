#include<iostream>
using namespace std;


const size_t g_QMaxSize = 5;


//ѭ������ֻ��� g_QMaxSize - 1 ��Ԫ��
//���� front �� rear ��ȵ�ʱ���п����ǿն���Ҳ�п�����������

template<typename T>
class SQueue
{
public:
	SQueue();
	SQueue(const T &r);
	void ClearQ();            //��ն���
	bool Empty()const;        //����Ϊ�շ���true
	T& GetElem();             //�����в�Ϊ�գ����ض���ͷԪ��
	bool PushQ(const T &r);   //������δ�����Ӷ�β����Ԫ�أ��ɹ�����true������������ʧ��false
	bool PopQ();              //ɾ����ͷԪ�أ��ɹ�����true������Ϊ�ջ�ʧ�ܷ���false
	int LengthQ()const;       //���ض��е�Ԫ�ظ���

private:
	T data[g_QMaxSize];  
	int front;    //��ͷ���±�����ɾ���������������Ϊָ��
	int rear;     //��β���±������������
};

template<typename T>
SQueue<T>::SQueue() : front(0), rear(0)
{

}

template<typename T>
SQueue<T>::SQueue(const T& r) : front(0), rear(0)
{
	this->data[rear] = r;
	++this->rear;
}

template<typename T>
void SQueue<T>::ClearQ()            //��ն���
{
	this->front = 0;
	this->rear = 0;    //���������±�ֵΪ0����Ϊ�ն�����
}

template<typename T>
bool SQueue<T>::Empty()const        //����Ϊ�շ���true
{
	if (this->front == this->rear)
		return true;
	return false;
}

template<typename T>
T& SQueue<T>::GetElem()             //�����в�Ϊ�գ����ض���ͷԪ��
{
	if (this->front == this->rear)
		throw string("����Ϊ��");

	return this->data[this->front];
}

template<typename T>
bool SQueue<T>::PushQ(const T& r)   //������δ�����Ӷ�β����Ԫ�أ��ɹ�����true������������ʧ��false
{
	if ((this->rear + 1) % g_QMaxSize == front)  //������Ϊ��
		return false;

	this->data[this->rear] = r;
	this->rear = (this->rear + 1) % g_QMaxSize;  //rear����ƶ�һ��λ�ã����������ת������ͷ��

	return true;
}

template<typename T>
bool SQueue<T>::PopQ()              //ɾ����ͷԪ�أ��ɹ�����true������Ϊ�ջ�ʧ�ܷ���false
{
	if (this->front == this->rear)  //���п�,Ϊ��  
		return false;

	this->front = (this->front + 1) % g_QMaxSize;  //front����ƶ�һλ���൱��ɾ��
					            //���������ת�������ͷ��
	return true;
}

template<typename T>
int SQueue<T>::LengthQ()const       //���ض��е�Ԫ�ظ���
{
	return (this->rear - this->front + g_QMaxSize) % g_QMaxSize;  //�õ����Ƕ�����Ԫ�صĸ���
}






struct person
{
	person() : m_name(""), m_age(0) { }
	person(const string &name, const int &age) : m_name(name), m_age(age) { }
	string m_name;
	int m_age;
};
void test00(void)
{
	SQueue<person> s;
	cout << "����s�Ƿ�Ϊ�գ� " << s.Empty() << endl;  //1
	cout << "��һ��Ԫ�ز����Ƿ�ɹ��� " << s.PushQ(person("��", 2400)) << endl;   //1
	auto p = s.GetElem();
	cout << "����s�ĵ�һ��Ԫ�أ� " << p.m_name << "  " << p.m_age << endl;  //��  2400
	cout << "�ڶ���Ԫ�ز����Ƿ�ɹ��� " << s.PushQ(person("��", 12400)) << endl;  //1
	cout << "������Ԫ�ز����Ƿ�ɹ��� " << s.PushQ(person("��", 3400)) << endl;   //1
	cout << "���ĸ�Ԫ�ز����Ƿ�ɹ��� " << s.PushQ(person("��", 24)) << endl;     //1
	cout << "�����Ԫ�ز����Ƿ�ɹ��� " << s.PushQ(person("��", 4000)) << endl;   //0
	cout << "����s�е�Ԫ�ظ���Ϊ�� " << s.LengthQ() << endl;   //4

	s.PopQ();  
	cout << "ɾ����һ��Ԫ�غ󣬴�ʱ����Ϊ" << s.LengthQ() << endl;  //3
	p = s.GetElem();
	cout << "��ͷ��: " << p.m_name << "  " << p.m_age << endl;  //��  12400
	s.ClearQ();
	cout << "���֮�󣬶����Ƿ�Ϊ�գ� " << s.Empty() << endl;  //1

}

int main()
{
	test00();



	system("pause");
	return 0;
}