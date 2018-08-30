class TrieNode{
public:
    int path;
    int end;
    TrieNode *child[26];
    TrieNode(){
        path = 0;
        end = 0;
        for(int i=0; i<26; ++i){
            child[i] = NULL;
        }
    }
};
class TrieTree{
public:
    TrieNode *root;

    TrieTree(){
        root = new TrieNode();
    }
    void insertWord(string word){
        if(word == "") return;
        TrieNode *node = root;
        for(int i=0; i<word.size(); ++i){
            int index = word[i] - 'a';
            if(node->child[index] == NULL){
                node->child[index] = new TrieNode();
            }
            node = node->child[index];
            node->path++;
        }
        node->end++;
    }
    void deleteWord(string word){
        if(searchWord(word)){
            TrieNode *node = root;
            for(int i=0; i<word.size(); ++i){
                int index = word[i] - 'a';
                if(node->child[index]->path-- == 1){
                    node->child[index] = NULL;
                    return;
                }
                node = node->child[index];
            }
            node->end--;
        }
    }
    bool searchWord(string word){
        if(word == "") return false;
        TrieNode *node = root;
        for(int i=0; i<word.size(); ++i){
            int index = word[i] - 'a';
            if(node->child[index] == NULL){
                return false;
            }
            node = node->child[index];
        }
        return node->end != 0;
    }
    int prefixNumber(string prefix){
        if(prefix == "") return false;
        TrieNode *node = root;
        for(int i=0; i<prefix.size(); ++i){
            int index = prefix[i] - 'a';
            if(node->child[index] == NULL){
                return 0;
            }
            node = node->child[index];
        }
        return node->path;
    }

};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if(words.empty() || board.size() == 0 || board[0].size() == 0) return res;
        TrieTree *trie = new TrieTree();
        for(int i=0; i<words.size(); ++i){
            trie->insertWord(words[i]);
        }
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool> > visit(row,vector<bool> (col,false));
        string temp;
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                int index = board[i][j] - 'a';
                if(trie->root->child[index] != NULL){
                    dfs(board,trie->root->child[index],visit,i,j,res,temp);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& board,TrieNode *curNode,vector<vector<bool> > &visit,int curX,int curY,vector<string> &res,string temp){
        visit[curX][curY] = true;
        temp.push_back(board[curX][curY]);

        if(curNode->end != 0){
            res.push_back(temp);
            curNode->end = 0;
        }
        static const int dx[] = {-1,1,0,0};
        static const int dy[] = {0,0,-1,1};
        for(int i=0; i<4; ++i){
            int newX = curX + dx[i];
            int newY = curY + dy[i];
            if(newX >= 0 && newX < board.size() && newY >= 0 && newY < board[0].size() && !visit[newX][newY]){
                int index = board[newX][newY] - 'a';
                if(curNode->child[index] != NULL){
                    dfs(board,curNode->child[index],visit,newX,newY,res,temp);
                }
            }
        }
        visit[curX][curY] = false;
    }
};
