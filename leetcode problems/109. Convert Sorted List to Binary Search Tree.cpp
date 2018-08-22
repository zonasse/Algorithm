/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution1 {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        ListNode *temp = head;
        vector<int> nums;
        while(temp){
            nums.push_back(temp->val);
            temp = temp->next;
        }
        return generate(nums,0,nums.size()-1);
    }
    TreeNode* generate(vector<int> &nums,int left,int right){
        if(left > right) return NULL;
        int mid = left + (right-left)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = generate(nums,left,mid-1);
        root->right = generate(nums,mid+1,right);
        return root;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution2 {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return new TreeNode(head->val);
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *last = slow;
        while(fast->next && fast->next->next){
            last = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        last->next = NULL;
        TreeNode *root = new TreeNode(slow->val);
        root->left = head == slow ? NULL : sortedListToBST(head);
        root->right = sortedListToBST(fast);
        return root;
    }

};
