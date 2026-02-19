/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int l = 0, r = n-1;
        int center = 0;
        while(l<=r){
            int mid = l + (r-l)/2;
            int num = mountainArr.get(mid);
            int prev = (mid == 0)?INT_MIN:mountainArr.get(mid-1);
            int next = (mid == n-1)?INT_MIN:mountainArr.get(mid+1);;
            if(prev < num && next < num){
                center = mid;
                break;
            }
            else if(prev < num){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        l = 0, r = center;
        while(l<=r){
            int mid = l + (r-l)/2;
            int num = mountainArr.get(mid);
            if(num == target) return mid;
            else if(num < target) l = mid+1;
            else r = mid-1;
        }
        l = center+1, r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            int num = mountainArr.get(mid);
            if(num == target) return mid;
            else if(num < target) r = mid-1;
            else l = mid+1;
        }
        return -1;
    }
};