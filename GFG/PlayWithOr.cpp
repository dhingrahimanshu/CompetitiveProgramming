int* game_with_number(int arr[], int n)
{
    for(int i = 1;i<n;i++){
        arr[i-1]|=arr[i];
    }
    return arr;
    
}
