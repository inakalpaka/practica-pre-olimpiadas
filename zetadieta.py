import math
def zetadieta (C,P,G):
    banana = [27,105]
    atun = [30,120]
    aceite = [1,9]
    return (math.ceil(C/banana[0])*banana[1]) + math.ceil((P/atun[0])*atun[1]) + math.ceil((G/aceite[0])*aceite[1])

print(zetadieta(88,90,50))
print(zetadieta(0,0,999))
print(zetadieta(0,999,0))
print(zetadieta(999,0,0))
print(zetadieta(999,999,999))