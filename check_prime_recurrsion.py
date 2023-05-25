def is_prime(n, divisor=2):
    # Base cases
    if n < 2:
        return False
    if n == 2:
        return True
    if n % divisor == 0:
        return False
    if divisor * divisor > n:
        return True
    
    # Recursive case
    return is_prime(n, divisor + 1)

# Test the function
limit = int(input("Enter the limit: "))

print("Prime numbers:")
for num in range(2, limit+1):
    if is_prime(num):
        print(num)
