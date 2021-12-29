



#ifndef __LISTEDGE_H__

    #define __LISTEDGE_H__
   

    typedef struct Edge {
         PNode* n; 
        float weight;
       

        struct Edge* next; 
    } Edge , *PEdge;



    Edge* create_edge(Node* , float);
    void add_firste(Edge** , Node* , float);
    void add_laste(Edge** , Node* , float );
    void deletee(Edge**);
    void print_liste(Edge*);
    void remove_edge( Edge** , Node* );

#endif