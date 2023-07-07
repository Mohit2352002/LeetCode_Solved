class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        unordered_map<int, int> cnt;
        for (int card : deck) ++cnt[card];
        int g = cnt[deck[0]];
        if (g == 1) return false;
        for (auto el:cnt) if ((g = __gcd(g, el.second)) == 1) return false;
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