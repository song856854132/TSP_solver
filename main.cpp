#include <iostream>
#include <fstream>
#include "tsp.h"

using namespace std;

int main()
{
    fstream input_file;
    TSP_solution TSP;
    struct tsp_node *head;
    struct tsp_node *tail;
    input_file.open("readfile.txt",ios::in);

    int city, x, y, city_num=0;
    //first time stream from file
    //input_file>>city>>x>>y;
    //struct tsp_node node = {city,x,y};
    //head = tail = &node;
    while (input_file>>city>>x>>y)
    {   // reading from file and push into ring: node1->node2->node3->......->node1 
        struct tsp_node tmp_node = {city,x,y};
        TSP.add_node(tmp_node);
        city_num++;
    }
    TSP.create_array();
    TSP.DP(1,0);
    // print the path
    while(head->next)
    {
        printf();
    }
}