#include<stdio.h>
#include<conio.h>
//calculating 
void hcf(int,int);
int GCD(){
	int n1,n2,g;
	printf("Enter two positve integers:\t");
	scanf("%d, %d",&n1,&n2);
	g=hcf(n1,n2);
	printf("GCD of %d and %d is %d ",g);
	return 0;
	}
	//recursion for GCD
	void hcf(int n1,int n2){
		if(n2!=0){
			return hcf(n2,n1%n2);
		}else{
			return n1;
		}
	}

void TOH(int,char,char,char);
int TOH(){
	int n;
	printf("Enter number of disks:\t");
	scanf("%d",&n);
	TOH(n,'A','B','C');
	return 0;
}
void TOH(int n, char Source, char Auxiliary, char Destination){
	if(n>0){
		TOH(n-1,Source,Destination,Auxiliary);
		printf("Move disk %d from %c to %c\n",n,Source,Auxiliary);
		TOH(n-1,Destination,Auxiliary,Source);
	}
}
