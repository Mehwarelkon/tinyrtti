### tinyRTTI
##### tinyRTTI is a very small library made as a small run time type information _ R T T I _
###### how to use

tiny rtti is used through its data type RTTI_ANY which stores a typeid and a pointer to data 
 stack example 
 ```c
 #include "tinryrtti.h"
 int main(){
    int x=4;
    RTTI_ANY forX;
    forX.type=RTTI_INT;
    forX.data=$x;
    return 0;  
 }
 ```
here forX has the type int and the data 
in other functions you can check if "ANY" is the right type 

### built-in types 

the built in types are 
NONE
INT
FLOAT
DOUBLE
CHAR
STRING

### how do i use my own type 

to use your own type you create the type lets say Foo
then you use append_type that return an id 
see example
```c
#include "smallrtti.h"

typedef struct {
    int x;
    int y;
} Foo;

TypeID Foo_ID;

int main(){
    Foo_ID=append_type();
    Foo f={1,2};
    
    RTTI_ANY foo;
    foo.type=Foo_ID;
    foo.data=&f;
}
```
now foo is ready for use 


### how to use with functions 

using ANY with functions is easy 
create a function that accept "ANY" or "ANY"s with or with out other types
inside the function check is "ANY" or "ANY"s is the desired type
if not stop function or handle error or printf _ like always _
ex
```c
#include "smallrtti.h"

typedef struct {
    int x;
    int y;
} Foo;

void printFoo(RTTI_ANY any){
    if(any.type!=Foo_ID){
    printf("error : input not of type foo ");
    return;
    }
    printf("x:%d,y:%d",(*(Foo*)any.data).x,(*(Foo*)any.data).y);
}

TypeID Foo_ID;

int main(){
    Foo_ID=append_type();
    Foo f={1,2};
    
    RTTI_ANY foo;
    foo.type=Foo_ID;
    foo.data=&f;
    printFoo(foo);
}
```

in this function we check if "ANY" is type Foo
then we print it 

# TODO: 
have methos to basic functionality like print copy destroy for ease of heap use 
start from NONE =1 instead of 0 to keep 0 for uninitialized user types for ease of debugging 
