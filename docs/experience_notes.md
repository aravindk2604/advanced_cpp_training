# Experience Notes
This is a gist of the important points that was discussed in this three day training conducted by Dr. Peter Gottsch.  

# Day 1

# Day 2

# Day 3
* Move semantics must ensure that the data structure is emptied after the move operation  
* Visual Studio on windows is more crash clean than Linux
* Memory allocation and deallocation takes considerably more time than most operations  
* For greater performance use `Expression Templates`  

#### Smart pointers
* Unique pointer  
Doesn't take one bit more memory than a raw pointer (Very useful).  

* Shared pointer  
Counter (reference count) in the shared pointer is thread safe because it is atomic.  
make_shared has only one memory allocation and deallocation because the data and the reference count is in a single memory. Hence this is faster than using `new`.  
For performance pass by reference for shared pointer to avoid increasing the reference count.  

* Weak pointer  
Weak pointer can be used to create a proper shared pointer.  
