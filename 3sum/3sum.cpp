class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> result;
        
        sort(nums.begin(),nums.end());
        
        
        cout<<"After Sorting"<<endl;
        for(int k : nums) {
            cout<<k << ",";
        }
        cout<<endl;
        
        for(int i=0; i<nums.size(); i++) {
            
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            
            vector<vector<int>> r = pairSum(nums,i+1,-1*nums[i]);
            
            for(vector<int> temp : r) {
                
                if(temp.size()==2) {
                    
                    vector<int> v;
                    v.push_back(temp[0]);
                    v.push_back(temp[1]);
                    v.push_back(nums[i]);
                    
                    sort(v.begin(),v.end());
                    result.push_back(v);
                }
            }
            
          
            
            
        }
        
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        
        return result;
        
    }
    
 public:
    vector<vector<int>> pairSum(vector<int> nums, int pos,int sum) {
        
        vector<vector<int>> result;
        
        int right = nums.size()-1;
        
        while(pos < right) {
            
            int s = nums[pos] + nums[right];
            
            if(s > sum) {
                right--;
                
            }
            else if(s < sum) {
                
                pos++;
                
            }
            
            else {
                
                vector<int> r;
                r.push_back(nums[pos]);
                r.push_back(nums[right]);
                result.push_back(r);
                
                
                if(pos < right && nums[pos]==nums[pos+1]) pos++;
                
                if(pos < right && nums[right]==nums[right-1]) right--;
                
                pos++;
                right--;
                
                
            }
            
        }
        
        
        
        return result;
        
    }
    
};