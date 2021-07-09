R,G = map(int, input().split())
if G > R:
    R,G = G,R
    


def f(h,r):
    global R,G
    g = h*(h+1)/2 - R + r
    if h==0 and r == 0 and g == 0:
        return 1
    elif h == 0:
        return 1        
    else:
        a = r - h
        b = g
        if b>a:
            a,b = b,a
        c = 0
        if a>=0 and b>=0:
            c = f(h-1, a)
        a = g - h
        b = r
        if b > a:
            a,b  = b,a
        d = 0
        if a>=0 and b>=0:
            d = f(h-1, a)
        return c+d

dp = [0]*1000

for i in range(900):
    dp[i] = f(i,R)

ans = 0
for i in range(900, -1, -1):
    if dp[i] > 0:
        ans = dp[i]
        break

print(ans)
