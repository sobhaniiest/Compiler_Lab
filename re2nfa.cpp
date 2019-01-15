#include <bits/stdc++.h>
#include <ctype.h>
#include <string.h>
#define size 50
using namespace std;

int t1=-1,t2=-1,t3=-1,n,k,s;
char str[size],s1[size],s2[size];

int pri(char o)
{
    int p;
    if(o=='*')
        p=3;
    if(o=='.')
        p=2;
    if(o=='+')
        p=1;
    return p;
}

void push(char x,char *y,int *z)
{
    (*z)++;
    y[*z] = x;
}

void pop(char *y,int *z)
{
    (*z)--;
}

void disp()
{
    int i;
    printf("The postfix expression is: ");
    for(i=0;i<=t1;i++)
        printf("%c ",s1[i]);
}

int check()
{
    int i,t=0;
    for(i=0;i<n;i++)
    {
        if(str[i]=='(')
            t++;
        if(str[i]==')')
            t--;
    }
    return t;
}

void postfix()
{
	int n,i,j,v;
	char t,c,m,u;
    n = strlen(str);
    v = check();
  
    if(v == 0)
    {
        printf("\nBalanced parentheses\n");

        for(i=0;i<n;i++)
        {
            c = str[i];
            t = s2[t2];
            if(int(c) >= int('a') && int(c) <= int('z'))
                push(c,s1,&t1);
                
            else if((t2 == -1) && (c=='('||c=='*'||c=='.'||c=='+'))
                push(c,s2,&t2);
            else if(t2 != (-1)  && (c=='('||c=='*'||c=='.'||c=='+'))
            {
                if(c == '(')
                    push(c,s2,&t2);
                else if(t == '(')
                    push(c,s2,&t2);
                else if(pri(c) >= pri(t))
                    push(c,s2,&t2);
                else if(pri(c)<pri(t) && t != '(')
                {
                    m = s2[t2];
                    j = t2;
                    while((t2 != (-1) || m != '(') && (pri(c) < pri(s2[j])))
                    {
                        m = s2[j];
                        push(m,s1,&t1);
                        pop(s2,&t2);
                        j--;
                    }
                    push(c,s2,&t2);
                }
            }
            else if(t == '(')
                push(c,s2,&t2);
            else if(c == ')')
            {
                while(s2[t2] != '(')
                {
                    push(s2[t2],s1,&t1);
                    pop(s2,&t2);
                }
                pop(s2,&t2);
            }
        }
        while(t2 != (-1))
        {
            u = s2[t2];
            push(u,s1,&t1);
            pop(s2,&t2);
        }

        disp();
        printf("\n");
    }
    else
        printf("\nUnbalanced parentheses");
}

struct re
{
	int is,fs;
};

int main()
{
    printf("Enter the regular expression:");
    cin>>str;
    postfix();

/////////////////////////////////////////////////////////////////////

    int i,ns1,ns2,j;
    char ch;
    char M[100][100];
    for(i=0;i<100;i++)
    {
    	for(j=0;j<100;j++)
    		M[i][j] = '-';
    }
    struct re ns[100];
    i = 0;
    k = 0;
    s = 1;
    while((ch=s1[i])!='\0')
    {
    	if(ch >= 'a' && ch <= 'z')
    	{
    		t3++;
    		ns[t3].is = s;
    		s++;
    		ns[t3].fs = s;
    		s++;
    		M[ns[t3].is][ns[t3].fs] = ch;
    	}
    	else if(ch == '*')
    	{
    		ns1 = ns[t3].fs+1;
    		ns2 = ns1+1;
    		M[ns1][ns[t3].is] = '^';
    		M[ns1][ns2] = '^';
    		M[ns[t3].fs][ns[t3].is] = '^';
    		M[ns[t3].fs][ns2] = '^';
    		ns[t3].is = ns1;
    		ns[t3].fs = ns2; 
    		cout<<ns1<<" "<<ns2<<"\n";   	
    	}
    	else if(ch == '.')
    	{
    		M[ns[t3-1].fs][ns[t3].is] = '^';
    		t3--;
    		ns[t3].fs = ns[t3+1].fs;
    	}
    	else if(ch == '+')
    	{
    		ns1 = ns[t3].fs+1;
    		ns2 = ns1+1;
    		M[ns1][ns[t3].is] = '^';
    		M[ns1][ns[t3-1].is] = '^';
    		M[ns[t3].fs][ns2] = '^';
    		M[ns[t3-1].fs][ns2] = '^';
    		t3--;
    		ns[t3].is = ns1;
    		ns[t3].fs = ns2; 
    	}
    	i++;
    }
    cout<<"  ";

    for(j=0;j<13;j++)
    	cout<<j<<" ";
    cout<<"\n";
    for(i=0;i<12;i++)
    {   
    	cout<<i<<" ";
    	for(j=0;j<13;j++)
    	{
    		cout<<M[i][j]<<" ";
    	}
    	cout<<"\n";
    }
}
