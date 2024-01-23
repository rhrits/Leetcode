class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> all{bitset<26>()};
        int res = 0;
        for (string word : arr) {
            bitset<26> cur;
            for (char c : word) {
                cur.set(c - 'a');
            }
            int n = cur.count();
            if (n < word.size()) continue;
            for (int i = (int)all.size() - 1; i >= 0; --i) {
                bitset<26> t = all[i];
                if ((t & cur).any()) continue;
                all.push_back(t | cur);
                res = max(res, (int)t.count() + n);
            }
        }
        return res;
    }
};