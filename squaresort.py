import math

def is_square(k):
	return math.sqrt(k).is_integer()
def partition_squares_first(dat):
	start = 0
	end = len(dat)-1
	while start<end:
		while is_square(dat[start]):
			start = start+1
		while not is_square(dat[end]):
			end = end-1
		if start<end:
			tmp = dat[start]
			dat[start] = dat[end]
			dat[end] = tmp
dat = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]
print(dat)
partition_squares_first(dat)
print(dat)
