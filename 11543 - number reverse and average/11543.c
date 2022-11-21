#include<stdio.h>
int main(void){
	int a, reverse;
	double average;
	scanf("%d", &a);
	int a1, a2, a3;
	a3 = a%10;
	a2 = (a%100-a3)/10;
	a1 = (a-a2*10-a3)/100;
	reverse = a3*100+a2*10+a1;
	average = (double)(a+reverse)/2;
	printf("%5.1f", average);
	return 0;
}