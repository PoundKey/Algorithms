arr = [5, 3, 9, 21, 10, 2]

def qsort(alist):
	if (len(alist) <= 1):
		return alist
	else:
		pivot = alist[0]
		left = [x for x in alist[1:] if x < pivot]
		right = [x for x in alist[1:] if x >= pivot]
		return qsort(left) + [pivot] + qsort(right)

print(arr)
print(qsort(arr))
