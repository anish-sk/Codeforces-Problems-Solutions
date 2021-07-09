import functools

c=[[0 for _ in range(25)] for _ in range(25)]

@functools.lru_cache(maxsize=None)
def f(i,j,k):
    global c
    if i == n+1:
        if j == 0:
            return 0
        else:
            return -1
    elif j==0:
        return 0
        
    return max(f(i+1,j-1,i)+a[i]+c[k][i], f(i+1,j,k))
        


