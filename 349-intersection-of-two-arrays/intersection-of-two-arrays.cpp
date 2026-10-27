class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st;
        vector<int>v;
       
        for(int i=0;i<nums1.size();i++){
            if(st.find(nums1[i])==st.end()){
                st.insert(nums1[i]);
            }
            else{
                continue;
            }
        }
        for(int i=0;i<nums2.size();i++){
            if(st.find(nums2[i])!=st.end()){
                v.push_back(nums2[i]);
                st.erase(nums2[i]);
            }
            else{continue;}

        }
   return v; }
};