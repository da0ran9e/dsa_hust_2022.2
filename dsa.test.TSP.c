#include<stdio.h>

int n, m;
int c[100][100];
int x[100];
int xopt[100];
int visited[100] = {0};
int f=0;
int fopt=999999;
int c_min = 9999999;
int count=0;

void Try(int k)
{
	for(int i=2; i<=n; i++)
	{
		if(visited[i]==0)
		{
			x[k]=i;
			visited[i]=1;
			f=f+c[x[k-1]][x[k]];
			if(k==n)
			{
				int f1 = f + c[x[k]][x[1]];
				if(f1 <= m) count++;
				if (f1 < fopt)
				{
					fopt=f1;
					for(int j=1; j<=n; j++) xopt[j] = x[j];
				}

			}
			else Try(k+1);
			visited[i]=0;
			f=f-c[x[k-1]][x[k]];

		}
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++)
	{
		for (int y=1; y<=n; y++)
		{
			scanf("%d", &c[i][y]);
			if (i != y) if (c[i][y] < c_min) c_min = c[i][y];
		}
	}
	x[1]=1;
	Try(2);
	printf("%d\n", count);
	return 0;
}
