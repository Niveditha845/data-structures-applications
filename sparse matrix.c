#include <stdio.h>
#include <stdlib.h>
struct node{
    int co,po;
    struct node *address;
};
typedef struct node *Node;

Node insertend(Node start,int co,int po){
    Node temp,cur;
    temp=(Node)malloc(sizeof(struct node));
    temp->co=co;
    temp->po=po;
    temp->address=NULL;
    if(start==NULL){
        return temp;
    }
    else{
        cur=start;
        while(cur->address!=NULL){
            cur=cur->address;
        }
        cur->address=temp;
        return start;
    }
}

void display(Node start){
    Node temp;
    if(start==NULL){
        printf("\nPolynomial empty");
    }
    else{
        temp=start;
        while(temp->address!=NULL){
            printf("%dx^%d + ",temp->co,temp->po);
            temp=temp->address;
        }
        printf("%dx^%d",temp->co,temp->po);
    }
}

Node addterm(Node res,int co,int po){
    Node temp,cur;
    temp=(Node)malloc(sizeof(struct node));
    temp->co=co;
    temp->po=po;
    temp->address=NULL;
    if(res==NULL){
        return temp;
    }
    else{
        cur=res;
        while(cur!=NULL){
            if(cur->po==po){
                cur->co=cur->co+co;
                return res;
            }
            cur=cur->address;
            if(cur==NULL){
                res=insertend(res,co,po);
                return res;
            }
        }
    }
    return res;
}

Node multiply(Node pol1,Node pol2){
    Node p1,p2,res=NULL;
    for(p1=pol1;p1!=NULL;p1=p1->address){
        for(p2=pol2;p2!=NULL;p2=p2->address){
            res=addterm(res,(p1->co)*(p2->co),(p1->po)+(p2->po));
        }
    }
    return res;
}

int main(){
    Node pol1=NULL,pol2=NULL,pol;
    int n,i,co,po;
    printf("Enter number of terms in first polynomial: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter coefficient and power of term %d: ",i+1);
        scanf("%d%d",&co,&po);
        pol1=insertend(pol1,co,po);
    }
    printf("\nFirst polynomial is: ");
    display(pol1);
    printf("\n\nEnter number of terms in second polynomial: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter coefficient and power of term %d: ",i+1);
        scanf("%d%d",&co,&po);
        pol2=insertend(pol2,co,po);
    }
    printf("\nSecond polynomial is: ");
    display(pol2);
    pol=multiply(pol1,pol2);
    printf("\n\nProduct of polynomials is: ");
    display(pol);
    return 0;
}
