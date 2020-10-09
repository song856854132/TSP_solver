#include <iostream>
#include <stdlib.h>
#include "tsp.h"
int** Brutal_Algorithm::create_array(int city_num)
{   // dynamic @D array generate 
    int** a = new int*[city_num+1];
    for(int i = 0; i < city_num+1; ++i)
        a[i] = new int[city_num+1];

    // list all possible path into array

    return a;
}

void Brutal_Algorithm::add_node(struct tsp_node node)
{   // adding node to the ring
    if (/* condition */) // non node in the ring
    {
        node_head = node_tail = 
    }
    else                // one or more nodes in the ring
    {
        
    }
    
    // generate a all-connecting graph

    
}