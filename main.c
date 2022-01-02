
#include<stdio.h>
#include<string.h>
#include <stdlib.h>



#include "graph.h"
#include "algo.c"




int main(){


   printf("helloworld\n");
   // node* Head1;
   // Head1 = (pnode)malloc(sizeof(node));
   // Head1->node_num = 0;
   // Head1->edges = NULL;
   // Head1->next = NULL;
   node* Head1 =create_node(0);
   print_list(Head1);



   for (int i = 1; i < 10; i++){
        add(&Head1, i);
   }

   // making sure that adding edges workes
   node *tmp2 = NULL;
   //node *Hcopy = Head1;
   int weights[] = {2, 1, 6, 16, 10, 12, 14 ,20, 5, 7 ,9 ,15, 1, 6, 16, 10, 12, 14 ,20, 5, 7 ,9 ,15, 1, 6, 16, 10, 12, 14 ,20, 5, 7 ,9 ,15, 1, 6, 16, 10, 12, 14 ,20, 5, 7 ,9 ,15};
   int count = 0;
   for (int i = 0; i < 10; i++){
      node *Hcopy = Head1;
      while (Hcopy){
         if (Hcopy->node_num == i){
            tmp2 = Hcopy;
            break;
         }
         Hcopy = Hcopy->next;
      }
      for (int j = 0; j < 10; j=j+2){
         if (j != i){
            add_firste(&Head1, j, tmp2, weights[count]);
            count = count + 1;
         }
      }
   }
   print_list(Head1);

  // removing node
   printf("\nremoving node 4\n");
   remove_node(&Head1, 0);
   
   
   
   print_list(Head1);


   shortsPath_cmd(&Head1, 8,2);



   int arr[]={8,6,2};
   TSP_cmd(&Head1, arr,3);

   


   deleten(&Head1);
   
   int a = find_num_nodes(&Head1);
   printf("num of nodes is %d\n", a);

   print_list(Head1);


return 0;

}