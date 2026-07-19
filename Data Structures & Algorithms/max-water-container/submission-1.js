class Solution {
    /**
     * @param {number[]} heights
     * @return {number}
     */
    maxArea(h){
        const n=h.length;
        let i=0,j=n-1,ans=0;
        while(i<j){
            if(h[i]>h[j]){
                ans=Math.max(ans,(j-i)*h[j]);
                j--;
            }else if(h[i]<h[j]){
                ans=Math.max(ans,(j-i)*h[i]);
                i++;
            }else{
                ans=Math.max(ans,(j-i)*h[i]);
                i++;
                j--;
            }
        }
        return ans;
    }
}
