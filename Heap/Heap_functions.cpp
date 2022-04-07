class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int Arr[], int N, int i)  
    {
      // Your Code Here
    int left_i = 2*i + 1;
    int right_i = 2*i + 2;
    int smallest = i;
    if (left_i < N && Arr[left_i] > Arr[smallest]) {
        smallest = left_i;
    }
    
    if (right_i < N && Arr[right_i] > Arr[smallest]) {
        smallest = right_i;
    }
    
    int tmp = Arr[i];
    Arr[i] = Arr[smallest];
    Arr[smallest] = tmp;
    if (smallest < N && smallest != i) {
        heapify(Arr, N, smallest);
    }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int Arr[], int N)  
    { 
    // Your Code Here
       // Build max heap
    for(int i = N/2 + 1 ; i >=0 ; i--) {
        heapify(Arr, N, i);
    }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        //buildHeap(arr,n);
         buildHeap(arr,n);
        for(int i = n-1; i>0; i--)
        {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};
