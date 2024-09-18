/* 
* The algorithm is quite simple here: 
* Step 1: Use "and" logic with 0x1 to show the last bits of both start and goal
* For example: start = 1010, (1010 & 0x1) = 0000, therefor the last bit of 1010 is 0
* Step 2: Compare two last bits of start and goal. If they're different, you will have to flip them to achieve goal
* For example: start = 1010, goal = 0111. After step 1, last bit of start is 0, last bit of goal is 1
* They're different at all, so we have to flip from 0 to 1 to achieve goal
* Step 3: Shift right bit of both start and goal and return to step 1 until both start and goal are 0
*/

int minBitFlips(int start, int goal) {
    int count = 0;
    while(start != 0 || goal != 0) {
        if((start & 0x1) != (goal & 0x1)) count++;
        start = start >> 1;
        goal = goal >> 1;
    }
    return count;
}
