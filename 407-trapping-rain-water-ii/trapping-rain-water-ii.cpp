#include <vector>
#include <queue> // For std::priority_queue
#include <iostream> // For demonstration, if needed
using namespace std;

class Cell{
    public:
        int height, row, col; 
        Cell(int h,int r,int c):height(h),row(r),col(c){};
};

struct Compare {
   bool operator()(const Cell& a, const Cell& b) {
        return a.height > b.height; // min-heap
    }
};


class Solution {
public:

    bool check(int x,int y,int m,int n){
        return x>=0 && y>=0 && x<m && y<n; 
    }
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size(); //row

        if (m == 0) return 0;    
        int n=heightMap[0].size(); //col
        
        if (m < 3 || n < 3) return 0; 
        //I need to ensure water doesn't leak so i need to check the matrix value of left right front and back, if for ith block we need to check if possible to store water without leaking then left(i) > i and so on for others

        //We need to check start from 1st row and till N-1 rows as 0th row and Nth row should not be considered as leakage will be there      

        //That's the wrong we need to make a priority queue of the boundary value and comparator of the height.
        //Pop from the priority queue check in all four directions if the if not visited it means the cell of middle and if the height of it is less than the boundary height than the least boundary height which is poped in order already from minheap so boundaryheight-currentCellHeight is the volume of the water to be stored.
        
        long long  ans=0;
        //make the visited array
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        priority_queue<Cell, vector<Cell>, Compare> pq; //minHeap

        for (int c = 0; c < n; ++c) {
            pq.push(Cell(heightMap[0][c], 0, c));        // top edge
            pq.push(Cell(heightMap[m-1][c], m-1, c));    // bottom edge
            visited[0][c] = visited[m-1][c] = true;
        }
        for (int r = 1; r < m - 1; ++r) {
            pq.push(Cell(heightMap[r][0], r, 0));        // left edge
            pq.push(Cell(heightMap[r][n-1], r, n-1));    // right edge
            visited[r][0] = visited[r][n-1] = true;
        }


        int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}}; //row me, column me movement
        while(!pq.empty()){
            Cell cell=pq.top();
            pq.pop();
            for(int i=0;i<4;i++) //moving up,down,left,right from the least boundary cells
            {
                int x=cell.row+dir[i][0];
                int y=cell.col+dir[i][1];

                if(check(x,y,m,n) && visited[x][y]==false){
                    visited[x][y]=true;
                    if(cell.height > heightMap[x][y]){
                        ans+=cell.height-heightMap[x][y];
                        pq.push(Cell(cell.height, x, y));
                        
                    }
                    else{
                        pq.push(Cell(heightMap[x][y],x,y));

                    }
                    
                }
            }
        }

        return ans;




    }
};