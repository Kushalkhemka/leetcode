class Solution {
public:
    bool check(char c1, char c2) {
        return (c1 == '(' && c2 == ')');
    }
    int longestValidParentheses(string s) {
    //     stack<int> stk;
    //     int count = 0; int permanentCount=0;
    //     for (int j = 0; j < s.length(); j++) {
    //         if (s[j] == '(') {
    //             if(!stk.empty()&& s.length()%2!=0 && stk.top()=='(') {count=0;}
    //             // push into stack
    //             else stk.push(s[j]);
    //         } else {
    //             // if s[j]==')'
    //                 if(!stk.empty() && check(stk.top(),s[j])){
    //                     stk.pop();
    //                     count+=2;
    //                 }
    //                 else{
    //                     permanentCount=max(count,permanentCount);
    //                     count=0;
    //                 }
    //         }
    //     }
    //     return max(count,permanentCount);


    //above approach is failed as we couldn't solve it using the characters

    //##NOTE##- WE CAN INSTEAD push the index if '(' and then pop out the index if ')' and keep doing and at last the actual value of the valid substring is i-stk.top();

    //initial state must be pushed with -1 of the stack and then we can subseqeutnly push the index it could handle all the cases;

    //I am doing a left and right pass (two pass strategy)
    int left=0,right=0,maxlength=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(') left++;
        else if(s[i]==')') right++;
        if(right>left){
            //to tackle ')(' this cases
            left=right=0;
        }

        if(left==right) {
            maxlength=max(maxlength,2*left); 
        }
    }
    left=right=0;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]=='(') left++;
        else if(s[i]==')') right++;
        if(right<left){
            //to tackle ')(' this cases
            left=right=0;
        }

        if(left==right) {
            maxlength=max(maxlength,2*left); 
        }
    }
    return maxlength;

    }
};