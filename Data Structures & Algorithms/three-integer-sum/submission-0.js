class Solution {
    /**
     * @param {number[]} nums
     * @return {number[][]}
     */
    threeSum(nums) {
        nums.sort((a,b)=>a-b);
        const ans=[];
        const n=nums.length;
        console.log(nums);
        for(let i=0;i<n-2;i++){
            if(i!=0 && nums[i]==nums[i-1]){
                continue;
            }
            const target=-1*nums[i];
            let l=i+1,r=n-1;
            while(l<r){
                const sum=nums[l]+nums[r];
                if(sum===target){
                    ans.push([nums[i],nums[l],nums[r]]);
                    console.log(nums[i],nums[l],nums[r]);
                    l++;
                    r--;
                    while(l<n && nums[l]===nums[l-1]){
                        l++;
                    }
                    while(r>l && nums[r]===nums[r+1]){
                        r--;
                    }
                }else if(sum>target){
                    r--;
                }else{
                    l++;
                }
            }
        }
        return ans;
    }
}
