class Solution
{
public:
    int trap(vector<int> &height){
              vector<int>maxleft(height.size());
              vector<int>maxright(height.size());
              int water=0;
              int n=height.size()-1;
              maxleft[0]=height[0];
              maxright[n]=height[n];
              for(int i=1;i<height.size();i++){
                maxleft[i]=max(maxleft[i-1],height[i]);
                maxright[n-i]=max(maxright[n-(i-1)],height[n-i]);
              }
              for (int i=0;i<height.size();i++){
              water+=min(maxleft[i],maxright[i])-height[i];

              
              }
              
  return water;  }
};