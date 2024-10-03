class Solution {
public: 
    struct state {
        int currX, currY, step;
    };

    bool reachTarget(int currX, int currY, int target) {
        return currX == target || currY == target || currX + currY == target;
    }

    int newStateOfX(int currX, int currY, int x, int y, int k) {
        int x1;
        if(k == 1) x1 = x;
        else if(k == 2) x1 = currX;
        else if(k == 3) x1 = 0;
        else if(k == 4) x1 = currX;
        else if(k == 5) x1 = currX + currY - y;
        else if(k == 6) x1 = x;
        else if(k == 7) x1 = 0;
        else if(k == 8) x1 = currX + currY;
        return x1;
    }

    int newStateOfY(int currX, int currY, int x, int y, int k) {
        int y1;
        if(k == 1) y1 = currY;
        else if(k == 2) y1 = y;
        else if(k == 3) y1 = currY;
        else if(k == 4) y1 = 0;
        else if(k == 5) y1 = y;
        else if(k == 6) y1 = currX + currY - x;
        else if(k == 7) y1 = currX + currY;
        else if(k == 8) y1 = 0;
        return y1;
    }

    bool canMeasureWater(int x, int y, int target) {
        vector<vector<int>> visited(x + 1, vector<int>(y + 1, 0));

        queue<state> q;
        state s;
        s.currX = 0;
        s.currY = 0;
        s.step = 0;
        q.push(s);
        visited[s.currX][s.currY] = 1;

        while(!q.empty()) {
            state s1 = q.front();
            int tempX = s1.currX;
            int tempY = s1.currY;
            int tempStep = s1.step;
            q.pop();

            if(reachTarget(tempX, tempY, target)) {
                return true;
                break;
            }

            for(int k = 1; k <= 8; k++) {
                int newX = newStateOfX(tempX, tempY, x, y, k);
                int newY = newStateOfY(tempX, tempY, x, y, k);
                if(newX >= 0 && newY >= 0 && newX <= x && newY <= y && visited[newX][newY] == 0) {
                    state s2;
                    s2.currX = newX;
                    s2.currY = newY;
                    s2.step = tempStep + 1;
                    visited[newX][newY] = 1;
                    q.push(s2);
                }
            }
        }
        return false;
    }
};
