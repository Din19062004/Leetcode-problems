class Solution {
private:
    struct point {
        int row;
        int col;
        int step;
    };
public:
    bool reachTarget(vector<vector<char>> &maze, vector<int> &entrance, int curRow, int curCol) {
        int r = maze.size(), c = maze[0].size();
        int r0 = entrance[0], c0 = entrance[1];
        return (curRow != r0 || curCol != c0) && (curRow == 0 || curCol == 0 || curRow == r - 1 || curCol == c - 1);
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<vector<bool>> visited(100, vector<bool>(100, 0));
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
        int r = maze.size(), c = maze[0].size();
        point p;
        p.row = entrance[0];
        p.col = entrance[1];
        p.step = 0;
        visited[p.row][p.col] = 1;
        queue<point> q;
        q.push(p);

        while(!q.empty()) {
            point p1 = q.front();
            int curRow = p1.row;
            int curCol = p1.col;
            int curStep = p1.step;
            q.pop();

            if(reachTarget(maze, entrance, curRow, curCol)) {
                return curStep;
                break;
            }

            for(int i = 0; i < 4; i++) {
                int newRow = curRow + dx[i];
                int newCol = curCol + dy[i];

                if(newRow >= 0 && newCol >= 0 && newRow <= r - 1 && newCol <= c - 1 
                    && visited[newRow][newCol] == 0 && maze[newRow][newCol] != '+') {
                        point p2;
                        p2.row = newRow;
                        p2.col = newCol;
                        p2.step = curStep + 1;
                        q.push(p2);
                        visited[newRow][newCol] = 1;
                }
            }
        }
        return -1;
    }
};
