#include <stdio.h>
#include <stdlib.h>

void Merge(int A[], int L[], int R[], int leftCount, int rightCount) {
    int i, j, k;

    i = 0; j = 0; k =0;

    while(i<leftCount && j< rightCount) {
        if(L[i]  R[j]) A[k++] = L[i++];
        else A[k++] = R[j++];
    }
    while(i < leftCount) A[k++] = L[i++];
    while(j < rightCount) A[k++] = R[j++];
}

void MergeSort(int A[],int n) {
    int mid, i, *L, *R;
    if(n < 2) return; // base condition. If the array has less than two element, do nothing.

    mid = n/2;  // find the mid index.

    // create left and right subarrays
    // mid elements (from index 0 till mid-1) should be part of left sub-array
    // and (n-mid) elements (from mid to n-1) will be part of right sub-array
    L = (int*)malloc(mid*sizeof(int));
    R = (int*)malloc((n- mid)*sizeof(int));

    for(i = 0;i<mid;i++) L[i] = A[i]; // creating left subarray
    for(i = mid;i<n;i++) R[i-mid] = A[i]; // creating right subarray

    MergeSort(L,mid);  // sorting the left subarray
    MergeSort(R,n-mid);  // sorting the right subarray
    Merge(A,L,R,mid,n-mid);  // Merging L and R into A as sorted list.
    free(L);
    free(R);
}

int main() {
    int A[] = {6,2,3,1,9,10,15,13,12,17}; // creating an array of integers.
    int i,numberOfElements;

    numberOfElements = sizeof(A)/sizeof(A[0]); // finding number of elements in array as size of complete array in bytes divided by size of integer in bytes.

    MergeSort(A,numberOfElements); // calling merge sort to sort the array.

    //printing all elements in the array once its sorted.
    for(i = 0;i < numberOfElements;i++) printf("%d ",A[i]);
    return 0;
}