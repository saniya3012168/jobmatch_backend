
'''[1]fstring
size=int(input("Enter size="))
sq_m=size/10.8
print(f"{size} is of {sq_m:.2f} size")

[2]
l=["abc","xyz","cds"] 
t=("asd","fds","rfse")  
s={1,2,3,4} 
s.append("dfs")  will generate error appending is not allowed
print(s)

[3]set 'diff'
friend={"bob","rolf","anna"}
abroad={"tfgh","rolf"}
local=friend.difference(abroad)      differernce
print(local)
print(friend.union(abroad))         union 

[4]set intersection
arts={"abc","xyz","bob","rolf"}
science={"bob","abc"}
print(arts.intersection(science))  intersection

[5]boolean
friend={"Bob","rolf"}
abroad={"Bob","rolf"}
print(friend == abroad)
abroad=friend
print(friend is abroad)

[6] 'in' keyword
movie={"abc","xyz"}
user=input("Enter movie=")
print(user in movie)'

[7] 'in'keyword in if statement
num=7
user=input("if you want to play enter y=")
if user=='y':
    user_num=int(input("Enter no="))
    if(user_num==num):
        print("right")
    elif num-user_num in (1,-1):
        print("num is bet this tuple")
    else:
        print("Wrong")

        
[8] list        
num=[1,2,3]
double=[i*2 for i in num]
print(double)

friend=["Saniya","Abc","xyz"]
start_s=[i for i in friend if friend.startswith('s')]
print(start_s)

[9] dictionary

f={"rolf":24,"ads":36,"gtg":21}
f["rolf"]=32
print(f)

f=[
    {"name":"afds","age":23},
    {"name":"afds","age":23},
    {"name":"afds","age":23}
]
print(f[1]["name"])

student={"asd":56,"grfs":65,"ert":90}
for i in student:
    print(f"{i}:{student[i]}")

if "bob" in student:
    print(f"bob:{student[bob]}")
else:
    print("not a student")

print(sum(student.values())/len(student.values()))


[10] Tuple
people=[("bob",42),("abc",23),("xyz",32)]
for name,age in people:
    print(f"Name:{name},Age: {age}")

person=("bob",42,"mechanic")
name,_,profession= person
print(name,profession)

def sum( a , b):
    add=x+b
    print(add)
    
sum(10,20)

[11] lambda function
add=lambda x,y:x+y
print(add(12,2))

def double(x):
    print (2*x)
seq=[1,2,3,4]
double=map(double,seq)


[12]dict comperhension
users=[
    (0,"bob","passward"),
    (1,"rolf","gyfs"),
    (2,"abc","trg"),
]
username_mapping={user[1]: user for user in users}
print(username_mapping["bob"])


[13] unpacking parameters
def add(x,y):
    return x+y
num=[3,4]
print(add(*num))

[14] keyword arguments  
def name(**kwargs):
    print(kwargs)
name(name="bob",age=25)

def named(**kwargs):
    print(kwargs)

def nice(**kwargs):
    named(**kwargs)
    for arg, value in kwargs.items():
        print(f"{arg}:{value}")
nice(name="bob",age=25)

[15]Object oriented programming
student={"name":"Rolf","grades":(89,90,78,80)}

def avg(sequence):
    return sum(sequence)/len(sequence)
print(avg(student["grades"]))

                 OR

class Student:
    def __init__(self):
        self.name="rolf"

student=Student()
print(student.name)

[16]__str__ & __refr__ method:
class person:
    def __init__(self,name,age):
        self.name=name
        self.age=age
    def __str__(self):
        return f"person {self.name},{self.age} years old"
    def __repr__(self):
        return f"<person ({self.name} ,{self.age})>"
    
bob=person("bob",35)
print(bob)

[17] cls:
class test:
    def instancde_method(self):
        print(f"called {self}")
    @classmethod
    def method(cls):
        print(f"called{cls}")
test.method(cls)

class book:
    types=("hardcover","paperback")

    def __init__(self,name,book_type,wt):
        self.name=name
        self.book_type=book_type
        self.wt=wt 
    def __repr__(self):
        return f"<Book {self.name},{self.book_type}, weighing{self. weight}g"
    @classmethod
    def hardcover(cls,name,page_wt):
        return book(name,book.type[0],page_wt+100)
    
Book=book.hardcover("Harry potter",1500)


print(book.types)

[18]class composition
class bookshelf:
    def __init__(self,qty):
        self.qty=qty
    def __str__(self):
        return f"Bookshelf with {self.qty} book"
    
shelf=bookshelf(300)

class book(bookshelf):
    def __inti__(self,name,qty):
        super().__init__(qty)
        self.name=name

    def __str__(self):
        return f"book {self.name}"
    
Book = book("Harry potter",120)
print(Book)

[19] import python
import sys
print(sys.path)

from mymodule import divide
print(divide(10,2))
print(__name__)

[20] Error
def divide(dividend,divisor):
    if divisor==0 :
        raise ZeroDivisionError("divisro cannot be zero")
    return dividend/divisor
    
grades=[]
print("welcome to the avg grade program")
try:
    avg=divide(sum(grades),len(grades))
    print(f"average is {avg}")
except ZeroDivisionError as e:
    print("there is no gradees yet")'''

user={"name":"abc","access_level":"admin"}

def get_password():
    return "1234"

'''def secure(fun):
    def function():
        if user["access_level"]=="admin":
            return fun()
    return function

get_password = secure(get_password)
print(get_password())
'''
def secure():
    if user["access_level"]=="admin":
        return get_password()
    return None

print(secure())