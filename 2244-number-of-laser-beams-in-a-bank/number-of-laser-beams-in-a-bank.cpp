class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        //so we need to count the ones in the string and keep it and move to next and then m*n gives the number of laserBeams if we found that there is no 1 on the next row then keep movving persistenting the count of last row, if found 1 on next row then do count and do m*n add to ans and forget the prev row count and move to next row.
        int prevRowCount=0; int ans=0;
        for(int i=0;i<bank.size();i++){
            int currentRowCount=0;
            int flag=0;
            for(int j=0;j<bank[i].length();j++){
                if(bank[i][j]=='1'){
                    //add to current row count
                    flag=1;
                    currentRowCount++;
                }
            }
            ans+=prevRowCount*currentRowCount;
            if(flag==1) prevRowCount=currentRowCount; // so we don't forgot prev row count if entire row having no security device.
        }
        return ans;
    }

};