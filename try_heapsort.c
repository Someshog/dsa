#include <stdio.h>
#define MAX 100
int RestoreHeapUp(int heap[], int index)
{
    int val = heap[index];
    while ((index > 1) && (heap[index / 2] < val))
    {
        heap[index] = heap[index / 2];
        index /= 2;
    }
    heap[index] = val;
}

int RestoreHeapDown(int heap[], int index, int n)
{
    int val = heap[index];
    int j = index*2;
    while(j<=n){
        if(j<n && heap[j+1]>heap[j]){
            j++;
        }
        if(heap[j]<val){
            break;
        }
        heap[j/2] = heap[j];
        j*=2;
    }
    heap[j/2] = val;

}

int main()
{
    int heap[MAX], n;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &heap[i]);
        RestoreHeapUp(heap, i);
    }
    int j = n;
    for (int i = 1; i <= n; i++)
    {
        int temp = heap[1];
        heap[1]=heap[j];
        heap[j] = temp;
        j--;
        RestoreHeapDown(heap,1,j);
    }
    printf("\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", heap[i]);
    }
}