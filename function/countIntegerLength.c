
int countIntegerLength(int x) {
    int count = 1;
    while(x > 9) {
        x = x/10;
        count++;
    }
    return count;   
}