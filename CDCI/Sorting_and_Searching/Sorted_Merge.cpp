
//https://leetcode.com/problems/merge-sorted-array/submissions/
class Solution {
public:
    // Merge from backwards
    void merge(vector<int>& num1, int m, vector<int>& num2, int n) {
        // Keep pointer at the end of both array
        int indA = m - 1;
        int indB = n - 1;
        
        // keep pointer at the end of mergeArray
        int mergeInd = m + n - 1;
        
        // if B is finised A is already sorted
        while(indB >= 0) {
            // move the greator elements to the end
            if (indA >= 0 && num1[indA] > num2[indB]) {
                num1[mergeInd] = num1[indA];
                indA--;
            } else {
                num1[mergeInd] = num2[indB];
                indB--;
            }
            mergeInd--;
        }
        
    }
};
