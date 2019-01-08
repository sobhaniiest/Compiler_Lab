#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 200

char state[size],symbol[size],fs[size],is,ss;
char ns[size][size][size];
char fstate[size];
char str[size];
int ind,length;
int ii = 0;

/*
INPUT FORMAT : 

abc    // state
01     // symbol
a      // initial state
c      // final state
ab b   // next state
c ac
bc c

1001   // string

*/

void nfa(char is,int index)
{
    int i,ptri,ptrj;
    if(index == length)
        fstate[ii++] = is;
    else
    {

        for(i=0;i<strlen(state);i++)
        {
            if(is == state[i])
            {
                ptri = i;
                break;
            }
        }
        for(i=0;i<strlen(symbol);i++)
        {
            if(str[index] == symbol[i])
            {
                ptrj = i;
                break;
            }
        }
        for(i=0;i<strlen(ns[ptri][ptrj]);i++)
        {
            is = ns[ptri][ptrj][i];
            nfa(is,index+1);
        }
    }

}

int main()
{
    int l,n,i,j,f,k;
    scanf("%s",state);
    l = strlen(state);
    scanf("%s",symbol);
    n = strlen(symbol);
    scanf("%c %c",&ss,&is);
    scanf("%s",fs);
    f = strlen(fs);

    for(i=0;i<l;i++)
    {
        for(j=0;j<n;j++)
            scanf("%s",ns[i][j]);
    }

    printf("The NFA is :\n");
    printf(" ");
    for(i=0;i<n;i++)
    	printf("   %c   ",symbol[i]);
    printf("\n");
    for(i=0;i<l;i++)
    {
        printf("%c   ",state[i]);
        for(j=0;j<n;j++)
        {
            for(k=0;k<strlen(ns[i][j]);k++)
                printf("%c,",ns[i][j][k]);
            printf(" ");
        }
        printf("\n");
    }

    printf("String : ");
    scanf("%s",str);

    ind = 0;
    length = strlen(str);
    nfa(is,ind);
    printf("\n");
    for(i=0;i<strlen(fstate);i++)
        printf("%c ",fstate[i]);
    printf("\n");
    int flag = 0;
    for(i=0;i<strlen(fs);i++)
    {
        for(j=0;j<strlen(fstate);j++)
        {
            if(fs[i] == fstate[j])
            {
                flag = 1;
                break;
            }
        }
    }

    if(flag)
        printf("The string is accepted\n");
    else
        printf("Is not accepted\n");

    return 0;
}