#include<iostream>
using namespace std;


template<typename T>
class Note
{
public:
	Note() : next(nullptr), data(0) {  }
	Note(const T &r, Note *n = nullptr) : data(r), next(n) {  }

	T data;                  //������
	Note<T> *next;    //ָ����
};

//ͷָ�룺����Ŀ�ʼ����
template<typename T>
class AWayList
{
public:
	AWayList(const T &r);  //�в�
	~AWayList();     //����

	Note<T>* push_front(const T &r);    //ͷ�巨
	Note<T>* push_back(const T &r);     //β�巨
	Note<T>* Insert(const T &r, int n); //���뷨
	size_t Size()const;  //��������Ĵ�С

	bool Empty()const;    //�ж��Ƿ�Ϊ�ձ�
	void Clear();    //�������
	Note<T>* GetElem(const int &pos)const;   //���ص�pos��Ԫ��
	Note<T>* LocateElem(const T &rhs)const;  //���Ҹ���Ԫ�أ�����������һ��Ԫ�ص�ָ��
	bool Del(const int &pos);       //ɾ��posλ�õ�Ԫ�أ�ʧ�ܷ���0

	void for_each() const
	{
		Note<T> *p = this->m_headp;
		for (; p != nullptr; p = p->next)
		{
			cout << p->data << " " ;
		}
	}

	Note<T> *m_headp;  //ͷָ�룬ָ��ͷ���
};



template<typename T>
AWayList<T>::AWayList(const T& r) : m_headp(new Note<T>(r, nullptr))  //�в�
{
	
}

template<typename T>
AWayList<T>::~AWayList()     //����
{
	//cout << "AWayList��������" << endl;
	this->Clear();
	delete this->m_headp;
	this->m_headp = nullptr;
}



template<typename T>
Note<T>* AWayList<T>::push_front(const T& r)    //ͷ�巨������ָ���һ��Ԫ�ص�ָ��
{
	Note<T> *p = this->m_headp;
	Note<T> *s = new Note<T>(r, p->next);
	p->next = s;
	return p;
}

template<typename T>
Note<T>* AWayList<T>::push_back(const T& r)     //β�巨������ָ�����һ��Ԫ�ص�ָ��
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
Note<T>* AWayList<T>::Insert(const T& r, int n)  //���뷨�����ز����Ԫ��ָ�����һλ
{
	Note<T> *p = this->m_headp;  //���ȴ��������ڵ�ָ��
	Note<T> *s = nullptr;

	int i = 1;
	while (p->next != nullptr && i < n)
	{
		p = p->next;
		++i;
	}
	if (p == nullptr || i > n )    //���ͷָ���ǿ�ָ�룬���ؼ�
		throw string("ͷָ��Ϊ�ջ�����λ��С��0");

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
bool AWayList<T>::Empty() const    //�ж��Ƿ�Ϊ�ձ�
{
	if (this->m_headp->next == nullptr)
		return true;
	return false;
}

template<typename T>
void AWayList<T>::Clear()    //�������
{
	if (this->Empty() == true)
	{
		return;  //���Ϊ�棬���Ǳ���ͷ�ڵ�
	}

	Note<T>* pd = this->m_headp->next;   //��ͷ�ڵ����һ��Ԫ�ؿ�ʼdelete
	Note<T>* pn = pd->next;              //ά����һ��Ԫ��
										 //ͷ�ڵ��������������ͷ�

	int i = 1;
	while (pn != nullptr)
	{
		delete pd;
		pd = pn;
		pn = pd->next;
		++i;
	}
	delete pd;

	//cout << "delete " << i << " ��" << endl;

}


template<typename T>
Note<T>* AWayList<T>::GetElem(const int& pos)const	//���ص�pos��Ԫ��
{
	Note<T>* p = this->m_headp;
	if (pos > (int)this->Size() + 1)
		throw string("pos���������С");
	if (pos < 0)
		throw string("������С��0��Ԫ��");

	int i = 0;
	while (i < pos)
	{
		p = p->next;
		++i;
	}
	return p;
}

template<typename T>
Note<T>* AWayList<T>::LocateElem(const T& rhs)const  //���Ҹ���Ԫ�أ���������Ԫ�ص�ָ��
{
	Note<T>* p = this->m_headp;

	while (p->data != rhs && p->next != nullptr)
	{
		p = p->next;
	}
	if (p->data != rhs)
	{
		throw string("δ�ҵ�Ԫ��");
	}
	return p;
}

template<typename T>
bool AWayList<T>::Del(const int& pos)       //ɾ��posλ�õ�Ԫ�أ�ʧ�ܷ���0
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

	//��pd��next��ֵ��p��next
	p->next = pd->next;
	delete pd;
	return true;
}





void test00(void)
{
	AWayList<string> s("head");
	s.push_back("��");
	s.push_back("��");
	s.push_back("��");
	s.push_back("��");
	s.push_back("��");
	s.Insert("��", 1);
	auto  pn = s.Insert("��", 4);    //���ص�ָ���ǲ��볾����һ��ָ��
	s.for_each();
	cout << endl;
	cout << s.Size() << endl;
	cout << pn->data << endl;     //������һ��ָ�룺��
	cout << pn->next->data << endl;  //��
}

void test01(void)
{
	AWayList<string> s1("head");
	s1.push_front("��");
	s1.push_front("��");
	s1.push_front("��");
	s1.push_front("��");
	s1.push_front("��");
	s1.for_each();
	cout << endl;
	cout << s1.Size() << endl;
	s1.push_back("��");
	s1.push_back("��");
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
	s.push_back("��");
	s.push_back("��");
	s.push_back("��");
	s.push_back("��");
	s.push_back("��");
	s.for_each();
	cout << endl;
	auto it = s.GetElem(3);
	cout << "��3��Ԫ���ǣ� " << it->data << endl;
	it = s.GetElem(5);
	cout << "��5��Ԫ���ǣ� " << it->data << endl;

	Note<string>* ip = nullptr;
	try
	{
		ip = s.LocateElem("��");
	}
	catch (string& s)
	{
		cout << s << endl;
	}
	cout << "���ҵ�Ԫ��data�ǣ� " << ip->data << "  ��һ��ָ���ǣ� " << ip->next << endl;

	bool ret = s.Del(1);
	s.for_each();
	cout << endl;
	cout << "ret = " << ret << endl;
}


void test03(void)
{
	AWayList<string> p("head");
	p.push_back("ϣ");
	p.push_front("��");
	p.push_back("��");
	p.Insert("��", 2);
	p.Insert("��", 2);
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
