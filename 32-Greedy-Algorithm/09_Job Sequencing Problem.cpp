// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
bool comp(Job j1 , Job j2) {
        if(j1.profit != j2.profit) {
            return j1.profit > j2.profit;
        } else {
            return j1.dead > j2.dead;
        }
    }
class Solution 
{
    public:
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr , arr + n , comp);
        
        int md = 0; // maximum deadline
        for(int i = 0 ; i < n ; i++) {
            md = max( arr[i].dead , md );
        }
        
        bool occupied[md ] = {};
        int jb = 0 , p = 0;
        
        for(int i = 0 ; i < n ; i++) {
            for(int j = arr[i].dead - 1; j >= 0; j--) {
                if(! occupied[j]) {
                    occupied[j] = true;
                    jb++;
                    p += arr[i].profit;
                    break;
                }
            }    
        }
        vector<int> ans = {jb , p};
        return ans;
        
    } 
};