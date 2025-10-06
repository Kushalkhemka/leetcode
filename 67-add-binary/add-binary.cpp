class Solution {
public:
    string addBinary(string a, string b) {
        int n1=a.length();int n2=b.length();
        //make two pointer on the string
        int i=n1-1; int j=n2-1; 
        int carry=0;string res;
        while(i >= 0 || j >= 0 || carry){ //jab tk dono me se choti 
            //if i is a valid pointer
            int currentSum=carry;
            if(i>=0){
                currentSum+= a[i]-'0'; i--;//str to digit c-'0'
            }
             if(j>=0){
                currentSum+= b[j]-'0'; j--;//str to digit c-'0'
            }
            res.push_back((currentSum%2)+'0');
            carry = currentSum / 2; 
        }
    reverse(res.begin(), res.end());
    return res;
    }
};