#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

/**
 * This file generates 12 files that are as follows. 5000 random, 5000 ascending, 5000 descending, 10000 random, 10000 ascending...etc.
*/

void reverseArray(int arr[], int start, int end)
{
    while(start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void selectionSort(int arr[], int size)
{
    int minIndex;

    for(int i = 0; i < size; i++)
    {
        minIndex = i;
        for(int j = i+1; j < size; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        std::swap(arr[minIndex], arr[i]);
    }
}

void bubbleSort(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; //Element to be placed at right position
    int i = low - 1; //Index of smaller element
    for(int j = low; j <= high-1; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i+1], arr[high]);
    return (i+1);
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}


int main()
{
    int currentTime = time(NULL);
    srand(currentTime);
    FILE* f;
    int arr1[5000];
    int arr2[10000];
    int arr3[20000];
    int arr4[50000];

    //Test case 1
    f = fopen("test1.txt", "w");
    //random order for 5000
    for(int i = 0; i < 5000; i++)
    {
        arr1[i] = rand();
        fprintf(f , "%d\n", arr1[i]);
    }
    fclose(f);

    //Test case 2
    f = fopen("test2.txt", "w");

    //sort the arr1 to be ascending
    bubbleSort(arr1, 5000);

    //ascending order for 5000
    for(int i = 1; i < 5001; i++)
    {
        
        fprintf(f , "%d\n", arr1[i]);
    }
    fclose(f);

    //Test case 3
    f = fopen("test3.txt", "w");

    //sort the arr1 to be descending
    reverseArray(arr1, 0, 5000);

    //ascending order for 5000
    for(int i = 0; i < 5000; i++)
    {
        
        fprintf(f , "%d\n", arr1[i]);
    }
    fclose(f);

    //Test case 4
    f = fopen("test4.txt", "w");
    //random order for 10000
    for(int i = 0; i < 10000; i++)
    {
        arr2[i] = rand();
        fprintf(f , "%d\n", arr2[i]);
    }
    fclose(f);

    //Test case 5
    f = fopen("test5.txt", "w");

    //sort the arr1 to be ascending
    quickSort(arr2, 0, 10000);

    //ascending order for 10000
    for(int i = 1; i < 10001; i++)
    {
        
        fprintf(f , "%d\n", arr2[i]);
    }
    fclose(f);

    //Test case 6
    f = fopen("test6.txt", "w");

    //sort the arr1 to be descending
    reverseArray(arr2, 0, 10000);

    //ascending order for 10000
    for(int i = 0; i < 10000; i++)
    {
        
        fprintf(f , "%d\n", arr2[i]);
    }
    fclose(f);

    //Test case 7
    f = fopen("test7.txt", "w");
    //random order for 20000
    for(int i = 0; i < 20000; i++)
    {
        arr3[i] = rand();
        fprintf(f , "%d\n", arr3[i]);
    }
    fclose(f);

    //Test case 8
    f = fopen("test8.txt", "w");

    //sort the arr1 to be ascending
    quickSort(arr3, 0, 20000);

    //ascending order for 20000
    for(int i = 1; i < 20001; i++)
    {
        
        fprintf(f , "%d\n", arr3[i]);
    }
    fclose(f);

    //Test case 9
    f = fopen("test9.txt", "w");

    //sort the arr1 to be descending
    reverseArray(arr3, 0, 20000);

    //ascending order for 5000
    for(int i = 0; i < 20000; i++)
    {
        
        fprintf(f , "%d\n", arr3[i]);
    }
    fclose(f);

    //Test case 10
    f = fopen("test10.txt", "w");
    //random order for 50000
    for(int i = 0; i < 50000; i++)
    {
        arr4[i] = rand();
        fprintf(f , "%d\n", arr4[i]);
    }
    fclose(f);

    //Test case 11
    f = fopen("test11.txt", "w");

    //sort the arr1 to be ascending
    quickSort(arr4, 0, 50000);

    //ascending order for 50000
    for(int i = 1; i < 50001; i++)
    {
        
        fprintf(f , "%d\n", arr4[i]);
    }
    fclose(f);

    //Test case 12
    f = fopen("test12.txt", "w");

    //sort the arr1 to be descending
    reverseArray(arr4, 0, 50000);

    //ascending order for 50000
    for(int i = 0; i < 50000; i++)
    {
        
        fprintf(f , "%d\n", arr4[i]);
    }
    fclose(f);

}