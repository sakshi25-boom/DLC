#include <stdio.h>

void merge(int a[], int l, int m, int r)
{
    int i = l, j = m + 1, k = 0;
    int temp[1000];

    while (i <= m && j <= r)
    {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= m)
        temp[k++] = a[i++];

    while (j <= r)
        temp[k++] = a[j++];

    for (i = l, k = 0; i <= r; i++, k++)
        a[i] = temp[k];
}

void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;

        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);

        merge(a, l, m, r);
    }
}

int main()
{
    int n, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    int marks[n];

    printf("Enter marks:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &marks[i]);

    mergeSort(marks, 0, n - 1);

    printf("Sorted marks in ascending order:\n");
    for (i = 0; i < n; i++)
        printf("%d ", marks[i]);

    return 0;
}