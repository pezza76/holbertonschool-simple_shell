# 🐢 Simple Shell

A simple UNIX command-line interpreter built in C that mimics basic behavior of the sh shell. This project was developed as part of a low-level programming module at Holberton School.


## Features

- Displays a shell prompt and waits for user input
- Tokenizes user input to extract commands and arguments
- Executes commands found in system $PATH
- Supports built-in commands:
    - exit — exits the shell
    - env — prints the current environment
- Handles errors like command not found
- Works both in interactive and non-interactive mode

## Compilation

To compile this program

```bash
  gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```


## Usage/Examples

Interactive Mode:
```bash
./hsh
($) ls -l
($) env
($) exit
```

Non-Interactive Mode:
```bash
echo "ls -l" | ./hsh
```

Demo example:
```bash
$ ./hsh
($) echo Hello, world!
Hello, world!
($) env
PATH=/usr/local/bin:/usr/bin:/bin
HOME=/home/user
...
($) exit
```


## Authors

- [Andrew P.](https://github.com/pezza76)
- [Alex A.](https://github.com/lolalex1)


## License

This project is for educational purposes only and is not intended for production use.