<h1 align="center">
	PUSH-SWAP
</h1>
<h2 align="center">
	<b><i>Algorithmic project</i></b><br>
</h2>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/psimarro-g/push_swap?color=lightblue" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/psimarro-g/push_swap?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/psimarro-g/push_swap?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/psimarro-g/push_swap?color=green" />
	<img alt="GitHub code lines" src="https://tokei.rs/b1/github/psimarro-g/push_swap?color=orange" height="20"/>
</p>

<p align="center">
	Mac OS X 10.15.7 (Darwin Kernel Version 19.6.0)<br>
</p>

<br>

This project comprises a stack sorting program and a checker program to verify the sorting was made correctly.
## The rules
 
There are 2 stacks named a and b.

At the beginning:

- The stack a contains a random amount of negative and/or positive numbers
  which are not duplicated.
- The stack b is empty.

The goal is to sort in ascending order numbers into stack a. To do so you have the
following operations at your disposal:

- sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
- sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
- ss : sa and sb at the same time.
- pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
- pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
- ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
- rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
- rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
- rrr : rra and rrb at the same time.

To illustrate the effect of some of these instructions, let’s sort a random list of integers:
```console
----------------------------------------------------------------------------------------------------------
Init a and b:
2
1
3
6
5
8
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec sa:
1
2
3
6
5
8
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec pb pb pb:
6 3
5 2
8 1
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec ra rb (equiv. to rr):
5 2
8 1
6 3
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec rra rrb (equiv. to rrr):
6 3
5 2
8 1
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec sa:
5 3
6 2
8 1
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec pa pa pa:
1
2
3
5
6
8
_ _
a b
----------------------------------------------------------------------------------------------------------
```
The project complies with the following rules:

- Global variables are not used.
- The program takes as an argument the stack
a formatted as a list of integers. The first argument should be at the top of the
stack.
- The program displays the smallest list of instructions possible to sort the stack
a, the smallest number being at the top.
- Instructions are separated by a ’\n’ and nothing else.
- If no parameters are specified, the program does not display anything and gives the
prompt back.
- In case of error, it displays "Error" followed by a ’\n’ on the standard error.
Errors include for example: some arguments aren’t integers, some arguments are
bigger than an integer and/or there are duplicates.

## Usage

Use make to compile.
```console
$> make
```
compiles program.
```console
$> ./create_stack <size> stack
```
creates a list of <size> randomly shuffled non repeated integers and outputs them to file "stack".
```console
$> make pswap
```
executes push_swap with file stack as input.
```console
$> make bonus
```
compiles checker program.
```console
$> ARG=$(cat stack); ./push_swap $ARG | ./checker $ARG
```
executes checker on push_swap output.

## Checker program

The program checker takes as an argument the stack a formatted
as a list of integers. The first argument is at the top of the stack. If no argument is given, it stops and displays nothing.
- It will then wait and read instructions on the standard input. Once all the instructions have been read, the program has to
execute them on the stack received as an argument.
- If after executing those instructions, the stack a is actually sorted and the stack b
is empty, then the program must display "OK" followed by a ’\n’ on the standard
output.
- In every other case, it must display "KO" followed by a ’\n’ on the standard output.
- In case of error, it displays "Error" followed by a ’\n’ on the standard error. Errors include for example: some arguments are not integers, some arguments
are bigger than an integer, there are duplicates, an instruction doesn’t exist and/or
is incorrectly formatted.
