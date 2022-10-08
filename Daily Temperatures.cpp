class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>>st;
        vector<int>v;
        for(int i=temp.size()-1;i>-1;){
            if(st.empty()){
                v.push_back(0);
                st.push({temp[i],i});
                i--;
            }
            else if(st.top().first>temp[i]){
                v.push_back(st.top().second-i);
                st.push({temp[i],i});
                i--;
            }
            else st.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};