n,s = [int(x) for x in input().split()]

def solve(n,s):
  if s&1:
    return 0
  s = s//2
  dp = [[0]*501 for _ in range(51)]

  dp[0][0] = 1
  
  for i in range(1,n+1):
    for j in range(s+1):
      for l in range(10):
        if j-l<0: continue
        dp[i][j] += dp[i-1][j-l]
  
  return dp[n][s]

print(solve(n,s)**2)