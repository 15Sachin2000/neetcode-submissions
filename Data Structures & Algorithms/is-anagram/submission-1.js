class Solution {
    /**
     * @param {string} s
     * @param {string} t
     * @return {boolean}
     */
    isAnagram(s, t) {
        if(s.length!==t.length) return false;
        const arr=new Array(26).fill(0);
        const aCharCode="a".charCodeAt(0);
        for(let i=0;i<s.length;i++){
            arr[s[i].charCodeAt(0)-aCharCode]++;
            arr[t[i].charCodeAt(0)-aCharCode]--;
        }
        return arr.every(item=>item==0);
    }
}
