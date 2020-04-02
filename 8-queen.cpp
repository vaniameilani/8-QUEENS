#include <stdio.h>
#include <conio.h>
#include <math.h>

int a[30], count=0;

int place (int pos){
	int i;
	for (i=1; i<pos; i++){
		if ((a[i]==a[pos]) || ((abs(a[i]-a[pos])==abs(i-pos))))
			return 0;			// if a queen exists in same column or diagonally
	}
	return 1;
}

void print (int n){
	int i,j;
	count ++;
	printf ("\n\nSolution #%d:\n", count);
	for (i=1; i<=n; i++){
		for (j=1; j<=n; j++){
			if (a[i]==j)
				printf ("Q\t");
			else
				printf ("*\t");
		}
		printf ("\n");
	}
}

void queen (int n){
	int k=1;	
	a[k]=0;		
	while(k!=0){ 
		do{
			a[k]++;
		}
		while ((a[k]<=n)&&!place(k)); 
		if (a[k]<=n){
			if (k==n)
				print(n);
			else {
				k++;
				a[k]=0;
			}
		}
		else 
			k--;
	}
}

int main(){
//	int n;
//	printf ("Enter the number of Queen : ");
//	scanf ("%d", &n);
	queen (8);
	printf ("\nTotal Solution=%d", count);
}
