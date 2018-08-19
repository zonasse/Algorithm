class Solution {
public:
    string simplifyPath(string path) {
        if(path.empty()) return path;
        int start = 0;
        int end = 0;
        string res = "";
        stack<string> pathStack;
        pathStack.push("/");
        while(start < path.size()){
            while(start < path.size() && path[start] == '/'){
                start++;
            }
            end = start;
            while(end < path.size() && path[end] != '/'){
                  end++;
            }
            string each = path.substr(start,end-start);
            if(each == ".."){
                if(pathStack.top() != "/"){
                    pathStack.pop();
                }
            }else if(each != "." && each != ""){
                pathStack.push(each);
            }
            start = end;
        }
        if(pathStack.size() == 1){
            return pathStack.top();
        }
        while(pathStack.size()>1){
            res = "/" + pathStack.top()+res;
            pathStack.pop();
        }
        return res;
    }
};
