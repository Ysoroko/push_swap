# push_swap

## Push_swap is a project about efficiently sorting a list of numbers with some constraints.

### We have two stacks and the following commands at our disposal:
- #### pb : push b - take the first element at the top of a and put it at the top of b
- #### pa : push a - take the first element at the top of b and put it at the top of a
- #### sa : swap a - swap the first 2 elements at the top of stack a
- #### sb : swap b - swap the first 2 elements at the top of stack b
- #### ss : sa and sb at the same time
- #### ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one
- #### rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one
- #### rr : ra and rb at the same time
- #### rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one
- #### rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one
- #### rrr : rra and rrb at the same time

### The project is composed of two parts:
- #### 📶 "push_swap" executable will accept the numbers as arguments and will display the necessary commands to sort them.
- #### ✅ "checker" executable will accept the numbers as argments, wait for user's input commands and apply them to the stack of numbers. When stopped it will display "OK" if the stack is sorted or "KO" if it's not.

## "push_swap" executable examples:
- #### Standard behaviour as required per subject:
![](images/push_swap_usual.png)
- #### Detailed version of the status of the stack at the start and at the end of execution of push_swap:
![](images/push_swap_detailed.png)

## "checker" executable examples:
- #### Standard behaviour as required per subject:

![](images/checker_ok.png)
<br/>
<br/>
<br/>
![](images/checker_ko.png)

- #### Detailed version of the status of the stacks after every instruction:

![](images/checker_detailed_ok.png)
<br/>
<br/>
<br/>
![](images/checker_detailed_ko.png)

## Try it:
- #### Git clone this repo, and just use "make" command in your terminal while inside the repo to compile the "push_swap" executable
- #### "make bonus" command in terminal while inside the repo will compile the "checker" executable
- #### You can launch push_swap with any numerical values as one string separated by spaces or multiple arguments. Example: "./push_swap 4 2 3 1" or "./push_swap "4 2 3 1""
- #### "checker" will accept the same format for numbers and will then wait for user input finished by Enter. You can input the following commands: sa sb ss pa pb ra rb rr rra rrb rrr. Checker will execute every single one of them and if stopped with CTRL+D will display "OK" or "KO" depending on whether the stack_a is sorted and stack_b is empty at the given moment. Example: "./checker 4 2 3 1" "pb" "sa" "pb" "rr".
