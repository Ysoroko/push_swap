# push_swap

## Push_swap is a project about efficiently sorting a list of numbers by using two stacks.

### It is composed of two parts:
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
