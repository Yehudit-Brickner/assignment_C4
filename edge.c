

#include<stdio.h>
#include<string.h>



#include "Listnode.h"
#include "listedge.h"
# include "node.c"




Edge* create_edge(Node* n, float weight){
    Edge* e = (Edge*)malloc(sizeof(Edge));
    if(!e){
        return NULL;
    }
    e->n=n;
    e->weight=weight;
    return e;
}

void add_firste(Edge** H, Node* n, float weight){
    Edge* e = create_edge(n,weight);
    if(!e){
        printf("no memory!");
        return;
    }
    e->next = *H;
    *H = e;
}


void add_laste(Edge** H, Node* n, float weight){
    Edge* e = create_edge(n,weight);
    if(!e){
        printf("no memory!");
        return;
    }
    if(!*H){
        *H = e;
        return;
    }
    Edge * tmp = *H;
    while(tmp->next)
        tmp = tmp->next;
    tmp->next = e;
}


void deletee(Edge** H){
    while(*H){
        Edge* tmp = *H;
        *H = (*H)->next;
        free(tmp);
    }
}




void print_liste(Edge* H){
    while(H){
        printf("%d, %f -> ", H->n->id, H->weight);
        H = H->next;
    }
    printf("||\n");
}


void remove_edge( Edge** H, Node* n){
    if(!*H)
        return;
    if((*H)->n->id == n->id){
        struct Edge *tmp = *H;
        *H = (*H)->next;
        free(tmp);
    }
    struct Edge *tmp = *H;
    while(tmp->next && (tmp->next)->n->id != n->id){
        tmp = tmp->next;
    }
    if(!tmp->next){
        return;
    }
    Edge *tmp2 = tmp->next;
    tmp->next = tmp->next->next;
    free(tmp2);
}








