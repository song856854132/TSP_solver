#include <iostream>
#include <fstream>
#include "tsp.h"

using namespace std;

int main()
{
    fstream input_file;
    Brutal_Algorithm TSP;
    struct stp_node *head;
    struct stp_node *tail;
    input_file.open("readfile.txt",ios::in);

    int city, x, y, city_num=0;
    //first time stream from file
    //input_file>>city>>x>>y;
    //struct stp_node node = {city,x,y};
    //head = tail = &node;
    while (input_file>>city>>x>>y)
    {   // reading from file and push into ring: node1->node2->node3->......->node1 
        struct stp_node tmp_node = {city,x,y};
        TSP.add_node(tmp_node);
        city_num++;

    }
    TSP.create_array(city_num);
    

}