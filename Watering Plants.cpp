class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int count = 0;
        int temp = capacity;
        int n = plants.size();
        for(int i = 0; i<n; i++)
        {   
            
            if(capacity < plants[i])
            {
                capacity = temp;
                count += 2 * i;  
            }
            capacity -= plants[i];
            count++;

        }
        return count;
    }
};
