class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) 
    {
        int i = 0, j = plants.size() - 1, canA = capacityA, canB = capacityB, res = 0;
        while (i < j) {
            res += (canA < plants[i]) + (canB < plants[j]);
            canA = canA < plants[i] ? capacityA : canA;
            canB = canB < plants[j] ? capacityB : canB;
            canA -= plants[i++];
            canB -= plants[j--];
        }
        return res + (i == j && max(canA, canB) < plants[i]);
    }

};
