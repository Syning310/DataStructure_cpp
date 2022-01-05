#include<iostream>
using namespace std;


const size_t g_MaxSize = 20;

template<typename T>
class Linear
{
public:
	Linear();      //初始化
	bool Empty();  //判断是否空表
	void Clear();  //清空线性表
	T& GetElem(const int& pos);  //返回表中第 pos 个元素
	int LocateElem(const T &rhs);  //查找给定元素，如果查找成功返回元素下标，如果失败返回-1
	int Insert(int pos, const T &rhs);  //在第 pos 位置插入给定元素
	bool Del(int pos);         //删除 pos 位置的元素，成功返回true，失败返回false
	size_t Length();           //返回线性表的长度


	size_t m_Length;  //线性表的长度
	T data[g_MaxSize];  //数组
};



void test00(void)
{
	Linear<int> p;
	cout << p.m_Length << endl;  //0
	cout << p.Empty() << endl;   //1
	cout << p.LocateElem(10) << endl;    //-1
	cout << p.Insert(0, 100) << endl;    //下标0
	cout << p.Insert(1, 200) << endl;    //下标1
	cout << p.Insert(2, 300) << endl;    //下标2
	cout << p.Insert(4, 400) << endl;    //-1

	cout << p.Del(3) << endl;
	cout << p.Del(0) << endl;
}

void test01(void)
{
	Linear<double> p;
	p.Insert(0, 5.55);
	p.Insert(1, 8.48);
	p.Insert(2, 3.14);
	p.Insert(3, 3.14);
	p.Insert(4, 3.14);
	p.Insert(5, 3.14);
	p.Insert(6, 3.14);
	p.Insert(7, 3.14);
	p.Insert(8, 3.14);

	cout << p.Empty() << endl;          //0
	cout << p.Length() << endl;         //9
	cout << p.LocateElem(3.14) << endl; //2
	cout << p.Del(0) << endl;
	cout << p.Del(7) << endl;
	cout << p.Length() << endl;         //7
	p.Insert(7, 18.86);

	double y = 0;
	try
	{
		y = p.GetElem(3);
	}
	catch (string& s)
	{
		cout << s << endl;
	}
	cout << y << endl;

}

int main()
{
	//test00();
	test01();


	system("pause");
	return 0;
}



template<typename T>
Linear<T>::Linear()      //初始化
{
	this->m_Length = 0;
	for (int i = 0; i < g_MaxSize; ++i)
	{
		this->data[i] = 0;
	}
}

template<typename T>
bool Linear<T>:: Empty()  //判断是否空表
{
	if (this->m_Length == 0)
		return 1;
	return 0;
}

template<typename T>
void Linear<T>::Clear()  //清空线性表
{
	this->m_Length = 0;
}

template<typename T>
T& Linear<T>::GetElem(const int &pos)  //返回表中 pos 下标的元素
{
	if (this->m_Length == 0 || pos < 0 || pos >= (int)this->m_Length)
	{
		throw string("长度为0或位置不合法");
	}
	return this->data[pos];
}

template<typename T>
int Linear<T>::LocateElem(const T& rhs)  //查找给定元素，如果查找成功,返回元素下标，如果失败返回-1
{
	if (this->m_Length == 0)
	{
		return -1;
	}

	for (size_t i = 0; i < this->m_Length; ++i)
	{
		if (this->data[i] == rhs)
		{
			return i;
		}
	}
	return -1;
}

template<typename T>
int Linear<T>::Insert(int pos, const T& rhs)  //在第 pos 位置插入给定元素,失败返回-1,成功返回下标
{
	if (this->m_Length == g_MaxSize)         //线性表长度已满
		return -1;
	
	if (pos < 0 || pos > (int)this->m_Length || pos == g_MaxSize)  //pos不在范围
		return -1;
	

	if (pos < (int)this->m_Length)
	{
		for (int k = this->m_Length - 1; k >= pos; --k)
		{
			this->data[k + 1] = this->data[k];
		}
	}

	this->data[pos] = rhs;
	++this->m_Length;
	return pos;
}

template<typename T>
bool Linear<T>::Del(int pos)         //删除 pos 位置的元素，成功返回true，失败返回false
{
	if (this->m_Length == 0)
	{
		return false;
	}
	if (pos < 0 || pos >= (int)this->m_Length)
	{
		return false;
	}
	
	if (pos < (int)m_Length - 1)
	{
		for (int k = pos; k < (int)this->m_Length; ++k)
		{
			this->data[k] = this->data[k + 1];
		}
	}
	--this->m_Length;
	return true;
}

template<typename T>
size_t Linear<T>::Length()           //返回线性表的长度
{
	return this->m_Length;
}






