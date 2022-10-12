public class MergeSort {

    public static void merge(int arr[], int si, int mid, int ei){
        int merged[]=new int[ei-si+1];
        int i=si;
        int j=mid+1;
        int k=0;

        while(i<=mid && j<=ei){
            if(arr[i]<arr[j]){
                merged[k++]=arr[i++];
            }
            else{
                merged[k++]=arr[j++];
            }
        }

        while(i<=mid){
            merged[k++]=arr[i++];
        }
        while(j<=ei){
            merged[k++]=arr[j++];
        }
        for(i=0;i<merged.length;i++){
            System.out.print(merged[i]+" ");
        }
        // for(i=0,j=si;i<merged.length;i++,j++){
        //     arr[j]=merged[i];
        // }
    }


    public static void divide(int arr[], int si, int ei){

        if(si>=ei){
            return;
        }
        int mid=si+(ei-si)/2;
        divide(arr, si, mid);
        divide(arr, mid+1, ei);
        merge(arr, si, mid, ei);
    }

    public static void main(String[] args) {
        int arr[]={9,4,7,2,3,1};
        int n=arr.length;
        divide(arr, 0, n-1);
        
    }
}
