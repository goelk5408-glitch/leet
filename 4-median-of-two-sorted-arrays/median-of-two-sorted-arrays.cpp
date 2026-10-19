
class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int m=arr1.size();
        int n=arr2.size();

        if(m>n){
            return findMedianSortedArrays(arr2, arr1);
        }

        int low=0;
        int high=m;
        int left=(m+n+1)/2;

        while(low<=high) {
            int mid1=low+(high-low)/2;
            int mid2=left-mid1;

            int l1=(mid1==0)?INT_MIN :arr1[mid1 - 1];
            int r1=(mid1 == m)? INT_MAX: arr1[mid1];

            int l2 =(mid2 == 0) ? INT_MIN:arr2[mid2 - 1];
            int r2 = (mid2 == n)?INT_MAX:arr2[mid2];

            if (l1 > r2) {
                high = mid1 - 1;
            }
            else if (l2 > r1) {
                low = mid1 + 1;
            }
            else {
                if ((m + n) % 2 == 1) {
                    return max(l1, l2);
                }

                return ((long long)max(l1, l2)
                      + min(r1, r2)) / 2.0;
            }
        }

        return 0.0;
    }
};
