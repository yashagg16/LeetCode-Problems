class Solution {
    public void swap(int[] arr, int a, int b){
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }
    public int[] sortArrayByParity(int[] arr) {
        int n = arr.length;
        int i = 0;
        int j = n-1;
        
        while(i < j){
            int a = arr[i]%2;
            int b = arr[j]%2;
            
            if(a == 0 && b == 0){
                i++;
            }
            else if(a == 0 && b == 1){
                i++;
                j--;
            }
            else if(a == 1 && b == 0){
                swap(arr, i, j);
                i++;
                j--;
            }
            else{
                j--;
            }
        }
        
        return arr;
    }
}