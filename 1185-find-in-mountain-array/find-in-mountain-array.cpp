class Solution {
public:
    int findInMountainArray(int target, MountainArray &a) {
        int length = a.length();
        int topPos = findPeakIndex(1, length - 2, a);
        int incPos = binarySearch(0, topPos, target, a, false);
        if (a.get(incPos) == target) 
            return incPos;
        int decPos = binarySearch(topPos + 1, length - 1, target, a, true);
        if (a.get(decPos) == target) 
            return decPos;

        return -1;
    }

    int findPeakIndex(int low, int high, MountainArray &a) {
        while (low != high) {
            int mid = low + (high - low) / 2;
            if(a.get(mid) < a.get(mid + 1)) {
                low = mid + 1;
            } 
            else {
                high = mid;
            }
        }
        return low;
    }

    int binarySearch(int low, int high, int target, MountainArray &a, bool reversed) {
        while(low != high) {
            int mid = low + (high - low) / 2;
            if(reversed) {
                if(a.get(mid) > target) {
                    low = mid + 1;
                }
                else {
                    high = mid;
                }
            } 
            else {
                if(a.get(mid) < target) {
                    low = mid + 1;
                }
                else {
                    high = mid;
                }
            }
        }
        return low;
    }
};
