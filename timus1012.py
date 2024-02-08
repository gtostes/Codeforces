# n,k = [int(x) for x in input().split()]
n = int(input())
k = int(input())

nz = k-1
z = 0
for _ in range(n-1):
  nz_ = (k-1)*(nz+z)
  z = nz
  nz = nz_

print(nz+z)
