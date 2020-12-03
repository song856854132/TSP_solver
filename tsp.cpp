#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <algorithm>
#include "tsp.h"
TSP_solution::TSP_solution(/* args */)
{
    city_num = 0;
}

TSP_solution::~TSP_solution()
{
}

void TSP_solution::add_node(tsp_node tmpnode, int num)
{
    node[num].x = tmpnode.x;
    node[num].y = tmpnode.y;
    city_num++;
}

void TSP_solution::create_array()
{
    tsp_edge** arr = new tsp_edge*[city_num];
    int** dp_tree = new int*[city_num*city_num];    
    for(int i=0; i<city_num; i++)
        arr[i] = new tsp_edge[city_num];
    for(int j=0; j<city_num*city_num; j++)
        dp_tree[j] = new int[city_num];
    VISIT_ALL = (1<<city_num)-1;
    for(int i=0; i<city_num; i++)
        for(int j=0; j<city_num; j++)
        {
            arr[i][j].dst = sqrt(pow((node[i].x - node[j].x),2)+pow((node[i].y - node[j].y),2));
            arr[i][j].last_node = node[i];
            arr[i][j].next_node = node[j];
        }
    
    matric = arr;
    tree = dp_tree;
}
// void TSP_solution::brutal_force()
// {
    
// }
void TSP_solution::dynamic_program(int mask, int pos)
{
    if(mask==VISIT_ALL)
        return;
    int dst = __INT_MAX__, chosenCity;

    for(int city=0; city<city_num; city++)
    {
        if((mask&(1<<city))==0)
        {
            int newdst = matric[pos][city].dst + tree[mask|(1<<city)][city];
            if(newdst < dst)
            {
                dst = newdst;
                chosenCity = city;
            }
        }
    }
    std::cout<<chosenCity<<"-->";
    dynamic_program(mask|(1<<chosenCity),chosenCity);
    
}
