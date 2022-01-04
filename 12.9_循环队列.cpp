#include<iostream>
using namespace std;


const size_t g_QMaxSize = 5;


//循环队列只存放 g_QMaxSize - 1 个元素
//否则 front 和 rear 相等的时候有可能是空队列也有可能是满队列

template<typename T>
class SQueue
{
public:
	SQueue();
	SQueue(const T &r);
	void ClearQ();            //清空队列
	bool Empty()const;        //队列为空返回true
	T& GetElem();             //若队列不为空，返回队列头元素
	bool PushQ(const T &r);   //若队列未满，从队尾插入元素，成功返回true；队列满，或失败false
	bool PopQ();              //删除队头元素，成功返回true；队列为空或失败返回false
	int LengthQ()const;       //返回队列的元素个数

private:
	T data[g_QMaxSize];  
	int front;    //队头的下标用来删除操作，可以理解为指针
	int rear;     //队尾的下标用来插入操作
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
void SQueue<T>::ClearQ()            //清空队列
{
	this->front = 0;
	this->rear = 0;    //把这两个下标值为0，就为空队列了
}

template<typename T>
bool SQueue<T>::Empty()const        //队列为空返回true
{
	if (this->front == this->rear)
		return true;
	return false;
}

template<typename T>
T& SQueue<T>::GetElem()             //若队列不为空，返回队列头元素
{
	if (this->front == this->rear)
		throw string("队列为空");

	return this->data[this->front];
}

template<typename T>
bool SQueue<T>::PushQ(const T& r)   //若队列未满，从队尾插入元素，成功返回true；队列满，或失败false
{
	if ((this->rear + 1) % g_QMaxSize == front)  //队列满为真
		return false;

	this->data[this->rear] = r;
	this->rear = (this->rear + 1) % g_QMaxSize;  //rear向后移动一个位置，若到最后则转到数组头部

	return true;
}

template<typename T>
bool SQueue<T>::PopQ()              //删除队头元素，成功返回true；队列为空或失败返回false
{
	if (this->front == this->rear)  //队列空,为真  
		return false;

	this->front = (this->front + 1) % g_QMaxSize;  //front向后移动一位，相当于删除
					            //若到最后则转到数组的头部
	return true;
}

template<typename T>
int SQueue<T>::LengthQ()const       //返回队列的元素个数
{
	return (this->rear - this->front + g_QMaxSize) % g_QMaxSize;  //得到的是队列中元素的个数
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
	cout << "队列s是否为空： " << s.Empty() << endl;  //1
	cout << "第一个元素插入是否成功： " << s.PushQ(person("宁", 2400)) << endl;   //1
	auto p = s.GetElem();
	cout << "队列s的第一个元素： " << p.m_name << "  " << p.m_age << endl;  //宁  2400
	cout << "第二个元素插入是否成功： " << s.PushQ(person("月", 12400)) << endl;  //1
	cout << "第三个元素插入是否成功： " << s.PushQ(person("青", 3400)) << endl;   //1
	cout << "第四个元素插入是否成功： " << s.PushQ(person("尘", 24)) << endl;     //1
	cout << "第五个元素插入是否成功： " << s.PushQ(person("卿", 4000)) << endl;   //0
	cout << "队列s中的元素个数为： " << s.LengthQ() << endl;   //4

	s.PopQ();  
	cout << "删除第一个元素后，此时长度为" << s.LengthQ() << endl;  //3
	p = s.GetElem();
	cout << "队头是: " << p.m_name << "  " << p.m_age << endl;  //月  12400
	s.ClearQ();
	cout << "清空之后，队列是否为空： " << s.Empty() << endl;  //1

}

int main()
{
	test00();



	system("pause");
	return 0;
}