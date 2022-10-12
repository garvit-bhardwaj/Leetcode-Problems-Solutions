class Solution {
public:
    int getBouq(vector<int>& bloomDay,int day,int k)	//Get the number of bouquets of size k at a certain day.
    {
        int result=0,count=0;
        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i]<=day)
                count++;
            else
                count=0;
            if(count==k)    //Reset the window size to 0 to consider the case with 2*k or more continous bloomed flowers.
                result++,count=0;
        }
        return result;
    }
    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        auto p=minmax_element(bloomDay.begin(),bloomDay.end());
        int j=*p.second,i=*p.first;
        int mid;
        while(i<j)				//Binary search on the range to get the minimum day where we may get `m` bouquets.
        {
            mid=(i+j)>>1;
            if(getBouq(bloomDay,mid,k)<m)
                i=mid+1;
            else
                j=mid;
        }
        return getBouq(bloomDay,i,k)>=m?i:-1;		//Final check if the result day can have atleast `m` bouquets.
    }
};
