class Solution {
    /**
     * @param {string[]} strs
     * @return {string[][]}
     */
    groupAnagrams(strs) {
        const mp={};
        for(let str of strs){
            const dp=new Array(26).fill(0);
            const a='a'.charCodeAt(0);
            for(let ch of str){
                dp[ch.charCodeAt(0)-a]++;
            }
            let key='';
            for(let i of dp){
                key+=String(i);
            }
            if(!mp[key]){
                mp[key]=[str];
            }else{
                mp[key].push(str);
            }
        }
        const ans=[];
        for(let key in mp){
            ans.push(mp[key]);
        }
        return ans;
    }
}
