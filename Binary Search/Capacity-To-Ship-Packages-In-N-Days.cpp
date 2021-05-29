//LEETCODE QUESTION
//Capacity to ship packages in D days
// Weights=[1,2,3,4,5,6,7,8,9,10]
// maximum number of days (D)=5
//Minimum capacity of ship
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int mini=*max_element(weights.begin(),weights.end());
         int maxa;
        for(int i=0;i<weights.size();i++)
        {
            maxa+=weights[i];
           
        }
      
        
        
       // int ans;
    while(mini<maxa)
{
    int mid=mini+(maxa-mini)/2;
    if(canBeTransferred(mid,D,weights))
    {
       // ans=min(mid,ans);
        maxa=mid;
    }
    else
    {
        mini=mid+1;
    }
}
return mini;
    }
    bool canBeTransferred(int mid,int D,vector<int>&  weights)
{
    int sum=0;
    int Day=1;
    for(int i=0;i<weights.size();i++)
    {
        if(sum+weights[i]<=mid)
        {
        sum+=weights[i];
        }
        else{
            Day++;
            sum=weights[i];
        }
    }
    return Day<=D;
}
};