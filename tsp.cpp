#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include "tsp.h"
TSP_solution::TSP_solution(/* args */)
{
    city_num = 0;
}

TSP_solution::~TSP_solution()
{
}

void TSP_solution::add_node(tsp_node tmpnode)
{
    node[city_num].x = tmpnode.x;
    node[city_num].y = tmpnode.y;
    node[city_num].node_name = tmpnode.node_name;
    city_num++; //max number of city
}

void TSP_solution::create_array()
{
    tsp_edge** arr = new tsp_edge*[city_num];
    double** dp_tree = new double*[int(pow(2,city_num))];    
    for(int i=0; i<city_num; i++)
        arr[i] = new tsp_edge[city_num];
    for(int i=0; i<pow(2,city_num); i++){ //i means all sub set of city. Ex: if contain 5,3,1,0 city, i=101011
        dp_tree[i] = new double[city_num]; 
        for(int j=0; j<city_num; j++){
            dp_tree[i][j]=__INT_MAX__;//first city to city j and contain i
        }
    }
    VISIT_ALL = (1<<city_num)-1;// = 11111111111
    for(int i=0; i<city_num; i++){
        for(int j=0; j<city_num; j++)
        {
            arr[i][j].dst = sqrt(pow((node[i].x - node[j].x),2)+pow((node[i].y - node[j].y),2));
            arr[i][j].last_node = node[i];
            arr[i][j].next_node = node[j];
        }
        arr[i][i].dst=__INT_MAX__;
    }
    path =new std::vector<int>* [1 << city_num];
    for(int i=0;i<1<<city_num;i++)
        path[i] = new std::vector<int> [city_num];
    matric = arr;
    tree = dp_tree;
    tree[1][0] = 0;//start
}

void TSP_solution::dynamic_program()
{
    for(int i=1; i<=VISIT_ALL; i++)//all sub set of city list(2^n)
    {
        if(!(i&1))//contain first city
            continue;
        for(int current=0; current<city_num;current++)
        {
            if(!(i&(1<<current)))//contain current city
                continue;
            for(int next=0; next<city_num; next++)
            {
                if((i&(1<<next))==0)//if next city hasn't visited
                {
                    double newdst = tree[i][current] + matric[current][next].dst; //i=city list, tree means best distance between first city and current city.
                    if(newdst < tree[i|(1<<next)][next]){
                        tree[i|(1<<next)][next] = newdst; //list add next city, distance between first and next.
                        path[i|(1<<next)][next] = path[i][current]; 
                        path[i|(1<<next)][next].push_back(next);
                    }
                }
                
            }
        }

    }
}

void TSP_solution::get_path()
{
    int mask = VISIT_ALL;
    double min=__INT_MAX__;
    int min_city;
    for(int j=0;j<city_num;j++)//min(tree[VISIT_ALL][j]+dst[j][0])
    {
        if(tree[mask][j] + matric[j][0].dst<min)
        {
            min=tree[mask][j] + matric[j][0].dst;
            min_city = j;
        }
    }
    printf("Best distance: %lf\n",min);
    std::cout<<"Path: 1 ";
    for(size_t i=0;i<path[VISIT_ALL][min_city].size();i++){
        std::cout<<node[path[VISIT_ALL][min_city][i]].node_name<<" ";
    }
    std::cout<<std::endl;

}

void TSP_solution::test(){
    double dst;
    int a,b=0;
    for(int i=0;i<city_num;i++){
        std::cin>>a;
        a-=1;
        dst+=matric[b][a].dst;
        b=a;
    }
    printf("Test Dst: %lf\n",dst);
}
