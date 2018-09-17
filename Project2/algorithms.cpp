#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
//Dylan Alvarez
/**
 * This file has the algorithms for each type of sort
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
