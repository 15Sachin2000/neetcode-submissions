class Solution {
    /**
     * @param {number[]} nums
     * @return {boolean}
     */
    hasDuplicate(nums) {
        const tmp={};
        for(let i of nums){
            if(tmp[i]){
                return true;
            }
            tmp[i]=true;
        }
        return false;
    }
}
