#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

// @lc code=start
class TimeVal
{
public:
    string value;
    int time;
    TimeVal(string value, int time)
    {
        this->time = time;
        this->value = value;
    }
};
class TimeMap
{
private:
    unordered_map<string, vector<TimeVal>> map;
    int low, high, mid;

public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        map[key].push_back(TimeVal{value, timestamp});
    }

    string get(string key, int timestamp)
    {
        vector<TimeVal> &timestamps = map[key];
        if ((timestamps).empty())
            return "";
        low = 0, high = map[key].size() - 1;
        while (low <= high)
        {
            mid = (low + high) / 2;

            if (timestamps[mid].time == timestamp)
                return timestamps[mid].value;
            if (timestamps[mid].time < timestamp)
                low = mid + 1;
            else
                high = mid - 1;
        }
        if (high >= 0)
            return (timestamps)[high].value;
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end
