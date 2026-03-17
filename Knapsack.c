#include<stdio.h>
int i,j;
struct data
{
int profit;
int weight;
float avg;
};
void sort_items(struct data items[],int n)
{
struct data temp;
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(items[i].avg<items[j].avg)
{
temp=items[i];
items[i]=items[j];
items[j]=temp;
}
}
}
}
int main()
{
int n,capacity;
printf("enter no.of items:\n");
scanf("%d",&n);
struct data items[n];
for(i=0;i<n;i++)
{
printf("enter profit of %d and weight:\n",i+1);
scanf("%d %d",&items[i].profit,&items[i].weight);
}
printf("enter knapsack capacity:\n");
scanf("%d",&capacity);
for(i=0;i<n;i++)
{
items[i].avg=items[i].profit/items[i].weight;
}
sort_items(items,n);
float totalvalue=0.0;
for(i=0;i<n;i++)
{
if(capacity>=items[i].weight)
{
capacity-=items[i].weight;
totalvalue+=items[i].profit;
}
else
{
totalvalue+=items[i].avg*capacity;
break;
}
}
printf("maximum profit: %.2f",totalvalue);
return 0;
}

