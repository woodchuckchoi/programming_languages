vector<string> mySplit(string s, string delim) {
        vector<string> ans;
        
        size_t pos = 0;
        std::string token;
        while ((pos = s.find(delim)) != std::string::npos) {
            token = s.substr(0, pos);
            ans.push_back(token);
            s.erase(0, pos + delim.length());
        }
        if (s.size() > 0) {
            ans.push_back(s);
        }
        return ans;
    }
