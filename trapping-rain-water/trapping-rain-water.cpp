class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        
        if(n<2)
            return 0;
        
        vector<int> left(n,0);
        vector<int> right(n,0);
        
        int maxL = height[0];

        int maxR = height[height.size()-1];
        
        cout<<"MaxR  : "<<maxR;
        
        for(int i=0,j=height.size()-1;i<height.size()&&j>=0;i++,j--) {
            
            maxL =  max(maxL,height[i]);
            left[i]= maxL;
            
            maxR = max(maxR,height[j]);
            right[j]=(maxR);
            
            
        }
        
        cout<<"Left prefix sum";
        
        for(int k : left)
        {
            cout<<k<<" ";
        }
        
        cout<<endl;
        cout<<"Right prefix sum";
        
        for(int k : right)
        {
            cout<<k<<" ";
        }
        
        int water =0;
        
        for(int i=0;i<height.size();i++) {
            
            water += min(left[i],right[i]) - height[i];
        }
        
        return water;
        
    }
};