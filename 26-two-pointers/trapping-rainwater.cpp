// https://leetcode.com/problems/trapping-rain-water/discuss/1687525/c-solution-with-intuition-and-explanation-on-time-o1-space

int trap(vector<int>& h) {
        int water = 0, lMax = h[0], n = h.size(), rMax = h[n-1];
        int l = 0 , r = n - 1;
        while(l <= r) {
            if(h[l] <= h[r]) {
                if(h[l] > lMax)
                    lMax = h[l];
                else 
                    water += lMax - h[l];
                l++;                    
            } else {
                if(h[r] > rMax)
                    rMax = h[r];
                else 
                    water += rMax - h[r];
                r--;
            }
        }
        return water;
    }