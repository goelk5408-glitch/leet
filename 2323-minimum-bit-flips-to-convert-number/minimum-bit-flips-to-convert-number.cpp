class Solution {
  
public:
    int a=0;
    int b=0;
    int count=0;
    int minBitFlips(int start, int goal) {
        a=start^goal;
        while(a>0){
            a=(a&a-1);
            count++;
        }return count;}};