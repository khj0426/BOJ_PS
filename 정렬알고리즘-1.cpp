//quick Sort
class Solution {
public:

    int Paration(vector<int> &v,int low,int high){
        
        int pivot = v[low];
        int i = low + 1;
        int j = high;
        while(i <= j){
            while(i <= j && v[i] < pivot){
                i++;
            }
            while(i <= j && v[j] > pivot){
                j--;
            }

            if(i <= j){
                swap(v[i],v[j]);
                i++;
                j--;
            }
        }
        swap(v[low],v[j]);
        return j;
    }

    void quickSort(vector<int> &v,int p,int r){
        if(p<r){
            int q = Paration(v,p,r);
            quickSort(v,p,q-1);
            quickSort(v,q+1,r);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums,0,nums.size()-1);
        return nums;
    }
};


//heap Sort
class Solution {
public:
		//힙 구성을 재귀적으로 구성한다
    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;
        
        //각각 왼쪽 오른쪽 자식
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && nums[left] > nums[largest])
            largest = left;

        if (right < n && nums[right] > nums[largest])
            largest = right;

        //최대힙에 위반되는 경우 재귀적으로 힙 구성
        if (largest != i) {
            swap(nums[i], nums[largest]);
            heapify(nums, n, largest);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
		//최초 힙 구성단계

        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(nums, n, i);
		
        //힙 정렬단계, 루트와 리프를 바꾸고 힙 다시 구성
         for (int i = n - 1; i > 0; i--) {
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
        return nums;
    }
};

//Counting Sort
public:
    void sortColors(vector<int>& nums) {
        int sums[3];
        int answers[301];
        memset(sums,0,sizeof(sums));
        memset(answers,0,sizeof(answers));
        //처음 횟수 저장
        for(int i = 0;i<nums.size();i++){
            sums[nums[i]]++;
        }   

        //누적합으로 횟수 저장
        for(int i = 0;i<=2;i++){
            if(i != 0){
                sums[i] += sums[i-1];
            }
        }

        for(int i = nums.size()-1;i>=0;i--){
            answers[sums[nums[i]]] = nums[i];
            sums[nums[i]]--; 
        }

        for(int i = 0;i<=nums.size()-1;i++){
            nums[i] = answers[i+1];
        }

        
}