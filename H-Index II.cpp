class Solution {
	public:
		int hIndex(vector<int>& citations) {
			int index;
			priority_queue<int> pq(begin(citations), end(citations));

			for (index = 0; !pq.empty() && index < pq.top();index++)
				pq.pop();  

			return index;
		}
	};
