#include <stdlib.h> 
#include <stdio.h>
#include "listnode.h"
#include "listedge.h"

Node* create_node(int id){
    Node* n = (Node*)malloc(sizeof(Node));
    if(!n){
        return NULL;
    }
    n->id=id;
    n->listinto;
    n->listoutfrom; 
    return n;
}

void add(Node** H, int id){
    if(*H){
        Node* tmp = *H;
        while(tmp){
            if(tmp->id==id){
                change_node( tmp, H);
             }
            tmp++;
        }
        add_first(*H, id);
    }
}

void change_node(Node* n, Node** H ){
    Edge *e = n->listoutfrom;
    Edge *tmp = e;
    while(!tmp){
        int n=tmp->n->id;
        Node *n1=tmp->n;
        Node* tmph=H;
        while(tmph->id != n ){
            tmph++;
        }
        remove_edgen(n1->listinto,n1);
        tmp++;
    }
}

void add_first(Node** H, int id){
    Node* n = create_node(id);
    if(!n){
        printf("no memory!");
        return;
    }
    n->next = *H;
    *H = n;
}

void add_last(Node** H, int id){
    Node* n = create_node(id);
    if(!n){
        printf("no memory!");
        return;
    }
    if(!*H){
        *H = n;
        return;
    }
    Node * tmp = *H;
    while(tmp->next)
        tmp = tmp->next;
    tmp->next = n;
}

void deleten(Node** H){
    while(*H){
        Node* tmp = *H;
        *H = (*H)->next;
        deletee(tmp->listinto);
        deletee(tmp->listoutfrom);
        free(tmp);
    }
}

void print_list(Node* H){
    while(H){
        printf("%d -> ", H->id);
        H = H->next;
    }
    printf("||\n");
}

void remove_node(Node** H, int id){
   Node *Hcopy =*H;
    if(!Hcopy)
        return;
    if((Hcopy)->id == id){
        Node *tmp = *H;

        //fixing others
        Edge *e = tmp->listoutfrom;
        Edge *tmpe = e;
        while(!tmpe){
            int n=tmpe->n->id;
            Node *n1=tmpe->n; 
            Node* tmph=H;
            while(tmph->id != n ){
                tmph++;
            }
            remove_edgen(n1->listinto,n1);
            tmp++;
        }
        e = tmp->listinto;
        tmpe = e;
        while(!tmpe){
            int n=tmpe->n->id;
            Node *n1=tmpe->n; 
            Node* tmph=H;
            while(tmph->id != n ){
                tmph++;
            }
            remove_edgen(n1->listoutfrom,n1);
            tmp++;
        }

        deletee(tmp->listinto);
        deletee(tmp->listoutfrom);
        Hcopy = (Hcopy)->next;
        free(tmp);
    }
    Node* tmp = Hcopy;
    while(tmp->next && tmp->next->id != id)
        tmp = tmp->next;
    if(!tmp->next)
        return;
    Node *tmp2 = tmp->next;
    //fixing others
        Edge *e = tmp2->listoutfrom;
        Edge *tmpe = e;
        while(!tmpe){
            int n=tmpe->n->id;
            Node *n1=tmpe->n; 
            Node* tmph=H;
            while(tmph->id != n ){
                tmph++;
            }
            remove_edgen(n1->listinto,n1);
            tmp++;
        }
        e = tmp2->listinto;
        tmpe = e;
        while(!tmpe){
            int n=tmpe->n->id;
            Node *n1=tmpe->n; 
            Node* tmph=H;
            while(tmph->id != n ){
                tmph++;
            }
            remove_edgen(n1->listoutfrom,n1);
            tmp++;
        }

        deletee(tmp->listinto);
        deletee(tmp->listoutfrom);

    tmp->next = tmp->next->next;
    free(tmp2);
}