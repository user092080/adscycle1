#include<stdio.h>
#include<stdlib.h>

struct node{
   struct node *rep;
   struct node *next;
   int data;
}*heads[50],*tails[50];

static int countRoot=0;

void makeSet(int x){
struct node *new=(struct node *)malloc(sizeof(struct node));
new->rep=new;
new->next=NULL;
new->data=x;
heads[countRoot]=new;
tails[countRoot++]=new;
}

struct node* find(int a){
int i;
struct node *tmp=(struct node *)malloc(sizeof(struct node));
for(i=0;i<countRoot;i++){
tmp=heads[i];
while(tmp!=NULL){
if(tmp->data==a)
return tmp->rep;
tmp=tmp->next;
}
  }
return NULL;
}

void unionSets(int a,int b){
int i,pos,flag=0,j;
struct node *tail2=(struct node *)malloc(sizeof(struct node));
struct node *rep1=find(a);
struct node *rep2=find(b);
if(rep1==NULL||rep2==NULL){
printf("\nElement not present in the Structure\n");
return;
}
if(rep1!=rep2){
for(j=0;j<countRoot;j++){
if(heads[j]==rep2){
pos=j;
flag=1;
countRoot-=1;
tail2=tails[j];
for(i=pos;i<countRoot;i++){
heads[i]=heads[i+1];
tails[i]=tails[i+1];
}
}
if(flag==1)
break;
}
for(j=0;j<countRoot;j++){
if(heads[j]==rep1){
tails[j]->next=rep2;
tails[j]=tail2;
break;
}
}
while(rep2!=NULL){
rep2->rep=rep1;
rep2=rep2->next;
}
}
}

int search(int x){
int i;
struct node *tmp=(struct node *)malloc(sizeof(struct node));
for(i=0;i<countRoot;i++){
tmp=heads[i];
if(heads[i]->data==x)
return 1;
while(tmp!=NULL){
if(tmp->data==x)
return 1;
tmp=tmp->next;
}
}
return 0;
}

void main(){
int choice,x,i,j,y,flag=0;

do{

printf("\n1.Create Set\n2.Union of set\n3.Display initial values\n4.Search Set\n5.Display values as a set\n6.Exit\n");

printf("Enter your choice :  ");
scanf("%d",&choice);

switch(choice){
case 1:
printf("\nEnter new element : ");
scanf("%d",&x);
if(search(x)==1)
printf("\nElement already present in the disjoint set DS\n");
else
makeSet(x);
break;
case 2:
printf("\nEnter first element : ");
scanf("%d",&x);
printf("\nEnter second element : ");
scanf("%d",&y);
unionSets(x,y);
break;
case 3:
printf("\n");
for(i=0;i<countRoot;i++)
printf("%d ",heads[i]->data);
printf("\n");
break;
case 4:
printf("\nEnter the element");
scanf("%d",&x);
struct node *rep=(struct node *)malloc(sizeof(struct node));
rep=find(x);
if(rep==NULL)
printf("\nElement not present in the DS\n");
else
printf("\nThe element  %dfound at  %d\n",x,rep->data);
break;
case 5:
for (i = 0; i <countRoot; i++) {
    printf("Set %d: ", i + 1);
    struct node *temp =heads[i];
    printf("{ ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("}\n");
 }

break;
case 6:
exit(0);
default:
printf("\nWrong choice\n");
break;
}
}while(1);
};
