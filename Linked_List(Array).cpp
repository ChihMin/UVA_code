#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

struct Node{
	string k , name , type ;
	Node(){} ; 
	Node( string _k , string _type , string _name ){
		k = _k , type = _type , name = _name; 	
	}
} ; 

struct list{
	int next , last ;
	Node data ; 
	list(){
		next = last = -1 ; 
	}
} ;

string nameTable[20000] ; 
list linked[20000] ; 
int n , cnt; 

void ini(){
	cnt = 0 ; 
	for(int i=0;i<=n+1;++i)
		linked[i] = list() ; 
}

bool cmp( const string &A , const string &B ){
	return A < B ; 	
}

int main(){
	
	int T ; 
	cin >> T ;
	while( T-- ){
		
		cin >> n ; 
		ini();  
		
		int head = -1, middle = -1 , back = - 1;
		while( n-- ){
			string name , type , k ; 
			cin >> k >> type >> name ;
			
			  
			if( !cnt ){
				linked[cnt].data = Node( k , type , name ) ; 
				middle = head = back = cnt++ ;  
				continue;
			}
			
			if( type == "A" ){
				//push_front ; 
				linked[cnt].data = Node( k , type , name ) ; 
				linked[cnt].last = head ; 
				linked[head].next = cnt ; 
				head = cnt++ ; 	
			}
			else if( type == "B" ){
				int next = linked[middle].next ;  
				linked[cnt].data = Node( k , type , name ) ; 
				linked[cnt].last = middle ;
				linked[cnt].next = linked[middle].next ; 
				linked[middle].next = cnt ; 
				middle = cnt ; 
				
				if( next != -1 )	linked[next].last = cnt ; 
				
				cnt++ ; 
				if( cnt == 2 )	head = middle  ; 
			}
			else{
				linked[cnt].data = Node( k , type , name ) ; 
				linked[cnt].next = back ; 
				linked[back].last = cnt ; 
				back = cnt++ ; 
			}
			
			if( cnt % 2 ){
				if( type == "A" )
					middle = linked[middle].next ; 
			}
			else{
				if( type == "B" || type == "C" )
					middle = linked[middle].last  ;	
			}
		}
		
		int ptr = head ; 
		printf("Before:\n");
		while( ptr != -1 ){
			Node &data = linked[ptr].data ; 
			cout << data.k << ' ' ; 
			cout << data.type << ' ' ;
			cout << data.name << endl ; 
			ptr = linked[ptr].last ; 
		}
		
		int m ; 
		cin >> m ; 
		for(int i=0;i<m;++i)
			cin >> nameTable[i] ;
		sort( nameTable , nameTable + m , cmp ) ;
		
		int ans = 0 ;
		ptr = head ; 
		printf("After:\n");
		while( ptr != -1 ){
			Node &data = linked[ptr].data ;
			string *name = lower_bound( nameTable , nameTable + m , data.name ) ; 
			if( *name != data.name ){
				cout << data.k << ' ' ; 
				cout << data.type << ' ' ;
				cout << data.name << endl ; 
				ans++ ; 
			}
			ptr = linked[ptr].last ; 
		}
		if( !ans )	printf("null\n");
	}
	
	return 0 ;
}
