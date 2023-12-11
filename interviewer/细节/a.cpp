class Solution {
public:
    string convert(string s){
        string ret = "";
        for(int i = 0;i < s.size();i++){
            //if(s[i] == ',' || s[i] == ':' || s[i] == ' ' || s[i]=='.'){
            if(isalpha(s[i]) || isdigit(s[i])){
              ret += tolower(s[i]);
            }
        }
        return ret;
    }
    bool isPalindrome(string s) {
        string ret = convert(s);
        int i = 0, j = ret.size()-1;
        bool flag = true;
        while(i < j){
            if(ret[i] != ret[j]){
                flag = false;
                break;
            }
            i++; j--;
        }
        return flag;
    }
};