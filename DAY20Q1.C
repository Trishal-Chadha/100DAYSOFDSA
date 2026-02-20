n = int(input())
arr = list(map(int, input().split()))

prefix_sum = 0
count = 0
freq = {0: 1}   # Important: handles subarrays starting from index 0

for num in arr:
    prefix_sum += num
    
    if prefix_sum in freq:
        count += freq[prefix_sum]
    
    freq[prefix_sum] = freq.get(prefix_sum, 0) + 1

print(count)