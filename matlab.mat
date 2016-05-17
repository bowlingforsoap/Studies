Adding a semicolon to the end of a command will suppress the output, though the command will still be executed, as you can see in the Workspace

Try pressing the Up arrow to return to the previous command

Name your MATLAB variables anything you'd like as long as they start with a letter and contain only letters, numbers, and underscores (_).

'clear' to clear all the variables in a workspace

'clc' clears the Command Window

MATLAB contains built-in constants, such as pi to represent π.
>> a = pi
a = 
    3.1416
Also, although only four decimal places are shown for π, it is represented internally with greater precision.

Imaginary numbers
>> z = sqrt (-9)
z =
   0.0000 + 3.0000i
   
All MATLAB 'variables are arrays', meaning that each variable can contain multiple elements. A single number, called a scalar, is actually a 1-by-1 array, meaning it contains 1 row and 1 column.

When you separate numbers by spaces (or commas), MATLAB combines the numbers into a row vector, which is an array with one row and multiple columns (1-by-n). When you separate them by semicolons, MATLAB creates a column vector (n-by-1)
>> x = [1;3].

 The : operator uses a default spacing of 1, however you can specify your own spacing, as shown below.
>> x = 20:2:26
x = 
    20    22    24    26
    
If you know the number of elements you want in a vector (instead of the spacing between each element), you could instead use the linspace function: linspace(first,last,number_of_elements). Note the use of commas (,) to separate inputs to the linspace function.
>> x = linspace(0,1,5)
x = 
    0    0.250    0.500    0.750    1.000
    
Both linspace and the : operator create row vectors. However, you can convert a row vector into a column vector using the 'transpose operator' (')
 
MATLAB contains many functions that help you to create commonly used matrices, such as matrices of 'random numbers'.
>> x = rand(2)
x = 
    0.8147    0.1270
    0.9058    0.9134
Note that the 2 in the command rand(2) specifies that the output will be a 2-by-2 matrix of random numbers.
Many matrix creation functions allow you to input one number to create a square matrix (n-by-n) or input two numbers to create nonsquare matrices.
>> x = rand(2)
x = 
    0.8147    0.1270
    0.9058    0.9134    >> x = rand(2,3)
x = 
    0.6324    0.2785    0.9575
    0.0975    0.5469    0.9649
    
'zeros' function to create a matrix of all zeros



SAVING/LOADING
==============
You can save variables in your workspace to a MATLAB specific file format called a MAT-file using the save command.
>> save foo x
The command above saves a variable named x to a MAT-file named foo.mat.

You can load variables from a MAT-file using the load command.
>> load foo
