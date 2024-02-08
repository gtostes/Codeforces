# n,k = [int(x) for x in input().split()][0:2]
n = int(input())
k = int(input())
m = int(input())

def mult(a, b, m):
    n = len(a)
    ans = [[0] * n for _ in range(n)]

    for i in range(n):
        for j in range(n):
            ans[i][j] = 0
            for k in range(n):
                ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]) % m

    for i in range(n):
        for j in range(n):
            a[i][j] = ans[i][j]

ans = [[1,0],[0,1]]

a = [[k-1,1],[k-1,0]]
for i in range(60):
  if (n>>i)&1:
    mult(ans,a,m)
  mult(a,a,m)

print((ans[1][0] + ans[1][1])%m)