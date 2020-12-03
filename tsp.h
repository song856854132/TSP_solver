#ifndef __TSP_H__
#define __TSP_H__

#define MAX_CITY 100
struct tsp_node
{
    int node_num;
    int x;
    int y; 
    struct tsp_node *next;
};

struct tsp_edge
{
    tsp_node last_node;
    tsp_node next_node;
    int dst;
};
/*
class Brutal_Algorithm
{
    struct tsp_node *node_head;
    struct tsp_node *node_tail;
    struct tsp_edge *edge_head;
    struct tsp_node *edge_tail;
    int *array;

public:
    Brutal_Algorithm();
    int** create_array(int city_num);
    void add_node(struct tsp_node node);
    ~Brutal_Algorithm();
};
*/

class TSP_solution
{
private:
    tsp_node node[MAX_CITY];
    tsp_edge** matric;
    int **tree;
    int city_num;
    int VISIT_ALL;

public:
    void add_node(tsp_node tmp, int num);
    void create_array();
    //void brutal_force();
    void dynamic_program(int mask, int pos);
    TSP_solution(/* args */);
    ~TSP_solution();
};


#endif