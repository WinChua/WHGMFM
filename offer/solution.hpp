#ifndef SOLUTION_H
#define SOLUTION_H
// use bit operation to perform add;
int aplusb(int a, int b) {
    while(a) {
       b = a ^ b;
       a = (a & (~b)) << 1;
    }
    return b;
}
#endif // SOLUTION_H
