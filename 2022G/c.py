# This is a translation of my cpp code as I think that it didn't
# work due to the numbers getting too large for it to handle
# I think I can just play around with the bound size to pass
# I get tle with python as it is just too slow
# This doesn't work properly as I ditched it to work on the cpp
# version as python is too slow to get this to pass

f = open("ts2_input.txt","r")

INT_MIN = -1e11
t = int(f.readline())

# Defines the part class to make things easier
class Part:
    def __init__(self, tot, req, mult):
        self.tot = tot
        self.req = req
        self.mult = mult

for test in range(1,t+1,1):
    if test > 2:
        break
    print("Case #"+str(test)+": ",end="")

    n = int(f.readline())
    a = [int(i) for i in f.readline().split()]
    bound = 800

    # Adds in the extra elements
    a.reverse()
    while n%bound:
        n += 1
        a.append(INT_MIN)
    a.reverse()

    # Generates all of the parts
    parts = []
    for i in range(0, n, bound):
        c = i//bound
        current = Part(0,0,0)
        for j in range(i, i+bound, 1):
            current.mult += a[j]*(i+bound-j)
            current.tot += a[j];
            current.req = min(current.req,current.tot)
        parts.append(current)

    out = 0
    for i in range(n):
        print(i,"out of",n)
        subtot = 0
        totals = []

        # Does the starting bit
        current = 0; ctot = 0; pos = i
        while pos < n and pos % bound:
            current += a[pos]
            if current < 0:
                break
            ctot += current
            pos += 1
        totals.append(ctot)

        if current < 0:
            subtot += ctot
            out += subtot
            continue

        # Does the middle bit
        partPos = pos//bound
        while partPos < len(parts):
            if current + parts[partPos].req < 0:
                break
            current += parts[partPos].tot;
            totals.append(parts[partPos].mult)
            partPos += 1

        # Does the ending bit
        lastTot = 0
        pos = partPos*bound
        while pos < n:
            current += a[pos]
            if current < 0:
                break
            lastTot += current
            pos += 1

        # Adds everything up
        subtot += lastTot
        offset = 1+pos - partPos*bound
        for j in range(len(totals)-1,-1,-1):
            subtot += offset*totals[j]
            offset += bound

        out += subtot

    print(out)

f.close()
