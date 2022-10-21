class Solution {
public:
   string decodeCiphertext(string e, int rows) {
		int size=e.size();
		int col=size/rows;
		string ans;
		for(int i=0;i<col;i++)
		{
			for(int j=i;j<size;j+=col+1)
			{
				ans+=e[j];
			}
		}
		while (isspace(ans.back()))
		{
			ans.pop_back();
		}
			return ans;
		}
	
};
