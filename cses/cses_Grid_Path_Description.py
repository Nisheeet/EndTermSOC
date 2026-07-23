paths = []
directions = {
    'L': (-1,  0),
    'R': ( 1,  0),
    'U': ( 0, -1),
    'D': ( 0,  1),
}

valid = "LRUD"
n=7
lm=48

templ = '?'*lm
board = [
    [0,1,1,1,1,1,1,1],
    [1,1,1,1,1,1,1,1],
    [1,1,1,1,1,1,1,1],
    [1,1,1,1,1,1,1,1],
    [1,1,1,1,1,1,1,1],
    [1,1,1,1,1,1,1,1],
    [1,1,1,1,1,1,1,1],
    [1,1,1,1,1,1,1,1],
]

def move(moves=[' ' for i in range(48)],cx=0,cy=0,left=lm):
    if left==0:
        if cx==0 and cy==7:
            paths.append(moves)       
        return
    
    touse = valid if templ[lm-left] == '?' else templ[lm-left]
    for turn in touse:
        h = directions[turn][0]
        v = directions[turn][1]
        nx = cx+h
        ny = cy+v
        if nx >= 0 and nx < n and ny >= 0 and ny < n and board[nx][ny]==1:
            board[nx][ny] = 0
            moves[lm-left] = turn
            move(moves,nx,ny,left-1)
            moves[lm-left] = ' '
            board[nx][ny] = 1
    return

t = input()
move()
print(len(paths))