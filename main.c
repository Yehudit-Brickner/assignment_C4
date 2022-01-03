
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "graph.h"
#include "algo.c"

// int power(int base, int n){
//     int ans=base;
//     if(n==0){
//       return 1;
//     }
//     for (int i=0;i<n-1;i++){
//         ans=ans*base;
//     }
//     return ans;
// }

int main(){
 // printf("please enter message\n");
  char req = getchar(); // this will mark what function we are on
  char prev_req=' ';
  char currChar=' ';

  bool space=false;
  bool lastnode=false;
  bool v=false;
  bool d=false;
  bool w=false;
  bool added =false;
  bool deleted=false;
  bool shortest=false;
  bool tsp=false;
  //int counter = 1;
  int vertex=-1;
  int dest=-1;
  int weight=-1;
  int length=0;
  int counttsp=0;
  int numnodes=0;
  int t=0;

  int* tsparr;

 // int* arr;

  node* head = create_node(0); //head of the list

  while(currChar!='\n'){
   // printf("curr= %c\n", currChar);
    if(req=='A'){
            //deleten(&head);
      currChar= getchar();
      if(currChar==32){
        space=true;
      } 
      
      if(currChar=='A'||currChar=='B'||currChar=='D'||currChar=='S'||currChar=='T'|| currChar=='\n' || currChar==-1){
        prev_req=req;
        req=currChar;
        v=false;
        // print_list(head);
        if(currChar=='A'){
          deleten(&head);
          v=false;
          //free(arr);
        }
      }

      else if(currChar=='n'){
        if(lastnode==false){
        lastnode=true;
        deleten(&head);
        head =create_node(0);

        //int num1=0;
        // for (int i=0;i<counter-1;i++){
        //   num1=num1+(arr[i]*power(10,counter-i-2));
        //   printf("arr[i]= %d\n", arr[i] );
        //   printf("pow %d\n",power(10,counter-i-2) );
        // }
        for (int i = 1; i<numnodes; i++){
           add(&head, i);
        }
        //free(arr);
        // print_list(head);
        }
        else{
          v=false;
        }
      }
      
      
      else{
        if(lastnode==true){
          if(currChar!=' '){
            if(v==false && space==true && d==false && w==false){
              vertex=currChar-48;
             v=true;
              space=false;
            }
            else if(v==true && space==false && d==false && w==false){
              vertex=vertex*10+currChar-48;
            }
            else if(d== false && space==true && w==false){
              dest= currChar-48;
              d=true;
              space=false;
            }
            else if(d==true && space==false && w==false){
              dest=dest*10+currChar-48;
            }
            else if(w==false && space==true){
              weight=currChar-48;
              w=true;
              space=false;
            }
            else if(w==true && space==false){
             weight=weight*10+currChar-48;
            }
          }
          else{
            if(v==true && d==true && w==true){
              node* Hcopy=head;
              while(Hcopy->node_num!=dest){
                Hcopy=Hcopy->next;
              }
              if(Hcopy->node_num==dest){
                add_firste(&head,vertex,Hcopy,weight);
                d=false;
                w=false;
              }

            }
          }
        }
        
        
        else{
          if(currChar!=' '){
        //printf("counter=%d\n", counter);
      // if(counter==1){
      //   arr=(int*)malloc(sizeof(int));
      // }
      // if(!arr){
      //   //problem
      //  // return;
      // }
      // if(counter>1){
      //    arr= realloc(arr, 1*sizeof(int));
      // }
      // if(!arr){
      //   //problem
      //   //return;
      // }
      // printf("this is a number\n");
      // arr[counter-1]=currChar-48;
      // printf("printong num %d\n",arr[counter-1]);
      //counter++;
      numnodes=numnodes*10+currChar-48;
          }
        }
      }
    }


    if(req=='B'){
      currChar= getchar();
      if(currChar==32){
        space=true;
      } 
      
      if(currChar=='A'||currChar=='B'||currChar=='D'||currChar=='S'||currChar=='T'|| currChar=='\n' || currChar==EOF){
        prev_req=req;
        req=currChar;
        if(currChar=='A'||currChar=='B'||currChar=='D'||currChar=='S'||currChar=='T'){
          added=false;
          v=false;
        }
      }
      else{
        if(currChar!=' '){
           if(v==false && space==true && d==false && w==false ){
            vertex=currChar-48;
            v=true;
            space=false;
          }
          else if(v==true && space==false && d==false && w==false ){
            v=v*10+currChar-48;
          }
          else if( d==false&& w==false && space==true){
            dest= currChar-48;
            d=true;
            space=false;
          }
          else if(d==true && w==false && space==false){
              dest=dest*10+currChar-48;
          }
          else if(w==false && space==true){
            weight=currChar-48;
            w=true;
            space=false;
          }
          else if(w==true && space==false){
            weight=weight*10+currChar-48;
          }
        }
        else{
          if(v==true && d==true && w==true && space==true){
              node* Hcopy=head;
              if(added==false){
                add(&head, vertex);
                added=true;
              }
              while(Hcopy->node_num!=dest){
                Hcopy=Hcopy->next;
              }
              if(Hcopy->node_num==dest){
                add_firste(&head,vertex,Hcopy,weight);
                d=false;
                w=false;
              }
          }
        }
      }
    }


    if(req=='D'){
      currChar= getchar();
      if(currChar==32){
        space=true;
      } 
      if(currChar=='A'||currChar=='B'||currChar=='D'||currChar=='S'||currChar=='T'|| currChar=='\n'|| currChar==EOF){
        prev_req=req;
        req=currChar;
        if(currChar=='A'||currChar=='B'||currChar=='D'||currChar=='S'||currChar=='T'){
          v=false;
          deleted=false;

        }
      }
      else{
        if(currChar!=' '){
          if(v==false && space==true){
            vertex=currChar-48;
            v=true;
            space=false;
          }
          else if(v==true&& space==false){
            vertex=vertex*10+currChar-48;
          }
        }
        if(v==true&& space==true){
          remove_node(&head, vertex);
          v=false;
          deleted=true;
        }
      }
    
    }


    if(req=='S'){
      currChar= getchar();
      if(currChar==32){
        space=true;
      } 
      if(currChar=='A'||currChar=='B'||currChar=='D'||currChar=='S'||currChar=='T'|| currChar=='\n'){
        prev_req=req;
        req=currChar;
        if(currChar=='A'||currChar=='B'||currChar=='D'||currChar=='S'){
          v=false;
          d=false;
          shortest=false;
        }
      }
      else{
        if(currChar!=' '){
          if(v==false && space ==true && d==false){
            vertex=currChar-48;
            v=true;
            space=false;
          }
          else if(v==true && space==false && d==false){
            vertex=vertex*10+currChar-48;
          }
          else if( d==false && space==true){
            dest= currChar-48;
            d=true;
            space=false;
          }
          else if( d==true && space==false){
           dest=dest*10+currChar-48;
          }
        }
        else{
          if(v==true && d==true){
            shortsPath_cmd(&head, vertex,dest);
            shortest=true;
          }
        }
    }
    }

    if(req=='T'){
      currChar= getchar();
      if(currChar==32){
        space=true;
      } 
      
      if(currChar=='A'||currChar=='B'||currChar=='D'||currChar=='S'||currChar=='T'|| currChar=='\n'|| currChar==EOF){
        prev_req=req;
        req=currChar;
        if(currChar=='A'||currChar=='B'||currChar=='D'||currChar=='S'||currChar=='T'){
         
          if(length>0){
            free(tsparr);
          }
          length=0;
          counttsp=0;
          t=0;
          }
        }
      
      // if(currChar!=' ' && currChar!='A' &&currChar!='B' &&currChar!='D' &&currChar!='S' &&currChar!='T' && currChar!='\n'&&){
      //     if(length==0){
      //       length=currChar-48;
      //     }
      // }
      else{
        if(currChar!=' '){
        if(space==true){
          tsp=false;
        }
        if(tsp==false && space==true){
          t=currChar-48;
          tsp=true;
          space=false;
        }
        else if(tsp==true && space==false){
          t=t*10+currChar-48;
        } 
      } 
      else{
        if(length==0 && t>0){
          tsparr =(int*)malloc(t*sizeof(int));
          length=t;
          tsp=false;
        }

        else if(counttsp<length){
        tsparr[counttsp]=t;
        tsp=false;
        counttsp=counttsp+1;
        }
        if(counttsp==length && length>0){
          TSP_cmd(&head,tsparr,length);
          free(tsparr);
          length=0;
          counttsp=0;
          tsp=false;
          t=0;
        }
      }
      }
      // if(length==0 && currChar!=32){
      //   tsparr =(int*)malloc(length*sizeof(int));
      //   if(!tsparr){
      //     // problem
      //    }
      // }
    }



    if(req=='\n' || req==EOF){
      
      if(prev_req=='A'){
        if(v==true && d==true && w==true){
              node* Hcopy=head;
              while(Hcopy->node_num!=dest){
                Hcopy=Hcopy->next;
              }
              if(Hcopy->node_num==dest){
                add_firste(&head,vertex,Hcopy,weight);
                d=false;
                w=false;
              }
        }
      }

      if(prev_req=='B'){
        if(v==true && d==true && w==true){
              node* Hcopy=head;
               if (added==false){
                add(&head,vertex);
              }
              while(Hcopy->node_num!=dest){
                Hcopy=Hcopy->next;
              }
              if(Hcopy->node_num==dest){
                add_firste(&head,vertex,Hcopy,weight);
                d=false;
                w=false;
              }
          }
      } 

      if(prev_req=='D' ){
        if(v==true && deleted==false){
          remove_node(&head, vertex);
          v=false;
        }
      }

      if(prev_req=='S' ){
        if(v==true && d==true && shortest==false){
          shortsPath_cmd(&head, vertex,dest);
          v=false;
          d=false;
        }

      }

      if (prev_req=='T'){
        if(tsparr){
          tsparr[counttsp]=t;
          TSP_cmd(&head,tsparr,length);
          free(tsparr);
      }
      }

     // print_list(head);
      // if(!arr){
      // free(arr);
      // }
      // if(!tsparr){
      // free(tsparr);
      // }
      deleten(&head);
      break;

  }

  }
return 0;

}

























/*
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
*/