#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "graph.h"


edge* create_edge( node* dest, int weight){
    edge* e = (edge*)malloc(sizeof(edge));
    if(!e){
        return NULL;
    }
    e->endpoint=dest;
    e->weight=weight;
    e->next=NULL;
    return e;
}


void add_firste(node** H, int src_id, node* dest, int weight){
    if(!H){
        return;
    }
    node* Hcopy=*H;
    while(Hcopy){
        if(Hcopy->node_num==src_id){
            edge* e = create_edge(dest,weight);
        
            if(!e){
                printf("no memory!");
                return;
            }
            edge* tmp=Hcopy->edges;
            e->next=tmp;
            Hcopy->edges=e;
             return;
        }
    Hcopy=Hcopy->next;
   
    }
}


void deletee(edge** H ,node* n){
    if(!(*H)){
        //H=NULL;
        return;

    }
    else{
   // while((*H)!=NULL){
    while(*H){
        edge* tmp = *H;
       *H = (*H)->next;
        free(tmp);
    } 
    n->edges=NULL;
   // H=NULL;
    }
}


void print_liste(edge** H){
    while(*H){
        if((*H)->next!=NULL){
        printf(" n-%d, w-%d -> ", (*H)->endpoint->node_num, (*H)->weight);
        (*H) = (*H)->next;
        }
        else{
        printf("n-%d, w-%d ", (*H)->endpoint->node_num, (*H)->weight);
        (*H) = (*H)->next;   
        }
    }
}


void remove_edge( edge** H, node* del, node* src){ 
    if(!*H)
        return;
    if((*H)->endpoint->node_num == del->node_num){

        edge *tmp = *H;
        src->edges=(*H)->next;
        tmp->endpoint=NULL;
        tmp->weight=INT_MAX;
        free(tmp);

    }
    else{
        edge *tmp = *H;
        while(tmp->next && (tmp->next)->endpoint->node_num != del->node_num){
            tmp = tmp->next;
        }
        if(!tmp->next){
            return;
        }
        edge *tmp2 = tmp->next;
        tmp->next = tmp->next->next;
        tmp=NULL;
        free(tmp2);
    }
}

