#define P pair<int,int>
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();
        queue<P> q;
        vector<vector<int>> best(n, vector<int>(m, -1));
        int startHealth=health-grid[0][0];
        if(startHealth<1) return false;
        q.push({0,0});
        best[0][0] = startHealth;
       
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            int h=best[r][c];

            q.pop();
            if(r==n-1 && c==m-1 && h>=1) return true; 
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr<n && nc<m && nr>=0 && nc>=0){
                    int newHealth=h-grid[nr][nc];

                    if(newHealth>=1 && newHealth > best[nr][nc]){
                        q.push({nr,nc});
                        best[nr][nc]=newHealth;
                    }
                }
            }
        }
        return false;
    }
};