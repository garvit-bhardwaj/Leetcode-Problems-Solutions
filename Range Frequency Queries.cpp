class RangeFreqQuery {
    unordered_map<int, vector<int>> mp;
public:
    RangeFreqQuery(vector<int>& arr) {
        for(int i = 0; i < size(arr); i++) mp[arr[i]].push_back(i);
    }
    
    int query(int L, int R, int V) {
        return upper_bound(begin(mp[V]), end(mp[V]), R) - lower_bound(begin(mp[V]), end(mp[V]), L); 
    }
};
