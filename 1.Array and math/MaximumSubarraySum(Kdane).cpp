// https://www.interviewbit.com/problems/max-sum-contiguous-subarray/

const int inf = -1e9;

int Solution::maxSubArray(const vector<int> &a) {
    
    int n = (int)a.size();
    int msf = inf;
    int ans = inf;
    for(int i = 0;i < n;i++){
        msf = max(msf + a[i], a[i]);
        ans = max(ans, msf);
    }
    return ans;
}
