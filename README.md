<h1 align="left">
	PUSH-SWAP
</h1>
<p align="left">
	<b><i>Algorithmic project</i></b><br>
</p>

<p align="left">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/psimarro-g/push_swap?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/psimarro-g/push_swap?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/psimarro-g/push_swap?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/psimarro-g/push_swap?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/psimarro-g/push_swap?color=green" />
</p>

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

### Checker program

Coming soon ...
