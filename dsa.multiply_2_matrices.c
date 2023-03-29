#include<stdio.h>

int main(){
	int x, y, Y, mem=0;
	int M1[101][101], M2[101][101];

	scanf("%d %d", &y, &x);
	Y=y;
	for(int i=1; i<=y; i++){
		for(int j=1; j<=x; j++){
			scanf("%d", &M1[i][j]);
		}
	}
	scanf("%d %d", &y, &x);
	for(int i=1; i<=y; i++){
		for(int j=1; j<=x; j++){
			scanf("%d", &M2[i][j]);
		}
	}

	for(int i=1; i<=Y; i++){
		for(int j=1; j<=x; j++){
			for(int k=1; k<=y; k++){
				mem += M1[i][k]*M2[k][j];
			}
			printf("%d ", mem);
			mem=0;
		}
		printf("\n");
	}
	return 0 ;
}