#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <map>

using namespace std;

struct Node{
	string k , type , name ; 
	Node(){} ; 
	Node( string &_k , string &_type , string &_name ){
		k = _k ; 
		type = _type ;
		name = _name ; 
	}
} ; 

struct list{
	list *next , *last ; 
	int left , right  ;
	Node data ; 
	
	list(){
		next = last = NULL ;
		left = right = 0 ; 
	}
	~list(){}
	void push_front( const Node &in );
	void push_back( const Node &in ) ; 
	void update();
} *root  ;

void list::push_front( const Node &in ){
	list *newHead = new list() ; 
	newHead->last = this ; 
	newHead->data = in ; 
	this->next = newHead ;
}

void list::push_back( const Node &in ){
	list *newBack = new list() ; 
	newBack->data = in ; 
	newBack->next = this ; 
	this->last = newBack ;  	
}

map < string , int > hash ;

int main(){
	
	int T ;
	scanf("%d", &T ) ; 
	while( T-- ){
		int n ; 
		root = 0 ;
		hash.clear() ; 
		
		string k , type , name ; 
		list *head = 0 , *middle = 0 , *back = 0 ; 
		
		scanf("%d",&n ) ; 
		int cnt = 0 ; 
		while( n-- ){
			cin >> k >> type >> name;  
			if( !root ){
				root = new list() ; 
				root->data = Node( k , type , name ) ;
				head = middle = back = root;
				++cnt ; 
				continue ;  
			}
			
			if( type == "A" ){	
				head->push_front( Node( k , type , name ) ) ; 
				head = head->next ; 
			}
			else if( type == "B" ){
				
				list *newMiddle = new list() ; 
				newMiddle->data = Node( k , type , name ) ; 
				
				if( middle->next ) middle->next->last = newMiddle ; 
				newMiddle->next = middle->next ; 
				middle->next = newMiddle ;
				newMiddle->last = middle ;
				
				middle = newMiddle ;
				if( cnt+1 == 2 )	head = middle ; 
			}
			else{
				back->push_back( Node( k , type , name ) ) ; 
				back = back->last ; 	
			}
			
			if( ( ++cnt ) % 2 ){
				if( type == "A" )	
					middle = middle->next ; 		
			}
			else{
				if( type == "C" || type == "B" )
					middle = middle->last ;
			}
		}
		
		int m ; 
		scanf("%d",&m) ; 
		while( m-- ){
			cin >> name ; 
			hash[name] = 1;  
		}
		
		printf("Before:\n");
		list *ptr = head ; 
		while( ptr ){
			cout << ptr->data.k << ' ' ;
			cout << ptr->data.type << ' ' ;
			cout << ptr->data.name << endl ;
			ptr = ptr->last ; 	
		}
		printf("After:\n");
		ptr = head ;
		int ans = 0 ;
		while( ptr ){
			if( hash.find( ptr->data.name ) == hash.end() ){
				cout << ptr->data.k << ' ' ;
				cout << ptr->data.type << ' ' ;
				cout << ptr->data.name << endl ;
				ans++ ; 
			}
			ptr = ptr->last ; 	
		}
		
		if( !ans )	printf("null\n");	
		delete root ; 
	}

	return 0; 	
}
