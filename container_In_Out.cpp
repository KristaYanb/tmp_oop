#include "container_atd.h"
#include <iostream>
using namespace std;

namespace simple_matrix
{
	node::~node() {}

	bool node::add_node(ifstream& ifst)
	{
		m = matr::In(ifst);
		if (m == NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	void container::In(ifstream& ifst)
	{
		while (!ifst.eof())
		{
			node* tmpNode = new node;
			if (tmpNode->add_node(ifst)) 
			{
				size++;
				if (head != NULL) 
				{
					tmpNode->next = head;
					head = tmpNode;
				}
				else 
				{
					tmpNode->next = NULL;
					head = tmpNode;
				}
			}
		}
	}

	bool node::output_node(ofstream& ofst)
	{
		m->Out(ofst);
		return true;
	}

	void container::Out(ofstream& ofst) // Вывод содержимого контейнера
	{
		ofst << "Container contains " << size << " elements. " << endl;		
		node* curNode = head;
		int i = 0;

		while (curNode != NULL)
		{
			ofst << i << ": ";
			curNode->output_node(ofst);
			curNode = curNode->next;
			i++;
		}
	}

	container::container() // Инициализация контейнера
	{
		size = 0;
		head = NULL;
	}

	void container::Clear()
	{
		node* curNode;
		curNode = head;
		while (curNode != NULL)
		{
			node* temp = curNode->next;
			delete curNode;
			curNode = temp;
		}
		head = NULL;
		size = 0;
	}

	container::~container() // Очистка контейнера от элементов
	{
		Clear();
	}

	node* container::get_node(int index)
	{
		node* retNode = head;

		for (int i = 0; i < index; i++) 
		{
			retNode = retNode->next;
		}

		return retNode;
	}

	// Вызов мультиметода для элементов контейнера 
	void container::Multimethod(ofstream &ofst) 
	{ 
		ofst << "\nMultimethod." << endl; 
		for(int i = 0; i < size - 1; i++) 
		{ 
			for(int j = i + 1; j < size; j++) 
			{
				get_node(i)->m->Multimethod(get_node(j)->m, ofst);
				get_node(i)->output_node(ofst);
				get_node(j)->output_node(ofst);
			} 
		} 
	}
} // end simple_shapes namespace