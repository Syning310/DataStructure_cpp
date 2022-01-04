#include<iostream>
using namespace std;


const size_t g_MaxSize = 5;

template<typename T>
class Sstack
{
public:
	Sstack();               //�޲ι���
	Sstack(const T &r);     //�вι���
	void ClearStack();      //���ջ
	bool Empty()const;      //Ϊ�շ�����
	T& GetTop();            //��ջ�����ҷǿգ�����ջ��Ԫ�أ������׳�һ���쳣
	void PushS(const T &r); //������Ԫ�ص�ջ��������Ϊջ��Ԫ��,��������׳��쳣
	void PopS();            //ɾ��ջ��Ԫ�أ�����ջ���±꣬���Ϊ���׳��쳣
	int LengthS()const;     //����ջ��Ԫ�ظ���


private:
	T data[g_MaxSize];
	int top;   //ջ�������-1���ջ����0��ʼ����
};

template<typename T>
Sstack<T>::Sstack() : top(-1)
{
	
}

template<typename T>
Sstack<T>::Sstack(const T& r) : top(0)
{
	data[top] = r;
}

template<typename T>
void Sstack<T>::ClearStack()    //���ջ
{
	this->top = -1;    //����new�����ģ��޷��ͷţ�ֱ����Ϊ-1����
}

template<typename T>
bool Sstack<T>::Empty()const     //�ж��Ƿ�Ϊ��
{
	if (top != -1)
		return false;
	return true;
}

template<typename T>
T& Sstack<T>::GetTop()      //��ջ�����ҷǿգ�����ջ��Ԫ�أ������׳�һ���쳣
{
	if (top == -1)
		throw string("ջΪ�գ��޷���ȡ");
	return this->data[this->top];
}

template<typename T>
void Sstack<T>::PushS(const T& r)  //������Ԫ�ص�ջ��������Ϊջ��Ԫ��,��������׳��쳣
{
	if (this->top == g_MaxSize - 1)
		throw string("ջ����,�޷����");

	++this->top;
	this->data[this->top] = r;
}

template<typename T>
void Sstack<T>::PopS()             //ɾ��ջ��Ԫ�أ�����ջ���±꣬���Ϊ���׳��쳣
{
	if (this->top == -1)
		throw string("ջΪ�գ��޷�ɾ��");
	--this->top;   //�±��1����
}

template<typename T>
int Sstack<T>::LengthS()const    //����ջ��Ԫ�ظ���
{
	return ++this->top;
}



void test00(void)
{
	//g_MaxSize = 5
	Sstack<string> s1("��");
	cout << s1.GetTop() << endl;  //��
	s1.PushS("��");
	s1.PushS("��");
	s1.PushS("��");
	s1.PushS("��");
	cout << "s1�Ƿ�Ϊ�գ� " << s1.Empty() << endl;  //0
	cout << s1.GetTop() << endl;  //��
	try
	{
		s1.PushS("��");
	}
	catch (const string& s)  //�����쳣
	{
		cout << s << endl; 
	}

	s1.PopS();    
	cout << s1.GetTop() << endl;    //��

	s1.ClearStack();  

	cout << "��ʱ��s1�Ƿ�Ϊ�գ� " << s1.Empty() << endl;  //1


}

int main()
{
	test00();



	system("pause");
	return 0;
}