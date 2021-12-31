#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "graph.h"
#include "node.c"
#include "edge.c"

int find_num_nodes(node **H){
    node *hcopy = *H;
    if (!(hcopy)){
        return 0;
    }
    int count = 0;
    while (hcopy){
        count = count + 1;
        hcopy = (hcopy)->next;
    }
    return count;
}



int* assigment(node **H, node *src){
    int num = find_num_nodes(H);

    int *visited;
    visited = (int *)calloc(num, sizeof(int));
    if (!visited){
        return NULL;
    }
    node *Hcopy = *H;
    int i = 1;
    visited[0] = src->node_num;
    while (Hcopy){
        if (Hcopy != src){
            visited[i] = Hcopy->node_num;
            i = i + 1;
        }
        Hcopy = Hcopy->next;
    }
    return visited;
}





int* dijakstra(node **H, node *src){
    int num = find_num_nodes(H);

    // int *visited;
    // visited = (int *)calloc(num, sizeof(int));
    // if (!visited){
    //     return NULL;
    // }
    // node *Hcopy = *H;
    // int i = 1;
    // visited[0] = src->node_num;
    // while (Hcopy){
    //     if (Hcopy != src){
    //         visited[i] = Hcopy->node_num;
    //         i = i + 1;
    //     }
    //     Hcopy = Hcopy->next;
    // }

    int *visited = assigment(H, src);
    if(visited==NULL){
        return NULL;
    }


    int *dist;
    dist = (int *)calloc(num, sizeof(int));
    if (!dist){
        return NULL;
    }
    for (int i = 0; i < num; i++){
        dist[i] = INT_MAX;
    }
    dist[0] = 0;
    // print for self check
    for (int i = 0; i < 4; i++){
        printf("%d,", dist[i]);
    }
    printf("\n");

    // starting the actual algo
    //filling initial distance from src to all others
    node *copy = *H;
    for (int j = 1; j < num; j++){
        edge *ecopy = src->edges;
        while (ecopy != NULL && ecopy->endpoint->node_num != visited[j]){
            ecopy = ecopy->next;
        }
        if (ecopy != NULL){
            if (ecopy->endpoint->node_num == visited[j]){
                dist[j] = ecopy->weight;
            }
        }
    }
    printf("dist should have the initial distance from src to all other\n");
    // print for self check
    for (int i = 0; i < 4; i++){
        printf("%d,", dist[i]);
    }
    printf("\n");

    

    for (int j=1;j<num;j++){
        
        node *copy=*H;
        while(copy && copy->node_num!=visited[j] ){
            copy=copy->next;    
        }
        if(copy->node_num==visited[j]){
            edge* ee=copy->edges;
            for(int k=1; k<num;k++){
                if(k!=j){
                    while (ee != NULL && ee->endpoint->node_num != visited[k]){
                        ee = ee->next;
                    }
                    if (ee != NULL){
                        if (ee->endpoint->node_num == visited[k]){
                            if(dist[j] != INT_MAX){
                                if (dist[k] > dist[j]+ee->weight){
                                    dist[k]=dist[j]+ee->weight;
                                }
                            }
                        }
                    }   
                }
            }
        }

    }



    free(visited);
    return (dist);
}





void shortsPath_cmd(node **head , int src,int dest){
    if(src==dest){
        printf("ans= 0\n") ;
    }
    else{
    
    node *hcopy=*head;
    while(hcopy && hcopy->node_num!=src){
        hcopy=hcopy->next;
    }
    if(hcopy->node_num==src){
        int *a;
        int *d;
        a=assigment(head,hcopy);
        if(a==NULL){
            //return problem
        }
        d=dijakstra(head,hcopy);
        if(d==NULL){
          //return problem  
        }
        // node *hcopy2=*head;
        // while(hcopy2 && hcopy2->node_num!=dest){
        // hcopy2=hcopy2->next;

        int num= find_num_nodes(head);
        int count=1;
        int stop=0;
        for (int i=1;i<num && stop==0;i++){
            if(a[i]!=dest){
                count=count+1;
            }
            stop=1;
            printf("ans= %d\n",d[count]) ;
        }

    free(a);
    free(d);  
    }
    else{   
        printf("ans = -1\n");
    }
    }
}



// void TSP_cmd(pnode head);

int main(){
    int a = INT_MAX;
    printf("hello yehudit %d\n", a);

    pnode Head1;
    Head1 = (pnode)malloc(sizeof(node));
    Head1->node_num = 0;
    Head1->edges = NULL;
    Head1->next = NULL;

    print_list(Head1);

    for (int i = 1; i < 4; i++)
    {
        add(&Head1, i);
    }

    // making sure that adding edges workes
    node *tmp2 = NULL;
    node *Hcopy = Head1;
    int weights[] = {2, 1, 6, 16, 10, 12};
    int count = 0;
    for (int i = 1; i < 4; i++){
        node *Hcopy = Head1;
        while (Hcopy){
            if (Hcopy->node_num == i){
                tmp2 = Hcopy;
                break;
            }
            Hcopy = Hcopy->next;
        }
        for (int j = 1; j < 4; j++){
            if (j != i){
                add_firste(&Head1, j, tmp2, weights[count]);
                count = count + 1;
            }
        }
    }
    print_list(Head1);

    shortsPath_cmd(&Head1, 3,2);
    shortsPath_cmd(&Head1, 0,2);
    shortsPath_cmd(&Head1, 2,2);

    // int *array = dijakstra(&Head1, Head1);
    // printf("print array\n");
    // for (int i = 0; i < 4; i++)
    // {
    //     printf("%d,", array[i]);
    // }
    // printf("\n");

    /*
    // a=find_num_nodes(&Head1);
    // printf("num of nodes is %d\n",a)  ;
    // print_list(Head1);
    // printf("removing 0 ( end of link)\n");
    // remove_node(&Head1, 0);
    // a=find_num_nodes(&Head1);
    // printf("num of nodes is %d\n",a)  ;
    // print_list(Head1);
    // printf("removing 3(begining of link)\n");
    // remove_node(&Head1, 3);
    // a=find_num_nodes(&Head1);
    // printf("num of nodes is %d\n",a)  ;
    // print_list(Head1);
    // printf("adding\n");
    // for (int i=1;i<5;i++){
    //      add(&Head1,i);
    // }
    // a=find_num_nodes(&Head1);
    // printf("num of nodes is %d\n",a)  ;
    // print_list(Head1);
    // printf("removing 2(middle of link)\n");
    // remove_node(&Head1, 2);
    // a=find_num_nodes(&Head1);
    // printf("num of nodes is %d\n",a)  ;
    // print_list(Head1);
    // printf("delete list\n");
    */

    deleten(&Head1);
    a = find_num_nodes(&Head1);
    printf("num of nodes is %d\n", a);

    print_list(Head1);

    return 0;
}