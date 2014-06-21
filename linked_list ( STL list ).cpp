#include <cstdio>
#include <list>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node{
	string type , name , k  ;
	Node(){} ; 
	Node( string _k , string _type , string _name ){
		name = _name , type = _type , k = _k ; 
	}	
} ; 

list < Node > v ; 
string hash[20000] ; 

bool cmp( const string &A , const string &B ){
	return A < B ; 	
}

int main(){
	
	int T ;
	scanf("%d",&T);
	while( T-- ){
		v.clear() ; 
		
		list < Node > :: iterator it ; 
		int n , m , cnt = 0 ;; 
		scanf("%d",&n);
		while( n-- ){
			string k , name , type ; 
			cin >> k >> type >> name ;
			int x = v.size();
			
			it = v.begin() ; 
			for(int i=0;i<x-1;++i)	it++;
			
			if( type == "A")	v.push_front( Node( k , type , name ) ) ;
			else if( type == "B" )	v.insert( it  , Node( k , type , name )) ;
			else v.push_back( Node( k , type , name ) ) ; 
		}
		
		scanf("%d",&m) ;
		while( m-- ){
			string name ; 
			cin >> name  ;
			hash[cnt++] = name ;
		}
		
		printf("Before:\n");
		for(it=v.begin();it!=v.end();++it){
			cout << it->k << ' ';
			cout << it->type << ' ';
			cout << it->name << endl ; 
		}
		
		sort( hash , hash + cnt , cmp );
		
		printf("After:\n");
		int ans = 0; 
		for( it = v.begin() ; it != v.end() ; ++it){
			string *a = lower_bound( hash , hash + cnt , it->name ); 
			if( *a == it->name )	continue;
			cout << it->k << ' ';
			cout << it->type << ' ';
			cout << it->name << endl ; 
			ans++ ;
		}
		if( !ans)	printf("null\n");
	}
	return 0; 
}	
