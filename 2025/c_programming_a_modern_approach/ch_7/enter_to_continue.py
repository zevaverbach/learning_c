i = 1
while True:
    if i % 1_000_000 == 0:
        print("press ENTER to continue...")
        while input() != "":
            continue
    print(i)
    i += 1
