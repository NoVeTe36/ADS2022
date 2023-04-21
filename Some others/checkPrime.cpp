bool isPrime(int a) {
    int count = 0;
    if (a == 1 || a == 0) {
        return 0;
    }
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) {
            count++;
        }
    }
    if (count == 0) {
        return true;
    }
    if (count != 0) {
        return false;
    }
}