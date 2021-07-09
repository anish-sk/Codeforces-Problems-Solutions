import functools

p=100000000

@functools.lru_cache(maxsize= None)
def f(n1,n2,k1,k2):
    global c
    global d
    if(n1==0):
        return int(n2<=k2)
    if(n2==0):
        #print('hi')
        return int(n1<=k1)
    if(k1==0):
        return f(n1,n2-1,c,k2-1)%p
    if(k2==0):
        return f(n1-1,n2,k1-1,d)%p
    return (f(n1-1,n2,k1-1,d)+f(n1,n2-1,c,k2-1))%p

a,b,c,d=map(int,input().split())
#print(n1,n2,k1,k2)
print((f(a,b,c,d))%p)
