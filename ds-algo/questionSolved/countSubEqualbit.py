subStr = input('enter bit string')
stack = []
count = 0
def countSub(sub):
    #to use vars from outside function use global keyword and redeclare
    global count
    for i in range(0, len(sub)):
        stack.append(sub[0])
        k=i+1
        push = 1
        pop = 0
        while ( len(stack) !=0 and k < len(sub)):
            if (sub[k] == sub[i]):
                stack.append(sub[k])
                push += 1
            else:
                stack.pop()
                pop += 1
            if (push == pop):
                count += 1
                break
            k += 1
    return count

print('total sub strings are ', countSub(subStr))
