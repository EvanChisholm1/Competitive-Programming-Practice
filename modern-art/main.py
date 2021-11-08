def createMatrix(width, height):
    matrix = {}
    for x in range(0, width):
        for y in range(0, height):
            matrix[(x,y)] = 'black'

    return matrix

def paintLine(matrix, direction, pos, width, height):
    # if it is a c go down that column and flip each cell from black to gold or gold to black
    # create matrix m
    if direction == 'C':
        for y in range(0, height):
            if matrix[(pos, y)] == 'black':
                matrix[(pos, y)] = 'gold'
            else:
                matrix[(pos, y)] = 'black'
    else:
        for x in range(0, width):
            if matrix[(x, pos)]== 'black':
                matrix[(x, pos)] = 'gold'
            else:
                matrix[(x, pos)] = 'black'

def countGold(matrix, width, height):
    count = 0
    for x in range(0, width):
        for y in range(0, height):
            if matrix[(x, y)] == 'gold':
                count += 1
    return count 

def printGrid(matrix, width, height):
    for y in range(0, height):
        row = 
        for



# read inputs m and n on 2 lines
m = int(input())
n = int(input())

# create a matrix with a width M and height N
canvas = createMatrix(m, n)

# read input K 
k = int(input())

# loop for k times
for i in range(0, k):
    # read input
    inputStr = input()
    direction = inputStr.split()[0]
    position = int(inputStr.split()[1])
    paintLine(canvas, direction, position, m, n)

amountOfGold = countGold(canvas, m, n)
print(amountOfGold)
