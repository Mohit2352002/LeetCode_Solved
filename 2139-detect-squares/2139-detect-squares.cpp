static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class DetectSquares {
public:
    unordered_map<int,unordered_map<int,int>> xhash;
    DetectSquares() {
        xhash.clear();
    }

    int countoccurrences(int x, int y){
        auto it = xhash.find(x);
        if(it == xhash.end())return 0;

        auto itr = xhash[x].find(y);
        if(itr == xhash[x].end())return 0;

        return xhash[x][y];
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        xhash[x][y]++;
        return;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int ans = 0;

        for(auto itr: xhash[x]){
            if(itr.first == y)continue;
            int y2 = itr.first;
            int count2 = itr.second;
            int s = abs(y - y2);

            int x3 = x + s;
            int y3 = y2;
            int count3 = countoccurrences(x3,y3);

            int x4 = x + s;
            int y4 = y;
            int count4 = countoccurrences(x4,y4);

            ans += (count2 * count3 * count4);

            x3 = x-s;
            count3 = countoccurrences(x3,y3);

            x4 = x-s;
            count4 = countoccurrences(x4,y4);

            ans += (count2*count3 * count4);
        }

        return ans;
    }
};











/*
class DetectSquares {
    int cntPoints[1001][1001] = {};
    vector<pair<int, int>> points;
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> p) {
        cntPoints[p[0]][p[1]]++;
        points.emplace_back(p[0], p[1]);
    }
    
    int count(vector<int> p) {
        int x1 = p[0], y1 = p[1], ans = 0;
        for (auto& [x3, y3] : points) {
            if (abs(x1-x3) == 0 || abs(x1-x3) != abs(y1-y3))
                continue; // Skip empty square or invalid square point!
            ans += cntPoints[x1][y3] * cntPoints[x3][y1];
        }
        return ans;
    }
};*/

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */