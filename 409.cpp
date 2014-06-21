#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define N 100

using namespace std;

int n , cnt1 , cnt2 ;
int ans_cnt[N];
char input[N][N] , s1[N][N] , s2[N][N];
/*
void LCS()
{
	for(int i=1;i<=cnt1;i++)
		for(int j=1;j<=cnt2;j++)
		{
			if(!strcmp(s1[i] , s2[j]))
				dp[i][j] = dp[i-1][j-1] + 1;	
			
			else
				dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
		}	
}
*/
int main()
{
	//freopen("a.txt","r",stdin);
	//freopen("b.txt","w",stdout);
	
	int test_case = 1;
	
	while(gets(input[0]))
	{
		sscanf(input[0],"%d%d",&cnt1,&n);
		
		for(int i=1;i<=cnt1;i++)
		{
			gets(input[0]);	
			
			for(int j=0;j<=(int)strlen(input[0]);j++)
				s1[i][j] = input[0][j] <= 90 && input[0][j] != 0 ? input[0][j] + 32 : input[0][j];
		}
		/*
		for(int i=1;i<=cnt1;i++)
			printf("%s\n",s1[i]);
		
		printf("--------------\n");
		*/
		int ans_str = 0 , ans_max = 0;
		
		for(int j=1;j<=n;j++)
		{
			int len = 0;
			cnt2 = 1;
			
			gets(input[j]);
			
		//	printf("%s\n",input[j]);
			
			for(int i=0;i<(int)strlen(input[j]);i++)
			{				
				if((input[j][i] >= 'A' && input[j][i] <= 'Z') || (input[j][i] >= 'a' && input[j][i] <= 'z'))		
					s2[cnt2][len++] = input[j][i] <= 90 ? input[j][i] + 32 : input[j][i];				
				
				else	
					if(len != 0)
					{										
						s2[cnt2++][len++] = '\0';
						len = 0;						
					}
			}
			cnt2--;	
			
			int str_cnt = 0;
			
			for(int a=1;a<=cnt1;a++)
				for(int b=1;b<=cnt2;b++)
					if(!strcmp(s1[a] , s2[b]))
						str_cnt++;
			/*
			for(int i=1;i<=cnt2;i++)
				printf("%s\n",s2[i]);
			
			
			memset(dp , 0 , sizeof(dp));
			*/
			ans_cnt[j] = str_cnt;
						
			if(str_cnt > ans_max)
			{
				ans_max = str_cnt;
				ans_str = j;
			} 	
			
		}
		printf("Excuse Set #%d\n",test_case++);
		
		for(int i=1;i<=n;i++)	
			if(ans_cnt[i] == ans_max)	
				printf("%s\n",input[i]);
		
		printf("\n");
	}
	return 0;	
}
