GENERAL
---/---
system('pause'); // pause program (e.g. to keep a console program from exiting afer it finishes)


VECTOR
---/--
  'format': vector<DataType> nameOfVector

  'printing'
    for(unsigned int i = 0; i < vectorName.size(); ..) { //// #size returns unsigned int, so there might be a runtime error if normal int is used
      cout << vectorName[i];
      //or cout << vectorName.at(i);
    }

    std::copy(path.begin(), path.end(), std::ostream_iterator<char>(std::cout, " "));

    size - the number of actual elements in vector
    capacity - preallocated possible number of elements in vector (>= size). Can be expanded using .reserve() method

  'accessing elements'
      vectorName[position]
      vectorName.at(position)

  'useful methods'
    #push_back(element) - adds an element and resizes it
    #at(index) - returns a
    #size() - returns an unsigned int that equals to the num. of elements
    #insert(vectorName.begin() + index, new value) - inserts an element at the index position and shifts the following values
    #erase(vectorName.begin() + index, new value) - erases an element at the index position and shifts the following values
    #clear() - clears the vector from all of its elements
    #empty() - returns true or false depending on the contents of the vector
    #end() - returns an iterator referring to the 'past-the-end element' in the vector container.


  EXCEPTIONS
  -----/----
  'syntax'
    try {
      throw 10;
    catch(const std::runtime_error& re) {
        // speciffic handling for runtime_error
        std::cerr << "Runtime error: " << re.what() << std::endl;
    } catch(const std::exception& ex) {
        // speciffic handling for all exceptions extending std::exception, except
        // std::runtime_error which is handled explicitly
        std::cerr << "Error occurred: " << ex.what() << std::endl;
    } catch (int x) {
      ...
    } catch (string str) {
      ...
    }
    catch(...) { //must come last : compile error
        // catch any other errors (that we have no information about)
        std::cerr << "Unknown failure occured. Possible memory corruption" << std::endl;
    }


CONST
--/--
  const objects need const functions:
    string doStuff() const;

  all const variables are static implicitly

  const allows the compiler to optimize code aggressively

  const closes (some of) the performance gaps between C/C++ and FORTRAN

  'const functions'
    ensure you wont be able to change the class
    mutable lets you change the variable even inside a const function
      mutable bool _flag;

  'bit-wise constantness' might differ from the 'logical constantness'

  memset
    allows to 'change' const values
    Sets the first num bytes of the block of memory pointed by ptr to the specified value (interpreted as an unsigned char).
    void * memset ( void * ptr, int value, size_t num );


SWITCH
--/---
  break says, that there is no need to go through the rest of the conditions
  you dont need break in default or the last case in a chain

  when defining a new variable brackets should be used to define new scope {}

  if none of the cases are correct, the default statement is executed


OOP (Object-oriented programming)
-----------------/---------------
  virtual = abstract (JAVA)
  pure virtual function: virtual returnType functionName() = 0;

  'Friends':
    A non-member function can access the private and protected members of a class if it is declared a friend of that class

    Similar to friend functions, a friend class is a class whose members have access to the private or protected members of another class




MEMORY
--/---
  'memory organization'
    Stack
    Heap
    Data segments: static program
    Datacode/text segment: machine intructions

  'memory allocation'
    for heap a memory search is performed
    stack doesnt requiere that many (such intensive) searches
    const are treated as source code, i.e. translated by the compiler into bit sequence
    loads and stores are expensive, i.e. compiler tries to hold variables in the registers as long as posssible

  'stack'
    ulimit -s unlimited // increases the stack size via terminal

  'structure member alignment'
    the struct (or union, class) member variables must be aligned to the highest bytes of the size of any member variables to prevent performance penalties



MACROS
---/--
  'define'
    =text replacement
    #define D 3 //interpreted at before compilation, all D occurences in code are replaces by 3

  'pragma push/pop'
    tells the compiler to start packing as tightly as possible from now on aligning at multiples of n bytes, stopping at #pragma /pack(pop)

  #ifndef H_IDENTIFIER
  #define H_IDENTIFIER
  #endif
    the structure is called 'include guards'; prevents repetative includes, making them indempotent


COMPILER FLAGS
-----/--------
  |-Wconversion| - show warnings on implicit conversion


TYPES
--/--
  'auto' - let compiler decide on the type itself
  'double':
    8 bytes = 64 bits
    1 bit - sign
    11 bits - exponent
    52 bits - mantissa
    if exponent contents only 0s, the ''


POINTERS, REFERENCES, ADDRESSES OF
------------------/---------------
  'address of' operator (&)
    paul = 42;
    melissa = &paul; // melissa now stores the address to paul
  'reference' operator (*)
    could be thought of as saying, "value pointed by"
    dave = *melissa; // dave now stores the value in the address, which melissa contains, i.e. 42 (paul)
  'pointer'
    int *melissa; // melissa's sole purpose now is to store someoneelse's address, but it can only point to an int value
    pointers are able to do math
      int *p;
      p++; // next memeory address (depends on the allignment)
      p--; // previous one
      p += 10; // + (10 * allignment) address
    'arrays' are const pointers, pointing to the first element
    'hell' (all valid):
      const int * //pointer to a const int value
      int * const // constant pointer to an int value
      const int * const // constant pointer to a const int value
  'reference'
    safer than pointers, for they do point to some valid spot in memory
    reference cannot be declared without the initiallization
  'const-reference'
    void efficientFoo(const &A a) {...} // the function won't be able to change the A object inside

  'SMART POINTERS'
    unique_ptr
      Copy assignment operator is implicitly deleted
      a non-null unique pointer always owns what it points to
      Example:
      std::unique_ptr<Foo> p1(new Foo);  // p1 владеет Foo
      std::unique_ptr<Foo> p2(std::move(p1));  // теперь p2 владеет Foo
      p1 = std::move(p2);  // владение возвращено p1

    auto_ptr
      No array allocation supported (will just call 'delete' not 'delete[]')
      Example:
      std::auto_ptr<A> a1(new A);
      std::auto_ptr<A> a2(a1); // a2 point to the object, a1 is null
      a1->foo(1); // error!
      a2->foo(1); // all good
      a1 = a2; // a1 point to the object, a2 is null
      a2->foo(1); // error!
      std::auto_ptr<A> a3 (new int[3]); // will still call delete, not delete[]





FUNCTIONS
---/-----
  argument - an object passed to the fuction
  parameter - an object defined in the function's description
    fuu(int a): a - parameter
    fuu(1): 1 - argument
    
  'pass-by-value'
    the argument is copied (~? not a deep copy)
  'pass-by-reference'
    function operates with the reference to the argument (aka the argument itself)
   'pass-by-reference Java'
    copy of a pointer is stored in the parameter, so that the change of the parameter''s contents leads to change in the argument, but what argument points to cannot be reassigned:
      static void accept_reference(Example e) { // :1
        e.value++; // will change the referenced object (argument)
        e = null; // will only change the parameter
    }
    

  'overloading'
    everything but the name defines a 'signature' for a function
    if theres a const and a non-const functions, C/C++ chooses the const one

  default arguments are allowed
    void foo(int a = 1) {....}
    void foo() {...} // error, because the compiler wouldnt know what to call: the first function or this


CASTS
--/--
  'static_cast'
    convert at compiler time
    static_cast<type> varOfSomeOtherType
    C-style cast: (type) varOfSomeOtherType //don't use it
    if not convertable, the behavior will be undefined

  'dynamic_cast'
    check is done in runtime
    null if not convertable

  'reinterpret_cast'
    tries to reinterpret what is being pointed to
      struct Cow {
        int mooCount;
        int legCount;
        char gender;
        bool dead;
      }
      Cow cow;
      cow.mooCount = 8;
      cow.legCount = 5;
      Cow* cowPtr = &cow;
      int* intPtr = reinterpret_cast<int*>(cowPtr); // now point to 8
      intPtr++; // now to 5

  'typeid'
    method to get a type id
    can be compared

  'integer to floating point'
    everything after decimal point is droped (lost)


ARRAYS
---/--
 const pointers to the first element

 arrayName[n] <=> pointerName + 1 // depending on the type adds a certain number of bytes

 &arrName == arrName

 In a 'function declaration', it is also possible to include 'multidimensional arrays'. The format for a tridimensional array parameter is:
  base_type[][depth][depth]
  void procedure (int myarray[][3][4])
  Notice that 'the first brackets [] are left empty', while the following ones specify sizes for their respective dimensions


STRUCTS
--/----
  have arrays-similar syntax for accessing data

  struct Person {
    str::string name;
    int age;
  };
  Person bucky = { "Bucky", 21 };
  cout << bucky.age << endl;


STRING
---/--
  'C-Style Character String'
    This string is actually a one-dimensional array of characters which is terminated by a null character '\0'


DECLARATION & DEFINITION
----------/-------------
  if the value of declared variable is not given explicitly its value is not defined (aka garbage)


STATIC
---/--
  inside a 'fucntion': static int count = 0; // the line is executed once and the variable remains in memory until the programm finishes

  extern
    When modifying a variable, extern specifies that the variable has static duration (it is allocated when the program begins and deallocated when the program ends).
    The variable or function may be defined in another source file, or later in the same file.
    Declarations of variables and functions at file scope are extern-al by default.


OPERATORS
----/----
  to explicitly restrict the usage of an operator use the following syntax:
    void operator=(UniquePointer& uptr) = delete;

  it is exactly 'as efficient as a raw pointer' and can be used in STL containers
