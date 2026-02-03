#include<stdio.h>

void towerofhanoi(int n,char s,char d,char a)
{
    if(n==1)
    {
        printf("move the disk %d from %c to %c\n",n,s,d);
     return;
    }
    towerofhanoi(n-1,s,a,d);
    printf("move disk %d from %c to %c\n",n,s,d);
     towerofhanoi(n-1,a,d,s);
}
int main()
{
    int disk_count;
    printf("enter how many disk are there:\n");
    scanf("%d",&disk_count);
    printf("reqired moves:\n");
    towerofhanoi(disk_count,'s','d','a');
}

