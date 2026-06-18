class Solution {
public:
    double angleClock(int hour, int minutes) {
        double diff=minutes*0.5;
        double hrDeg=hour*30+diff;
        double minDeg=minutes*6;
        double ans=abs(minDeg-hrDeg);
        double ans_complement=360-ans;
        return min(ans_complement,ans);
    }
};