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

	void container::OutSquare(ofstream& ofst) 
	{ 
		ofst << "Container contains " << size << " elements. " << endl;
		ofst << "Only square." << endl; 

		node* curNode = head;
		int i = 0;

		while (curNode != NULL)
		{
			ofst << i << ": ";
			curNode->m->OutSquare(ofst);
			curNode = curNode->next;
			i++;
		}
	}

	void matr::OutSquare(ofstream& ofst)
	{
		ofst << endl; // пустая строка 
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

} // end simple_shapes namespace