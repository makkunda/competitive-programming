# ans is 648
x = 1
n = 1
while n<=100 :
	x=x*n
	n=n+1
sm = 0
print x
while x > 0 :
	t = x%10
	sm = sm + t
	x = x // 10
print sm