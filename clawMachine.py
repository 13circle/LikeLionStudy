board = [[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]]
moves = [1,5,3,5,1,2,1,4]

def solution(board, moves):
    answer = 0
    bucket = []
    for j in moves:
        for i in range(len(board)):
            if board[i][j-1] != 0:
                bucket.append(board[i][j-1])
                board[i][j-1] = 0
                break
        if len(bucket) > 1:
            print(bucket)
            if bucket[-1] == bucket[-2]:
                bucket.pop()
                bucket.pop()
                answer = answer + 2
    return answer

print(solution(board, moves))