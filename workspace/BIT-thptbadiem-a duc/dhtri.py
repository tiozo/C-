def backdiff3_120(n):
  return 3 * ( 1 + [0,1,1,1][n % 4] + 2*[0,1][n % 2] )

def backdiff3_90(n):
  return 6 * ( 1 + [1,2][n % 2] + [0,1,1][n % 3] + [0,2,1,1,2][n % 5] )

def backdiff3_60(n):
  return 1 + [0,1][n % 2] + 6 * [0,1,1][n % 3] + 2 * (n>1)

d0 = d1 = d2 = 0
for i in range(0,10):
  d3 = backdiff3_120(i) + backdiff3_60(i) + backdiff3_90(i)
  d2 = d2 + d3
  d1 = d1 + d2
  d0 = d0 + d1
  n = i+1
  ap = ((n * 839./120. + 1039./80.) * n + 11./30.) * n
  a60 = n*(n+2)*(2*n+1)/8 + 2*((3*n*n - 1)*n/6)        ## exact with int
  a120= 3*(((22*n+45)*n-4)*n/48)                       ## exact with int
  a90 = 6*(n*(n+1)*(n+2)/6 + (((2*n+5)*n+2)*n)/8 + (((2*n+3)*n-3)*n)/18 + ((2*n+3)*n-3)*n/10) ## exact
  aa = a60 + a90 + a120
  print(n, d3, d2, d1, d0, aa, ap, ap-d0)
