class Solution {
public:
    string addBinary(string a, string b) {
         //fill the same length for a and b
        string ans;
        while(a.size() < b.size()){
            a = '0' + a;
        }
        while(a.size() > b.size()){
            b = '0' + b;
        }
        //define carry bit
        int carry = 0;
        
        //do binary add operation
        for(int i = a.size()-1; i >= 0; i--){
            carry = carry + (a[i] - '0' + b[i] - '0');
            ans = char(carry % 2 + '0') + ans;
            carry = carry / 2;
        }
        //if carry is overflow, add 1 in the front
        if(carry == 1){
            ans = '1' + ans;
        }
        return ans;
    }
};
