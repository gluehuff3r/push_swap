push_swap

You’re given a list of integers and you have to sort them using only two stacks and a very limited set of operations. The catch is that the program doesn’t actually sort the numbers directly it just prints the moves needed to do it.

What’s going on

-There are two stacks

-You can only push, swap, rotate, or reverse rotate

-Every move has to be printed

-At the end, stack A must be sorted in ascending order

Input handling

Works with:

-Multiple arguments

-A single quoted string

-Handles negative numbers

-Checks for overflows

-Rejects duplicates

-If something’s wrong, it just prints Error and exits

How it sorts:

-Small inputs are handled with direct logic because overthinking them is pointless

-Bigger inputs are handled by:

-Turning values into relative positions

-Sorting based on binary bits

-This keeps things predictable and avoids weird comparisons

Usage
make
./push_swap 3 1 2


To make sure it actually worked use the checker:

./push_swap 3 1 2 | ./checker_linux 3 1 2

Notes

-No extra output

-Memory is cleaned properly

-The focus is on getting the job done with a reasonable number of moves

Author

haabu-sa (hamzah)
42 Network