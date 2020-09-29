def permutation(arr):
    ret = [[] for _ in range(len(arr))]

    # 1<= 부분집합 갯수 <= 전체
    for i in arr:
        ret[0].append([i])

    for i in range(1, len(ret)):
        # ret[i-1]에 그 뒤의 idx에 있는 원소를 하나씩 늘려간다.
        q = ret[i-1].copy()
        while q:
            el = q.pop()
            idx = arr.index(el[-1])
            for cp_idx in range(idx+1, len(arr)):
                ret[i].append(el+[arr[cp_idx]])
    
    print(ret)

if __name__ == "__main__":
    permutation([1,2,3,4,5])