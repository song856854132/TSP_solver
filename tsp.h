#ifndef __TSP_H__
#define __TSP_H__

struct tsp_node
{
    int node_num;
    int x;
    int y; 
    struct tsp_node* next_node;
};

struct tsp_edge
{
    int last_node;
    int next_node;
    int dst;
    struct tsp_edge* next_edge;
};

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

#endif