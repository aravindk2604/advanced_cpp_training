# Experience Notes
This is a gist of the important points that was discussed in this three day training conducted by Dr. Peter Gottschling.

#### Day 1
* It is good practice to compile your code with multiple compilers and analyse the subtle differences  
* Any kind of conversion (implicit or explicit) in the code is better if avoided  
* `Ternary operator` can be used in the assignment operation but `if statement` cannot be used  
* C-style cast is a brutal way of casting. Do Not Use  
* C-style cast is quite difficult to search in a large code base when compared to C++ style cast  
* When defining a function inside a header file, declare it as `inline` so that the linker doesn't complain  
* Anonymous namespaces can ensure all your implementations are available and provides a workaround to avoid global static variables  
* Prefer `using` over `typedef`  
* Use `free functions` in `std::copy` over class methods  
  

```  
Instead of  
copy(v1.begin(), v1.begin()+3, v2.begin());  
Use  
copy(begin(v1), begin(v1)+3, begin(v2));  
This works for arrays as well and not just STL containers  

```  

* Prefer `Public Interface` over `friend`
* `std::endl` clears buffer and `\n` only goes to new line
* Implement `output operator` and `initializer list` early when writing a class
* `Function Overloads` are picked over `template specializations`
* `Move semantics` can bring in insecurities in code when `lvalue` which was originally an `rvalue`, becomes an `xvalue`
* `valgrind` is a memory leak checker run in terminal
* `const lvalue` accepts everything, therefore work with `non-const lvalue`
* A `std::move operation` should ensure to return the state of the object to when it was initialized by the default ctor

#### Day 2

#### Day 3
* Move semantics must ensure that the data structure is emptied after the move operation  
* Visual Studio on windows is more crash clean than Linux
* Memory allocation and deallocation takes considerably more time than most operations  
* For greater performance use `Expression Templates`  

#### Smart pointers
* Unique pointer  
Doesn't take one bit more memory than a raw pointer (Very useful).  

* Shared pointer  
Counter (reference count) in the shared pointer is thread safe because it is atomic.  
make_shared has only one memory allocation and deallocation because the data and the reference count is in a single contiguous memory. Hence this is faster than using `new`.  
For performance improvement, pass by reference for shared pointer to avoid increasing the reference count.  

* Weak pointer  
Weak pointer can be used to create a proper shared pointer.  
