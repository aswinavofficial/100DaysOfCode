class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        if(arr.size()<3) {
            return 0;
        }
        
        
        vector<int> peaks;
        
        int maxPeak = 0;
        
        for(int i=1;i<arr.size()-1;i++) {
            
            if(arr[i-1]<arr[i]&& arr[i+1]<arr[i]) {
                peaks.push_back(i);
            }
            
        }
        
        cout<<"Peaks"<<endl;
        
        for(int i : peaks) {
            
            cout<<"Peak : "<<arr[i]<<" Index : "<<i<<endl;
            
            int current_peak=1;
            int j = i;
            
            while(j>0 && arr[j-1]<arr[j]) {
                current_peak++;
                j--;
                
            }
            j=i;
            while(j<arr.size()-1 && arr[j]>arr[j+1]) {
                current_peak++;
                j++;
            }
            
            if(current_peak > maxPeak)
                maxPeak = current_peak;
            
            
            
        }
        
        return maxPeak;
    }
};