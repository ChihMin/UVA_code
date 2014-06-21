#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

struct Node
{
	char suit , rank;	
} last;

queue < Node > Q[30];

void ini()
{
	for(int i=0;i<13;i++)
		while( !Q[i].empty() )
			Q[i].pop();	
}

int prog( char c )
{
	if( c >= '2' && c <= '9' )
		return c - '1';
	
	if( c == 'A' )
		return 0;
	
	if( c == 'T' )
		return 9 ;
	
	if( c == 'J' )
		return 10;
		
	if( c == 'Q' )
		return 11;
	
	return 12;	
	
}

int main()
{
	char input[100];
	
	while( gets( input ) && input[0] != '#' )
	{
		ini();
	
		for(int i=0,j=12;i<(int)strlen(input);i+=3,--j)
		{
			Node tmp;
			tmp.rank = input[i] ;
			tmp.suit = input[i+1];
			Q[j].push( tmp );	
		}	
		
		int count_back = 3;
		while( count_back-- )
		{
			gets( input );
			for(int i=0,j=12;i<(int)strlen(input);i+=3,--j)
			{
				Node tmp;
				tmp.rank = input[i] ;
				tmp.suit = input[i+1];
				Q[j].push( tmp );	
			}			
		}	
	
		/*
		for(int i=0;i<13;i++)
		{
			printf("%2d ----> ",i+1);
			while( !Q[i].empty() )
			{
				Node top = Q[i].top(); Q[i].pop();	
				printf("%c%c\t",top.rank,top.suit);
			}	
			printf("\n");
		}
		printf("\n");
	*/
		
	//	char ch[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
	//	for(int i=0;i<13;i++)	printf("%d\n",prog( ch[i] ));
		
		int now = 12 , cnt = 0;
		while( !Q[now].empty() )
		{			
			Node top = Q[now].front(); Q[now].pop();	
			int rank = prog( top.rank );
			
	//		printf("%d  %c%c\n",rank+1,top.rank,top.suit);
			
			now = rank;
			last = top;
			++cnt;
		}
		
		if( cnt < 10 )	printf("0");	
		printf("%d,%c%c\n",cnt,last.rank,last.suit);
	}
	
	
	return 0;	
}
