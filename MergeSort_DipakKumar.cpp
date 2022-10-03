#include<bits/stdc++.h>
using namespace std;

void Merge(int A[],int p,int q,int r){
    int n1=q-p+1;
    int n2=r-q;
    int L[n1+1],R[n2+1],i,j,k;
    for(i=0;i<n1;i++)
        L[i]=A[p+i];
    for(j=0;j<n2;j++)
        R[j]=A[q+j+1];
    L[i]=R[j]=INT_MAX;
    i=j=0;
    for(k=p;k<=r;k++){
        if(L[i]<=R[j])
            A[k]=L[i++];
        else
            A[k]=R[j++];
    }
}

void Merge_Sort(int A[],int p,int r){
    if(p<r){
        int q=(p+r)/2;
        Merge_Sort(A,p,q);
        Merge_Sort(A,q+1,r);
        Merge(A,p,q,r);
    }
}

int main()
{
    int n;
    cout<<"Enter number of Elements :";
    cin>>n;
    int A[n];
    cout<<"Enter Array elements :-\n";
    for(int i=0;i<n;i++)
        cin>>A[i];
    Merge_Sort(A,0,n-1);
    cout<<"\nSorted Array :-\n";
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    return 0;
}
