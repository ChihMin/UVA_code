#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

double cost[10][90][90];

void ini()
{
	//0.1  0.25 0.53 0.87 1.44
	for(int i=8;i<18;i++)
		for(int j=0;j<60;++j)
		{
			cost[1][i][j] = 0.1;	
			cost[2][i][j] = 0.25;	
			cost[3][i][j] = 0.53;	
			cost[4][i][j] = 0.87;	
			cost[5][i][j] = 1.44;	
		}	
	//0.06 0.15 0.33 0.47 0.80 
	for(int i=18;i<22;++i)
		for(int j=0;j<60;++j)
		{
			cost[1][i][j] = 0.06;	
			cost[2][i][j] = 0.15;	
			cost[3][i][j] = 0.33;	
			cost[4][i][j] = 0.47;	
			cost[5][i][j] = 0.80;		
		}
	
	// 0.02 0.05 0.13 0.17 0.30
	for(int i=22;i<24;i++)
		for(int j=0;j<60;++j)
		{
			cost[1][i][j] = 0.02;	
			cost[2][i][j] = 0.05;	
			cost[3][i][j] = 0.13;	
			cost[4][i][j] = 0.17;	
			cost[5][i][j] = 0.30;
		}
	
	for(int i=0;i<8;++i)
		for(int j=0;j<60;++j)
		{
			cost[1][i][j] = 0.02;	
			cost[2][i][j] = 0.05;	
			cost[3][i][j] = 0.13;	
			cost[4][i][j] = 0.17;	
			cost[5][i][j] = 0.30;
		}	
	
	// process the special time points
	cost[1][18][0] = 0.1;	
	cost[2][18][0] = 0.25;	
	cost[3][18][0] = 0.53;	
	cost[4][18][0] = 0.87;	
	cost[5][18][0] = 1.44;
	
	cost[1][22][0] = 0.06;	
	cost[2][22][0] = 0.15;	
	cost[3][22][0] = 0.33;	
	cost[4][22][0] = 0.47;	
	cost[5][22][0] = 0.80;
	
	cost[1][8][0] = 0.02;	
	cost[2][8][0] = 0.05;	
	cost[3][8][0] = 0.13;	
	cost[4][8][0] = 0.17;	
	cost[5][8][0] = 0.30;	
}

int main()
{
	ini();
	
	/*
	for(int i=0;i<24;i++)
	{
		for(int j=0,k=59;j<3;++j,k=(k+1)%60)
			printf("%d %d--->  %lf\t%lf\t%lf\t%lf\t%lf\n",i,k,cost[1][i][k],cost[2][i][k],cost[3][i][k],cost[4][i][k],cost[5][i][k]);
		printf("\n\n");
	}*/
	
	char str[200] ;
	while( gets( str ) && str[0] != '#' )
	{
		char c;
	
		int cnt[200];
		char pn[200];
		
		memset( cnt , 0 , sizeof(cnt) );
		 
		int st_m , st_h;
		int ed_m , ed_h;
		
		
		sscanf( str , "%c %s %d %d %d %d",&c,pn,&st_h,&st_m,&ed_h,&ed_m);	
		int type = c - 'A' + 1;
	//	printf("%c %s %d %d %d %d\n",c,pn,st_h,st_m,ed_h,ed_m);
	
		double sum = 0;
		
		int t1 = int(100.0 * cost[type][9][0]);
		int t2 = int(100.0 * cost[type][19][0]);
		int t3 = int(100.0 * cost[type][7][0]);
		
		//printf("%d %d %d\n",t1,t2,t3);
		
		int t_ed_h;
		
		t_ed_h = ed_h;
		if( st_h > ed_h )
			t_ed_h += 24;
		
		if( st_h == ed_h )
			if( st_m > ed_m )
				t_ed_h += 24;	
				
		
		bool ok1 = 0;
		bool ok2 = 0;
		for(int i = st_h , k = st_h  ; k <= t_ed_h ; i = (i+1)%24 ,++k)
		{
			
			if( i == st_h && i == ed_h && st_m < ed_m )
			{
				for(int j=st_m+1;j<=ed_m;++j)
				{
					sum += cost[type][i][j];	
					cnt[(int)(100*cost[type][i][j])]++;
				}
			}
			
			else if( i == st_h && !ok1 )
			{
				for(int j=st_m+1;j<60;++j)
				{
					sum += cost[type][i][j];	
					cnt[(int)(100*cost[type][i][j])]++;
				}
				ok1 = 1;
			}
				
			else if( i == ed_h && !ok2 )
			{
				for(int j=0;j<=ed_m;++j)
					sum += cost[type][i][j],cnt[(int)(100*cost[type][i][j])]++;
				ok2 = 1;
			}
			else
				for(int j=0;j<60;++j)
					sum += cost[type][i][j],cnt[(int)(100*cost[type][i][j])]++;
		}
		
		printf("%10s",pn);
		printf("%6d%6d%6d",cnt[t1],cnt[t2],cnt[t3]);
		printf("%3c%8.2lf\n",c,sum);
	}
	
	return 0;	
}
