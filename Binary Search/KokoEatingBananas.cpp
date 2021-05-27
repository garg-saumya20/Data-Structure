class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int left=1;
        int right=*max_element(piles.begin(),piles.end());
        int result=-1;
        while(left<=right)
        {
            
            int mid=left+(right-left)/2;
            if(isPossible(piles,mid,H))
            {
                result=mid;
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
                
        }
        return result;
        
        
    }
    bool isPossible(vector<int>& piles,int k,int H)
    {
        int n=piles.size();
        int hours=0;
        for(int i=0;i<n;i++)
        {
            if(piles[i]<=k)
            {
                hours++;
            }
            else
            {
                int div=piles[i]/k;
                hours+=div;
                if(piles[i]%k!=0)
                {
                    hours++;
                }
            }
        }
        return hours<=H;
    }
};