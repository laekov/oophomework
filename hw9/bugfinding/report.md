Problems
===
# Under different compilers
## gnu g++ 6.3.0 (MacPorts)
Compilations is fine.

There is a runtime error saying a pointer is released before allocated.
## clang 8.1.0
A mass of compilation errors. Maybe my compiler is broken.
## gnu g++ 4.8.4 (Ununtu 14.04)
Compilation is fine.

Runtime error saying double free or corruption (fasttop)
## gnu g++ 4.7.2 (MinGW 32)
Compiled and run with no problem. 

However, the last output `str1.show()` is presented with a string of grabled.
# Bug
Copy constructor and `operator =` of `bug` class is not defined, so `data_` pointer is directly copied during executing `test(str1)`.

To fix this, rewriting the copy constructor is needed.
