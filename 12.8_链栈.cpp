#include<iostream>
using namespace std;


template<typename T>
class SNote
{
public: 
	SNote(const T &r, SNote<T> *p = nullptr) : data(r), next(p) {  } 
	T data;            //������
	SNote<T> *next;    //ָ����
};

template<typename T>
class LtStack
{
public:
	LtStack();    //�޲ι���
	LtStack(const T &r);  //�вι���
	T& GetTop();          //����ջ��Ԫ��
	bool Empty()const;    //Ϊ�շ���true
	void ClearLS();       //���ջ,����ǿ���ջ����ֱ��return
	int PushLS(const T &r);  //ѹջ�����ش�ʱջ��Ԫ�ظ���
	int PopLS();             //��ջ�����ش�ʱջ��Ԫ�ظ���
	int Length()const;       //����ջ��Ԫ�ظ���
	~LtStack()  //��������
	{
		this->ClearLS();
	}

	SNote<T> *top;   //ջ�������԰�������ͷָ��
	int m_count;  //ͳ��ջ����
};

template<typename T>
LtStack<T>::LtStack() : top(nullptr), m_count(0)   //�޲ι���
{

}

template<typename T>
LtStack<T>::LtStack(const T& r) : top(new SNote<T>(r)), m_count(1)  //�вι���
{

}

template<typename T>
T& LtStack<T>::GetTop()          //����ջ��Ԫ��
{
	if (this->Empty())
	  throw string("��ջΪ��");
	return this->top->data;
}

template<typename T>
bool LtStack<T>::Empty()const    //Ϊ�շ���true
{
	if (this->top != nullptr)
		return false;
	return true;
}

template<typename T>
void LtStack<T>::ClearLS()       //���ջ,����ǿ���ջ����ֱ��return
{
	if (this->Empty())
	{
		return;
	}
	SNote<T> *pd = this->top;

	while (this->top->next != nullptr)
	{
		this->top = this->top->next;
		delete pd;
		pd = this->top;
	}
	delete pd;
	this->top = nullptr;
	this->m_count = 0;
}

template<typename T>
int LtStack<T>::PushLS(const T& r)  //ѹջ�����ش�ʱջ��Ԫ�ظ���
{
	if (this->Empty())
	{
		this->top = new SNote<T>(r);
		return ++this->m_count;
	}
	SNote<T> *s = new SNote<T>(r, this->top);  //��������һ���ڵ㣬ָ������topҲ������һ���ڵ�ĵ�ַ
	this->top = s;                             //topָ�����ѹ������Ԫ��
	return ++this->m_count;
}

template<typename T>
int LtStack<T>::PopLS()             //��ջ�����ش�ʱջ��Ԫ�ظ���
{
	if (this->Empty())
	  return this->m_count;
	if (this->top->next == nullptr)
	{
		delete this->top;
		this->top = nullptr;
		return --this->m_count;
	}

	SNote<T> *pd = this->top;
	this->top = this->top->next;
	delete pd;
	return --this->m_count;
}

template<typename T>
int LtStack<T>::Length()const       //����ջ��Ԫ�ظ���
{
	return this->m_count;
}




void test00(void)
{
	LtStack<string> ls("��");
	cout << "ls��ջ�Ƿ�Ϊ�գ� " << ls.Empty() << endl;  //0
	ls.ClearLS();  //�����ջ
	cout << "ls��ջ�Ƿ�Ϊ�գ� " << ls.Empty() << endl;  //1
	cout << ls.PushLS("��") << endl;  //1
	cout << ls.PushLS("��") << endl;  //2 
	cout << ls.PushLS("��") << endl;  //3
	cout << ls.PushLS("��") << endl;  //4
	cout << ls.Length() << endl;  //4
	cout << ls.GetTop() << endl;  //��

	cout << ls.PopLS() << endl;  //3
	ls.ClearLS();

	cout << ls.Length() << endl;  //0

	try
	{
		ls.GetTop();
	}
	catch (const string& s)
	{
		cout << s << endl;
	}

}


int main()
{
	test00();



	system("pause");
	return 0;
}