#include<stdio.h>
#include<math.h>
typedef struct
{   int n2;  // ����
    int d;  // ��ĸ
} FRACTION;
int maxcommonfactor(int a,int b){
    if(a%b==0) return b;
    return maxcommonfactor(b,a%b);
}
void add(FRACTION *f1,FRACTION *f2){
    f1->n=f1->n*f2->d+f1->d*f2->n;
    f1->d=f1->d*f2->d;
}

void main(){
    FRACTION f1,f2;
    int mcfactor;
    printf("��������������\n");
    scanf("%d/%d %d/%d",&f1.n,&f1.d,&f2.n,&f2.d);
    add(&f1,&f2);
    printf("%d/%d\n",f1.n,f1.d);
    if(f1.n%f1.d==0){
        printf("%d",f1.n/f1.d);//����Ϊ����
    }
    else{
        mcfactor=abs(maxcommonfactor(f1.n,f1.d));
        f1.n=f1.n/mcfactor;
        f1.d=f1.d/mcfactor;
        printf("%d/%d\n",f1.n,f1.d); //��������Լ��
    }
}
//  a   b   c
//  12  16  12 
//  16  12  4
//  12  4   0