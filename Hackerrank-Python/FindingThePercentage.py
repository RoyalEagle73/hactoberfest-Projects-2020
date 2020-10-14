def find_avg_marks(student_marks,query_name):
    avg_marks=sum(student_marks[query_name])/len(student_marks[query_name])
    return avg_marks

if __name__ == '__main__':
    n = int(input())
    student_marks = {}
    for _ in range(n):
        name, *line = input().split()
        scores = list(map(float, line))
        student_marks[name] = scores
    query_name = input()
    result = find_avg_marks(student_marks,query_name)
    print("{:.2f}".format(result))
