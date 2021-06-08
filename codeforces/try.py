if __name__ == '__main__':
    t = int(input())
    while t > 0 :
        t = t - 1
        a =  input().split()
        n = int(a[0])
        k = int(a[1])
        print(str((n**k)%(10**9 + 7))+"\n")
        
