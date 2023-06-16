static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class MedianFinder {
    priority_queue <int, vector<int>, greater<>> right;
    priority_queue <int> left;
    int median;
    unsigned short lcount, rcount;

    
public:
    MedianFinder() {
        median = -2147483648;
        lcount = 0;
        rcount = 0;
    }
    
    void addNum(int num) {  
        if(median==-2147483648){
            median=num; 
            return; 
        }   
        if(num<median){
            left.push(num);
            if(lcount>rcount){
                right.push(median);
                median = left.top();
                left.pop();
                rcount++;
            }
            else
                lcount++;
        }
        else{
            right.push(num);
            if(rcount>lcount){
                left.push(median);
                median = right.top();
                right.pop();
                lcount++;
            }
            else
                rcount++;
        }
    }
    
    double findMedian() {
        if(lcount==rcount)
            return median;
        else if(lcount>rcount){
            double sum = median+left.top();
            return sum/2;
        }
        else{
            double sum = median+right.top();
            return sum/2;
        }
    }
};











/*
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
*/











/*
//wo using a variable median
class MedianFinder {
public:
    priority_queue<int>left;
    priority_queue<int,vector<int>,greater<int>>right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(!left.empty() and num<left.top())  left.push(num);
        else    right.push(num);
        if(left.size()==right.size()+2)   right.push(left.top()), left.pop();
        else if(right.size()==left.size()+2)    left.push(right.top()), right.pop();
    }
    
    double findMedian() {
        if(left.size()>right.size())    return left.top();
        if(right.size()>left.size())    return right.top();
        return (double)(left.top()+right.top())/2;
    }
};
*/









/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */




