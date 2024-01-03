class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
        int j =i;
        int l = 2*j +1;
        int r = 2*j +2;
        
        if(l<n && arr[j]<arr[l]){
            j = l;
        }
        if(r<n && arr[j]<arr[r]){
            j = r;
        }
        if(j!=i){
            swap(arr[i],arr[j]);
            heapify(arr , n , j);
        }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        for(int i = n/2;i>=0;i--){
            heapify(arr , n , i);
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr , n);

        
        for(int i =0 ;i<n;i++){
            swap(arr[0],arr[n-i-1]);
            heapify(arr , n-i-1 , 0);
        }
    }
};
