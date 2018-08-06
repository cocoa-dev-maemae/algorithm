// Java code here
// O(n*k) solution for finding 
// maximum sum of a subarray 
// of size k
class SlidingWindow 
{ 
    // Driver code
    public static void main(String[] args)
    {
        int arr[] = {1, 4, 2, 10, 2, 3, 1, 0, 20};
        int k = 4;
        int n = arr.length;
        System.out.println(maxSum(arr, n, k));
    }
    
    // Returns maximum sum in
    // a subarray of size k.
    private static int maxSum(int arr[], int n, int k)
    {
        // Initialize result
        int maxSum = Integer.MIN_VALUE;
     
        // Consider all blocks starting with i.
        for (int i = 0; i < n - k + 1; i++) {
            int curSum = 0;
            for (int j = 0; j < k; j++)
                curSum = curSum + arr[i + j];
     
            // Update result if required.
            maxSum = Math.max(curSum , maxSum);
        }
        return maxSum;
    }
}
