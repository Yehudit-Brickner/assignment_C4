#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;



//node 
node* create_node(int id) ;
void add(node** H, int id);
void add_first(node** H, int id);
void change_node(node* , node** );
void deleten(node**);
void print_list(node*);
void remove_node(node**, int);

//edge
edge* create_edge( node* dest, int weight);
void add_firste(node** H, int src_id, node* dest, int weight);
void deletee(edge** H, node* n);
void print_liste(edge** H);
void remove_edge( edge** H, node* del, node* src);



void build_graph_cmd(pnode *head);
void insert_node_cmd(pnode *head);
void delete_node_cmd(pnode *head);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);

int find_num_nodes(node **H);
int* assigment(node **H, node *src);
int* dijakstra(node **H, node *src);
void shortsPath_cmd(node **head, int src, int dest);
void TSP_cmd(node **head, int *arr,int length);
int find_num_nodes(node** H);
void permute(int *a, int left, int right, int lengtha , int **mat, int* low, int count, int max,int *arr);
void swap(int *x, int *y);

#endif
