print("Welcome to the Number Guessing Game!")
target = int(input("Please enter the target number: "))

min = 1
max = 10

num = int(input("Please enter a number between " + str(min) + " and " + str(max) + ": "))
while num != target:
	if num > max or num < min:
		print("error!")
	elif num < target:
		min = num + 1
	elif num > target:
		max = num - 1
	num = int(input("Please enter a number between " + str(min) + " and " + str(max) + ": "))
print("Bingo!")
