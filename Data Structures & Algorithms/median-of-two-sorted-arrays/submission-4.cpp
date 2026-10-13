class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        int sum=n1+n2;
        if(sum%2){
            if(n1==0|| n2==0){
                if(n2==0){
                    return nums1[sum/2];
                }
                return findMedianSortedArrays(nums2,nums1);
            }
            return findValue(sum/2,nums1,nums2);
        }
        if(n1==0 || n2==0){
            if(n2==0){
                return (1.0*nums1[sum/2]+1.0*nums1[(sum-1)/2])/2.0;
            }
            return findMedianSortedArrays(nums2,nums1);
        }
        int a=findValue(sum/2,nums1,nums2);
        int b=findValue((sum-1)/2,nums1,nums2);
        cout<<a<<" "<<sum/2<<" "<<b<<" "<<(sum-1)/2<<endl;
        return (a*1.0+b*1.0)/2.0;
    }
private:
    int findValue(int idx,vector<int>& nums1, vector<int>& nums2){
        int n1=nums1.size(),n2=nums2.size();
        int l=0,r=min(idx,n1-1);
        while(l<=r){
            int m=l+(r-l)/2;
            int x=idx-m;
            if(x>n2){
                l=m+1;
                continue;
            }
            if(x==n2){
                if(nums1[m]>=nums2[x-1]) return nums1[m];
                l=m+1;
            }
            else if(x==0){
                if(nums1[m]<=nums2[x]) return nums1[m];
                r=m-1;
            }
            // else if(x==n2-1){
            //     if(nums1[m]>=nums2[x]) return nums1[m];
            //     l=m+1;
            // }
            else{
                if(nums1[m]>=nums2[x-1] && nums1[m]<=nums2[x]){
                    return nums1[m];
                }
                if(nums1[m]<nums2[x-1]) l=m+1;
                else r=m-1;
            }
        }
        l=0,r=min(idx,n2-1);
        while(l<=r){
            int m=l+(r-l)/2;
            int x=idx-m;
            if(x>n1){
                l=m+1;
                continue;
            }
            if(x==n1){
                if(nums2[m]>=nums1[x-1]) return nums2[m];
                l=m+1;
            }
            else if(x==0){
                if(nums2[m]<=nums1[x]) return nums2[m];
                r=m-1;
            }
            else{
                if(nums2[m]>=nums1[x-1] && nums2[m]<=nums1[x]){
                    return nums2[m];
                }
                if(nums2[m]<nums1[x-1]) l=m+1;
                else r=m-1;
            }
        }
        return 0;
    }
};
