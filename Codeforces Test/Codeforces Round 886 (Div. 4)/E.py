t = int(input())


def check(x , arr):
	ans =0
	for i in arr:
		ans += (i + 2*x)*(i + 2*x)
		# print(ans)
	return ans

while(t):
	
	a= input().split()
	n = int(a[0])
	m = int(a[1])

	arr = [int(x) for x in input().split()]
	lo=1
	hi =1e18
	while(lo<=hi):
		mid = (int)(lo+hi)//2
		k = check(mid , arr)
		# print(lo , mid)
		if(k==m):
			print(mid)
			break
		elif(k<m):
			lo = mid+1
		else:
			hi= mid-1

	t-=1
