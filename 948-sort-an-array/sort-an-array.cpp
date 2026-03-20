class CustomSort {
public:
    // Sort small range directly
    void smallSort(vector<int>& a, int l, int r) {
        if (r - l == 2 && a[l] > a[l + 1]) {
            swap(a[l], a[l + 1]);
        }
    }

    // Return the k-th smallest element in a[l..r)
    // Deterministic linear-time selection idea.
    int selectKth(vector<int>& a, int l, int r, int k) {
        while (true) {
            int n = r - l;
            if (n <= 5) {
                sort(a.begin() + l, a.begin() + r);
                return a[l + k];
            }

            // Step 1: group by 5 and move medians to the front
            int numMedians = 0;
            for (int i = l; i < r; i += 5) {
                int subR = min(i + 5, r);
                sort(a.begin() + i, a.begin() + subR);
                int medianIndex = i + (subR - i) / 2;
                swap(a[l + numMedians], a[medianIndex]);
                numMedians++;
            }

            // Step 2: recursively find pivot from medians
            int pivot = selectKth(a, l, l + numMedians, numMedians / 2);

            // Step 3: 3-way partition around pivot
            int i = l, lt = l, gt = r;
            while (i < gt) {
                if (a[i] < pivot) {
                    swap(a[i], a[lt]);
                    i++;
                    lt++;
                } else if (a[i] > pivot) {
                    gt--;
                    swap(a[i], a[gt]);
                } else {
                    i++;
                }
            }

            int leftSize = lt - l;
            int midSize = gt - lt;

            if (k < leftSize) {
                r = lt;
            } else if (k < leftSize + midSize) {
                return pivot;
            } else {
                k -= leftSize + midSize;
                l = gt;
            }
        }
    }

    void customSort(vector<int>& a, int l, int r) {
        int n = r - l;
        if (n <= 1) return;
        if (n == 2) {
            smallSort(a, l, r);
            return;
        }

        // Find a deterministic middle value to split on
        int midValue = selectKth(a, l, r, n / 2);

        // 3-way partition around midValue
        int i = l, lt = l, gt = r;
        while (i < gt) {
            if (a[i] < midValue) {
                swap(a[i], a[lt]);
                i++;
                lt++;
            } else if (a[i] > midValue) {
                gt--;
                swap(a[i], a[gt]);
            } else {
                i++;
            }
        }

        // Recurse on both sides
        customSort(a, l, lt);
        customSort(a, gt, r);
    }

    void sortArray(vector<int>& nums) {
        customSort(nums, 0, (int)nums.size());
    }
};
class Solution {
public:
    
    // int partition(vector<int>& nums, int low, int high){
    //     int pivot = nums[high];
    //     int i = low;
    //     for(int j=low; j<high; j++){
    //         if(nums[j] < pivot){
    //             swap(nums[j], nums[i]);
    //             i++;
    //         }
    //     }
    //     swap(nums[i], nums[high]);
    //     return i;
    // }
    // void quick_sort(vector<int>& nums, int low, int high){
    //     if(low<high){
    //         int pt = partition(nums, low, high);
    //         quick_sort(nums, low, pt-1);
    //         quick_sort(nums, pt+1, high);
    //     }
    // }
    // void merge(vector<int>& nums, int low, int mid, int high){
    //     int n1 = mid - low + 1;
    //     int n2 = high - mid;
    //     vector<int> left(n1), right(n2);
    //     for(int i=0; i<n1; i++){
    //         left[i] = nums[low+i];
    //     }
    //     for(int i=0; i<n2; i++){
    //         right[i] = nums[mid+1+i];
    //     }
    //     int l = 0, r = 0, ind = low;
    //     while(l<n1 && r <n2){
    //         if(left[l] < right[r]){
    //             nums[ind] = left[l];
    //             l++;
    //         }
    //         else{
    //             nums[ind] = right[r];
    //             r++;
    //         }
    //         ind++;
    //     }
    //     while(l<n1){
    //         nums[ind] = left[l];
    //         ind++, l++;
    //     }
    //     while(r<n2){
    //         nums[ind] = right[r];
    //         ind++, r++;
    //     }
    // }
    // void merge_sort(vector<int>& nums, int low, int high){
    //     if(low >= high) return;
    //     int mid = low + (high-low)/2;
    //     merge_sort(nums, low, mid);
    //     merge_sort(nums, mid+1, high);
    //     merge(nums, low, mid, high);
    // }

    // void count_sort(vector<int> &nums){
    //     vector<int> count(2 * 50000 + 1, 0);
    //     for(int num: nums){
    //         count[num + 50000]++;
    //     }
    //     int ind = 0;
    //     for(int val=0; val<count.size(); val++){
    //         int freq = count[val];
    //         while(freq != 0){
    //             nums[ind] = val - 50000;
    //             ind++;
    //             freq--;
    //         }
    //     }
    // }
    vector<int> sortArray(vector<int>& nums) {
        // quick_sort(nums, 0, nums.size()-1);
        // merge_sort(nums, 0, nums.size()-1);
        CustomSort cs;
        cs.sortArray(nums);
        // count_sort(nums);
        return nums;
    }
};