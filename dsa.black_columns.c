#include<stdio.h>
#include<string.h>

int main(){
	int r, c, cell;
	bool is_black[1001];
	int cnt=0;

	scanf("%d %d", &r, &c);
	memset(is_black, 1, c);
	
	for(int i=0; i<r; i++){
		for (int j=0; j<c; j++){
			scanf("%d", &cell);
			is_black[j] = is_black[j]&cell;
		}
	}
	for(int k=0; k<c; k++) if(is_black[k]) cnt++;
	printf("%d", cnt);
return 0;
}