amount = 1011

num_20s = amount // 20
amount -= num_20s * 20
num_10s = amount // 10
amount -= num_10s * 10
num_5s = amount // 5
amount -= num_5s * 5
num_1s = amount

print("$20 bills: %.0f" % num_20s)
print("$10 bills: %.0f" % num_10s)
print("$5 bills: %.0f" % num_5s)
print("$1 bills: %d" % num_1s)
