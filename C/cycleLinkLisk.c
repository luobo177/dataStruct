/*head pointer refer to the first one node
tail pointer refer to the last one node
the last node should point to the first node
*/
#include <stdio.h>
#include <stdlib.h>
struct cycleLinkList{
    int data;
    struct cycleLinkList *next;
};

struct cycleLinkList *initNode(int num){
    struct cycleLinkList *newNode=
    (struct cycleLinkList *)malloc(sizeof(struct cycleLinkList));
    newNode->data = num;
    newNode->next= NULL;
    return newNode;
}

void addNode(struct cycleLinkList **tail,struct cycleLinkList *header,int num){
    struct cycleLinkList *newNode = initNode(num);
    (*tail)->next=newNode;//tail is an address,*tail refer to a struct,**tail refer to pointer point to struct
    (*tail)=newNode;
    (*tail)->next = header;
}

void printList(struct cycleLinkList **header){
    if((*header)==NULL){
        printf("empty list");
        return;
    }
    struct cycleLinkList* temp = *header;
    while((temp)->next!=*header){
        printf("%d\n",(temp)->data);
        temp=(temp)->next;
    }
    printf("%d\n",(temp)->data);
}

void removeNode(struct cycleLinkList **header,struct cycleLinkList **tail,int num){
    /*   header=header地址,
    *header=header指针，
    **header=header指向的结构体
    用p，q遍历，p在前，q在后
     */ 
    if(*header == NULL){
        printf("empty list");
        return;
    }
    struct cycleLinkList *p,*q;
    p=*header; //p是指向结构体的指针
    q=p->next;//q是指向结构体的指针
    if(p==q){
        if(p->data==num)
        printf("唯一节点，且找到num");
        else{
            printf("唯一节点，没找到num");
            return;
        }
        *header = *tail =NULL;
        free(p);
        return;
    }
    if((*header)->data==num){
        *header = (*header)->next;
        free(p);
        (*tail)->next=*header;
        return;
    }
    while(q->data!=num){
        if(q->next==*header){
            printf("did't find the target");
            return;
        }
        p=q;
        q = q->next;
    }
    //到此q指向的结构体值为目标
    p->next = q->next;
    if(q==*tail)
    *tail = p;
    printf("successful remove %d\n",q->data);
    free(q);
}

int main(){   
    struct cycleLinkList *header,*tail;
    header = tail = initNode(3);
    header->next=header;
    // addNode(&tail,header,4);
    // addNode(&tail,header,5);
    // addNode(&tail,header,6);
    removeNode(&header,&tail,4);
    printList(&header);
    return 1;
}