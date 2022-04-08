#include<stdio.h>
/*
This is code for linear probing in open addressing. If you want to do quadratic probing and double hashing which are
also
open addressing methods in this code when I used hash function that (pos+1)%hFn in that place just replace with an
other function.
*/
void insert(int ary[], int size){
int element,pos,n=0;
printf("Enter key element to insert");
scanf("%d",&element);
pos = element%size;
while(ary[pos]!= 0) {
if(ary[pos]== size)
break;
pos = (pos+1)%size;
n++;
if(n==size)
break; // If table is full we should break, if not check this, loop will go to infinite loop.
}
if(n==size)
printf("Hash table was full of elements.No Place to insert this element\n");
else
ary[pos] = element; //Inserting element
}
void delet(int ary[],int size){
int element,n=0,pos;
printf("Enter an element to delete");
scanf("%d",&element);
pos = element%size;
while(n++ != size){
if(ary[pos]==0){
printf("Element not found in hash table\n");
break;
}
else if(ary[pos]==element){
ary[pos]=0;
printf("Element deleted\n");
break;
}
else{
pos = (pos+1) % size;
}

}
if(--n==size)
printf("Element not found in hash table\n");
}
void search(int ary[],int size){
int element,pos,n=0;
printf("\nEnter an element you want to search");
scanf("%d",&element);

pos = element%size;
while(n++ != size){
if(ary[pos]==element){
printf("Element found at index %d",pos);
break;
}
else
if(ary[pos]==size ||ary[pos]!=0)
pos = (pos+1) %size;
}
if(--n==size)
printf("Element not found in hash table\n");
}
void display(int ary[],int size){
int i;
printf("Index\t Value\n");
for(i=0;i<size;i++)
printf("%d\t %d\n",i,ary[i]);
}
int main(){
int size,hFn,i,choice;
printf("Enter size of hash table");
scanf("%d",&size);
int ary[size];

for(i=0;i<size;i++)
ary[i]=0;
do{
printf("Enter your choice\n");
printf(" 1-> Insert\n 2-> Delete\n 3-> Display\n 4-> Searching\n 0-> Exit\n");
scanf("%d",&choice);
switch(choice){
case 1:

insert(ary,size);
break;
case 2:
delet(ary,size);
break;
case 3:
display(ary,size);
break;
case 4:
search(ary,size);
break;
default:
printf("Enter correct choice\n");
break;
}
}while(choice);
return 0;
}
