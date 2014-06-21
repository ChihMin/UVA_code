#include <cstdio>
#include <cstdlib>
#include <queue>
#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Node
{
	int n;
	int a , b ;	
	int list[1000];
};

int n , cnt ;
int a , b , target;
int ans[1000];
bool hash[1001][1001];
string cast[6];
queue < Node > q;

void ini()
{
	cast[0] = "fill A\n";	
	cast[1] = "fill B\n";
	cast[2] = "empty A\n";
	cast[3] = "empty B\n";
	cast[4] = "pour A B\n";
	cast[5] = "pour B A\n"; 
	
	while( !q.empty() )
		q.pop();
		
	memset( hash , 0 ,sizeof( hash )); 
}

bool bfs( int x ,  Node input )
{	
	if( x == 0 )
		input.a = a ;
		
	if( x == 1 )
		input.b = b;
			
	if( x == 2 )	
		input.a = 0;
		
	if( x == 3 )
		input.b = 0;
	
	if( x == 4 )
	{
		if( input.b == 0 )
		{
			input.b += input.a ;
			input.a = 0;	
		}
		if( input.a == a )
		{
			int tmp_b = b - input.b;
			if( input.a <= tmp_b )
			{
				input.b += input.a ;
				input.a = 0;
			}
			else
			{
				input.b = b;
				input.a -= tmp_b ;
			}
		}
	}	
	
	if( x == 5 )
	{
		if( input.b == b )
		{
			int tmp_a = a - input.a ;
			if( input.b <= tmp_a )
			{
				input.a += input.b;
				input.b = 0;	
			}
			
			else
			{
				input.a = a;
				input.b -= tmp_a;	
			}
		}
		
		if( input.a == 0 )
		{
			if( input.b <= a )
			{
				input.a = input.b ;
				input.b = 0;
			}
			
			else
			{
				input.a = a;
				input.b -= a ;	
			}
		}
	}
		
	input.list[input.n++] = x;
	
	if( !hash[input.a][input.b] )
	{
		q.push( input );
		if(  input.b == target )
		{
			for(int i=0;i<input.n;++i)
				cout << cast[input.list[i]] ;
			
			cout << "success\n";
			return true;
		}
		hash[input.a][input.b] = 1;
	}
	
	return false;
}

int main()
{	
	
	while( ~scanf("%d %d %d",&a,&b,&target) )
	{ 
		ini();
		//printf("%d %d %d\n",a,b,target);
		
		Node input;
		input.a = input.b = input.n = 0; 
		hash[input.a][input.b] = 1;
		
		q.push( input );
		while( !q.empty() )
		{
			Node u = q.front(); q.pop();
			
			/*
			if(  u.b == target )
			{
				cnt = u.n;
				for(int i=0;i<cnt;++i)
					cout << cast[u.list[i]] ;
				
				cout << "success\n";
				break;
			}*/
			/*
			for(int i=0;i<u.n;++i)
				cout << cast[u.list[i]] << "\n"; 
			cout << "\n";
			*/
			bool ok  = 0;
			for(int i=0;i<6;++i)
			{	
				ok = bfs( i ,  u );
				if( ok )	break;
			}
			
			if( ok )
			{	
			//	cout << "yaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n";
				break;
			}
		}
	} 
	return 0;
} 
