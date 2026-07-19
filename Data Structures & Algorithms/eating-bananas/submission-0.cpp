class Solution {
public:
bool isValid(vector<int>& arr,int k,int h){
    int sum=0;
    for(int i:arr){
        sum+=ceil((1.0*i)/k);
    }
    return (sum<=h);
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int mx=piles[0];
        for(int i:piles){
            mx=max(mx,i);
        }
        int ans=mx,l=1,r=mx;
        while(l<=r){
            int k=l+(r-l)/2;
            if(isValid(piles,k,h)){
                ans=k;
                r=k-1;
            }else{
                l=k+1;
            }
        }
        return ans;
    }
};
