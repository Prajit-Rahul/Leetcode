class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = nums1.size()-1, j = m-1;
        while(j>=0){
            nums1[i--] = nums1[j--];
        }
        i = n, j = 0;
        int k = 0;
        while(i < nums1.size() && j < n){
            if(nums1[i] < nums2[j]){
                nums1[k++] = nums1[i++];
            }
            else{
                nums1[k++] = nums2[j++];
            }
        }
        while(i<nums1.size()){
            nums1[k++] = nums1[i++];
        }
        while(j<n){
            nums1[k++] = nums2[j++];
        }
    }
};