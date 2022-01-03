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
        return;
    }
    if(!(*H)->next){
       // *H=NULL;
        free(*H);
        H=NULL;
    }
    else{
        while((*H)!=NULL){
            edge* tmp = *H;
            *H = (*H)->next;
            free(tmp);
        }
        // edge* tmp = *H;
        // *H = (*H)->next;
        // tmp=NULL;
        // free(tmp);
        // H=NULL;
        // free(H);
    }
    n->edges=NULL;
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
        //edge *tmp2 =*H;
        src->edges=(*H)->next;
       // *H = (*H)->next;
        tmp->endpoint=NULL;
        tmp->weight=INT_MAX;
        //*H=tmp->next;
        //tmp=NULL;
        
        //tmp->next=NULL;
        free(tmp);
    
       // printf("deletd the first edge\n");
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


/*
// int main(){
//      printf("helloworld\n");
//      pnode Head1;
//      Head1= (pnode) malloc (sizeof(node));
//      Head1->node_num=0;
//      Head1->edges=NULL;
//      Head1->next= NULL;
//       printf("helloworld\n");
//        printf("hi1\n");
   
//     print_list(Head1); 
   
//    printf("hi1\n");
   
//      for (int i=1;i<7;i++){
//          add(&Head1,i);
//      }
//     printf("hi1\n");
//     // making sure that adding edges workes
//     node *tmp2=NULL;
//     node *Hcopy=Head1;
//     for (int i=1;i<7;i++){
//         node *Hcopy=Head1;
//         while(Hcopy){
//             if(Hcopy->node_num==i){
//                 tmp2=Hcopy;
//                 break;
//             }
//         Hcopy=Hcopy->next;
//         }   
//         for(int j=1;j<7;j++){
//             if(j!=i){
//                 add_firste(&Head1, j,tmp2,j);       
//             }
//         }
//     }
//     printf("hi\n");
//     print_list(Head1);
//     // making sure that removing edges workes
//     node *tmp3=NULL;
//     node *Hcopy1=Head1;
//     edge *H =Hcopy1->next->edges;
//     int i=6;
//     while(Hcopy1){
//         if(Hcopy1->node_num==i){
//             tmp3=Hcopy;
//            break;
//         }
//         Hcopy1=Hcopy1->next;
//     }

//     //remove_edge(&H,tmp3);   
//         // need to send pointer to the linkedlist of edges    
    
//      remove_node (&Head1, 3);  
    
//     print_list(Head1);  
//     deleten(&Head1);
//     free(Head1);
//     print_list(Head1);
//     printf("helloworld\n");
    
// return 0;
    

// }
*/