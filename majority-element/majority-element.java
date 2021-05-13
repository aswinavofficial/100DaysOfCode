class Solution {
    public int majorityElement(int[] nums) {
        
        int maj =0;
        int count = 0;
        
        for(int num:nums) {
            
            if(num == maj) {
                count ++;
            }
            else if(count==0) {
                maj = num;
                count++;
            }
            else {
                count --;
            }
        }
        
        
        count =0;
        for(int num:nums) {
            
            if(num == maj) {
                count++;
            }
            
            if(count > nums.length/2)
                return maj;
        }
        
        return maj;
        
         
    }
}