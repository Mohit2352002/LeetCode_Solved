int speedup = []{ios::sync_with_stdio(0); cin.tie(0); return 0; }();

class Solution {
    int cnt[10000];
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        for (int d : deck) cnt[d] = 0;
        for (int d : deck) ++cnt[d];
        int g = cnt[deck[0]];
        if (g == 1) return false;
        for (int d : deck) if ((g = gcd(g, cnt[d])) == 1) return false;
        return true;
    }
};









/*
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        unordered_map<int, int> count;
        int res = 0;
        for (int i : deck) ++count[i];
        for (auto el : count) res = __gcd(el.second, res);
        return res > 1;
    }
};*/