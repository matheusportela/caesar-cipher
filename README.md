# caesar-cipher
Didactic implementation of Caesar Cipher in C. A C extension for Python is also provided.

## What is the Caesar cipher?

Quoting the [Wikipedia's article on Caesar cipher](https://en.wikipedia.org/wiki/Caesar_cipher):

> In cryptography, a Caesar cipher, also known as Caesar's cipher, the shift cipher, Caesar's code or Caesar shift, is one of the simplest and most widely known encryption techniques. It is a type of substitution cipher in which each letter in the plaintext is replaced by a letter some fixed number of positions down the alphabet. For example, with a left shift of 3, D would be replaced by A, E would become B, and so on. The method is named after Julius Caesar, who used it in his private correspondence.

## Why did I implement it?

If you do a [quick search for "Caesar cipher" in GitHub](https://github.com/search?utf8=%E2%9C%93&q=caesar+cipher), you'll find hundreds of repositories implementing this algorithm in at least 10 programming languages. Therefore, why take the effort to implement it one more time?

Well, I had three reasons for doing this:
* I wanted to start studying cryptography with a hands-on approach, implementing the most important algorithms in current use. Caesar cipher is a natural choice since it is one of the oldest and simplest encryption algorithms.
* I was eager to code something in C again, since it has been a while since my last C project.
* I've never written any C extension for Python and that would be a nice way to get in contact with it for the first time.

## Command-Line Interface
If you simply want to use my program to encode something, say to strengthen your password, you only need to interact with the command-line interface program.

First, build the software using `make` command:
```bash
$ make
```

Now, simply execute it giving a shift integer and a text to encode:
```bash
$ ./caesar_cipher 5 test
yjxy
$ ./caesar_cipher -5 yjxy
test
$ ./caesar_cipher 30 test
3$23
$ ./caesar_cipher -30 "3\$23"
test
```

## C
Since you have the source code in your hands, you may want to use it in your own programs. In order to achieve that, you only have to import the header file and call the `caesar` method.

Three arguments are required:
* `char* output`: Allocated `char` array to store the output of the algorithm.
* `char* input`: Allocated null-terminated `char` array containing text to be encoded.
* `int shift`: Rotation to be applied to `input`.

Let's create an example program. Copy and paste this piece of code to `my_caesar.c`.
```c
#include <stdio.h>
#include "caesar.h"

int main() {
  char input[] = "test";
  char output[5];
  int shift = 5;
  
  caesar(output, input, shift);
  printf("%s\n", output);
  return 0;
}
```

Now you can compile the program and see it working.
```bash
$ gcc -c my_caesar.c caesar.c
$ gcc -o my_caesar my_caesar.o caesar.o
$ ./my_caesar
yjxy
```

## Python
A Python module was also created so you can use the implemented Caesar cipher inside Python scripts. Simply install it using the provided `setup.py` script as follows:
```bash
$ python setup.py install
```

From now on, `pycaesar` is available for your Python modules:
```python
>>> import pycaesar
>>> pycaesar.caesar('test', 5)
'yjxy'
>>> pycaesar.caesar('yjxy', -5)
'test'
>>> pycaesar.caesar('test', 30)
'3$23'
>>> pycaesar.caesar('3$23', -30)
'test'
```

Since it has been programmed in C and exported as an extension, `pycaesar` benefits from ultrafast execution. Here follows the benchmark executed in IPython:
```python
>>> %timeit pycaesar.caesar("test", 200)
The slowest run took 13.99 times longer than the fastest. This could mean that an intermediate result is being cached 
1000000 loops, best of 3: 358 ns per loop
```
