//LEETCODE QUESTION
//MINIMUM NUMBER OF DAYS TO MAKE M BOUQETS

 bool isPossible(vector<int>& bloomDay, int m, int k, ll x){
        ll bouquet = 0, adjacentBloomers = 0;
        for(int i = 0; i<bloomDay.size(); i++){
            if(bloomDay[i]<=x){
                adjacentBloomers++;
                if(adjacentBloomers==k){
                    bouquet++; 
                    adjacentBloomers = 0;
                }
            }else{
                adjacentBloomers = 0;
            }
        }
        
        return bouquet>=m;
        
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int flowers = bloomDay.size();
       
        if(k*m >flowers)return -1;
        
        ll lo = INT_MAX, hi = INT_MIN, mid;
       
        for(auto& day:bloomDay){
            hi = max(hi, (ll)day);
            lo = min(lo, (ll)day);
        }
        
        int ans = 1;
        if(lo == hi)return lo;
        
        
        while(lo<=hi){
            mid = lo+(hi-lo)/2;
            if(isPossible(bloomDay, m, k, mid)){
                ans = mid;
                hi = mid-1;
            }else {
                lo = mid+1;
            }
        }
        
        return ans;
    }
