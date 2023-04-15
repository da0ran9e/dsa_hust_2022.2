#include<stdio.h>
#include<string.h>
#define N_MAX 10001
#define max(a,b) (((a)>(b))?(a):(b))



typedef struct{
	int c;
	int e;
}Terms;
//store terms of each polynomial with index is id <id><term>
Terms poly[N_MAX][N_MAX];
bool exist[N_MAX]={0};
int terms[N_MAX]={0};
int pows[N_MAX][N_MAX];

int pow(int n, int x){
	int res=1;
	for (int i=0; i<x; i++){
		res*=n;
	}
	return res;
}

void sort(int index){
	//printf("%d %d\n", poly[3][1].c, poly[3][1].e);
	for(int i=1; i<=terms[index]; i++){
		for (int j=1; j<=terms[index]-i; j++){
			if(poly[index][j].e < poly[index][j+1].e){
				Terms temp = poly[index][j];
				poly[index][j] = poly[index][j+1];
				poly[index][j+1] = temp;
			}
		}
	}
}

int main( ){
	char command[100];
	int poly_id,poly_id1, poly_id2, coef, Exp, variable_value, result_poly_id;

	do{
		scanf("%s", command);
		if(strcmp(command, "*")==0) continue;

		if(strcmp(command, "Create")==0 ){
			scanf("%d", &poly_id);
			if(exist[poly_id]!=1) exist[poly_id]=1;
		}
		else if(strcmp(command, "AddTerm")==0){
			scanf("%d %d %d", &poly_id, &coef, &Exp);
			if(pows[poly_id][Exp]=='\0'){
				terms[poly_id]++;
				poly[poly_id][terms[poly_id]].c = coef;
				poly[poly_id][terms[poly_id]].e = Exp;
				pows[poly_id][Exp]=terms[poly_id];
			}
			else{
				poly[poly_id][pows[poly_id][Exp]].c += coef;
			}
			
			if(exist[poly_id]!=1) exist[poly_id]=1;
		}
		else if(strcmp(command, "EvaluatePoly")==0 ){
			scanf("%d %d", &poly_id, &variable_value);
			int result = 0;
			if(exist[poly_id]==1){
				for(int i=1; i<=terms[poly_id]; i++){
					result+=poly[poly_id][i].c*pow(variable_value, poly[poly_id][i].e);
				}
				printf("%d", result);
			}
			else{
				printf("%d", 0);
			}
		}
		else if(strcmp(command, "AddPoly")==0 ){
			scanf("%d %d %d", &poly_id1, &poly_id2, &result_poly_id);
			for(int i=1; i<=terms[poly_id1]; i++){
				poly[result_poly_id][i].c = poly[poly_id1][i].c;
				poly[result_poly_id][i].e = poly[poly_id1][i].e;
				pows[result_poly_id][poly[poly_id1][i].e]=1;
				terms[result_poly_id]++;
			}
			for(int i=1; i<=terms[poly_id2]; i++){
				if(pows[result_poly_id][poly[poly_id2][i].e]=='\0'){
					terms[result_poly_id]++;
					pows[result_poly_id][poly[poly_id2][i].e]=terms[result_poly_id];
					poly[result_poly_id][terms[result_poly_id]].c = poly[poly_id2][i].c;
					poly[result_poly_id][terms[result_poly_id]].e = poly[poly_id2][i].e;
				}
				else{
					poly[result_poly_id][i].c += poly[poly_id2][i].c;	
				}
				
			}
		}
		else if(strcmp(command, "PrintPoly")==0){
			scanf("%d", &poly_id);
			//printf("%d %d\n", poly[3][1].c, poly[3][1].e);
			sort(poly_id);
			for(int i=1; i<=terms[poly_id]; i++){
				printf("%d %d ", poly[poly_id][i].c, poly[poly_id][i].e);
			}
			printf("\n");
		}
		else if(strcmp(command, "Destroy")==0 ){
			scanf("%d", &poly_id);
		}

	}while(strcmp(command, "*"));

	return 0;
}