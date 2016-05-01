#include<iostream>
using namespace std;
#ifndef __TEST_H__
#define __TEST_H__

#endif
class Node {
public:
	int num ;
	Node* next;
};
//int getArrayLen(Node& array)
//{
//return (sizeof(array) / sizeof(array[0]));
//}
template <class T>
class List
{
public:
	T* head = new T;

//private:
	List() { head->num = -1; }
	void create(int num);
	void destroy(T* head);
	T* search(T* head, int num);
	void insert(T* head, T* node_in);
	T* del(T* head, int num);
	T* yuesefu(int total_num, int start_num, int interval_num);
	void display(T* head);
	~List(){ destroy(head); }
};

template <class T>
void List<T>::create(int num)
{
	int cnt = 1;
	T* first_node = new T;
	head->next = first_node;
	first_node->num = 1;

	while (cnt<num)
	{
		T* new_node = new T;
		first_node->next = new_node;
		new_node->num = first_node->num + 1;
		first_node = new_node;
		cnt++;
	}
	first_node->next = head;
}

template <class T>
void List<T>::destroy(T* head)
{
	T* pre_point ;
	T* point;
	pre_point = head;
	point = head->next;
	while (point != NULL && point !=head)//|| p_next != 0xdddddddd
	{
		delete pre_point;
		pre_point = NULL;
		pre_point = point;
		point = point->next;
	}
}

template <class T>
T* List<T>::search(T* head, int num)
{
	T* _head = head;
	int cnt = 0;
	while (cnt < num)
	{
		_head = _head->next;
		cnt++;
	}
	return _head;
}

template <class T>
void List<T>::insert(T* head, T* node_in)
{
	//´ıÊµÏÖ
}

template <class T>
T* List<T>::del(T* head, int num)
{
	T* pre_target ;
	T* target ;
	pre_target = List::search(head, num);
	target = pre_target->next;
	pre_target->next = target->next;
	//delete target;
	return pre_target->next;
}

template <class T>
void List<T>::display(T* head)
{
	while (head->next->num != -1)
	{
		cout << head->next->num << "  ";
		head = head->next;
	}
}

template <class T>
T* List<T>::yuesefu(int total_num, int start_num, int interval_num)
{
	List<T>::create(total_num);
	cout << "The Joseph circle is:"<<endl;
	display(head);
	T* start_node = head ;
	int spec = start_num + interval_num;
	if (start_num>total_num)
	{
		while (start_num>total_num)
		{
			start_num = start_num%total_num;
		}
	}

	if (interval_num>total_num)
	{
		while (interval_num>total_num)
		{
			interval_num = interval_num%total_num;
		}
	}
	while (total_num>1)
	{
		if (spec > total_num)
		{
			while (spec > total_num)
			{
				spec = spec%total_num;
			}
		}
		start_node = List<T>::del(head, spec);
		start_num = start_node->num;
		total_num--;
		spec = spec + interval_num;
	}
	return start_node;
}

void main()
{
	List<Node> list; 
	Node* last_node = new Node;
    int total_num,  start_num,  interval_num;
	cout<<"Please input total number of people:";
	cin>>total_num;
	cout<<"Please input start number of Joseph circle:";
	cin>>start_num;
	cout<<"Please input interval number of Joseph circle:";
	cin>>interval_num;
	
	last_node = list.yuesefu(total_num, start_num, interval_num);
	cout << endl;
	cout << "The last person is:" << endl;
	cout << last_node->num << endl;
	system("pause");
}
