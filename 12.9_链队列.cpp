#include<iostream>
using namespace std;

template<typename T>
class QNote
{
public:
	QNote() : data(0), next(nullptr) {  }
	QNote(const T &r,  QNote<T>  *p = nullptr) : data(r), next(p) {  }
	T data;          //������
	QNote<T> *next;  //ָ����
};

template<typename T>
class LstQue
{
public:
	LstQue();
	LstQue(const T &r);
	~LstQue();

	bool Empty()const;              //������Ϊ�շ���true
	T& GetElem();                   //���ض�ͷ�ڵ��data,���������Ϊ�գ��׳�һ��string�쳣
	T& PushQue(const T &r);		    //����Ԫ�أ����ض�βָ��
	QNote<T>* PopQue();             //ɾ��Ԫ�أ����ض�ͷָ��,������Ϊ�գ��׳�һ��string�쳣
	void ClearQue();                //���������
	int LengthQue()const;           //���������еĳ���

private:
	QNote<T> *head;     //��ͷָ�룬����ɾ��Ԫ�أ�ָ���һ��Ԫ��
	QNote<T> *tail;     //��βָ�룬���ڲ���Ԫ�أ�ָ�����һ��Ԫ��
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
bool LstQue<T>::Empty()const              //������Ϊ�շ���true
{
	if (this->head != nullptr)
		return false;
	return true;
}

template<typename T>
T& LstQue<T>::GetElem()                   //���ض�ͷ�ڵ��data,���������Ϊ�գ��׳�һ��string�쳣
{
	if (this->Empty())
		throw string("������Ϊ��");
	return this->head->data;
}

template<typename T>
T& LstQue<T>::PushQue(const T& r)  //����Ԫ�أ����ض�βָ��
{
	if (this->Empty())
	{
		this->tail = new QNote<T>(r, nullptr);
		this->head = this->tail;
		return this->tail->data;
	}
	
	QNote<T> *s = new QNote<T>(r, nullptr);    //����һ���½ڵ�
	this->tail->next = s;                      //�ѵ�ǰ���һ���ڵ�ָ������½ڵ㣬����½ڵ������һ���ڵ�
	this->tail = s;                            //�Ѷ�βָ��ָ������½ڵ㣬���һ���ڵ�

	return this->tail->data;
}

template<typename T>
QNote<T>* LstQue<T>::PopQue()             //ɾ��Ԫ�أ����ض�ͷָ��,������Ϊ�գ��׳�һ��string�쳣
{
	if (this->Empty())
		throw string("������Ϊ��");

	if (this->head->next == nullptr)    //��ֻ��һ���ڵ�����
	{
		delete this->head;              //ֻ��һ���ڵ㣬ֱ��delete���Ԫ��
		this->head = nullptr;           //Ȼ��Ѷ�ͷ��βָ����Ϊ��
		this->tail = nullptr;
		return this->head;
	}


	QNote<T> *pd = this->head;        //����һ��pdָ��ָ���һ��Ԫ��
	this->head = this->head->next;    //��ͷָ�룬ָ����һ��Ԫ��
	delete pd;                        //�ͷ�ԭ����Ԫ��
	return this->head;                //�������Ķ�ͷָ��
}

template<typename T>
void LstQue<T>::ClearQue()                //���������
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
int LstQue<T>::LengthQue()const           //���������еĳ���
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
	cout << "lq�������Ƿ�Ϊ�գ� " << lq.Empty() << endl;    //1
	string ret;
	try
	{
		ret = lq.GetElem();
	}
	catch (const string& s)
	{
		cout << s << endl;     //�쳣
	}
	cout << "lq�����еĳ���Ϊ�� " << lq.LengthQue() << endl;

	ret = lq.PushQue("��");
	cout << "��βԪ��Ϊ�� " << ret << endl;    //��
	lq.PopQue();    //ɾ��Ԫ��
	cout << "lq�������Ƿ�Ϊ�գ� " << lq.Empty() << endl;    //1

}


struct person
{
	person (string name = "", int age = 0) : m_name(name), m_age(age) {  }
	string m_name;
	int m_age;
};

void test01(void)
{
	LstQue<person> le(person("��", 2400));
	le.PushQue(person("��", 12220));
	le.PushQue(person("��", 6000));
	le.PushQue(person("��", 4000));
	le.PushQue(person("��", 24));
	//��ʱ������  ��  ��  ��  ��  ��
	 cout << "le�����еĳ��ȣ�  " << le.LengthQue() << endl;

	 person ret;
	 int i = 0;
	 int j = le.LengthQue();
	for (; i < j; ++i)
	{
		ret = le.GetElem();
		cout << "���γ��ӣ� " << ret.m_name << endl;
		le.PopQue();
	}

	le.PushQue(person("��", 12220));
	le.PushQue(person("��", 6000));
	le.PushQue(person("��", 4000));
	le.PushQue(person("��", 24));
	le.PushQue(person("��", 12220));
	le.PushQue(person("��", 6000));
	le.PushQue(person("��", 4000));
	le.PushQue(person("��", 24));

	cout << "le�����е�ǰ����Ϊ�� " << le.LengthQue() << endl;    //8
	le.ClearQue();
}


int main()
{
	//test00();
	test01();

	system("pause");
	return 0;
}