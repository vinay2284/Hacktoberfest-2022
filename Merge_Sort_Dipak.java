import java.lang.*;
import java.io.*;

public class Sort_Merge {
    public void Merge(int A[],int p,int q,int r) {
        int n1=q-p+1;
        int n2=r-q;
        int L[]=new int[n1+1],R[]=new int[n2+1],i,j,k;
        for(i=0;i<n1;i++)
            L[i]=A[p+i];
        for(j=0;j<n2;j++)
            R[j]=A[q+j+1];
        L[i]=R[j]=Integer.MAX_VALUE;
        i=j=0;
        for(k=p;k<=r;k++){
            if(L[i]<=R[j])
                A[k]=L[i++];
            else
                A[k]=R[j++];
        }
    }

    public void Merge_Sort(int A[],int p,int r) {
        if(p<r) {
            int q=(p+r)/2;
            Merge_Sort(A,p,q);
            Merge_Sort(A,q+1,r);
            Merge(A,p,q,r);
        }
    }
    
	public static void main(String[] args) throws IOException{
	    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		System.out.print("Enter number of Elements : ");
		int n=Integer.parseInt(br.readLine());
        int A[]=new int[n];
        System.out.println("Enter Array elements :-");
        for(int i=0;i<n;i++)
            A[i]=Integer.parseInt(br.readLine());
        Merge_Sort(A,0,n-1);
        System.out.println("\nSorted Array :-");
        for(int i=0;i<n;i++)
            System.out.print(A[i]+" ");
	}
}
