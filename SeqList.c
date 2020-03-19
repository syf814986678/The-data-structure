#include<stdio.h>
#define maxsize 100
#define error -1
#define ok 1
typedef struct 
{
    int elem[maxsize];
    int last;
}SeqList;

int DelList(SeqList *L,int i){
    int k;
    if(i<1||i>L->last+1){
        printf("不合法");
        return error;
    }
    //*e=L->elem[i-1];
    for(k=i;k<=L->last;k++){
        L->elem[k-1]=L->elem[k];
    }
    L->last--;
    return ok;
}
int DelSame(SeqList *l){
    int i,j;
    if(l->last<=0) return ok;
    for(i=0,j=0;i<=l->last;i++){
        if(l->elem[i]!=l->elem[i+1]){
           // l->elem[j+1]=l->elem[i+1]; 
            l->elem[j]=l->elem[i];
          //  printf("循环内%d\n",l->elem[i+1]);
           // printf("循环内%d\n",l->elem[i+2]);
            j++;
        }
       // l->last=j-1;
    }
    l->last=j-1;
}

int main(){

    SeqList SeqList;
    SeqList.elem[0]=1;
    SeqList.elem[1]=1;
    SeqList.elem[2]=2;
    SeqList.elem[3]=4;
    SeqList.elem[4]=4;
    SeqList.elem[5]=5;
    SeqList.last=5;
    //int e;
   // DelList(&SeqList,3);
    DelSame(&SeqList);
    for(int i=0;i<=SeqList.last;i++){
        printf("循环外%d\n",SeqList.elem[i]);
    }
   // printf("%d\n",SeqList.last);
    return 0;
}
