#include <stdio.h>
#define SIZE 10

int largest(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void radix_sort(int arr[], int n)
{
    int bucket[SIZE][SIZE], bucket_count[SIZE];
    int NOP = 0, remainder, divisor = 1;
    int large = largest(arr, n);
    while (large > 0)
    {
        NOP++;
        large /= SIZE;
    }
    for (int pass = 0; pass < NOP; pass++)
    {
        for (int i = 0; i < SIZE; i++)
        {
            bucket_count[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            remainder = (arr[i] / divisor) % SIZE;
            bucket[remainder][bucket_count[remainder]] = arr[i];
            bucket_count[remainder] = 1;
        }
        int count = 0;
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < bucket_count[i]; j++)
            {
                arr[count++] = bucket[i][j];
            }
        }
        divisor *= SIZE;
    }
}

int main()
{
    int arr[] = {50, 40, 30, 20, 10};
    radix_sort(arr, 5);
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
}