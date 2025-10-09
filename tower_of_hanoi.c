#include <stdio.h>
#include <stdlib.h>
void TOH(int n,char s,char d,char t)
{
    if(n>1)
    {
        TOH(n-1,s,t,d);
        printf("\n move %d disc from %c to %c",n,s,d);
        TOH(n-1,t,s,d);
    }
    else
        printf("\move %d disc from %c to %c",n,s,d);
}

int main()
{
    int n;
    printf("\n No.of disc's:");
    scanf("%d",&n);
    TOH(n,'S','T','D');
    return 0;
}
