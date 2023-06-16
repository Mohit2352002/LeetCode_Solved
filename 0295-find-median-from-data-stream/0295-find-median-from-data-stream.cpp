class MedianFinder {
    priority_queue<int>max_heap;
    priority_queue<int,vector<int>,greater<int>>min_heap;
    int median=INT_MAX;
public:
    MedianFinder() {
    }
    
    void addNum(int nums) {
        if(median==INT_MAX) median=nums;
        else{
            if(nums>median){
                min_heap.push(nums);
                if(min_heap.size()-max_heap.size()==2){
                    max_heap.push(median);
                    median=min_heap.top();
                    min_heap.pop();
                }
            }
            else{
                max_heap.push(nums);
                if(max_heap.size()-min_heap.size()==2){
                    min_heap.push(median);
                    median=max_heap.top();
                    max_heap.pop();
                }
            }
        }
    }
    
    double findMedian() {
        if(min_heap.size()==max_heap.size()) return median;
        else if(min_heap.size()>max_heap.size()){
            double ans=(median+min_heap.top()+0.0)/2;
            return ans;
        }
        else{
            double ans=(median+max_heap.top()+0.0)/2;
            return ans;
        }
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */