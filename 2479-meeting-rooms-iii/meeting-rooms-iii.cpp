#define P pair<long long,int>

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) { 
        if (a[0] == b[0])
            return (a[1] < b[1]);
        return (a[0] < b[0]);
    }

    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> roomUsedCount(n,0);

        priority_queue<int, vector<int>, greater<int>> availableRooms;
        priority_queue<P, vector<P>, greater<P>> pq;

        //initialise PQ
        for(int i=0;i<n;i++){
            availableRooms.push(i);
        }

        sort(meetings.begin(),meetings.end(),cmp); //sort the meetings array

        int m=meetings.size();

        for(int i=0;i<m;i++){
            long long startTime=meetings[i][0];
            long long endTime=meetings[i][1];
            long long duration=endTime-startTime;

            while(!pq.empty() && pq.top().first<=startTime){
                int roomID=pq.top().second;
                pq.pop();
                availableRooms.push(roomID);
            }

            if(!availableRooms.empty()){
                int roomID=availableRooms.top();
                availableRooms.pop();

                roomUsedCount[roomID]++;
                pq.push({endTime,roomID});
            }
            else{
                //if room is not available then delay the meeting
                long long currEndTime=pq.top().first;
                int roomID=pq.top().second;
                pq.pop();

                roomUsedCount[roomID]++;
                pq.push({currEndTime+duration,roomID});
            }
        }

        int firstMaxi=0;

        //calculate the max first max encountered in the roomUsedCount
        for(int i=0;i<n;i++){
            if(roomUsedCount[i]>roomUsedCount[firstMaxi]){
                firstMaxi=i;
            }
        }

        return firstMaxi; 
    }
};