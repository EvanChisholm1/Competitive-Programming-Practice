# def createMatrix(width, height):
#     matrix = {}
#     for x in range(0, width):
#         for y in range(0, height):
#             matrix[(x,y)] = False

#     return matrix

def paintLine(rows, cols, direction, pos): 
    # if it is a c go down that column and flip each cell from black to gold or gold to black
    # create matrix m
    realpos = pos - 1
    if direction == 'C':
        cols[realpos] += 1
    else:
        rows[realpos] += 1

    # if direction == 'C':
    #     for y in range(0, height):
    #         matrix[(realpos, y)] = not matrix[(realpos, y)]
    # else:
    #     for x in range(0, width):
    #         matrix[(x, realpos)] = not matrix[(x, realpos)]

def countGold(rows, cols):
    count = 0
    for col in cols:
        for row in rows:
            if row + col % 2 == 1:
                count += 1
    # for x in range(0, width):
    #     for y in range(0, height):
    #         if matrix[(x, y)]:
    #             count += 1
    return count 


# read inputs m and n on 2 lines
n = int(input())
m = int(input())
cols = [0] * m
rows = [0] * n

# create a matrix with a width M and height N
# canvas = createMatrix(m, n)

# read input K 
k = int(input())

# loop for k times
for i in range(0, k):
    # read input
    inputStr = input()
    direction = inputStr.split()[0]
    position = int(inputStr.split()[1])
    paintLine(rows, cols, direction, position)

amountOfGold = countGold(rows, cols)
print(amountOfGold)
