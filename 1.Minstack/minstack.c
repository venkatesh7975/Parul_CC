//import libraries 
#include <stdio.h>
#include <stdlib.h>

//initilization 
int *stack;
int *minstack;
int top=-1;
int mintop=-1;
int N;

void push(int value,int N){
    //check overflow condition
    if(top==N-1){
        printf("overflow\n");
        return;
    }
    //push into stack
    stack[++top]=value;
    //push into minststack:
    if(mintop==-1 || value<=minstack[mintop]){
            minstack[++mintop]=value;
    }
    //print
    printf("Pushed %d\n",value);
}
void pop(){
    //check underflow conditin
    if(top==-1){
        printf("underflow\n");
        return;
    }
    //pop from minstack(if stack[top]==minstack[mintop]),mintoo--
    if(stack[top]==minstack[mintop]){
        mintop--;
    }
    //pop from stack:top--
    top--;
}
void Top(){
    //check empty condition
    if(top==-1){
        printf("stack is empty\n");
    }
    //print stack[top]
    printf("Top: %d\n",stack[top]);
}
void getMin(){
    //check empty condition
    if(mintop==-1){
        printf("Minstack empty\n");
        return;
    }
    //minstack[mintop]
    printf("Min: %d\n",minstack[mintop]);
}

int main(){
    stack=malloc(N*sizeof(int));
    minstack=malloc(N*sizeof(int));
    scanf("%d",&N);
    while (1){
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1:
                int val;
                scanf("%d",&val);
                push(val,N);
                break;

            case 2:
                 pop();
                 break;
            case 3:
                Top();
                break;
            case 4:
                getMin();
                break;
            case 5:
                printf("Exit\n");
                return 0;
                 
        }
    }
}