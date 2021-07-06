class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        
        unordered_set<int> mem;
        
        for(int  i=0;i<nums.size();i++) {
            
            mem.insert(nums[i]);
        }
        
        int maxSeq = 0;
        
        for(int i : mem) {
            
            int current_seq=1;
            
            int j = i-1;
            
            while(mem.find(j) !=mem.end()) {
                
                current_seq++;
                mem.erase(mem.find(j));
                j--;
                
            }
            
            j = i+1;
            while(mem.find(j) !=mem.end()) {
                
                current_seq++;
                mem.erase(mem.find(j));
                j++;
                
            }
            
            maxSeq = max(maxSeq,current_seq);
            //mem.erase(mem.find(i));
        }
        
        return maxSeq;
        
    }
};