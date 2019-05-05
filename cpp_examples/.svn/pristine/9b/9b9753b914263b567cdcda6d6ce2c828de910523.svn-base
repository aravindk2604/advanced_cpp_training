
# CXXFLAGS+=  -std=c++11
# CXXFLAGS+=  -std=c++1y
# CXXFLAGS+=  -std=c++14
CXXFLAGS+=  -std=c++17
# CXXFLAGS+=  -std=c++11
# CXXFLAGS+=  -stdlib=libc++
# CXXFLAGS+=  -I. 
# CXXFLAGS+=  -O3 -DNDEBUG
CXXFLAGS+=  -g -O0 # -Wno-long-double
CXXFLAGS+=    -pedantic
CXXFLAGS+=    -Wall
# CXXFLAGS+=    -Weverything
# CXXFLAGS+=    -Werror
# CXXFLAGS+=    -Wno-array-bounds
CXXFLAGS+=    -Wno-unused-value
CXXFLAGS+=    -Wno-unused-variable
# CXXFLAGS+=    -Wno-unused-but-set-variable
CXXFLAGS+=    -pthread
# CXXFLAGS+=    -fno-rtti
CXXFLAGS+=    -Wno-parentheses

# CXX=   g++-4.4
# CXX=   g++-4.6 
# CXX=   g++-4.7 
# CXX=   g++-4.8 
# CXX=   g++-4.9 
# CXX=   g++-5 
# CXX=   g++-6 
# CXX=   g++-7.1 
# CXX=   g++-7
# CXX=   clang++-3.4  
# CXX=   clang++-3.5  
# CXX=   clang++-3.6  
# CXX=   clang++-3.8  
# CXX=   clang++-3.9  
# CXX=   clang++-4.0
CXX=   clang++-5.0

%:	%.cpp
	${CXX} ${CXXFLAGS} -o $@ $?

