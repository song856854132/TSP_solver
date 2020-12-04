#include <iostream>
#include <fstream>
#include<vector>
#include "tsp.h"

using namespace std;

int main()
{
    fstream input_file;
    TSP_solution TSP;
    input_file.open("readfile.txt",ios::in);

    int x, y, city_num=0;
    char* city_name;
    city_name = new char[20];
    //first time stream from file
    //input_file>>city>>x>>y;
    //struct tsp_node node = {city,x,y};
    //head = tail = &node;
    int t=clock();
    while (input_file>>city_name>>x>>y)
    {   // reading from file and push into ring: node1->node2->node3->......->node1 
        struct tsp_node tmp_node = {city_name,x,y};
        TSP.add_node(tmp_node);
        city_num++;
        city_name = new char[20];
    }
    TSP.create_array();
    TSP.dynamic_program();
    TSP.get_path();
    std::cout<<"Execution Time: "<<(clock()-t)/1e+6<<" s"<<std::endl;
    
    
}