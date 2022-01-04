#include<iostream>
using namespace std;


template<typename T>
class SNote
{
public: 
	SNote(const T &r, SNote<T> *p = nullptr) : data(r), next(p) {  } 
	T data;            //数据域
	SNote<T> *next;    //指针域
};

template<typename T>
class LtStack
{
public:
	LtStack();    //无参构造
	LtStack(const T &r);  //有参构造
	T& GetTop();          //返回栈顶元素
	bool Empty()const;    //为空返回true
	void ClearLS();       //清空栈,如果是空链栈，则直接return
	int PushLS(const T &r);  //压栈，返回此时栈的元素个数
	int PopLS();             //出栈，返回此时栈的元素个数
	int Length()const;       //返回栈的元素个数
	~LtStack()  //析构函数
	{
		this->ClearLS();
	}

	SNote<T> *top;   //栈顶，可以把它当成头指针
	int m_count;  //统计栈个数
};

template<typename T>
LtStack<T>::LtStack() : top(nullptr), m_count(0)   //无参构造
{

}

template<typename T>
LtStack<T>::LtStack(const T& r) : top(new SNote<T>(r)), m_count(1)  //有参构造
{

}

template<typename T>
T& LtStack<T>::GetTop()          //返回栈顶元素
{
	if (this->Empty())
	  throw string("链栈为空");
	return this->top->data;
}

template<typename T>
bool LtStack<T>::Empty()const    //为空返回true
{
	if (this->top != nullptr)
		return false;
	return true;
}

template<typename T>
void LtStack<T>::ClearLS()       //清空栈,如果是空链栈，则直接return
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
int LtStack<T>::PushLS(const T& r)  //压栈，返回此时栈的元素个数
{
	if (this->Empty())
	{
		this->top = new SNote<T>(r);
		return ++this->m_count;
	}
	SNote<T> *s = new SNote<T>(r, this->top);  //创建出来一个节点，指针域存放top也就是下一个节点的地址
	this->top = s;                             //top指向这个压进来的元素
	return ++this->m_count;
}

template<typename T>
int LtStack<T>::PopLS()             //出栈，返回此时栈的元素个数
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
int LtStack<T>::Length()const       //返回栈的元素个数
{
	return this->m_count;
}




void test00(void)
{
	LtStack<string> ls("宁");
	cout << "ls链栈是否为空： " << ls.Empty() << endl;  //0
	ls.ClearLS();  //清空链栈
	cout << "ls链栈是否为空： " << ls.Empty() << endl;  //1
	cout << ls.PushLS("宁") << endl;  //1
	cout << ls.PushLS("尘") << endl;  //2 
	cout << ls.PushLS("月") << endl;  //3
	cout << ls.PushLS("青") << endl;  //4
	cout << ls.Length() << endl;  //4
	cout << ls.GetTop() << endl;  //青

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