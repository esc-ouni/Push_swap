import random

nums = list(range(0, 99)) # list of integers from 1 to 99
                           # adjust this boundaries to fit your needs
random.shuffle(nums)
print(*nums)
