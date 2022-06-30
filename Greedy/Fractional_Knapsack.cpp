#include<bits/stdc++.h>
#include<vector>
using namespace std;





bool static comparator(Item a,Item b)
    {
       double r1 = (double) a.value / (double) a.weight;
         double r2 = (double) b.value / (double) b.weight;
         return r1 > r2;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        
        sort(arr,arr+n,comparator);
        double max_profit=0.0;
        int curr_wt=0;
        for(int i=0;i<n;i++)
        {
            if(curr_wt+arr[i].weight<=W)
            {
                curr_wt=curr_wt+arr[i].weight;
                max_profit+=arr[i].value;
            }
            else
            {
                int remain_wt = W-curr_wt;
               max_profit += (arr[i].value / (double) arr[i].weight) * (double) remain_wt;
            
                break;
            }
            
            
        }
        return max_profit;
        
    }
        