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
        ~node();
    };

    struct container
    {
    public:
        int size;
        node* head;
        void In(ifstream& ifst);
        void OutSquare(ofstream& ofst);
        void Clear();

        container();
        ~container();
    };
} // end simple_matrix namespace
#endif
