class Solution {
public:
    int partition(vector<int>& nums, int low, int high){
        int pivot = nums[high];
        int i = low;
        for(int j=low; j<high; j++){
            if(nums[j] < pivot){
                swap(nums[j], nums[i]);
                i++;
            }
        }
        swap(nums[i], nums[high]);
        return i;
    }
    void quick_sort(vector<int>& nums, int low, int high){
        if(low<high){
            int pt = partition(nums, low, high);
            quick_sort(nums, low, pt-1);
            quick_sort(nums, pt+1, high);
        }
    }
    void merge(vector<int>& nums, int low, int mid, int high){
        int n1 = mid - low + 1;
        int n2 = high - mid;
        vector<int> left(n1), right(n2);
        for(int i=0; i<n1; i++){
            left[i] = nums[low+i];
        }
        for(int i=0; i<n2; i++){
            right[i] = nums[mid+1+i];
        }
        int l = 0, r = 0, ind = low;
        while(l<n1 && r <n2){
            if(left[l] < right[r]){
                nums[ind] = left[l];
                l++;
            }
            else{
                nums[ind] = right[r];
                r++;
            }
            ind++;
        }
        while(l<n1){
            nums[ind] = left[l];
            ind++, l++;
        }
        while(r<n2){
            nums[ind] = right[r];
            ind++, r++;
        }
    }
    void merge_sort(vector<int>& nums, int low, int high){
        if(low >= high) return;
        int mid = low + (high-low)/2;
        merge_sort(nums, low, mid);
        merge_sort(nums, mid+1, high);
        merge(nums, low, mid, high);
    }
    vector<int> sortArray(vector<int>& nums) {
        // quick_sort(nums, 0, nums.size()-1);
        merge_sort(nums, 0, nums.size()-1);
        return nums;
    }
};