#include<stdio.h>
#include<stdlib.h>
#define maxsize 5
int stack [maxsize],top,n,i,item;
void push(int);
void display();
int pop();
int peek();
int main()
{
	int poppeditem, choice;
	top=-1;
	do{
	printf("1.push\n 2.pop\n 3.display\n 4.peek\n 5.exit\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:printf("Enter the element: ");
	    scanf("%d, item");
        push(item);
        break;
        
        case 2:
       	poppeditem=pop();
        printf("The popped item is %d\n ",poppeditem);
	    scanf("%d, item");
        break;
        
        case 3:
	    printf("Display all elements: ");
	    scanf("%d, item");
        display();
        break;
        
        case 4:
        poppeditem= peek();
	    printf("The peeked item is %d\n",poppeditem);
	    scanf("%d, item");
        break;
        
        default:
        printf("wrong choice! please enter the valid choice\n");
      }
    } while(choice!=5);	
}
void push(int item){
	if(top==maxsize-1){
		printf("The stack is full");
		exit(0);	
	} else{
		stack[++top]=item;
	}
}
int pop(){
	int item;
	if(top<0){
		printf("stack is empty");
		exit(0);
	}else{
		item=stack[top--];
		return item;
	}
}
int peek(){
	int item;
	if(top<0){
		printf("stack is empty");
		exit(0);
	}else{
		item=stack[top];
		return item;
	}
}
void display(){
	for(i=0;i>=0;i--){
		printf("%d\n",stack[i]);
	}
}




