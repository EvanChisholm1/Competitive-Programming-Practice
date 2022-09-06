t = int(input())

def prime_sieve(num):
    prime_list = [True] * (num + 1)

    prime_list[0] = False 
    prime_list[1] = False

    for j, prime in enumerate(prime_list):
        if prime == True:
            for k in range(j * 2, len(prime_list), j):
                prime_list[k] = False

    return prime_list

largest_num = 0
nums = []

for i in range(0, t):
    num = int(input()) * 2
    nums.append(num)
    if num > largest_num:
        largest_num = num

prime_list = prime_sieve(largest_num)


for num in nums:
    for prime, isPrime in enumerate(prime_list):
        if isPrime == True:
            other_prime = num - prime
            if prime_list[other_prime] == True:
                print("{} {}".format(prime, other_prime))
                break

