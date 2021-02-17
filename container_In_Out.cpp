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

	void container::Out(ofstream& ofst) // ����� ����������� ����������
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

	container::container() // ������������� ����������
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

	container::~container() // ������� ���������� �� ���������
	{
		Clear();
	}

} // end simple_shapes namespace