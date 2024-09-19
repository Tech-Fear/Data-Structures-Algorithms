class Solution {
private:
    static bool compare(int a,int b){
        string x=to_string(a)+to_string(b);
        string y=to_string(b)+to_string(a);
        return x>y;
    }
public:
    string largestNumber(vector<int>& nums) {
        string largest="";
        sort(nums.begin(),nums.end(),compare);
        for(int num:nums){
            largest+=to_string(num);
        }
        int count =0;
        for(int i=0;i<largest.length();i++){
            if(largest[i]-'0'!=0) break;
            count++;
        }
        largest=largest.substr(count);
        if(largest.length()==0) return "0";
        return largest;
    }
};