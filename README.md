# Summary of the math.h Project

The `math.h` project focuses on recreating the standard `math.h` library in the C programming language. This initiative has been designed to give developers a comprehensive understanding of computational methods while reinforcing the principles of structured programming.

## Installation
````
git clone https://github.com/0xmisha/math.h.git
cd math.h/src
make
````

## Requirements

- Gcc
- Make
- check.h (for tests)

## Info

Here's a quick rundown of what was achieved:

- **Reimplementation of `math.h` Functions**: The project successfully reimplemented the following functions from the `math.h` library:
  - `abs`
  - `acos`
  - `asin`
  - `atan`
  - `ceil`
  - `cos`
  - `exp`
  - `fabs`
  - `floor`
  - `fmod`
  - `log`
  - `pow`
  - `sin`
  - `sqrt`
  - `tan`

- **C11 Standard Compliance**: All coding was done following the C11 standard using the gcc compiler.
  
- **Code Structuring**: Adherence to the Google coding style was maintained, and the project was structured as a static library. All source codes were organized in the `src` folder within the develop branch.
  
- **Legacy Code Avoidance**: Outdated and obsolete language constructs were deliberately avoided, and the POSIX.1-2017 standard was adhered to.
  
- **Prefixing**: Each function was prefixed with `s21_` to maintain clarity and uniqueness.
  
- **Unit Testing**: A rigorous testing regime was set up using the Check library. The tests compared the results from the `s21_math` library with the standard `math.h` library to ensure accuracy.
  
- **Coverage**: Tests covered at least 80% of each function's code, as verified with `gcov`.
  
- **Build Automation**: A `Makefile` was provided to simplify the building process. It included targets like `all`, `clean`, `test`, `s21_math.a`, and `gcov_report`.
  
- **gcov Reporting**: The gcov report was made accessible in an HTML format to ensure transparency.
  
- **Accuracy**: A stringent accuracy threshold was maintained, with 16 significant digits for the total verifiable accuracy and up to 6 decimal places for the fractional part.
