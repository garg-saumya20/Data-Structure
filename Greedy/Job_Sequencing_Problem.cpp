#include<bits/stdc++.h>
#include<stack>
using namespace std;

bool static comparator(Job a,Job b )
    {
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<int> v;
        int profit_sum=0;
        int count_jobs=0;
        int max_slot=arr[0].dead;
        sort(arr,arr+n,comparator);
        for(int i=0;i<n;i++)
        {
            max_slot=max(max_slot,arr[i].dead);
        }
        int slot_arr[max_slot+1];
        for (int i = 0; i <= max_slot; i++)
         slot_arr[i] = -1;
         
        for(int i=0;i<n;i++)
        {
            for(int j=arr[i].dead;j>0;j--)
            {
                if(slot_arr[j]==-1)
                {
                    slot_arr[j]=arr[i].id;
                    profit_sum+=arr[i].profit;
                    count_jobs++;
                    break;
                }
               
            }
        }
        v.push_back(count_jobs);
        v.push_back(profit_sum);
        return v;
    } 

    //TC O(NlogM)+ O(N*M)
    //Sc O(M)