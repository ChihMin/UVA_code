#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

char s[100][10][10];

int sq( int a )
{
	return a*a ;	
}

int th( int a , int b ,int c ,int d )
{
	return 1000*a+100*b+10*c+d;	
}

int six(int a,int b, int c, int d, int e , int f )
{
	return a*100000+b*10000+c*1000+d*100+e*10+f;	
}

int eight( int a,int b, int c, int d, int e , int f , int g , int h)
{
	return a*10000000+b*1000000+c*100000+d*10000+e*1000+f*100+g*10+h;	
}

void ini()
{
	for(int a=0;a<10;++a)
		for(int b=0;b<10;++b)
		{
			//printf("%d %d %d\n",square(a),square(b),10*a+b);
			if( sq( a + b ) == ( 10*a+b ) )
				printf("%d%d\n",a,b);
		}

	for(int a=0;a<10;++a)
		for(int b=0;b<10;++b)
			for(int c=0;c<10;++c)
				for(int d=0;d<10;++d)
					if( sq( a*10+b+c*10+d ) == th(a,b,c,d) )	
						printf("%d%d%d%d\n",a,b,c,d);
	for(int a=0;a<10;++a)
		for(int b=0;b<10;++b)
			for(int c=0;c<10;++c)
				for(int d=0;d<10;++d)
					for(int e=0;e<10;++e)
						for(int f=0;f<10;++f)
							if(sq( a*100+b*10+c+d*100+e*10+f ) == six(a,b,c,d,e,f))
								printf("%d%d%d%d%d%d\n",a,b,c,d,e,f);

	for(int a=0;a<10;++a)
		for(int b=0;b<10;++b)
			for(int c=0;c<10;++c)
				for(int d=0;d<10;++d)
					for(int e=0;e<10;++e)
						for(int f=0;f<10;++f)
							for(int g=0;g<10;++g)
								for(int h=0;h<10;++h)
									if( sq( a*1000+b*100+c*10+d+1000*e+100*f+10*g+h) == eight(a,b,c,d,e,f,g,h)  )     
										printf("%d%d%d%d%d%d%d%d\n",a,b,c,d,e,f,g,h);
}

int main()
{
	ini();
	
	
	//system("pause");
	return 0;	
}
