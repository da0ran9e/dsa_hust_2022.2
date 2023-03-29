#include<stdio.h>
#include<limits.h>

int Xmax=0, 
	Xmin=INT_MAX, 
	Ymax=0, 
	Ymin=INT_MAX;

int main(){
	int x, y;
	int t;
	scanf("%d", &t);
	for (int i=0; i<t*2; i++){
		scanf("%d %d", &x, &y);
		//printf("%d %d", x, y);
		if(x<Xmin) Xmin = x;
		if(x>Xmax) Xmax = x;
		if(y<Ymin) Ymin = y;
		if(y>Ymax) Ymax = y;
	}
	int rec = (Xmax-Xmin)*(Ymax-Ymin);
	printf("%d", rec);
	return 0 ;
	
}

