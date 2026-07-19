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
            const key=dp.join(',');
            if(!mp[key]){
                mp[key]=[str];
            }else{
                mp[key].push(str);
            }
        }
        return Object.values(mp);
    }
}
