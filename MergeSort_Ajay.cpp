//i have done some modifications but also included some comments for easier understanding

#include <stdio.h>
#define size 4 // defining array size
void inputArray(int array[], int length)
{
    printf("Input %d (integer) elements: ", length);
    // note, in the for loop, the intitializing statement is decreasing the value of length by 1 because in arrays, counting starts from 0
    for (length--; length >= 0; length--)
    {
        scanf("%d", &array[length]);
    }
}

void printArray(int array[], int length)
{
    printf("The elements of the given array are: ");
    for (int i = 0; i < length; i++)
        printf("%d ", array[i]);
}
void merge(int array[], int lower, int middle, int upper)
{
    int i, j, k;
    int left[middle - lower + 1];            // creating sub-array to store elements in the left portion of 'array[]'
    int right[upper - middle];               // creating sub-array to store elements in the right portion of 'array[]'
    for (i = 0; i < middle - lower + 1; i++) // copying appropriate elements from array[] to left[]
        left[i] = array[lower + i];
    for (j = 0; j < upper - middle; j++) // copying appropriate elements from array[] to right[]
        right[j] = array[middle + 1 + j];
    i = 0;     // initial index of sub-array left[]
    j = 0;     // initial index of sub-array right[]
    k = lower; // initial index of merged array
    for (k = lower; i < middle - lower + 1 && j < upper - middle; k++)
    { // THIS CONDITION SORTS IN ASCENDING ORDER
        if (left[i] <= right[j])
            array[k] = left[i++]; // storing value of left[i] in array[k] if the former is smaller
        else
            array[k] = right[j++]; // storing value of right[j] in array[j] if the former is smaller
    }
    while (i < middle - lower + 1)
        array[k++] = left[i++]; // copying back the remaining elements of left[] to array[]
    while (j < upper - middle)
        array[k++] = right[j++]; // copying back the remaining elements of right[] to array[]
}
void mergeSort(int array[], int lower, int upper)
{
    if (lower >= upper)
        return;                                         // signifies that array contains only one element
    mergeSort(array, lower, (lower + upper) / 2);       // sorting the left portion of the array
    mergeSort(array, ((lower + upper) / 2) + 1, upper); // sorting the right portion of the array
    merge(array, lower, (lower + upper) / 2, upper);    // merging the two portions once sorting is done
}
int main()
{
    int array[size];
    inputArray(array, size);
    mergeSort(array, 0, size - 1); // passing 'size-1' because array-index-counting starts from 0
    printArray(array, size);
    return 0;
}
