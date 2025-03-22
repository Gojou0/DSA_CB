class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int s = m - 1;
            int e = 0;
            while (s >= 0 && e < n){
                if (nums1[s] > nums2[e]){                   //check from last of first array and first of second array
                    swap(nums1[s], nums2[e]);
                    s--;
                    e++;
                }else{
                    break;
                }
            }
            sort(nums1.begin(),nums1.begin() + m);           // sort both the arrays afterwards
            sort(nums2.begin(),nums2.end());
    
            for (int i = m; i < m + n; i++){
                nums1[i] = nums2[i-m];
            }
        }
    };