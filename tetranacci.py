
def calc_tetranacci(k):
	tn_arr=[0,0,0,1]
	if k<len(tn_arr):
		return tn_arr[k]
	k = k-3
	curr_sum = 1
	curr_start = 0
	while k:
		curr_tn = curr_sum
		if k==1:
			return curr_tn
		curr_sum=curr_sum+curr_tn-tn_arr[curr_start]
		tn_arr[curr_start] = curr_tn
		curr_start = curr_start+1
		if curr_start == 4:
			curr_start = 0
		k=k-1

for i in range(4,100):
	tet = calc_tetranacci(i)
	print(f"Tetranacci {i}={tet}")
	print(tet==sum([calc_tetranacci(i-1),calc_tetranacci(i-2),calc_tetranacci(i-3),calc_tetranacci(i-4)]))
