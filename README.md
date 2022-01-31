# The monty program
## This is just a place holder for the 0x19. C - Stacks, Queues - LIFO, FIFO project.

<img src="https://camo.githubusercontent.com/5306a81dd85f97f77bf27a282eb5f32d2733522ab58689ad24c372d2e9554fc3/68747470733a2f2f7062732e7477696d672e636f6d2f6d656469612f4346595957793655454145394f772d2e706e67" height=450 width=900/>

### Requirements
Usage: monty file

where file is the path to the file containing Monty byte code

If the user does not give any file or more than one argument to your program, print the error message USAGE: monty file, followed by a new line, and exit with the status EXIT_FAILURE

If, for any reason, it’s not possible to open the file, print the error message Error: Can't open file <file>, followed by a new line, and exit with the status EXIT_FAILURE
  
where <file> is the name of the file
  
If the file contains an invalid instruction, print the error message L<line_number>: unknown instruction <opcode>, followed by a new line, and exit with the status EXIT_FAILURE
  
where is the line number where the instruction appears.
  
Line numbers always start at 1
  
The monty program runs the bytecodes line by line and stop if either: 
- it executed properly every line of the file
- it finds an error in the file
- an error occured
  
If you can’t malloc anymore, print the error message Error: malloc failed, followed by a new line, and exit with status EXIT_FAILURE.
You have to use malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, …)

--- 
 
## The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.


  
## Compilation & Output
```
 Your code will be compiled this way:
$ gcc -Wall -Werror -Wextra -pedantic -std=c90 *.c -o monty
  ```  
  
  
### Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```
luis@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
luis@ubuntu:~/monty$
```
Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:
```
luis@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
luis@ubuntu:~/monty$
```

 ---
  
## License
Copyright © 2021, [Luis Obregon](https://github.com/luisobregon21),
Released under the [Holberton School PR](LICENSE).
