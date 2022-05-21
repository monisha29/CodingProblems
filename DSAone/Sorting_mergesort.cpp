//https://practice.geeksforgeeks.org/problems/merge-sort/1/

https://practice.geeksforgeeks.org/problems/merge-sort/1/
https://practice.geeksforgeeks.org/problems/merge-sort/1/
 public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int head1 = l;
         int head2 = m+1;
         int n = r - l + 1;
         int arr2[n];
         int ind = 0;
        // cout << l << " :: " << m << " :: " << r << " N is " << n << endl;
         while(head1 <= m && head2 <= r) {
             if (arr[head1] < arr[head2]) {
                 arr2[ind] = arr[head1];
                 ind++;
                 head1++;
             } else {
                 arr2[ind] = arr[head2];
                 ind++;
                 head2++;
             }
         }
         
         
         
         while(head1 <= m) {
             arr2[ind] = arr[head1];
             head1++;
             ind++;
             
         }
         
         while(head2 <= r) {
             arr2[ind] = arr[head2];
             head2++;
             ind++;
         }
         int addin = l;
         for(int i = 0 ; i < n ; i++) {
             arr[addin] = arr2[i];
            // cout << " got at :: " << arr[i] << endl;
              addin++;
         }
         
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if (l < r) {
            int mid = (l+r)/2 ;
          //  cout << " start  :: " << l << " :: "  << mid << " :: " << r << endl;
            mergeSort(arr, l , mid);
            mergeSort(arr, mid+1, r);
            merge(arr, l , mid, r);
        }
    }
