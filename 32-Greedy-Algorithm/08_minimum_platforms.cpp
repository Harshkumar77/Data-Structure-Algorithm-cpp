// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

int findPlatform(int arr[], int dep[], int n)
{
    // Your code here
    sort(arr , arr + n);
    sort(dep , dep + n);
    
    int mp = 0 , p = 0 , d = 0;
    
    for(int i = 0; i < n; i++) {
        while( dep[d] < arr[i]) {
            d++;
            p--;
        }
        p++;
        mp = max(p , mp);
    }
    
    return mp;
}