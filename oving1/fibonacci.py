def isFibonacciNumber(n):
    a = 0;
    b = 1;
    while b < n:
        a, b = b, a + b
    return b == n

print(isFibonacciNumber(7))