#include<iostream>
using namespace std;

template<typename T>
class QNote
{
public:
	QNote() : data(0), next(nullptr) {  }
	QNote(const T &r,  QNote<T>  *p = nullptr) : data(r), next(p) {  }
	T data;          //数据域
	QNote<T> *next;  //指针域
};

template<typename T>
class LstQue
{
public:
	LstQue();
	LstQue(const T &r);
	~LstQue();

	bool Empty()const;              //链队列为空返回true
	T& GetElem();                   //返回队头节点的data,如果链队列为空，抛出一个string异常
	T& PushQue(const T &r);		    //插入元素，返回队尾指针
	QNote<T>* PopQue();             //删除元素，返回队头指针,链队列为空，抛出一个string异常
	void ClearQue();                //清空链队列
	int LengthQue()const;           //返回链队列的长度

private:
	QNote<T> *head;     //队头指针，用于删除元素，指向第一个元素
	QNote<T> *tail;     //队尾指针，用于插入元素，指向最后一个元素
};

template<typename T>
LstQue<T>::LstQue() : tail(nullptr), head(nullptr)
{

}

template<typename T>
LstQue<T>::LstQue(const T& r) : tail(new QNote<T>(r, nullptr)), head(nullptr)
{
	this->head = tail;
}

template<typename T>
LstQue<T>::~LstQue()
{
	this->ClearQue();
}


template<typename T>
bool LstQue<T>::Empty()const              //链队列为空返回true
{
	if (this->head != nullptr)
		return false;
	return true;
}

template<typename T>
T& LstQue<T>::GetElem()                   //返回队头节点的data,如果链队列为空，抛出一个string异常
{
	if (this->Empty())
		throw string("链队列为空");
	return this->head->data;
}

template<typename T>
T& LstQue<T>::PushQue(const T& r)  //插入元素，返回队尾指针
{
	if (this->Empty())
	{
		this->tail = new QNote<T>(r, nullptr);
		this->head = this->tail;
		return this->tail->data;
	}
	
	QNote<T> *s = new QNote<T>(r, nullptr);    //创建一个新节点
	this->tail->next = s;                      //把当前最后一个节点指向这个新节点，这个新节点变成最后一个节点
	this->tail = s;                            //把队尾指针指向这个新节点，最后一个节点

	return this->tail->data;
}

template<typename T>
QNote<T>* LstQue<T>::PopQue()             //删除元素，返回队头指针,链队列为空，抛出一个string异常
{
	if (this->Empty())
		throw string("链队列为空");

	if (this->head->next == nullptr)    //当只有一个节点的情况
	{
		delete this->head;              //只有一个节点，直接delete这个元素
		this->head = nullptr;           //然后把队头队尾指针置为空
		this->tail = nullptr;
		return this->head;
	}


	QNote<T> *pd = this->head;        //创建一个pd指针指向第一个元素
	this->head = this->head->next;    //队头指针，指向下一个元素
	delete pd;                        //释放原来的元素
	return this->head;                //返回如今的队头指针
}

template<typename T>
void LstQue<T>::ClearQue()                //清空链队列
{
	if (this->Empty())
		return ;

	QNote<T> *pd = this->head;
	while (this->head->next != nullptr)
	{
		this->head = this->head->next;
		delete pd;
		pd = this->head;
	}
	delete pd;
	this->head = nullptr;
	this->tail = nullptr;
}

template<typename T>
int LstQue<T>::LengthQue()const           //返回链队列的长度
{
	if (this->Empty())
		return 0;

	QNote<T> *p = this->head;
	int i = 0;
	while (p->next != nullptr)
	{
		p = p->next;
		++i;
	}
	return ++i;

}








void test00(void)
{
	LstQue<string> lq;
	cout << "lq链队列是否为空： " << lq.Empty() << endl;    //1
	string ret;
	try
	{
		ret = lq.GetElem();
	}
	catch (const string& s)
	{
		cout << s << endl;     //异常
	}
	cout << "lq链队列的长度为： " << lq.LengthQue() << endl;

	ret = lq.PushQue("宁");
	cout << "队尾元素为： " << ret << endl;    //宁
	lq.PopQue();    //删除元素
	cout << "lq链队列是否为空： " << lq.Empty() << endl;    //1

}


struct person
{
	person (string name = "", int age = 0) : m_name(name), m_age(age) {  }
	string m_name;
	int m_age;
};

void test01(void)
{
	LstQue<person> le(person("宁", 2400));
	le.PushQue(person("月", 12220));
	le.PushQue(person("青", 6000));
	le.PushQue(person("卿", 4000));
	le.PushQue(person("尘", 24));
	//此时队伍是  宁  月  青  卿  尘
	 cout << "le链队列的长度：  " << le.LengthQue() << endl;

	 person ret;
	 int i = 0;
	 int j = le.LengthQue();
	for (; i < j; ++i)
	{
		ret = le.GetElem();
		cout << "依次出队： " << ret.m_name << endl;
		le.PopQue();
	}

	le.PushQue(person("月", 12220));
	le.PushQue(person("青", 6000));
	le.PushQue(person("卿", 4000));
	le.PushQue(person("尘", 24));
	le.PushQue(person("月", 12220));
	le.PushQue(person("青", 6000));
	le.PushQue(person("卿", 4000));
	le.PushQue(person("尘", 24));

	cout << "le链队列当前长度为： " << le.LengthQue() << endl;    //8
	le.ClearQue();
}


int main()
{
	//test00();
	test01();

	system("pause");
	return 0;
}