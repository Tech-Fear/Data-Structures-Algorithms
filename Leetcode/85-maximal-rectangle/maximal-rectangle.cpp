class Solution {
private:
    vector<int> getNSR(vector<int>&height){
        stack<int>st;
        int n=height.size();
        vector<int>NSR(n);
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                NSR[i]=n;
            }else{
                while(!st.empty()&&height[st.top()]>=height[i]){
                    st.pop();
                }
            if(st.empty()) NSR[i]=n;
            else NSR[i]=st.top();
            }
            st.push(i);
        }
        return NSR;
    }
    vector<int>getNSL(vector<int>&height){
        stack<int>st;
        int n=height.size();
        vector<int>NSL(n);
        for(int i=0;i<n;i++){
            if(st.empty()){
                NSL[i]=-1;
            }else{
                while(!st.empty() && height[st.top()]>=height[i]){
                    st.pop();
                }
                if(st.empty()){
                    NSL[i]=-1;
                }else{
                    NSL[i]=st.top();
                }
            }
            st.push(i);
        }
        return NSL;
    }
    int calcMaxArea(vector<int>&height){
        vector<int>NSR=getNSR(height);
        vector<int>NSL=getNSL(height);
        int n=height.size();
        vector<int>width(n);
        int maxArea=0;
        for(int i=0;i<n;i++){
            width[i]=NSR[i]-NSL[i]-1;
        }
        for(int i=0;i<n;i++){
            int a=height[i]*width[i];
            maxArea=max(maxArea,a);
        }
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>height(m);
        for(int i=0;i<m;i++){
            height[i]=(matrix[0][i]=='1'?1:0);
        }
        int maxArea=calcMaxArea(height);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0') height[j]=0;
                else height[j]+=1;
            }
            maxArea=max(maxArea,calcMaxArea(height));
        }
        return maxArea;
    }
};