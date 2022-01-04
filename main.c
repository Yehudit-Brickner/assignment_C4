
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "graph.h"
#include "algo.c"



int main(){
 
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

  int vertex=-1;
  int dest=-1;
  int weight=-1;
  int length=0;
  int counttsp=0;
  int numnodes=0;
  int t=0;

  int* tsparr;


  node* head = create_node(0); //head of the list

  while(currChar!='\n'){
 
    if(req=='A'){
           
      currChar= getchar();
      if(currChar==32){
        space=true;
      } 
      
      if(currChar=='A'||currChar=='B'||currChar=='D'||currChar=='S'||currChar=='T'|| currChar=='\n' || currChar==-1){
        prev_req=req;
        req=currChar;
        v=false;
        if(currChar=='A'){
          deleten(&head);
          v=false;
        }
      }

      else if(currChar=='n'){
        if(lastnode==false){
        lastnode=true;
        deleten(&head);
        head =create_node(0);

        for (int i = 1; i<numnodes; i++){
           add(&head, i);
        }

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
          if(!tsparr){
            printf("no memory allocated cant run tsp\n");
          }
        }

        else if(counttsp<length){
          if(tsparr){
            tsparr[counttsp]=t;
          }
            tsp=false;
            counttsp=counttsp+1;
          
        }
        if(counttsp==length && length>0){
          if(tsparr){
            TSP_cmd(&head,tsparr,length);
            free(tsparr);
          }
          length=0;
          counttsp=0;
          tsp=false;
          t=0;
        }
      }
      }
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
      deleten(&head);
      break;

  }

  }
return 0;

}


