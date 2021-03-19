import sympy
import random
list_2 = random.sample(range(100, 900), 100)
even_list = []
odd_list = []
prime_list = []
# random.randint(100, 900)
print(list_2)
even_count, odd_count, prime_count = 0, 0, 0

# iterating each number in list
for num in list_2:
    # checking condition
    if sympy.isprime(num):
        prime_count += 1
        prime_list.append(num)

    elif num % 2 == 0:
        even_count += 1
        even_list.append(num)

    else:
        odd_count += 1
        odd_list.append(num)
print(even_count, odd_count, prime_count)
print(prime_list, even_list, odd_list)
