#include <stdio.h>

struct sqlist
{
    int data[10];
    int length;
};
void initList(struct sqlist *list){
    list->length = 0;
}

void setNum(struct sqlist *list,int index,int num){
    list->data[index] = num;
}
void exchangeNum(struct sqlist *list,int index1,int index2){
    int temp = list->data[index1];
    list->data[index1] = list->data[index2];
    list->data[index2] = temp;
}

void insertNum(struct sqlist *list,int index,int num){
    int max_size = sizeof(list->data)/sizeof(list->data[0]);
    if(list->length ==max_size || index>list->length || index<0){
        printf("out of range of array");
    }else{
        if(index==list->length){
            list->data[index]=num;
            list->length++;
        }else{
            for(int i=list->length-1;i>=index;i--){
                list->data[i+1]=list->data[i];
            }
            list->data[index]=num;
            list->length++;
        }
    }
}
void addNum(struct sqlist *list,int num){
    int max_size = sizeof(list->data)/sizeof(list->data[0]);
    if(list->length>=max_size){
        printf("out of range of array");
    }
    list->data[list->length]=num;
    list->length++;
}

void getLength(struct sqlist *list){
    printf("%d\n",list->length);
}

void getAllData(struct sqlist *list){
    for(int i=0;i<list->length;i++){
        printf("%d ",list->data[i]);
    }
    printf("\n");
}

int main(){
    struct sqlist list;
    initList(&list);
    addNum(&list,5);
    addNum(&list,4);
    addNum(&list,3);
    addNum(&list,2);
    addNum(&list,1);
    getAllData(&list);
}