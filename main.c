#include <stdio.h>
#include <stdlib.h>

void arrayCopy(int fromArray[], int toArray[], int size)
{
    for (int i=0; i < size; i++)
    {
        // iterate through each value from myarray and copy it to new array
        toArray[i] = fromArray[i];
    }
}

void myFavoriteSort(int arr[], int size)
{
    int temp;
    for (int y=0; y < size - 1; y++)
    {
        for (int z=0; z < size - 1 - y; z++ )
        {
            if (arr[z] > arr[z+ 1])
            {
                // if prev val is greater than next val, assign temp to next val
                temp = arr[z+1];
                // next val = prev val
                arr[z+1] = arr[z];
                // prev val = temp(next val), and so the vals have been swapped
                arr[z] = temp;
            }
        }
    }
}

int linSearch(int arr[], int size, int target, int *numComparisons)
{
    *numComparisons = 0;
    for (int i=0; i<size; i++)
    {
        // number of comparisons is always 1 more than i as it starts at 1 whereas i starts at 0
        *numComparisons = i + 1;
        // when value found return the position, else return -1
        if (arr[i]==target)
            return i;
    }
    return -1;
}

int binSearch(int arr[], int size, int target, int* numComparisons)
{
    *numComparisons = 0;
    int min=0; // lowest position in array
    int mid=0; // initialize mid
    int max=size-1; // highest position in array
    while (min<=max) // check to see if only 1 or 2 numbers left in array to stop looping
    {
        mid = (min + max)/2; // mid is halfway(binary search)
        *numComparisons = *numComparisons + 1;
        if (target==arr[mid]) // if target is midway, then found, else...
        {
           return mid;
        }
        else if (target<arr[mid])
        {
            max = mid - 1; // max becomes pos below mid if target is less than mid pos int's val
        }
        else
        {
            min = mid + 1; // min becomes pos above mid if target is greater than mid pos int's val
        }
    }
    return -1; // else not found return -1;
}

int main()
{

    int *my_arr; // initialize array
    int size=10; // random size assigned
    
    my_arr = (int *) malloc(size * sizeof(int)); // array assigned with size of 100
    
    int input;
    int i=0;
    printf("Enter Integers to the Array (-999 to stop entering integers): \n");
    
    scanf("%d", &input); // take input from user
    
    while (input != -999)
    {
        my_arr[i] = input;
        if (i>=size - 1) // if array is full
        {
            int *temp;
            size = size*2; // size doubles
            temp = (int *) malloc(size * sizeof(int)); // temp array gets the new doubled size
            arrayCopy(my_arr, temp, size); // copy numbers from my array to temp array
            free(my_arr); // free my array
            my_arr = temp; // my array becomes temp array
        }
        i++; // increase counter
        scanf("%d", &input); // keep taking input to loop
    }
    
    int *copiedArray;
    copiedArray = (int *) malloc(i *sizeof(int)); // copy array takes new size of as many values as user entered
    arrayCopy(my_arr, copiedArray, i); // coppy contents from my array to copied array
    myFavoriteSort(copiedArray, i); // sort this array
    
    int lComparisons = 0;
    int bComparisons = 0;
    int val;
    printf("\nEnter Number to search for (-999 to stop searching): \n");
    scanf("%d", &val); // take in value to search from user input
    while (val != -999)
    {
        int lpos = linSearch(my_arr, size, val, &lComparisons);
        int bpos = binSearch(copiedArray, i, val, &bComparisons);
        if (lpos!=-1) // if value is found
        {
            printf("\nLinear search for: %d\n", val);
            printf("Number found at position: %d\n", lpos);
            printf("Number of comparisons to find the number: %d\n", lComparisons);
            printf("\nBinary search for: %d\n", val);
            printf("Number found at position: %d\n", bpos);
            printf("Number of comparisons to find the number: %d\n", bComparisons);
        }
        else // else print not found and repeat loop
        {
            printf("\nNumber not found...\n");
        }
        printf("\nEnter Number to search for (-999 to stop searching): \n");
        scanf("%d", &val); // keep loop going
    }
    
    free(my_arr); // free memory
    free(copiedArray); // free memory
    return 0;
}

