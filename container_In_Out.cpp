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
		if (m->k2 == 0)
		{
			m->Out1(ofst);
			return true;
		}
		if (m->k2 == 1)
		{
			m->Out2(ofst);
			return true;
		}
		if (m->k2 == 2)
		{
			m->Out3(ofst);
			return true;
		}
	}

	int node::summa_node(ofstream& ofst)
	{
		return m->Summa();;
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
			curNode->summa_node(ofst);
			ofst << "Summa = " << curNode->summa_node(ofst) << endl;
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