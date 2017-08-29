class Solution {
private:
    vector<string> url;
    unordered_map<string, int> hash;
    const string CHAR62 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string dec2url(int c){
        string ret = "";
        while (c){
            ret = CHAR62[c % 62] + ret;
            c /= 62;
        }
        return ret;
    }
        int url2dec(string s){
        int ret = 0;
        for (auto& c : s){
            for (int i = 0; i < 62; ++ i)
                if (CHAR62[i] == c) ret = ret * 62 + i;
        }
        cout << ret << endl;
        return ret;
    }
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (hash.count(longUrl) > 0) return dec2url(hash[longUrl]);
        url.push_back(longUrl);
        hash[longUrl] = url.size() - 1;
        cout << 1 << endl;
        return dec2url(url.size() - 1);
    }
    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return url[url2dec(shortUrl)];
    }
};
// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));