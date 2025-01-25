# Parameters Task Description

You need to write a program that calculates the greatest common divisor (GCD) or the least common multiple (LCM) of two integers. The arguments will be passed to the program via command-line arguments (using `argc`, `argv`). The program must handle the following options:

### Options:

- **`--help`** or **`-h`**:  
  If this option appears anywhere among the parameters, regardless of the other arguments, the program should output:  
  ```
  Usage: [OPTION]... [Integer1] [Integer2]
  ```

- **`--gcd`** or **`-d`**:  
  The program should calculate the GCD of the two numbers, which should be the last two arguments.  
  This is the default option, meaning if no other options like `--help`, `--gcd`, or `--lcm` are provided, the program should calculate the GCD of the last two integers.

- **`--lcm`** or **`-m`**:  
  The program should calculate the LCM of the two numbers, which should be the last two arguments.

- **`--quiet`** or **`-q`**:  
  If the program runs correctly, this option should have no effect. However, if any errors occur, instead of printing "ERROR\n", the program should print just `"\n"` and terminate.

### Errors:

The program should handle the following errors:
- **Too few arguments**:  
  If there are not enough arguments (e.g., missing integers), the program should print "ERROR\n" (unless `--quiet` is used).
  
- **Conflicting options (`--gcd` and `--lcm`)**:  
  If both `--gcd` and `--lcm` are specified together, the program should print "ERROR\n" (unless `--quiet` is used).

### Assumptions:
- If the program has at least two arguments and neither `--help` nor `-h` are present, the last two arguments are valid positive integers within the range of `int`.

### Example Usage:

1. **GCD Calculation** (default):
   ```bash
   ./prog 9 21
   ```
   Output:
   ```
   3
   ```

2. **LCM Calculation**:
   ```bash
   ./prog --lcm 44 121
   ```
   Output:
   ```
   11
   ```

3. **Help Option**:
   ```bash
   ./prog 17 -h
   ```
   Output:
   ```
   Usage: [OPTION]... [Integer1] [Integer2]
   ```

4. **Too Few Arguments**:
   ```bash
   ./prog
   ```
   Output:
   ```
   ERROR
   ```

5. **Conflicting Options (`--gcd` and `--lcm`)**:
   ```bash
   ./prog --lcm --gcd 9 21
   ```
   Output:
   ```
   ERROR
   ```

6. **Quiet Mode with Conflicting Options**:
   ```bash
   ./prog --lcm --gcd -q 9 21
   ```

7. **Quiet Mode with Correct Arguments**:
   ```bash
   ./prog -q 4 2
   ```
   Output:
   ```
   2
   ```