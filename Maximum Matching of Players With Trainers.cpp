class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end(), greater<int>());
        sort(trainers.begin(), trainers.end(), greater<int>());
        
        int count = 0;
        int j = 0;
        
        for(int i = 0;i < players.size() && j < trainers.size(); i++){
            if(players[i] <= trainers[j]){
                count++;
                j++;
            }
        }
        
        return count;
    }
};
