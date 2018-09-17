#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <iostream>

//Algoritm analysis



void startClock(timespec *clock)
{
    if(clock_gettime(CLOCK_REALTIME, clock))
    {
       std::cout << "This will never happen, no clock, only ocurrs on windows";
    }
}
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


int main() {
    //Time for test 1

    timespec clock1;
    timespec clock2;
    int arr1[5000];
    int arr2[10000];
    int arr3[20000];
    int arr4[50000];
    
    
    FILE* f = fopen("test1.txt", "r");
    for(int i = 0; i < 5000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr1[i] = n;
    }
    fclose(f);

    //Time the quicksort
    startClock(&clock1);
    quickSort(arr1, 0, 5000);
    startClock(&clock2);
    std::cout << "Quick Sort Test 1 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;


    //Time for test 2

    f = fopen("test2.txt", "r");
    for(int i = 0; i < 5000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr1[i] = n;
    }
    fclose(f);


    //Time the quicksort
    startClock(&clock1);
    quickSort(arr1, 0, 5000);
    startClock(&clock2);
    std::cout << "Quick Sort Test 2 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;


    //Time for test 3

    f = fopen("test3.txt", "r");
    for(int i = 0; i < 5000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr1[i] = n;
    }
    fclose(f);


    //Time the quicksort
    startClock(&clock1);
    quickSort(arr1, 0, 5000);
    startClock(&clock2);
    std::cout << "Quick Sort Test 3 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;

    
    //Time for test 4

    f = fopen("test4.txt", "r");
    for(int i = 0; i < 10000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr2[i] = n;
    }
    fclose(f);

    //Time the quicksort
    startClock(&clock1);
    quickSort(arr2, 0, 10000);
    startClock(&clock2);
    std::cout << "Quick Sort Test 4 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;


    //Time for test 5

    f = fopen("test5.txt", "r");
    for(int i = 0; i < 10000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr2[i] = n;
    }
    fclose(f);


    //Time the quicksort
    startClock(&clock1);
    quickSort(arr2, 0, 10000);
    startClock(&clock2);
    std::cout << "Quick Sort Test 5 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;


    //Time for test 6

    f = fopen("test6.txt", "r");
    for(int i = 0; i < 10000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr2[i] = n;
    }
    fclose(f);


    //Time the quicksort
    startClock(&clock1);
    quickSort(arr2, 0, 10000);
    startClock(&clock2);
    std::cout << "Quick Sort Test 6 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;


 //Time for test 7

    f = fopen("test7.txt", "r");
    for(int i = 0; i < 20000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr3[i] = n;
    }
    fclose(f);

    //Time the quicksort
    startClock(&clock1);
    quickSort(arr3, 0, 20000);
    startClock(&clock2);
    std::cout << "Quick Sort Test 7 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;


    //Time for test 8

    f = fopen("test8.txt", "r");
    for(int i = 0; i < 20000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr3[i] = n;
    }
    fclose(f);


    //Time the quicksort
    startClock(&clock1);
    quickSort(arr3, 0, 20000);
    startClock(&clock2);
    std::cout << "Quick Sort Test 8 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;


    //Time for test 9

    f = fopen("test9.txt", "r");
    for(int i = 0; i < 20000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr3[i] = n;
    }
    fclose(f);


    //Time the quicksort
    startClock(&clock1);
    quickSort(arr3, 0, 20000);
    startClock(&clock2);
    std::cout << "Quick Sort Test 9 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;


 //Time for test 10

    f = fopen("test10.txt", "r");
    for(int i = 0; i < 50000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr4[i] = n;
    }
    fclose(f);

    //Time the quicksort
    startClock(&clock1);
    quickSort(arr4, 0, 50000);
    startClock(&clock2);
    std::cout << "Quick Sort Test 10 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;


    //Time for test 11

    f = fopen("test11.txt", "r");
    for(int i = 0; i < 50000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr4[i] = n;
    }
    fclose(f);


    //Time the quicksort
    startClock(&clock1);
    quickSort(arr4, 0, 50000);
    startClock(&clock2);
    std::cout << "Quick Sort Test 11 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;


    //Time for test 12

    f = fopen("test12.txt", "r");
    for(int i = 0; i < 50000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr4[i] = n;
    }
    fclose(f);


    //Time the quicksort
    startClock(&clock1);
    quickSort(arr4, 0, 50000);
    startClock(&clock2);
    std::cout << "Quick Sort Test 12 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;


    std::cout << std::endl;

 //Time for test 1

    f = fopen("test1.txt", "r");
    for(int i = 0; i < 5000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr1[i] = n;
    }
    fclose(f);

    //Time the bubblesort
    startClock(&clock1);
    bubbleSort(arr1, 5000);
    startClock(&clock2);
    std::cout << "Bubble Sort Test 1 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;


    //Time for test 2

    f = fopen("test2.txt", "r");
    for(int i = 0; i < 5000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr1[i] = n;
    }
    fclose(f);


    //Time the bubblesort
    startClock(&clock1);
    bubbleSort(arr1, 5000);
    startClock(&clock2);
    std::cout << "Bubble Sort Test 2 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;


    //Time for test 3

    f = fopen("test3.txt", "r");
    for(int i = 0; i < 5000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr1[i] = n;
    }
    fclose(f);


    //Time the bubblesort
    startClock(&clock1);
    bubbleSort(arr1, 5000);
    startClock(&clock2);
    std::cout << "Bubble Sort Test 3 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;

    
    //Time for test 4

    f = fopen("test4.txt", "r");
    for(int i = 0; i < 10000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr2[i] = n;
    }
    fclose(f);

    //Time the bubblesort
    startClock(&clock1);
    bubbleSort(arr2, 10000);
    startClock(&clock2);
    std::cout << "Bubble Sort Test 4 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;


    //Time for test 5

    f = fopen("test5.txt", "r");
    for(int i = 0; i < 10000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr2[i] = n;
    }
    fclose(f);


    //Time the bubblesort
    startClock(&clock1);
    bubbleSort(arr2, 10000);
    startClock(&clock2);
    std::cout << "Bubble Sort Test 5 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;


    //Time for test 6

    f = fopen("test6.txt", "r");
    for(int i = 0; i < 10000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr2[i] = n;
    }
    fclose(f);


    //Time the bubblesort
    startClock(&clock1);
    bubbleSort(arr2, 10000);
    startClock(&clock2);
    std::cout << "Bubble Sort Test 6 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;


 //Time for test 7

    f = fopen("test7.txt", "r");
    for(int i = 0; i < 20000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr3[i] = n;
    }
    fclose(f);

    //Time the bubblesort
    startClock(&clock1);
    bubbleSort(arr3, 20000);
    startClock(&clock2);
    std::cout << "Bubble Sort Test 7 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;


    //Time for test 8

    f = fopen("test8.txt", "r");
    for(int i = 0; i < 20000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr3[i] = n;
    }
    fclose(f);


    //Time the bubblesort
    startClock(&clock1);
    bubbleSort(arr3, 20000);
    startClock(&clock2);
    std::cout << "Bubble Sort Test 8 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;


    //Time for test 9

    f = fopen("test9.txt", "r");
    for(int i = 0; i < 20000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr3[i] = n;
    }
    fclose(f);


    //Time the bubblesort
    startClock(&clock1);
    bubbleSort(arr3, 20000);
    startClock(&clock2);
    std::cout << "Bubble sort Test 9 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;


 //Time for test 10

    f = fopen("test10.txt", "r");
    for(int i = 0; i < 50000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr4[i] = n;
    }
    fclose(f);

    //Time the bubblesort
    startClock(&clock1);
    bubbleSort(arr4, 50000);
    startClock(&clock2);
    std::cout << "Bubble Sort Test 10 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;


    //Time for test 11

    f = fopen("test11.txt", "r");
    for(int i = 0; i < 50000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr4[i] = n;
    }
    fclose(f);


    //Time the bubblesort
    startClock(&clock1);
    bubbleSort(arr4, 50000);
    startClock(&clock2);
    std::cout << "Bubble Sort Test 11 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;


    //Time for test 12

    f = fopen("test12.txt", "r");
    for(int i = 0; i < 50000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr4[i] = n;
    }
    fclose(f);


    //Time the bubblesort
    startClock(&clock1);
    bubbleSort(arr4, 50000);
    startClock(&clock2);
    std::cout << "Bubble Sort Test 12 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;

std::cout << std::endl;


//Time for test 1

    f = fopen("test1.txt", "r");
    for(int i = 0; i < 5000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr1[i] = n;
    }
    fclose(f);

    //Time the selectionsort
    startClock(&clock1);
    selectionSort(arr1, 5000);
    startClock(&clock2);
    std::cout << "Selection Sort Test 1 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;


    //Time for test 2

    f = fopen("test2.txt", "r");
    for(int i = 0; i < 5000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr1[i] = n;
    }
    fclose(f);


    //Time the selectionsort
    startClock(&clock1);
    selectionSort(arr1, 5000);
    startClock(&clock2);
    std::cout << "Selection Sort Test 2 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;


    //Time for test 3

    f = fopen("test3.txt", "r");
    for(int i = 0; i < 5000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr1[i] = n;
    }
    fclose(f);


    //Time Selectionsort
    startClock(&clock1);
    selectionSort(arr1, 5000);
    startClock(&clock2);
    std::cout << "Selection Sort Test 3 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;

    
    //Time for test 4

    f = fopen("test4.txt", "r");
    for(int i = 0; i < 10000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr2[i] = n;
    }
    fclose(f);

    //Time the selectionsort
    startClock(&clock1);
    selectionSort(arr2, 10000);
    startClock(&clock2);
    std::cout << "Selection Sort Test 4 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;


    //Time for test 5

    f = fopen("test5.txt", "r");
    for(int i = 0; i < 10000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr2[i] = n;
    }
    fclose(f);


    //Time the selectionsort
    startClock(&clock1);
    selectionSort(arr2, 10000);
    startClock(&clock2);
    std::cout << "Selection Sort Test 5 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;


    //Time for test 6

    f = fopen("test6.txt", "r");
    for(int i = 0; i < 10000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr2[i] = n;
    }
    fclose(f);


    //Time the selectionsort
    startClock(&clock1);
    selectionSort(arr2, 10000);
    startClock(&clock2);
    std::cout << "Selection Sort Test 6 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;


 //Time for test 7

    f = fopen("test7.txt", "r");
    for(int i = 0; i < 20000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr3[i] = n;
    }
    fclose(f);

    //Time the selectionsort
    startClock(&clock1);
    selectionSort(arr3, 20000);
    startClock(&clock2);
    std::cout << "Selection Sort Test 7 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;


    //Time for test 8

    f = fopen("test8.txt", "r");
    for(int i = 0; i < 20000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr3[i] = n;
    }
    fclose(f);


    //Time the selectionsort
    startClock(&clock1);
    selectionSort(arr3, 20000);
    startClock(&clock2);
    std::cout << "Selection Sort Test 8 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;


    //Time for test 9

    f = fopen("test9.txt", "r");
    for(int i = 0; i < 20000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr3[i] = n;
    }
    fclose(f);


    //Time the selectionsort
    startClock(&clock1);
    selectionSort(arr3, 20000);
    startClock(&clock2);
    std::cout << "Selection sort Test 9 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;


 //Time for test 10

    f = fopen("test10.txt", "r");
    for(int i = 0; i < 50000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr4[i] = n;
    }
    fclose(f);

    //Time the selectionsort
    startClock(&clock1);
    selectionSort(arr4, 50000);
    startClock(&clock2);
    std::cout << "Selection Sort Test 10 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;


    //Time for test 11

    f = fopen("test11.txt", "r");
    for(int i = 0; i < 50000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr4[i] = n;
    }
    fclose(f);


    //Time the selectionsort
    startClock(&clock1);
    selectionSort(arr4, 50000);
    startClock(&clock2);
    std::cout << "Selection Sort Test 11 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;


    //Time for test 12

    f = fopen("test12.txt", "r");
    for(int i = 0; i < 50000; i++)
    {
        int n;
        fscanf(f, "%d", &n);
        arr4[i] = n;
    }
    fclose(f);


    //Time the selectionsort
    startClock(&clock1);
    selectionSort(arr4, 50000);
    startClock(&clock2);
    std::cout << "Selection Sort Test 12 time: " << (clock2.tv_sec - clock1.tv_sec) + ((clock2.tv_nsec - clock1.tv_nsec) *(1/1000000000.0))  << " Seconds" << std::endl;

}