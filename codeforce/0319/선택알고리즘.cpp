class Solution {
public:
    int Partition(vector<int>& v,int Left,int Right){
        int pivot = Left;
        int store = pivot;
        for(int i = Left+1;i<=Right;i++){
            if(v[i] < v[pivot]){
                store++;
                swap(v[i],v[store]);
            }
        }
        swap(v[store],v[pivot]);
        pivot = store;
        return pivot;
    }

    int Select(vector<int>& v,int low,int high,int k){
        int p = Partition(v,low,high);
        if(p == k){
            return v[p];
        }
        else if(p < k){
            return Select(v,p+1,high,k);
        }
        else if(p > k){
            return Select(v,low,p-1,k);
        }
        return p;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int val = Select(nums,0,nums.size()-1,nums.size()-k);
        return val;
    }
};