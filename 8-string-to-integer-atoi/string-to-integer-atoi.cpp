
class Solution {
public:
    int myAtoi(string s) {
        // first is to eat all the leading space
        int i = 0;
        char symbol;
        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        // all leading zeroes eaten now it's time to check if there is any
        // symbol or not
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            symbol = s[i];
            i++;
        } else {
            symbol = '+';
        }

        // ignore the leading zeroes
        while (i < s.length() && s[i] == '0') {
            i++;
        }
        long long res = 0;
          while (i < s.length() && isdigit(s[i])) {
              // Check for overflow before updating res
              if (res > (LLONG_MAX - (s[i] - '0')) / 10) {
                  if (symbol == '-') {
                      return INT_MIN;
                  } else {
                      return INT_MAX;
                  }
              }
              // so read and cout character by character
              res = (long long)(res * 10) + (long long)(s[i] - '0');
              i++;
          }

          if (symbol == '-') {
              if (res > (long long)INT_MAX + 1) {
                  return INT_MIN;
              }
              return (int)-res;
          } else {
              if (res > INT_MAX) {
                  return INT_MAX;
              }
              return (int)res;
          }
      }

};