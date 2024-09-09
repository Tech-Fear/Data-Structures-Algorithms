/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int rowStart=0,rowEnd=m-1;
        int colStart=0,colEnd=n-1;
        vector<vector<int>>matrix(m,vector<int>(n,-1));
        ListNode *cur=head;
        while(cur && rowStart<=rowEnd && colStart<=colEnd){
            for(int j=colStart;j<=colEnd&&cur;j++){
                matrix[rowStart][j]=cur->val;
                cur=cur->next;
            }
            rowStart++;
            for(int j=rowStart;j<=rowEnd&&cur;j++){
                matrix[j][colEnd]=cur->val;
                cur=cur->next;
            }
            colEnd--;
            for(int j=colEnd;j>=colStart&&cur;j--){
                matrix[rowEnd][j]=cur->val;
                cur=cur->next;
            }
            rowEnd--;
            for(int j=rowEnd;j>=rowStart && cur;j--){
                matrix[j][colStart]=cur->val;
                cur=cur->next;
            }
            colStart++;
        }
        return matrix;
    }
};