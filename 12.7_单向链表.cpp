#include<iostream>
using namespace std;


template<typename T>
class Note
{
public:
	Note() : next(nullptr), data(0) {  }
	Note(const T &r, Note *n = nullptr) : data(r), next(n) {  }

	T data;                  //数据域
	Note<T> *next;    //指针域
};

//头指针：链表的开始部分
template<typename T>
class AWayList
{
public:
	AWayList(const T &r);  //有参
	~AWayList();     //析构

	Note<T>* push_front(const T &r);    //头插法
	Note<T>* push_back(const T &r);     //尾插法
	Note<T>* Insert(const T &r, int n); //插入法
	size_t Size()const;  //返回链表的大小

	bool Empty()const;    //判断是否为空表
	void Clear();    //清空链表
	Note<T>* GetElem(const int &pos)const;   //返回第pos个元素
	Note<T>* LocateElem(const T &rhs)const;  //查找给定元素，返回它的上一个元素的指针
	bool Del(const int &pos);       //删除pos位置的元素，失败返回0

	void for_each() const
	{
		Note<T> *p = this->m_headp;
		for (; p != nullptr; p = p->next)
		{
			cout << p->data << " " ;
		}
	}

	Note<T> *m_headp;  //头指针，指向头结点
};



template<typename T>
AWayList<T>::AWayList(const T& r) : m_headp(new Note<T>(r, nullptr))  //有参
{
	
}

template<typename T>
AWayList<T>::~AWayList()     //析构
{
	//cout << "AWayList析构函数" << endl;
	this->Clear();
	delete this->m_headp;
	this->m_headp = nullptr;
}



template<typename T>
Note<T>* AWayList<T>::push_front(const T& r)    //头插法，返回指向第一个元素的指针
{
	Note<T> *p = this->m_headp;
	Note<T> *s = new Note<T>(r, p->next);
	p->next = s;
	return p;
}

template<typename T>
Note<T>* AWayList<T>::push_back(const T& r)     //尾插法，返回指向最后一个元素的指针
{
	Note<T> *p = this->m_headp;
	Note<T> *s = nullptr;
	while (p->next != nullptr)
	{
		p = p->next;	
	}

	s = new Note<T>(r, p->next);
	p->next = s;
	return s;
}

template<typename T>
Note<T>* AWayList<T>::Insert(const T& r, int n)  //插入法，返回插入的元素指针的上一位
{
	Note<T> *p = this->m_headp;  //首先创建两个节点指针
	Note<T> *s = nullptr;

	int i = 1;
	while (p->next != nullptr && i < n)
	{
		p = p->next;
		++i;
	}
	if (p == nullptr || i > n )    //如果头指针是空指针，返回假
		throw string("头指针为空或输入位置小于0");

	s = new Note<T>(r, p->next);
	p->next = s;
	return p;
}


template<typename T>
size_t AWayList<T>::Size()const
{
	Note<T> *p = this->m_headp->next;
	size_t i = 0;

	while (p != nullptr)
	{
		++i;
		p = p->next;
	}
	return i;
}


template<typename T>
bool AWayList<T>::Empty() const    //判断是否为空表
{
	if (this->m_headp->next == nullptr)
		return true;
	return false;
}

template<typename T>
void AWayList<T>::Clear()    //清空链表
{
	if (this->Empty() == true)
	{
		return;  //如果为真，我们保留头节点
	}

	Note<T>* pd = this->m_headp->next;   //从头节点的下一个元素开始delete
	Note<T>* pn = pd->next;              //维护下一个元素
										 //头节点留给析构函数释放

	int i = 1;
	while (pn != nullptr)
	{
		delete pd;
		pd = pn;
		pn = pd->next;
		++i;
	}
	delete pd;

	//cout << "delete " << i << " 次" << endl;

}


template<typename T>
Note<T>* AWayList<T>::GetElem(const int& pos)const	//返回第pos个元素
{
	Note<T>* p = this->m_headp;
	if (pos > (int)this->Size() + 1)
		throw string("pos超出链表大小");
	if (pos < 0)
		throw string("不存在小于0的元素");

	int i = 0;
	while (i < pos)
	{
		p = p->next;
		++i;
	}
	return p;
}

template<typename T>
Note<T>* AWayList<T>::LocateElem(const T& rhs)const  //查找给定元素，返回它的元素的指针
{
	Note<T>* p = this->m_headp;

	while (p->data != rhs && p->next != nullptr)
	{
		p = p->next;
	}
	if (p->data != rhs)
	{
		throw string("未找到元素");
	}
	return p;
}

template<typename T>
bool AWayList<T>::Del(const int& pos)       //删除pos位置的元素，失败返回0
{
	Note<T> *p = this->m_headp;
	Note<T> *pd = p->next;

	if (this->Empty() == true)
		return false;
	if (pos > (int)this->Size())
		return false;

	int i = 1;
	while (i < pos)
	{
		++i;
		p = p->next;
		pd = p->next;
	}

	//把pd的next赋值给p的next
	p->next = pd->next;
	delete pd;
	return true;
}





void test00(void)
{
	AWayList<string> s("head");
	s.push_back("宁");
	s.push_back("宁");
	s.push_back("宁");
	s.push_back("宁");
	s.push_back("宁");
	s.Insert("月", 1);
	auto  pn = s.Insert("尘", 4);    //返回的指针是插入尘的上一个指针
	s.for_each();
	cout << endl;
	cout << s.Size() << endl;
	cout << pn->data << endl;     //尘的上一个指针：宁
	cout << pn->next->data << endl;  //尘
}

void test01(void)
{
	AWayList<string> s1("head");
	s1.push_front("宁");
	s1.push_front("月");
	s1.push_front("尘");
	s1.push_front("瑶");
	s1.push_front("心");
	s1.for_each();
	cout << endl;
	cout << s1.Size() << endl;
	s1.push_back("卿");
	s1.push_back("青");
	s1.for_each();
	cout << endl;
	cout << s1.Size() << endl;
	s1.Clear();
	s1.for_each();
	cout << endl;
	cout << s1.Size() << endl;

}

void test02(void)
{
	AWayList<string> s("head");
	s.push_back("宁");
	s.push_back("宁");
	s.push_back("月");
	s.push_back("宁");
	s.push_back("卿");
	s.for_each();
	cout << endl;
	auto it = s.GetElem(3);
	cout << "第3个元素是： " << it->data << endl;
	it = s.GetElem(5);
	cout << "第5个元素是： " << it->data << endl;

	Note<string>* ip = nullptr;
	try
	{
		ip = s.LocateElem("月");
	}
	catch (string& s)
	{
		cout << s << endl;
	}
	cout << "查找的元素data是： " << ip->data << "  下一个指针是： " << ip->next << endl;

	bool ret = s.Del(1);
	s.for_each();
	cout << endl;
	cout << "ret = " << ret << endl;
}


void test03(void)
{
	AWayList<string> p("head");
	p.push_back("希");
	p.push_front("心");
	p.push_back("尘");
	p.Insert("月", 2);
	p.Insert("宁", 2);
	p.for_each();
	cout << endl;
	p.Del(1);
	p.Del(2);
	p.Del(1);
	p.for_each();
	cout << endl;
	bool ret = p.Del(3);
	cout << "ret = " << ret << endl;


}

int main()
{
	//test00();
	//test01();
	//test02();
	test03();

	system("pause");
	return 0;
}
