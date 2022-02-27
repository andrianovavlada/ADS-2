// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    double a = value;
    while (n != 1) {
        value = value * a;
        n--;
    }
    return value;
}

uint64_t fact(uint16_t n) {
    if (n == 1)
        return 1;
    else
        return n * fact(n - 1);
}

double calcItem(double x, uint16_t n) {
    double y = 0;
    y = pown(x, n) / fact(n);
    return y;
}

double expn(double x, uint16_t count) {
    double y = 0;
    while (count != 0) {
        y = y + calcItem(x, count);
        count--;
    }
    y += 1;
    return y;
}

double sinn(double x, uint16_t count) {
    double y = 0;

    while (count != 1) {
        y = y + pown(-1, count - 1) * calcItem(x, 2 * count - 1);
        count--;
    }
    y += x;
    return y;
}

double cosn(double x, uint16_t count) {
    double y = 0;
    while (count != 1) {
        y = y + pown(-1, count - 1) * calcItem(x, 2 * count - 2);
        count--;   
    }
    y += 1;
    return y;
}
