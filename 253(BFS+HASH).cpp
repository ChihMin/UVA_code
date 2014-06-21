#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

struct Node
{
	char a,b,c,d,e,f;	
};

Node target;
Node start;
queue < Node > Q;
bool hash[4][4][4][4][4][4];
// r = 0 b = 1  g = 2

void ini()
{
	memset( hash , 0 , sizeof( hash ) );
	while( !Q.empty() )	Q.pop();	
}

int get_hash( char c )
{
	if( c == 'r' )	return 0;
	if( c == 'b' )  return 1;
	return 2;	
}

void update( Node *sample , char str[] )
{
	sample->a = str[0];
	sample->b = str[1];
	sample->c = str[2];
	sample->d = str[3];
	sample->e = str[4];
	sample->f = str[5];
}

void exchange( Node now , Node *tmp , int type )
{
	if( type == 1 )
	{
		tmp->a = now.c;
		tmp->d = now.a;
		tmp->f = now.d;
		tmp->c = now.f;	
	}
	
	if( type == 2 )
	{
		tmp->b = now.a;
		tmp->f = now.b;
		tmp->e = now.f;
		tmp->a = now.e;		
	}
	
	if( type == 3 )
	{
		tmp->b = now.c;
		tmp->d = now.b;
		tmp->e = now.d;
		tmp->c = now.e;		
	}
} 

bool check( Node x , Node y )
{
	if( x.a == y.a )
		if( x.b == y.b )
			if( x.c == y.c )
				if( x.d == y.d )
					if( x.e == y.e )
						if( x.f == y.f )
							return true;
	return false;
}

void bfs(  )
{
	Q.push( start );
	int a = get_hash( start.a );
	int b =	get_hash( start.b );
	int c = get_hash( start.c );
	int d = get_hash( start.d );
	int e = get_hash( start.e );
	int f = get_hash( start.f );
	
	hash[a][b][c][d][e][f] = 1;
	
	bool find = 0;
	find = check( target , start );
	
	while( !Q.empty() )
	{
		Node now = Q.front(); Q.pop();
		for(int i=1;i<=3;i++)
		{
			Node tmp = now;
			exchange( now , &tmp , i );	
			
			a = get_hash( tmp.a );
			b =	get_hash( tmp.b );
			c = get_hash( tmp.c );
			d = get_hash( tmp.d );
			e = get_hash( tmp.e );
			f = get_hash( tmp.f );
		
			if( !hash[a][b][c][d][e][f] )
			{
				hash[a][b][c][d][e][f] = 1;
				if( check( target , tmp ) )
				{
					find = 1;
					break;
				}
				
				Q.push( tmp );
			}
		}	
		if( find )	break;
	}	
	
	if( find )	printf("TRUE\n");
	else	printf("FALSE\n");
}



int main()
{
	char input[100];
	
	while( gets( input ))
	{
		ini();
		
		char s1[100] , s2[100];
		for(int i=0,j=6;i<6;i++,++j)
		{
			s1[i] = input[i];
			s2[i] = input[j];
		}
		s1[6] = s2[6] = 0;
	
		update( &target , s2 );	// have been exchange
		update( &start , s1 );

		bfs();
	}
	
	
	return 0;	
}
