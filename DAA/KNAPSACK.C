#include<stdio.h>
int i, j;
struct data
{
    int profit;
    int weight;
    float avg;
};
void sort_items(struct data items[], int n)
{
    struct data temp;
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(items[i].avg < items[j].avg)
            {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

int main()
{
    int n, capacity;

    printf("Enter no. of items:\n");
    scanf("%d", &n);

    struct data items[n];

    for(i = 0; i < n; i++)
    {
        printf("Enter profit and weight of item %d:\n", i + 1);
        scanf("%d %d", &items[i].profit, &items[i].weight);
    }

    printf("Enter knapsack capacity:\n");
    scanf("%d", &capacity);

    // FIX: type casting for correct average calculation
    for(i = 0; i < n; i++)
    {
        items[i].avg = (float)items[i].profit / items[i].weight;
    }

    sort_items(items, n);

    float totalvalue = 0.0;

    for(i = 0; i < n; i++)
    {
        if(capacity >= items[i].weight)
        {
            capacity -= items[i].weight;
            totalvalue += items[i].profit;
        }
        else
        {
            totalvalue += items[i].avg * capacity;
            break;
        }
    }

    printf("Maximum profit: %.2f\n", totalvalue);

    return 0;
}
