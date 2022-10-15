//Problem 287: Find the duplicate number  https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
    public int findDuplicate(int[] arr) {
        int i=0;
        while(i<arr.length){
            if(arr[i] != i+1){
                int correct = arr[i] - 1;
                if(arr[i] != arr[correct]){
                    swap(arr, i, correct);
                }else{
                    return arr[i];
                }
            }else{
                i++;
            }
        }
        return -1;
    }
    static void swap(int[] arr, int first, int second){
        int temp = arr[second];
        arr[second] = arr[first];
        arr[first] = temp;
    }
}