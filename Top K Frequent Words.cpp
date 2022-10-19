class Solution {
public:
    
    // comparator
    
    struct comparator
    {
        bool operator() (pair<int, string>& a, pair<int, string>& b)
        {
            if(a.first == b.first)           // if frequency are equal put lexicographically greater element on top
            {
                return a.second < b.second;
            }
            else                            // if frequency are not equal put the elements on top which has less frequency
            {
                return a.first > b.first;
            }
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        int n = words.size();
        
        // declare a map which store the frequency of words
        
        unordered_map<string, int> mp;
        
        for(auto word : words)
        {
            mp[word]++;
        }
        
        // declare a priority queue
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, comparator> pq;
        
        for(auto x : mp)
        {
            if(pq.size() < k)             // firstly push k elements into pq
            {
                pq.push({x.second, x.first});
            }
            else
            {
                if(pq.top().first < x.second || (pq.top().first == x.second && pq.top().second > x.first))
                {
                    pq.pop();
                    
                    pq.push({x.second, x.first});
                }
            }
        }
        
        // push all the elements from pq to res
        
        vector<string> res;
        
        while(!pq.empty())
        {
            res.push_back(pq.top().second);
            
            pq.pop();
        }
        
        // reverse the res
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};
