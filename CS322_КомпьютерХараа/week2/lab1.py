import statistics

# Лабораторийн даалгавар:

x = [[1, 2, 3, 4, 5],
     [21, 22, 23, 24, 25],
     [31, 32, 33, 34, 35]]

# matrix - aas column awna
def column(matrix, i):
    return [row[i] for row in matrix]

def exercise1():
    # 1. indexing болон slicing ашиглах
    print("ex1: ")
    print(x[1])
    print(x[0][2])
    print(x[2][1:3])
    print(x[0][0:5:2])
    print()
    print("============================================")
    print()
    # 2.
    y = [0, 0, 0]
    for i in range(len(y)):
        y[i] = cal_average(x[i]).__float__()
    print(y)
    print()
    print("============================================")
    print()
    # 3.
    z = [0, 0, 0, 0, 0]
    #  [17.66, 18.66, 19.66, 20.66, 21.66] // average of [1, 21, 31] = 17.66
    for i in range(len(z)):
       z[i] = round(statistics.mean(column(x, i)).__float__(),2)

    print(z)

xx = [1, 3, 5, 6, 7, 8, 6, 1, 2, 3]
y = [0, 0, 0, 0, 0, 0, 0, 0]

def exercise2():
    # 1.
    print("ex2: ")
    i = 0
    while(i < len(y)):
        y[i] = round(statistics.mean(xx[i:i+3]).__float__(), 2)

        i = i + 1

    print()
    print("{%0.2}".format(y))
    print()
    # 2.
    print(cal_average(xx))
    print(cal_average(y))

def cal_average(lst):
    sum_num = 0
    for t in lst:
        sum_num = sum_num + t

    avg = sum_num / len(lst)
    return avg

# Geriin daalgawar

def homework():
    w = []
    count = 0
    x = int(input("x too oruulna uu")) # 10
    y = int(input("y too oruulna uu")) # 2
    for i in range(x):
        w.append(int(input()))

    ynums = []

    for i in w:
        lst = map(int, str(i))
        if y in lst:
            count = count + 1

    print("y orson too: ", count)
    print("y toonuud: ", ynums)
    print("w: ", w)
    print("mean: ", statistics.mean(w))
    print("median: ", statistics.median(w))
    print("mode: ", statistics.mode(w))

if __name__ == '__main__':
    exercise1()
    exercise2()
    homework()
