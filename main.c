
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "graph.h"
#include "algo.c"

int power(int base, int n){
    int ans=base;
    if(n==0){
      return 1;
    }
    for (int i=0;i<n-1;i++){
        ans=ans*base;
    }
    return ans;
}

int main(){
  printf("please enter message\n");
  char req = getchar(); // this will mark what function we are on
  bool space=false;
  bool lastnode=false;
  char currChar=' ';
  int counter = 1;
  int vertex=-1;
  int dest=-1;
  int weight=-1;
  int length=0;
  int counttsp=0;
  int* tsparr;
  int* arr;
  node* head = create_node(0); //head of the list
  while(currChar!='\n'){
   // printf("curr= %c\n", currChar);
    if(req=='A'){
            //deleten(&head);
      currChar= getchar();
      if(currChar==32){
        space=true;
      } 
      
      else if(currChar=='A'||currChar=='B'||currChar=='D'||currChar=='S'||currChar=='T'|| currChar=='\n'){
        req=currChar;
        if(currChar=='A'){
          deleten(&head);
          free(arr);
        }
      }

      else if(currChar=='n'){
        if(lastnode==false){
        lastnode=true;
        deleten(&head);
        head =create_node(0);

        int num1=0;
        for (int i=0;i<counter-1;i++){
          num1=num1+(arr[i]*power(10,counter-i-2));
          printf("arr[i]= %d\n", arr[i] );
          printf("pow %d\n",power(10,counter-i-2) );
        }
        for (int i = 1; i<num1; i++){
           add(&head, i);
        }
        free(arr);
        print_list(head);
        }
        else{
          vertex=-1;
        }
      }
      
      
      else{
        if(lastnode==true){

          if(vertex==-1){
            vertex=currChar-48;
          }
          else if( dest==-1){
            dest= currChar-48;
          }
          else if(weight==-1){
            weight=currChar-48;
          }
          if(vertex!=-1 && dest!=-1 && weight!=-1){
              node* Hcopy=head;
              while(Hcopy->node_num!=dest){
                Hcopy=Hcopy->next;
              }
              if(Hcopy->node_num==dest){
                add_firste(&head,vertex,Hcopy,weight);
                dest=-1;
                weight=-1;
              }
          }
        }
        
        
        
        else{
        printf("counter=%d\n", counter);
      if(counter==1){
        arr=(int*)malloc(sizeof(int));
      }
      if(!arr){
        //problem
       // return;
      }
      if(counter>1){
         arr= realloc(arr, 1*sizeof(int));
      }
      if(!arr){
        //problem
        //return;
      }
      printf("this is a number\n");
      arr[counter-1]=currChar-48;
      printf("printong num %d\n",arr[counter-1]);
      counter++;
        }
      }
    }


    if(req=='B'){
      currChar= getchar();
      if(currChar==32){
        space=true;
      } 
      
      else if(currChar=='A'||currChar=='B'||currChar=='D'||currChar=='S'||currChar=='T'|| currChar=='\n'){
        req=currChar;
        if(currChar=='B'){
          vertex=-1;
        }
        else{
           if(vertex==-1){
            vertex=currChar-48;
          }
          else if( dest==-1){
            dest= currChar-48;
          }
          else if(weight==-1){
            weight=currChar-48;
          }
          if(vertex!=-1 && dest!=-1 && weight!=-1){
              node* Hcopy=head;
              add(&head, vertex);
              while(Hcopy->node_num!=dest){
                Hcopy=Hcopy->next;
              }
              if(Hcopy->node_num==dest){
                add_firste(&head,vertex,Hcopy,weight);
                dest=-1;
                weight=-1;
              }
          }
        }
      }
      //do somthing
    }


    if(req=='D'){
      currChar= getchar();
      if(currChar==32){
        space=true;
      } 
      else if(currChar=='A'||currChar=='B'||currChar=='D'||currChar=='S'||currChar=='T'|| currChar=='\n'){
        req=currChar;
        if(currChar=='D'){
          vertex=-1;
        }
      }
      else{
        vertex=currChar-48;
        remove_node(&head, vertex);
        vertex=-1;
      }
      //do somthing
    }


    if(req=='S'){
      currChar= getchar();
      if(currChar==32){
        space=true;
      } 
      else if(currChar=='A'||currChar=='B'||currChar=='D'||currChar=='S'||currChar=='T'|| currChar=='\n'){
        req=currChar;
        if(currChar=='S'){
          vertex=-1;
          dest=-1;
        }
      }
      else{
        if(vertex==-1){
          vertex=currChar-48;
        }
        else if( dest==-1){
          dest= currChar-48;
      }
      if(vertex!=-1 && dest!=-1){
        shortsPath_cmd(&head, vertex,dest);
      }
      //do somthing
    }
    }

    if(req=='T'){
      currChar= getchar();
      if(currChar==32){
        space=true;
      } 
      
      else if(currChar=='A'||currChar=='B'||currChar=='D'||currChar=='S'||currChar=='T'|| currChar=='\n'){
        req=currChar;
        if(currChar=='T'){
          length=0;
          counttsp=0;
          free(tsparr);
        }
      }
      if(length==0 && currChar!=32 && (currChar!='A'&&currChar!='B'&&currChar!='D'&&currChar!='S'&&currChar!='T'&& currChar!='\n')){
        length=currChar-48;
      }
      else{
        tsparr[counttsp]=currChar-48;
        counttsp=counttsp+1;
      } 
      if(length!=0){
        tsparr =(int*)malloc(length*sizeof(int));
        if(!tsparr){
          // problem
         }
      }
      if(counttsp==length){
        TSP_cmd(&head,tsparr,length);
        free(tsparr);
        length=0;
        counttsp=0;
      }
      //do somthing
    }



    if(req=='\n'){
      free(arr);
      free(tsparr);
      deleten(&head);
      break;
    }

  }


return 0;

}


























 // if (req == 'A' || req == 'B' || req == 'S' || req == 'D' || req == 'T'){ 
// if(req=='A'){
//          if (req == 'A'){
//             deleten(&head);
//             while (currChar != 'n'){
//                currChar=getchar();
//                if(currChar==32){
//                   space=true;
//                }
//             else{
//                space=false;
//             }
//             while (currChar != 'n' && !space){
//                c = (char*)malloc(sizeof(currChar));
//                if (c != NULL && counter>1){
//                    c= realloc(c, counter);
//                }
//                 c[counter-1] = currChar;
//                 counter++;      //num of vertices
//             }
//             int n = 0;
//             for (int i=1; i<counter; i++){
//                 n = n + (c[i-1]-48)*pow(10, counter-1-i);
//                 printf("10 to the power %d = %f\n",counter-1-i, pow(10,counter-1-i) );
//                 printf("n= %d, c[i]=%c, c[i]=%d, c[i]-48=%d \n", n,c[i],c[i],c[i]-48);
//             }
//             head = create_node(0); //head of the list
//             for (int i = 1; i<n; i++){
//                 add(&head, i);
//             }
//            print_list(head);
//          }
//          }
//  //  }

// print_list(head);

//     printf("helloworld\n");
//    // node* Head1;
//    // Head1 = (pnode)malloc(sizeof(node));
//    // Head1->node_num = 0;
//    // Head1->edges = NULL;
//    // Head1->next = NULL;
//    node* Head1 =create_node(0);
//    print_list(Head1);



//    for (int i = 1; i < 10; i++){
//         add(&Head1, i);
//    }

//    // making sure that adding edges workes
//    node *tmp2 = NULL;
//    //node *Hcopy = Head1;
//    int weights[] = {2, 1, 6, 16, 10, 12, 14 ,20, 5, 7 ,9 ,15, 1, 6, 16, 10, 12, 14 ,20, 5, 7 ,9 ,15, 1, 6, 16, 10, 12, 14 ,20, 5, 7 ,9 ,15, 1, 6, 16, 10, 12, 14 ,20, 5, 7 ,9 ,15};
//    int count = 0;
//    for (int i = 0; i < 10; i++){
//       node *Hcopy = Head1;
//       while (Hcopy){
//          if (Hcopy->node_num == i){
//             tmp2 = Hcopy;
//             break;
//          }
//          Hcopy = Hcopy->next;
//       }
//       for (int j = 0; j < 10; j=j+2){
//          if (j != i){
//             add_firste(&Head1, j, tmp2, weights[count]);
//             count = count + 1;
//          }
//       }
//    }
//   // print_list(Head1);


//   // printf("shortest path from 0 to 2\n");
//    shortsPath_cmd(&Head1, 0,2);
//    // removing node
//    printf("\nremoving node 4\n");
//    remove_node(&Head1, 0);
   
   
   
//    print_list(Head1);


//    shortsPath_cmd(&Head1, 15,2);



//    int arr[]={11,6,2};
//    TSP_cmd(&Head1, arr,3);


//       shortsPath_cmd(&Head1, 3,2);
//       shortsPath_cmd(&Head1, 3,6);
//    int arr2[]={3,6,2};
//    TSP_cmd(&Head1, arr2,3);


//    deleten(&Head1);
   
//    // int a = find_num_nodes(&Head1);
//    // printf("num of nodes is %d\n", a);

//   // print_list(Head1);
