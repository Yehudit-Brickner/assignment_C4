#include <stdlib.h>
#include <stdio.h>

#include "graph.h"

node* create_node(int id){
    node* n = (node*)malloc(sizeof(node));
    if(!n){
        return NULL;
    }
    n->node_num=id;
    n->edges=NULL;
    n->next=NULL;
    
    return n;
}


void add_first(node** H, int id){
    node* n = create_node(id);
    if(!n){
        printf("no memory!");
        return;
    }
    n->next = *H;
    *H = n;
}


void change_node(node* n1, node** H ){
     edge *e = n1->edges;
     edge *tmp = n1->edges;
     while(!tmp){
         int n = tmp->endpoint->node_num;
         pnode n1=tmp->endpoint;
         node* tmph=*H;
         while(tmph->node_num != n ){
             tmph++;
         }
         tmp++;
     }
 }


void add(node** H, int id){
    if(*H){
        node* tmp = *H;
        while(tmp){
            if(tmp->node_num==id){
                change_node( tmp, H);
                return;
            }
            tmp=tmp->next;
        }
        add_first(H, id);
    }
}


void deleten(node** H){
    if(!H){
        return;
    }
    if(!(*H)->next){
        *H=NULL;
        free(*H);
    }
    else{
        while((*H)->next!=NULL){
            node* tmp = *H;
            *H = (*H)->next;
            edge* e1=tmp->edges;
            deletee(&e1);
            free(tmp);
        }
    
        node* tmp = *H;
        *H = (*H)->next;
        edge* e1=tmp->edges;
        deletee(&e1);
        tmp=NULL;
        free(tmp);
        H=NULL;
        free(H);
    }
}


void print_list(node* H){
    while(H){
        if(H->next!=NULL){ 
            printf("%d ", H->node_num);
            if(H->edges!=NULL){
                printf("edges: ");
                edge *e1=H->edges;
                print_liste(&e1);   
            }
            printf(" => ");
            printf("\n");
            H = H->next;
        }
        else{
            printf("%d ", H->node_num);
            if(H->edges!=NULL){
                printf("edges:");
                edge *e1=H->edges;
                print_liste(&e1);
            }
            H = H->next;
        }
    }
    printf("||\n");
}


void remove_node(node** H, int id){
    node *Hcopy =*H;
    if(!H)
        return;
    
    if((*H)->node_num == id){
        node *tmp = *H;
        edge *e = tmp->edges;
        deletee(&e);
        
        while(Hcopy){
            if(Hcopy!=tmp){
                edge* e1 = Hcopy->edges;
                remove_edge(&e1,tmp);
            }
        }
        Hcopy=Hcopy->next;

        *H=(*H)->next;
        tmp=NULL;
        free(tmp);
        return;
    }
    node *tmp=*H;
    while(tmp->next && tmp->next->node_num !=id){
        tmp=tmp->next;
    }
    if(!tmp->next){
        return;
    }
    node *tmp2=tmp->next;
    while(Hcopy){
        if(Hcopy!=tmp2){
            edge* e1 = Hcopy->edges;
            remove_edge(&e1,tmp2);
            break;
        }
    }
    Hcopy=Hcopy->next;


    
    tmp->next=tmp->next->next;
    edge* e=tmp2->edges;
    deletee(&e);
    free(tmp2);
    
          
}


// int main(){


//     printf("helloworld\n");
//      node* Head1;
//      for (int i=0; i<20;i++){
//         add_first(&Head1,i);
//      }
//      print_list(Head1); 
//      for (int i=0;i<20;i=i+5){
//          remove_node(&Head1,i);
//      }
//      print_list(Head1);
//      deleten(&Head1);
//      print_list(Head1);

//     printf("helloworld\n");

//     return 0;


//  }