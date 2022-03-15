def availableMoves(puzzle):
    zeroPlace = findZeroIdx(puzzle)
    possibleMoves = ['v', '^', '<', '>']
    if zeroPlace > 5:
        possibleMoves.remove('v')
    if zeroPlace < 3:
        possibleMoves.remove('^')
    if zeroPlace % 3 == 0:
        possibleMoves.remove('<')
    if zeroPlace % 3 == 2:
        possibleMoves.remove('>')
    return possibleMoves


def findZeroIdx(puzzle):
    for i in range(len(puzzle)):
        if puzzle[i] == 0:
            return i


def applyPlayerMove(puzzle, selected_move):
    zeroPlace = findZeroIdx(puzzle)
    if selected_move == 'v':
        puzzle[zeroPlace + 3], puzzle[zeroPlace] = puzzle[zeroPlace], puzzle[zeroPlace + 3]

    elif selected_move == '>':
        puzzle[zeroPlace + 1], puzzle[zeroPlace] = puzzle[zeroPlace], puzzle[zeroPlace + 1]

    elif selected_move == '<':
        puzzle[zeroPlace - 1], puzzle[zeroPlace] = puzzle[zeroPlace], puzzle[zeroPlace - 1]

    elif selected_move == '^':
        puzzle[zeroPlace - 3], puzzle[zeroPlace] = puzzle[zeroPlace], puzzle[zeroPlace - 3]
    return puzzle


def solved(puzzle):
    for i in range(len(puzzle)):
        if i != puzzle[i]:
            return False
    return True
