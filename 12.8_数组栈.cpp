#include<iostream>
using namespace std;


const size_t g_MaxSize = 5;

template<typename T>
class Sstack
{
public:
	Sstack();               //无参构造
	Sstack(const T &r);     //有参构造
	void ClearStack();      //清空栈
	bool Empty()const;      //为空返回真
	T& GetTop();            //若栈存在且非空，返回栈顶元素，否则抛出一个异常
	void PushS(const T &r); //插入新元素到栈顶，并成为栈顶元素,如果满了抛出异常
	void PopS();            //删除栈顶元素，返回栈顶下标，如果为空抛出异常
	int LengthS()const;     //返回栈的元素个数


private:
	T data[g_MaxSize];
	int top;   //栈顶如果是-1则空栈，从0开始计数
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
void Sstack<T>::ClearStack()    //清空栈
{
	this->top = -1;    //不是new出来的，无法释放，直接置为-1即可
}

template<typename T>
bool Sstack<T>::Empty()const     //判断是否为空
{
	if (top != -1)
		return false;
	return true;
}

template<typename T>
T& Sstack<T>::GetTop()      //若栈存在且非空，返回栈顶元素，否则抛出一个异常
{
	if (top == -1)
		throw string("栈为空，无法获取");
	return this->data[this->top];
}

template<typename T>
void Sstack<T>::PushS(const T& r)  //插入新元素到栈顶，并成为栈顶元素,如果满了抛出异常
{
	if (this->top == g_MaxSize - 1)
		throw string("栈已满,无法添加");

	++this->top;
	this->data[this->top] = r;
}

template<typename T>
void Sstack<T>::PopS()             //删除栈顶元素，返回栈顶下标，如果为空抛出异常
{
	if (this->top == -1)
		throw string("栈为空，无法删除");
	--this->top;   //下标减1即可
}

template<typename T>
int Sstack<T>::LengthS()const    //返回栈的元素个数
{
	return ++this->top;
}



void test00(void)
{
	//g_MaxSize = 5
	Sstack<string> s1("宁");
	cout << s1.GetTop() << endl;  //宁
	s1.PushS("尘");
	s1.PushS("月");
	s1.PushS("乐");
	s1.PushS("青");
	cout << "s1是否为空： " << s1.Empty() << endl;  //0
	cout << s1.GetTop() << endl;  //青
	try
	{
		s1.PushS("卿");
	}
	catch (const string& s)  //接收异常
	{
		cout << s << endl; 
	}

	s1.PopS();    
	cout << s1.GetTop() << endl;    //乐

	s1.ClearStack();  

	cout << "此时的s1是否为空： " << s1.Empty() << endl;  //1


}

int main()
{
	test00();



	system("pause");
	return 0;
}