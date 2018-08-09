/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};
*/
class Solution1 {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(!pNode){
            return NULL;
        }
        if(!pNode->next){
            return getMaxLeft(pNode->right);
        }
        if(pNode->left || pNode->right){
            if(!pNode->right){
                return pNode->next;
            }else{
                return getMaxLeft(pNode->right);
            }
        }
        if(!pNode->left && !pNode->right){
            if(pNode == pNode->next->left){
                //×óÒ¶×Ó
                return pNode->next;
            }else{
                //ÓÒÒ¶×Ó
                if(pNode->next->next){
                    if(pNode->next == pNode->next->next->right){
                        return NULL;
                    }else{
                        return pNode->next->next;
                    }
                }else{
                    return NULL;
                }
            }
        }
        return NULL;
    }
    TreeLinkNode* getMaxLeft(TreeLinkNode *node){
        if(!node){
            return node;
        }
        while(node->left){
            node = node->left;
        }
        return node;
    }
};
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};
*/
class Solution2 {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(!pNode){
            return NULL;
        }
        if(pNode->right){
            TreeLinkNode *temp = pNode->right;
            while(temp->left){
                temp = temp->left;
            }
            return temp;
        }
        while(pNode->next){
            if(pNode == pNode->next->left){
                return pNode->next;
            }
            pNode = pNode->next;
        }
        return NULL;
    }
};
