class Solution
{
public:
    double pow(double n, int t)
    {
        if (t < 0)
        {
            n = 1.0 / n;
        }
        
        double result = 1.0;
        double ans = n;
        
        while (t!= 0)
        {
            if (t% 2 != 0)
            {
                result *= ans;
            }
            t=t/ 2;
            ans= ans*ans;
        }
        
        return result;
    }
};
