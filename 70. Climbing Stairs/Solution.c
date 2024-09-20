/* Call T(n) is the number of ways to climb to n(th) stair
* If n == 0, T(n) = 0
* If n == 1, T(n) = 1
* If n > 1, to jump at the (n)th stair, you have two ways:
*** Climb 1 step from the (n - 1)th stair
*** Climb 2 steps from the (n - 2)th stair
*** Therefor: T(n) = T(n - 1) + T(n - 2)
*/


int climbStairs(int n) {
    int a = 0, b = 1, steps;
    if(n == 0) {
        steps = a;
    }
    else if(n == 1) {
        steps = b;
    }
    else {
        for(int i = 0; i < n; i++) {
            steps = a + b;
            a = b;
            b = steps;
        }
    }
    return steps;
}
