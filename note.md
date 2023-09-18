## Q1.the differences between malloc(),free() and delete,new:
## A1:
- malloc(): It is a C library function that can also be used in C++, while the “new” operator is specific for C++ only. 
- Both malloc() and new are used to allocate the memory dynamically in heap. But “new” does call the constructor of a class whereas “malloc()” does not.
- free() is a C library function that can also be used in C++, while “delete” is a C++ keyword.
- free() frees memory but doesn’t call Destructor of a class whereas “delete” frees the memory and also calls the Destructor of the class.

## Q2.当使用delete或者free后,内存空间被释放了,但是指向这片空间的指针的值没变,仍旧指向原本的地址,但这个地址已经不属于程序的有效内存空间了,于是这个指针成为了悬空指针
## A2:
使用free（L.data）后，L.data的内存空间被释放掉了，但是L.data的值并没有改变，它仍然指向原来的内存地址，只是这个地址已经不属于程序的有效内存空间了。这就是悬空指针的问题，如果再次使用L.data，可能会发生程序崩溃或者数据错误。为了避免这个问题，应该在释放内存后将L.data设为NULL，表示它不指向任何有效的内存空间。

## Q3.为什么释放内存空间后,这片空间的地址成为了无效地址
## A3：
这是因为当程序使用new或者malloc等函数分配内存时，操作系统会为程序分配一块内存空间，并记录这个空间的地址和大小。当程序使用delete或者free等函数释放内存时，操作系统会将这个空间的地址和大小从记录中删除，并将这个空间标记为可用，以便其他程序或者同一个程序的其他部分可以再次分配。因此，当程序释放了一块内存空间后，这个空间就不再属于程序的有效内存空间了，而是属于操作系统的可用内存空间了。

## Q4.为什么C++中为超过索引上限的数组元素赋值时没有报错
## A4:
因为C++中并没有检查越界的行为,只要你赋值时所使用的内存是有效内存,它就不会报错,当然,这样的赋值是不安全的

## Q5.malloc函数分配的内存属于堆区还是栈区
## A5:
堆区,栈区的内存由程序自动释放

## Q6.free函数如何确定要释放的内存由malloc分配
## A6:
- `malloc` 时多分配一些内存，用来存储实际分配的大小，`free` 时根据这个大小来释放内存。
- 用一个链表来记录 `malloc` 分配的内存地址和大小，`free` 时在链表中查找是否存在该地址。
- 用一些不可移植的平台相关的方法，比如检查内存地址是否在堆区范围内。
😊
一般来说，`free` 函数只能释放由 `malloc` 分配的内存，因为它需要根据 `malloc` 时存储的内存大小和地址来释放内存。如果 `free` 一个不是由 `malloc` 分配的内存，可能会导致未定义行为或者内存错误。

## Q7.typedef的使用方式
## A7:
对结构体使用typedef的语法是为了给结构体类型定义一个**别名**，方便在声明结构体变量时使用。一般的语法格式是：

```c++
typedef struct 结构体标签 {
    // 结构体成员
} 别名;
```
例如：
```c++
typedef struct Person {
    int age;
    char name[20];
} Per;
```

这样就可以用`Per`来代替`struct Person`来声明结构体变量，如：

```c++
Per p1;
```
也可以在定义结构体时省略结构体名，直接给出别名，如：
```c++
typedef struct {
    int age;
    char name[20];
} Per;
```
这样的话，就不能再用`struct`来声明结构体变量了，只能用`Per`。

## Q8.结构体的变量名
## A8:
struct在C语言中:
struct tag一起才是一个结构体名。使用tag去定义变量是非法的(虽然在一些编译器中可能也可以实现)。

而在C++中可以使用tag去定义变量，struct是C++对C语言的兼容，其实和Class区别不大，但在编码时使用struct时还是将它视作了C语言的struct而非class的替代品。

## Q8
在C++中，`.`和`->`是两个不同的运算符，它们都用于访问类或结构体的成员。`.`运算符用于访问类或结构体的成员，而`->`运算符用于访问指向类或结构体的指针的成员。例如，如果有一个名为`obj`的类实例，我们可以使用`obj.member`来访问该类的成员。如果有一个指向该类实例的指针，则可以使用`ptr->member`来访问该类的成员。此外，`::`运算符用于访问命名空间、枚举、静态成员和嵌套类的作用域。

## Q9
对于一个结构体数组a来说，a[1]是一个结构体变量，而不是结构体指针。在C语言中，结构体数组的每个元素都是一个结构体类型的变量，都包含结构体中所有的成员项。因此，a[1]表示a数组中第二个元素，即一个结构体变量。如果要访问该结构体变量的成员，可以使用`.`运算符。例如，如果有一个名为`a`的结构体数组，我们可以使用`a[1].member`来访问该结构体的成员。

## Q10:++i与i++的区别是什么
## A10
在C++中，i++和++i都是自增运算符，它们的作用都是将变量i的值加1。但是，它们之间有一个重要的区别。单独使用时，i++和++i的效果都是一样的，就是i=i+1。但是，如果当成运算符使用，就会有区别了。 

以a=i++和a=++i为例，a=i++的意思是先把i的值赋予a，然后再执行i=i+1；而a=++i的意思是先执行i=i+1，然后再把i的值赋予a。所以说两者参与运算时的区别就是：a=i++ , a 返回原来的值a=i,i=i+1; a=++i , a 返回加1后的值,a=i+1,i=i+1。也就是说 i++ 是先赋值，然后再自增；++i 是先自增，后赋值。

此外，还有一个区别：i++不能作为左值，而++i可以。这意味着 ++i 可以出现在赋值语句左边，而 i++ 不能。