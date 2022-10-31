class MedianFinder {
    priority_queue<int> ma;
    priority_queue<int, vector<int>, greater<int>> mi;

   public:
    MedianFinder() {}

    void addNum(int num) {
        if (ma.size() == 0)
            ma.push(num);
        else if (num > ma.top())
            mi.push(num);
        else
            ma.push(num);
        if (mi.size() > ma.size()) {
            ma.push(mi.top());
            mi.pop();
        }
        if (ma.size() - mi.size() > 1) {
            mi.push(ma.top());
            ma.pop();
        }
    }

    double findMedian() {
        if (ma.size() == mi.size())
            return 1.0 * (ma.top() + mi.top()) / 2.0;
        else
            return ma.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */