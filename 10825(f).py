import sys
read = sys.stdin.readline

class Student :
    def __init__(self,name,lang,eng,math):
        self.name = name
        self.lang = lang
        self.eng = eng
        self.math = math
    def __lt__(self,other):
        if self.lang != other.lang :
            return self.lang > other.lang
        elif self.eng != other.eng :
            return self.eng < other.eng
        elif self.math != other.math :
            return self.math > other.math
        else:
            return self.name[0] < other.name[0]

n = int(input())
list = []
for _ in range(n):
    name, lang, eng , math = read().split()
    lang = int(lang); eng = int(eng); math = int(math)
    student = Student(name,lang,eng,math)
    list.append(student)
    list.sort()
for i in list:
    print(i.name)
