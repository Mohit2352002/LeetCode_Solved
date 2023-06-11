class Solution {
public:
   vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size(), i = 0;
        vector<vector<int>> res;
        //case 1: no overlapping case before the merge intervals
		//compare ending point of intervals to starting point of newInterval
        while(i < n && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i]);
            ++i;
        }                           
		//case 2: overlapping case and merging of intervals
        while(i < n && newInterval[1] >= intervals[i][0]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            ++i;
        }
        res.push_back(newInterval);
        // case 3: no overlapping of intervals after newinterval being merged
        while(i < n){
            res.push_back(intervals[i]);
            ++i;
        }
        return res;
    }
};









/*
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int n=intervals.size();
        int i=0;
        vector<vector<int>>result;
        while(i<n){
            if(intervals[i][1] < newInterval[0]) {
                result.push_back(intervals[i]);
            } else if (intervals[i][0] > newInterval[1]) {
                break;
            } else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
            i++;
        }
        result.push_back(newInterval);
        while(i < n) {
            result.push_back(intervals[i]);
            ++i;
        }
        return result;
    }
};
*/








/*
//TLE TC:O(N^2) SC:O(1)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        
        while(i < intervals.size()) {
            if(intervals[i][1] < newInterval[0])
                i++;
            else if (intervals[i][0] > newInterval[1]){
                intervals.insert(intervals.begin() + i, newInterval);
                return intervals;
            } else {
                //Overlap : merge them
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
                intervals.erase(intervals.begin()+i);
            }
        }
        
        intervals.push_back(newInterval);
        return intervals;
    }
};
*/