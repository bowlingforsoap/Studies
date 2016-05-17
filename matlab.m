!!! INDICES START FROM 1 (not 0) !!!

Adding a semicolon to the end of a command will suppress the output, though the command will still be executed, as you can see in the Workspace

Try pressing the Up arrow to return to the previous command

Name your MATLAB variables anything you''d like as long as they start with a letter and contain only letters, numbers, and underscores (_).

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
The 'colon operator'can refer to a range of values. The following syntax creates a matrix containing the first, second, and third rows of the matrix A.
>> x = A(1:3,:)

    
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

The * operator performs matrix multiplication. The .* operator, in contrast, performs elementwise multiplication and allows you to multiply the corresponding elements of two equally sized arrays.
>> z = [3 4] .* [10 20]
z = 
    30    80
    
Use the 'numel' function to return the number of elements in an array.
    
#function overloading in terms of return values (treir numbers)
The size function can be applied to an array to produce a single output variable containing the array size. 
>> s = size(x)
The size function can be applied to a matrix to produce either a single output variable or two output variables. Use square brackets ([ ]) to obtain more than one output.
>> [xrow,xcol] = size(x)    

The maximum value of a vector and its corresponding index value can be determined using the max function. The first output from the max function is the maximum value of the input vector. When called with two outputs, the second output is the index value.
>> [xMax,idx] = max(x)
#function overloading in terms of return values (treir numbers)

#Documentation
You can enter 
>> doc fcnName
to get information on any MATLAB function.

#plots
Two vectors of the same length can be plotted against each other using the plot function.
>> plot(x,y)

##line style
The plot function accepts an additional argument that allows you to specify the color, line style, and marker style using different symbols in single quotes.
>> plot(x,y,'r--o')
The command above plots a red (r) dashed (--) line with a circle (o) as a marker. You can learn more about the symbols available in the documentation for Line Specification.
Another example: black (k), square (s), no line - 'ks'

The plot function accepts optional additional inputs consisting of a property name and an associated value.
>> plot(y,'LineWidth',5)
The command above plots a heavy line
##line style

To 'plot one line on top of another', use the hold on command to hold the previous plot while you add another line. You can also use the hold off command to return to the default behavior.

Close all open figure windows by issuing the 'close all' command.

When you 'plot a single vector by itself', MATLAB uses the vector values as the y-axis data and sets the x-axis data to range from 1 to n (the number of elements in the vector).
The plot function accepts a property name and property value pair after the plotted arguments and line specifier.

##plot labels
Labels can be added to plots using 'plot annotation functions', such as title. The input to these functions is a string. Strings in MATLAB are enclosed in single quotes (').
>> title('Plot Title')

Use the 'ylabel' function to add the Y-axis label

Use the legend function to specify a legend.
>> legend('a','b','c')
##plot labels
#plots


SAVING/LOADING
==============
You can save variables in your workspace to a MATLAB specific file format called a MAT-file using the save command.
>> save foo x
The command above saves a variable named x to a MAT-file named foo.mat.

You can load variables from a MAT-file using the load command.
>> load foo
