//import libraries
#include <stdio.h>
#include <stdlib.h>
//initilizing k,front=-1;rear=-1;*queue;
int k;
int front=-1;
int rear=-1;
int *queue;
//enqueue funcion
void enqueue(int x){
    //check overflow
    if ((rear+1)%k==front){
        printf("Queue Overflow\n");
        return;
    }
    if(front==-1){
        front=0;
    }
    rear=(rear+1)%k;
    queue[rear]=x;
    printf("Enqueued %d\n",x);
}

//dequeu
void  dequeue(){
    //check underflow
    if(front==-1){
        printf("Queue Underflow\n");
        return;
    }
    printf("Dequeued %d\n",queue[front]);
    if (front==rear){
        front=-1;
        rear=-1;
    }else{
        front=(front+1)%k;
        
    }
}

//main function
int main(){
    
    scanf("%d",&k);
    queue=malloc(sizeof(int)*k);
    int x;
    while(scanf("%d",&x)==1){
        if(x>=0){
          
            enqueue(x);
        }
        else if(x==-1){
            dequeue();
        }
    }
}