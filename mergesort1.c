#include "my.h"

void merge(int *l, int n, int *r, int m, int a[])
{
    int i,j,k;
    i=j=k=0;
    while (i<n && j <m)
    {
        if (l[i] < r[j]) a[k++] = l[i++];
        else a[k++] = r[j++];
    }
    while (i<n) a[k++] = l[i++];
    while (j<m) a[k++] = r[j++];
}
void mergesort(int a[], int n)
{
    int i,j;
    if (n<2) return;
    int mid = n/2;
    int *L = calloc(mid, sizeof(int));
    int *R = calloc(n - mid, sizeof(int));
    for (i=0; i<mid; i++) L[i] = a[i];
    for (i=mid; i<n; i++) R[i-mid] = a[i];
    mergesort(L,mid);
    mergesort(R,n-mid);
    merge(L, mid, R, n-mid, a);
    free(L);
    free(R);
    return;
}
void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}
int partition(int a[], int start, int end)
{
    int pIndex = start;
    int pivot = a[end];
    for (int i=start; i<end; i++)
    {
        if (a[i] < pivot)
        {
            swap(&a[i],&a[pIndex]);
            pIndex = pIndex+1;
        }
    }
    swap(&a[end],&a[pIndex]);
    return pIndex;
}
void qksort(int a[], int start, int end)
{
    if (start>=end) return;
    int pIndex = partition(a,start,end);
    qksort(a,start,pIndex-1);
    qksort(a,pIndex+1,end);
    return;
}
void merge1 (int a[], int low, int mid, int high)
{
    int i = low;
    int j = mid+1;
    int n = high - low + 1;
    int k =0;
    int *temp = calloc(n, sizeof(int));
    while (i<=mid && j<=high)
    {
        if (a[i] < a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while (i<=mid) temp[k++] = a[i++];
    while (j<=high) temp[k++] = a[j++];
    i = low;
    k=0;
    while (i<=high) a[i++] = temp[k++];
    free(temp);
}
void mergesort1 (int a[], int low, int high)
{
    if (low >= high) return;
    int mid = (low+high)/2;
    mergesort1(a, low, mid);
    mergesort1(a, mid+1, high);
    merge1(a, low, mid, high);
}
int main (void)
{
    int a[] = {2,4,1,6,8,5,-1,3,7};
    int n = sizeof(a)/sizeof(a[0]);
    //qksort(a,0, n-1);
    //mergesort(a,n);
    mergesort1(a,0, n-1);
    eol;
    for (int i=0; i<n; i++) printf("%d,", a[i]);
    eol;
    return 1;
}