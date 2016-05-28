API Concepts OpenCV 2.x
=======================
All the OpenCV classes and functions are placed into the cv namespace

OpenCV handles all the memory /automatically (in OpenCV 1.x it''s not the case)
  When a Mat instance is copied, no actual data is really copied. Instead, the reference counter is incremented to memorize that there is another owner of the same data.

  There is also the Mat::clone method that creates a full copy of the matrix data.

Type name of a Mat object consists of several parts. Here''s example for 'CV_64FC1':
  'CV'_ - this is just a prefix
  64 - number of bits per base matrix /element (e.g. pixel value in grayscale image or single color element in BGR image)
  'F' - type of the base element. In this case it''s F for float, but can also be /S (signed) or /U (unsigned)
  'Cx' - number of channels in an image as I outlined earlier

  A primitive OpenCV data type is one of unsigned char, bool, signed char, unsigned short, signed short, int, float, double, or a tuple of values of one of these types, where all the values in the tuple have the same type. 'Any primitive type' from the list 'can be defined by' an identifier in the form CV_<bit-depth>{U|S|F}C(<number_of_channels>), for example: uchar ~ CV_8UC1, 3-element floating-point tuple ~ CV_32FC3, and so on

OpenCV offers the Ptr template class that is similar to std::shared_ptr from C++11. So, instead of using plain pointers:
  'T* ptr = new T(...);'
  you can use:
  'Ptr<T> ptr(new T(...));'
  or:
  'Ptr<T> ptr = makePtr<T>(...);'

  Ptr<T> encapsulates a pointer to a T instance and a reference counter associated with the pointer
