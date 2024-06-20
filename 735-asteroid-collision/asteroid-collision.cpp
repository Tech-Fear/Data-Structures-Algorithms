class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=0;i<asteroids.size();i++){
            int curr = asteroids[i];
            
            if(st.empty())st.push(curr);
            
            else{
                int top=st.top();
                
                if(top<0){
                    st.push(curr);
                }
                else{
                    if(curr<0){
                        if(top==abs(curr)){
                            st.pop() ;
                            continue;
                        } 
                        
                        if(top>abs(curr))continue;
                        int flag=0;
                        while(!st.empty() && st.top()>0){
                            if(st.top()==abs(curr)){
                                st.pop() ;
                                flag=1;
                                break;
                            } 
                            if(st.top()<abs(curr))st.pop();
                            else {
                                flag=1;
                                break;
                            }
                        }
                        if(flag==0)st.push(curr);

                        
                    }
                    else{
                        st.push(curr);
                    }
                }
            }
        }
        
        
        vector<int> ans;
        while(!st.empty()){
            int top=st.top();
            ans.push_back(top);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};