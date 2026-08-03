class Solution {
public:
    void merge(vector<int>& nums,int s,int m,int e){
        vector<int> a(nums.begin()+s,nums.begin()+m+1);
        vector<int> b(nums.begin()+m+1,nums.begin()+e+1);
        for(int i:a) cout<<i<<" ";
        cout<<endl;
        int i1=0,i2=0,n1=m-s+1,n2=e-m;
        while(i1<n1 && i2<n2){
            int k=s+i1+i2;
            if(a[i1]>b[i2]){
                nums[k]=b[i2];
                i2++;
            }else{
                nums[k]=a[i1];
                i1++;
            }
        }
        while(i1<n1){
            int k=s+i1+i2;
            nums[k]=a[i1];
            i1++;
        }
        while(i2<n2){
            int k=s+i1+i2;
            nums[k]=b[i2];
            i2++;
        }
    }
    void mergeSort(vector<int>& nums,int s,int e){
        if(s==e) return;
        int mid=s+(e-s)/2;
        mergeSort(nums,s,mid);
        mergeSort(nums,mid+1,e);
        merge(nums,s,mid,e);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};