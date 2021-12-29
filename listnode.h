#ifndef __LISTNODE_H__

    #define __LISTNODE_H__
  
    
    typedef struct Node {
        int id; 
        struct listedge* listinto;
        struct listedge* listoutfrom;

        struct Node* next; 
    } Node, *PNode;

    Node* create_node(int);
    void add(Node**, int);
    void add_first(Node**, int);
    void add_last(Node**, int);
    void change_node(Node* , Node** );
    void deleten(Node**);
    void print_list(Node*);
    void remove_node(Node**, int);
    

#endif