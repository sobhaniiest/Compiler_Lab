#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 20

int main()
{
    int l,n,i,j,ptri,ptrj;
    char state[size],symbol[size],is,fs,ss;
    scanf("%s",state);
    l = strlen(state);
    scanf("%s",symbol);
    n = strlen(symbol);
    scanf("%c %c %c",&ss,&is,&fs);
    char ns[l+1][n+1];

    for(i=0;i<l;i++)
    {
        for(j=0;j<n;j++)
            scanf(" %c",&ns[i][j]);
    }

    printf("The DFA is :\n");
    printf(" ");
    for(i=0;i<n;i++)
    	printf(" %c",symbol[i]);
    printf("\n");
    for(i=0;i<l;i++)
    {
        printf("%c ",state[i]);
        for(j=0;j<n;j++)
            printf("%c ",ns[i][j]);
        printf("\n");
    }

    char str[size];
    printf("String : ");
    scanf("%s",str);
   
    for(i=0;i<strlen(str);i++)
    {
    	printf("%c ",is);
    	for(j=0;j<n;j++)
    	{
    		if(str[i] == symbol[j])
    		{
    			ptrj = j;
    			break;
    		}
    	}
    	for(j=0;j<l;j++)
    	{
    		if(is == state[j])
    		{
    			ptri = j;
    			break;
    		}
    	}
        
    	is = ns[ptri][ptrj];
    	printf("-> %c\n",is);
    }

    if(is == fs)
    	printf("The string is accepted\n");
    else
    	printf("Is not accepted\n");

    return 0;
}