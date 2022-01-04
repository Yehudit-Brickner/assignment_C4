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

    

    for (int j=1;j<num;j++){
        
        node *copy=*H;
        while(copy && copy->node_num!=visited[j] ){
            copy=copy->next;    
        }
        if(copy->node_num==visited[j]){
            for(int k=1; k<num;k++){
                edge* ee=copy->edges;
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
        printf("Dijsktra shortest path: 0 \n") ;
    }
    else{
        node *hcopy1=*head;
        while(hcopy1->next && hcopy1->node_num!=dest){
            hcopy1=hcopy1->next;
        }
        if(hcopy1->node_num!=dest){  
            printf("Dijsktra shortest path: -1 \n");
            return; 
        }

        node *hcopy=*head;
        while(hcopy->next && hcopy->node_num!=src){
            hcopy=hcopy->next;
        }
        if(hcopy->node_num==src){
            int *a;
            int *d;
            a=assigment(head,hcopy);
            if(a==NULL){
                printf("problem alocating memory, coudnt run function Shortest Path\n");
                return;
            }
            d=dijakstra(head,hcopy);
            if(d==NULL){
                free(a);
                printf("problem alocating memory, coudnt run function Shortest Path\n");
            }

            int num= find_num_nodes(head);
            int count=1;
            int stop=0;
            for (int i=1;i<num && stop==0;i++){
                if(a[i]!=dest){
                    count=count+1;
                }
                else{
                stop=1;
                    if(d[count]!=INT_MAX){
                        printf("Dijsktra shortest path: %d \n",d[count]) ;
                    }
                    else{
                        printf("Dijsktra shortest path: = -1 \n"); 
                    }
                }
            }

        free(a);
        free(d);  
        }
        else{   
            printf("Dijsktra shortest path: = -1 \n");
        }
    }
}


void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


void permute(int *a, int left, int right, int lengtha , int **mat, int *low, int count, int max,int *arr){

    if (left == right){

        // go through the list and add up from the mat ex 1-2-3 = mat[1][2]+mat[2][3]
        int sum=0;
        int rowcol1=-1;
        int rowcol2=-1;

        for(int j=0; j<lengtha-1;j++){ //val in list
            for (int k=0;k<lengtha+1; k++){ // find column/row in mat
                if(mat[k][0]==a[j]) {
                    rowcol1=k;
                } 
                if(mat[k][0]==a[j+1]){
                    rowcol2=k;
                }
            }
            if(mat[rowcol1][rowcol2]!=INT_MAX){
                sum=sum+mat[rowcol1][rowcol2];
            }
            else{
                sum= INT_MAX;
                break;
            }
        }
        

        // printf("= %d \n",sum);
        if (sum < *low){
            *low =sum;
        }
        for (int k=0;k<max;k++){
            if(arr[k]==INT_MAX){
                arr[k]=*low;
                break;
            }
        }
    }

    
    else{
        for (int i = left; i <= right; i++){
            swap((a+left), (a+i));
            permute(a, left+1, right,lengtha, mat, low, count, max, arr);
            swap((a+left), (a+i)); //backtrack
        }
    }
}



void TSP_cmd(node **head, int* arr, int length){
    for (int i=0;i<length;i++){
        node *hcopy=*head;
        while(hcopy->next && hcopy->node_num!=arr[i]){
            hcopy=hcopy->next;
        }
        if(hcopy->node_num!=arr[i]){  
            printf("TSP shortest path: -1 \n");
            return; 
        }
    }
    int l =length+1;
    int** mat = (int**)malloc(l * sizeof(int*));
    if(!mat){
        printf("problem alocating memory, coudnt run function TSP\n");
    }
    for (int index=0;index<l;++index){
        mat[index] = (int*)malloc(l * sizeof(int));
        if(!mat[index]){
          printf("problem alocating memory, coudnt run function TSP\n");
          for (int j=0;j<index;j++){
              free(mat[j]);
          } 
          free(mat); 
        }
    }    

    for(int i=0; i<l;i++){
        for (int j=0;j<l;j++){
            mat[i][j]=INT_MAX;
        }
    }
    
    //fill in column names and rows names
    for (int i=1; i<l;i++){
        mat[0][i]=arr[i-1];
        mat[i][0]=arr[i-1];    
    }
    
    //** mat[row][column] = mat[from][to]


    // for all numbers in list run digesktra and fill in rows
    int num=find_num_nodes(head);
    // find src
    for (int i=0;i<length;i++){
        node *hcopy= *head;
        while(hcopy&& hcopy->node_num!= arr[i]){
            hcopy=hcopy->next;
        }
        if(hcopy->node_num==arr[i]){  
            //found src  
            int *a = assigment(head, hcopy);
            if(!a){
                printf("problem alocating memory, coudnt run function TSP\n");
                for (int i=0;i<l;i++){
                    free(mat[i]);
                }
                free(mat);
            }
            int *d = dijakstra(head, hcopy);
            if(!d){
                printf("problem alocating memory, coudnt run function TSP\n");
                for (int i=0;i<l;i++){
                    free(mat[i]);
                }
                free(mat);
                free(a);
            }
            // find the row that we are lookin for
            int r =a[0];
            int row=0;
            for (int j=1;j<l;j++){
                if(mat[j][0]==r){
                    row=j;
                }
            }
            for(int j=0; j<length+1;j++){
                int col=-1;
                for (int k=0; k<num; k++){
                    if(col==-1){
                        if(a[k]==mat[0][j]){
                            col=k;
                            mat[row][j]=d[k];
                        }
                    } 
                } 
            }
            free(a);
            free(d);
        }

        else{
        // return not in graph
        }
    }

    int count=1;
    int listlen=1;
    while (count<=length){
        listlen=listlen*count;
        count=count+1;
    }
    int* list = (int*)calloc(listlen,sizeof(int));
    for (int i=0; i<listlen;i++){
        list[i]=INT_MAX;
    }
    int low=INT_MAX;
    permute(arr,0,length-1, length,mat, &low, 0, listlen, list);
    
    int ans=low;
    
  
    if(ans!=INT_MAX){
    printf("TSP shortest path: %d \n",ans);
    }
    else{
     printf("TSP shortest path: -1 \n");   
    }

    for (int i=0;i<l;i++){
        free(mat[i]);
    }
    free(mat);
    free(list);
           
}   






