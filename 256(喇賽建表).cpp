#include <cstdio>
#include <cstdlib>

using namespace std;

char s[5][20][10];
int main()
{/*
	00
	01
	81
	0000
	0001
	2025
	3025
	9801
	000000
	000001
	088209
	494209
	998001
	00000000
	00000001
	04941729
	07441984
	24502500
	25502500
	52881984
	60481729
	99980001
*/	
	int len[5];
	len[1] = 3;
	len[2] = 5;
	len[3] = 5;
	len[4] = 9;
	
	sprintf(s[1][0],"00");
	sprintf(s[1][1],"01");	
	sprintf(s[1][2],"81");
	
	sprintf(s[2][0],"0000");
	sprintf(s[2][1],"0001");
	sprintf(s[2][2],"2025");
	sprintf(s[2][3],"3025");
	sprintf(s[2][4],"9801");
	
	sprintf(s[3][0],"000000");
	sprintf(s[3][1],"000001");
	sprintf(s[3][2],"088209");
	sprintf(s[3][3],"494209");
	sprintf(s[3][4],"998001");
	
	sprintf(s[4][0],"00000000");
	sprintf(s[4][1],"00000001");
	sprintf(s[4][2],"04941729");
	sprintf(s[4][3],"07441984");
	sprintf(s[4][4],"24502500");
	sprintf(s[4][5],"25502500");
	sprintf(s[4][6],"52881984");
	sprintf(s[4][7],"60481729");
	sprintf(s[4][8],"99980001");
	
	
	int x;
	while( ~scanf("%d",&x) )
	{
		int n = x/2;
		for(int i=0;i<len[n];i++)
			printf("%s\n",s[n][i]);	
	}
	
	
	return 0;	
}
