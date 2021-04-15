#pragma once
#ifndef __container_atd__
#define __container_atd__
#include "matr_atd.h"

namespace simple_matrix
{
    class node
    {
    public:
        matr* m;
        node* next;
        bool add_node(ifstream& ifst);
        bool output_node(ofstream& ofst);
        ~node();
    };

    struct container
    {
    public:
        int size;
        node* head;
        void In(ifstream& ifst);
        void Out(ofstream& ofst);
        void Multimethod(ofstream& ofst);
        void Clear();

        node* get_node(int index);

        container();
        ~container();
    };
} // end simple_matrix namespace
#endif
