#include<stdio.h>
int length(char a[100]);
int stringfunc(int num);
void main()
{
    int num;
    printf("no of lines to print:");
    scanf("%d",&num);
    stringfunc(num);
}
int length(char a[100])
{
    int i;
    for(i=0;a[i]!='\0';i++);
    return i;
}
int stringfunc(int num)
{
    char str[10][100];
    int i;
    int L;
    int j;
    int b[100];
    for(i=0;i<=num;i++)
    {
        gets(str[i]);
    }
    for(i=0;i<=num;i++)
    {
        b[i]=length(str[i]);
    }
    L=b[0];
    for(i=1;i<=num;i++)
    {
        if(b[i]>L)
        {
            L=b[i];
            j=i;
        }
    }
    printf(" The longest line is: ");
    puts(str[j]);
    return;
}
