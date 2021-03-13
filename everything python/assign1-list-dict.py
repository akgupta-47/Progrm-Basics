import re
import random

# question 1
eng = []
math = []
sci = []
it = []
maxLst = []
minLst = []
avgLst = []
for i in range(0, 4):
    eng.append(int(input()))
    math.append(int(input()))
    sci.append(int(input()))
    it.append(int(input()))


def findall(lst):
    print('the max marks in test is ', max(lst))
    print('the min marks in test is ', min(lst))
    print('the avg marks in test is ', sum(lst)/len(lst))
    maxLst.append(max(lst))
    minLst.append(min(lst))
    avgLst.append(sum(lst)/len(lst))


findall(eng)
findall(math)
findall(sci)
findall(it)

print('overall maximum is ', max(maxLst))
print('overall minimum is ', min(minLst))
print('overall average is ', sum(avgLst) / len(avgLst))

# question 2
print('Input your basic salary ')
# input function generally returns string so we have specify it as integer to apply comparison ooperators
Basic_Salary = int(input())
if Basic_Salary <= 10000:
    DA = (Basic_Salary * 80) / 100
    HRA = (Basic_Salary * 20) / 100
elif Basic_Salary <= 20000:
    DA = (Basic_Salary * 90) / 100
    HRA = (Basic_Salary * 25) / 100
elif Basic_Salary < 20000:
    DA = (Basic_Salary * 90) / 100
    HRA = (Basic_Salary * 25) / 100
Gross_Salary = Basic_Salary + DA + HRA
print(Gross_Salary)

# question 4
list_1 = [10, 20, 30, 40, 50, 60, 70, 80]
list_1.append(200)
list_1.append(300)
print(list_1)

list_1.remove(10)
list_1.remove(30)
print(list_1)

list_1.sort(reverse=True)
print(list_1)

# question 5
D = {1: "One", 2: "Two", 3: "Three", 4: "Four", 5: "Five"}
D[6] = 'Six'
D.update({7: "Seven"})
print(D)
D.pop(6)
del D[7]
print(D)
key = 5
if key in D.keys():
    print("present sir")
print(len(D))

# question 6
# new question about list
list_2 = random.sample(range(100, 900), 100)
# random.randint(100, 900)
print(list_2)
even_count, odd_count = 0, 0

# iterating each number in list
for num in list_2:
    # checking condition
    if num % 2 == 0:
        even_count += 1

    else:
        odd_count += 1
print(even_count, odd_count)


# concepts

nest_list = [[1, 2, 3], [4, 8, 7], [2, 9, 11], [5, 6, 7], [1, 15, 4]]
for i in nest_list:
    print(min(i), max(i))


def first_fun(name, lname):
    print(name + " "+lname + " ello there mate")


name = 'Chandler'
lname = 'bing'
first_fun(name, lname)


# this will give error for b
def newFun(a, b):
    print(a+b)


newFun(4)


def first_fun(name="Joey"):
    print(name+" ello there mate")


name = 'Chandler'
first_fun(name)
first_fun()


def listFun(iter_list_first):
    for i in iter_list_first:
        print(i)


iter_list_first = [1, 2, 3, 4]
listFun(iter_list_first)

# question 7


def comp_interest(p, r, t):
    Amount = p * (pow((1+r/100), t))
    Comp_I = Amount - p
    print("comp interest ", Comp_I)


comp_interest(10000, 4, 5)

# CLasses
'''
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def myfunc(self):
        print("Hello I am " + self.name)


p1 = Person("Ross", 25)
p1.myfunc()
'''
# question 8a


class Restraunt:
    def __init__(self, res_name, cuisine):
        self.res_name = res_name
        self.cuisine = cuisine

    def describe_res(self):
        print(self.res_name, self.cuisine)

    def open_res(self):
        print("We are open")


p1 = Restraunt("Sagar ratna", "South Indian")
p1.describe_res()
p1.open_res()

# question 3
password = "ChandlerBing@123"
flag = 0
passLen = len(password)
while True:
    if (passLen < 6 and passLen > 16):
        flag = -1
        break
    elif not re.search("[a-z]", password):
        flag = -1
        break
    elif not re.search("[A-Z]", password):
        flag = -1
        break
    elif not re.search("[$#@]", password):
        flag = -1
        break
    elif not re.search("[0-9]", password):
        flag = -1
        break
    else:
        flag = 0
        print("You got the password right!!")
        break

if flag == -1:
    print("you got the password wrong mate!!")
