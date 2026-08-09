class Solution {
public:
    int optimalBob(int s,int m,vector<int> &piles,int* sa,int* sb){
        int n=piles.size();
        if(s>=n) return 0;
        int l=min(n-1,s+2*m-1);
        int ans=0,sum=0,i=s,tmpsa=0,tmpsb=0;
        while(i<=l){
            sum+=piles[i];
            i++;
            int nm=max(m,i-s);
            int nsa=*sa,nsb=sum+*sb;
            optimalAlice(i,nm,piles,&nsa,&nsb);
            ans=max(ans,nsb);
            if(ans==nsb){
                tmpsa=nsa;
                tmpsb=nsb;
            }
        }
        *sa=tmpsa,*sb=tmpsb;
        return ans;
    }
    int optimalAlice(int s,int m,vector<int> &piles,int* sa,int* sb){
        int n=piles.size();
        if(s>=n) return 0;
        int l=min(n-1,s+2*m-1);
        int ans=0,sum=0,i=s,tmpsa=0,tmpsb=0;
        while(i<=l){
            sum+=piles[i];
            // cout<<i<<" "<<sum<<endl;
            i++;
            int nm=max(m,i-s);
            int nsa=sum+*sa,nsb=*sb;
            optimalBob(i,nm,piles,&nsa,&nsb);
            ans=max(ans,nsa);
            if(ans==nsa){
                tmpsa=nsa;
                tmpsb=nsb;
            }
        }
        *sa=tmpsa,*sb=tmpsb;
        return ans;
    }
    int stoneGameII(vector<int>& piles) {
        int sa=0,sb=0;
        return optimalAlice(0,1,piles,&sa,&sb);
        // return sa;
    }
};