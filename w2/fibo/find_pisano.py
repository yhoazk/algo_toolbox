#!/usr/bin/python
'''
This works only when the sequence is smaller than n.
We need to loop until we find the sequence.
'''
def fib_seq(n, m):
    a=0; b=1; c=int; found=0; i =0
    if n <= 1:
        return n
    else:
        while found < 2:
            c = (a + b) % m
            if([a,b,c] == [0,1,1]):
                found +=1
                if found == 2:
                    print(i)
            a=b; b=c
            i+=1
        return a

if __name__ == '__main__':
    n, m = map(int,raw_input().split(" "))
    fib_seq(n,m)


## for i in {1..50}; do echo $i $i | ./find_pisano.py; done
#http://webspace.ship.edu/msrenault/fibonacci/fib.htm
