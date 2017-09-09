class Solution {
public:
    string simplifyPath(string path) {
        if (path.size() == 0) return "";
        vector<string> q;
        int i = 0;
        while (i < path.size()){
            i ++;
            string tmp = "";
            while (i < path.size() && path[i] != '/'){
                tmp = tmp + path[i];
                i ++;
            }
            if (tmp == "." || tmp == "") continue;
            if (tmp == ".."){
                if (!q.empty()) q.pop_back();
                continue;
            }
            q.push_back(tmp);
        }
        string ret = "";
        for (int i = 0; i < q.size(); ++ i)
            ret = ret + "/" + q[i];
        if (ret == "") ret = "/";
        return ret;
    }
};