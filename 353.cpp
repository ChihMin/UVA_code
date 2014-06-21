#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct TrieNode
{
	TrieNode *l[128];
	int n ;
	
	TrieNode()
	{
		memset( l , 0 , sizeof( l ));
		n = 0;
	}
} *root = new TrieNode();

void add( char *s )
{
	TrieNode *p = root;
	for( ; *s ; ++s )
	{
		if( !p->l[(int)*s] )
			p->l[(int)*s] = new TrieNode();
		p = p->l[(int)*s];	
	}	
	p->n++;
}

bool lookup( char *s )
{
	TrieNode *p = root;
	
	for( ; *s ; ++s )
	{
		if( !p->l[(int)*s] )
			return false;	
		p = p->l[(int)*s];
	}
	
	return p->n > 0;
}

void del( )
{
	TrieNode *p = root ;
	for(int i=0;i<=128;i++)
		p->l[i] = 0;	
}
	
bool check( char *s )
{
	int len = (int)strlen( s ) ; 
	for(int i=0 , j=len-1 ;i<len/2;++i,--j)
		if( s[i] != s[j] )
			return false ;	
	return true ;	
}

int main()
{
	char s[100];
	
	while( ~scanf("%s",s) )
	{	
		int num = 0;
		del( );
		
		int len = (int)strlen( s );
		for(int i=1;i<=len;++i)
		{
			for(int j=0;j<len;++j)
			{
				char tmp[100];
				int cnt = 0;
				for(int k=j , l=0 ; k<len && l<i;++l , ++k )
				{
					tmp[l] = s[k];
					++cnt ;
				}	
				
				if( cnt == i )
				{
					tmp[cnt] = 0;
					if( check( tmp ) && !lookup( tmp ) )
					{
						++num;						
						//printf("%s\n",tmp);
						add( tmp );	
					}
				}
				
				else	
					break;
			}
		}	
		printf("The string '%s' contains %d palindromes.\n",s,num);
	}
	
	return 0;	
}
