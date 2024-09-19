int getSumOfAllDigits(int num) {
    int sum = 0;
    while(num > 0) {
        int temp = num % 10;
        num /= 10;
        sum += temp;
    }
    return sum;
}

int addDigits(int num) {
    int sum = getSumOfAllDigits(num);
    while(sum >= 10) {
        sum = getSumOfAllDigits(sum);
    }
    return sum;
}
