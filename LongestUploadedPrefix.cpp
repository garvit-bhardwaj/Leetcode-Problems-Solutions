class LUPrefix {
public:
    int prev = 0;
    vector<int> vis;
    LUPrefix(int n) {
        vis.assign(n + 1, 0);
    }
    
    void upload(int video) {
        vis[video] = 1;
    }
    
    int longest() {
        for(int i = prev + 1; i < vis.size(); i++){
            if(vis[i]) prev++;
            else break;
        }
        return prev;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
