    int bestRotation(vector<int>& A) {
        int N = A.size();
        int change[N] = {0};
        for (int i = 0; i < N; ++i) change[(i - A[i] + 1 + N) % N] -= 1;
        for (int i = 1; i < N; ++i) change[i] += change[i - 1] + 1;
        return distance(change, max_element(change, change + N));
    }
