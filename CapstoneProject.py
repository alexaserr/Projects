# project.py
# Alfonso Pineda and Alexa Serrano
# Capstone Project starter code

import random

# k is black king
# Q is white queen
# K is white king


def switchStamp(s):
    if s == "@":
        s = "#"
    else:
        s = "@"
    return s


def makeBoard():
    board = []
    stamp = "@"
    for r in range(8):
        row = []
        for c in range(8):
            row.append(stamp)
            stamp = switchStamp(stamp)
        board.append(row)
        stamp = switchStamp(stamp)
    return board


def printBoard(board):
    for r in range(8):
        for c in range(8):
            print(board[r][c], end=" ")
        print()


def setBoard(board):
    rowK = random.randrange(0, 8)
    colK = random.randrange(0, 8)
    board[rowK][colK] = "K"

    rowk = random.randrange(0, 8)
    colk = random.randrange(0, 8)

    diffR = abs(rowK - rowk)  #Valor absoluto
    diffC = abs(colK - colk)

    while diffR < 2 and diffC < 2:
        #print("Discarded", rowK, colK, rowk, colk)
        rowk = random.randrange(0, 8)
        colk = random.randrange(0, 8)

        diffR = abs(rowK - rowk)
        diffC = abs(colK - colk)

    board[rowk][colk] = "k"

    rowQ = random.randrange(0, 8)
    colQ = random.randrange(0, 8)

    while (rowQ == rowK and colQ == colK) or (rowQ == rowk and colQ == colk):
        rowQ = random.randrange(0, 8)
        colQ = random.randrange(0, 8)

    board[rowQ][colQ] = "Q"

    return board


# Recieves the board matrix and the piece to look for.
# Returns a list two elements, containing the row and column (coordinates) of the piece.
# If it doesn't find the piece, it will return None.
def findPiece(board, piece):
    for r in range(8):
        for c in range(8):
            if board[r][c] == piece:
                return [r, c]
    return None


# Returns True if pos is inside the board
# Returns False if
def inBounds(pos):
    if pos[0] >= 0 and pos[0] <= 7 and pos[1] >= 0 and pos[1] <= 7:
        return True
    else:
        return False


def isAnyOutOfBounds(positions):
    for p in positions:
        if inBounds(p) == False:
            return True
    return False


def checkBoard(board):
    # Plan:
    # 1. Find out if k is in check.
    # 2. Print a list of possible moves for k.

    #Checkmate and Check
    check = False
    checkmate = False

    # About k.
    posk = findPiece(board, 'k')
    rk = posk[0]
    ck = posk[1]

    positionsk = [[rk, ck + 1], [rk - 1, ck + 1], [rk - 1, ck], [rk - 1, ck - 1],
                  [rk, ck - 1], [rk + 1, ck - 1], [rk + 1, ck],
                  [rk + 1, ck + 1]]

    # k can't move outside the board.
    while isAnyOutOfBounds(positionsk):
        for pos in positionsk:
            if inBounds(pos) == False:
                positionsk.remove(pos)

    # About K.
    posK = findPiece(board, 'K')
    rK = posK[0]
    cK = posK[1]

    positionsK = [[rK, cK + 1], [rK - 1, cK + 1], [rK - 1, cK], [rK - 1, cK - 1],
                  [rK, cK - 1], [rK + 1, cK - 1], [rK + 1, cK],
                  [rK + 1, cK + 1]]

    # K can't move outside the board.
    while isAnyOutOfBounds(positionsK):
        for pos in positionsK:
            if inBounds(pos) == False:
                positionsK.remove(pos)

    # For Q.
    posQ = findPiece(board, 'Q')

    r = posQ[0]
    c = posQ[1]

    positionsQ = []

    rQ = r
    cQ = c

    # Q can't move outside the board.
    while isAnyOutOfBounds(positionsQ):
      for pos in positionsQ:
          if inBounds(pos) == False:
              positionsQ.remove(pos)

    # Queen - Right
    for cQ in range(c + 1, 8):
        if board[rQ][cQ] == 'k':
            check = True
        if board[rQ][cQ] == 'K':
            break
        positionsQ.append([rQ, cQ])

    # Queen - Left
    for cQ in range(c - 1, -1, -1):
        if board[rQ][cQ] == 'k':
            check = True
        if board[rQ][cQ] == 'K':
            break
        positionsQ.append([rQ, cQ])

    # Queen - Up
    rQ = r
    cQ = c
    for rQ in range(r - 1, -1, -1):
        if board[rQ][cQ] == 'k':
            check = True
        if board[rQ][cQ] == 'K':
            break
        positionsQ.append([rQ, cQ])

    # Queen - Down
    for rQ in range(r + 1, 8):
        if board[rQ][cQ] == 'k':
            check = True
        if board[rQ][cQ] == 'K':
            break
        positionsQ.append([rQ, cQ])

    # Queen - DUR
    rQ = r - 1
    cQ = c + 1
    while rQ > -1 and cQ < 8:
        # See if k is here
        # See if K is here
        if board[rQ][cQ] == 'k':
            check = True
        if board[rQ][cQ] == 'K':
            break
        positionsQ.append([rQ, cQ])
        rQ -= 1
        cQ += 1

    # Queen - DUL
    rQ = r - 1
    cQ = c - 1
    while rQ > -1 and cQ > -1:
        # See if k is here
        # See if K is here
        if board[rQ][cQ] == 'k':
            check = True
        if board[rQ][cQ] == 'K':
            break
        positionsQ.append([rQ, cQ])
        rQ -= 1
        cQ -= 1

    # Queen - DDR
    rQ = r + 1
    cQ = c + 1
    while rQ < 8 and cQ < 8:
        # See if k is here
        # See if K is here
        if board[rQ][cQ] == 'k':
            check = True
        if board[rQ][cQ] == 'K':
            break
        positionsQ.append([rQ, cQ])
        rQ += 1
        cQ += 1  ###Warning!

    # Queen - DDL
    rQ = r + 1
    cQ = c - 1
    while rQ < 8 and cQ > -1:
        # See if k is here
        # See if K is here
        if board[rQ][cQ] == 'k':
            check = True
        if board[rQ][cQ] == 'K':
            break
        positionsQ.append([rQ, cQ])
        rQ += 1
        cQ -= 1

    # removing moves of Q and K for k.
    for elem in positionsk:
        if elem in positionsK or elem in positionsQ:
            positionsk.remove(elem)
    for elem in positionsk:
        if elem in positionsQ or elem in positionsK:
            positionsk.remove(elem)
    for elem in positionsk:
        if elem in positionsK or elem in positionsQ:
            positionsk.remove(elem)
    for elem in positionsk:
        if elem in positionsQ or elem in positionsK:
            positionsk.remove(elem)
    for elem in positionsk:
        if elem in positionsK or elem in positionsQ:
            positionsk.remove(elem)
    for elem in positionsk:
        if elem in positionsQ or elem in positionsK:
            positionsk.remove(elem)
    for elem in positionsk:
        if elem in positionsK or elem in positionsQ:
            positionsk.remove(elem)
    for elem in positionsk:
        if elem in positionsQ or elem in positionsK:
            positionsk.remove(elem)

    if len(positionsk) == 0 and check == True:
        checkmate = True

        #  [    #0,      #1,       #2   ]
    return [positionsk, check, checkmate]

#####

# Game Menu.
b = []
choice = int(input())

if choice == 1:
    b = makeBoard()
    b = setBoard(b)
elif choice == 2:
    for r in range(8):
        line = input()
        line = line.strip()
        row = line.split(" ")
        b.append(row)
printBoard(b)

movesk = checkBoard(b)
print("Black King Moves:", movesk[0])
print("Check:", movesk[1])
print("Checkmate:", movesk[2])