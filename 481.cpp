#include <cstdio>
#include <cstdlib>
#define N 200000

using namespace std;

int s[N];
int lis[N] , pos[N];
int n , cnt;
bool ok;

void binary(int i , int j , int now)
{
	if(i+1 == j || i == j)
	{
		if(s[now] < lis[i])
		{
			lis[i] = s[now];
			pos[now] = i;	
			ok = 1;
		}
		else if(s[now] <= lis[j])
		{	
			lis[j] = s[now];	
			pos[now] = j;	
			ok = 1;
		}
	}
		
	else
	{
		if(s[now] < lis[(i+j)/2])	binary(i , (i+j)/2 , now);	
		else binary((i+j)/2 , j , now);
	}
}

void LIS()
{
	for(int i=1;i<n;i++)
	{
		ok = 0;
		binary(1 , cnt , i);
		
		if(!ok)
		{
			lis[++cnt] = s[i] ;	
			pos[i] = cnt;
		}
	}
}

void find_LIS(int size)
{
	for(int i=n-1;i>=0;i--)
		if(pos[i] == size)
			lis[size--] = s[i];
}

int main()
{
	//freopen("a.txt","r",stdin);
	//freopen("b.txt","w",stdout);
	
	n = 0;
	while(~scanf("%d",&s[n])) n++;
	
	pos[0] = 1;
	lis[++cnt] = s[0] ;

	LIS();
	find_LIS(cnt);
	
	printf("%d\n-\n",cnt);
	for(int i=1;i<=cnt;i++)	printf("%d\n",lis[i]);

	return 0;	
}
