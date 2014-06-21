#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define N 1000

using namespace std;

char dad[N] , mom[N];
int dp[N][N] , prev[N][N];
int len_mom , len_dad;
int list[N] , size;

void initialize()
{
	for(int i=0 ; i < len_mom ; i++)
		for(int j=0 ; j < len_dad ; j++)
			dp[i][j] = 0;
	size = 0;
}

void str_copy(const char *str1 , const char *str2)
{
	for(int i=0 , j=1 ; i < len_mom ; i++ , j++)	
		mom[j] = *(str1 + i);

	for(int i=0 , j=1 ; i < len_dad ; i++ , j++)
		dad[j] = *(str2 + i);
}

void LCS()
{
	for(int i=1;i<=len_mom;i++)
		for(int j=1;j<=len_dad;j++)
		{
			if(mom[i] == dad[j])
			{
				dp[i][j] = dp[i-1][j-1] + 1;
				prev[i][j] = 1;
			}
			
			else
				dp[i][j] = max( dp[i-1][j] , dp[i][j-1] );			
		}
}

int main()
{
	char s1[N] , s2[N];
	
	int case_num = 1;
	while(gets(s1) && s1[0] != '#')
	{		
		gets(s2);	

		len_mom = (int)strlen(s1);
		len_dad = (int)strlen(s2);
		
		str_copy(s1 , s2);
		initialize();
		
		LCS();
		
		printf("Case #%d: you can visit at most %d cities.\n",case_num++,dp[len_mom][len_dad]);
	}		
	return 0;	
}
