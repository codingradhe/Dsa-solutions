// brute force problem
class Solution {
public:
    int trap(vector<int>& h) {
        int water, ans = 0,nxtgt = 0,pregt =0;
        int n = h.size();
        vector<pair<int,int>>v(n);
        for(int i = n-1;i>=0;i--){
            v[i] = {h[i],nxtgt};
            nxtgt = max(h[i],nxtgt);
        }
        for(int i =0;i<n;i++){
            pregt = max(pregt,v[i].first);
            water = min(pregt,v[i].second)-h[i];
            if(water<0) ans+=0;
            else ans+=water;
        }
        return ans;
    }
};
//class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int water, ans = 0,l = 1,r =n-2;
        int lmax = h[0],rmax = h[n-1];
        while(l<=r){
            if(lmax<rmax){
                if(h[l]<min(lmax,rmax)) {
                    ans += (min(lmax,rmax)-h[l]);
                }
                lmax = max(lmax,h[l]);
                l++;
            }
            else{
                if(h[r]<min(lmax,rmax)) {
                    ans += (min(lmax,rmax)-h[r]);
                }
                rmax = max(rmax,h[r]);
                r--;
            }
        }
        return ans;
    }
};
