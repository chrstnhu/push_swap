# Push swap

Project 42 school

Write a programm that sort data on a stack with a limited set of instructions and the smallest of moves.

## Functions autorized
* read, write
* malloc, free
* exit

## Run
Git clone and go to project directory :

```bash
git clone git@github.com:chrstnhu/push_swap.git && cd push_swap
```

Make :
```bash
make
```

Run push_swap :
```bash
./push_swap 105 60 90

```
## Test
* Try differents numbers 

## Rules

<details>
  <summary> swap </summary>

  * sa : first 2 elements at the top of stack a
  * sb : first 2 elements at the top of stack b
  * ss : sa and sb

</details>

<details>
  <summary> push </summary>

  * pa : Take the first element of top b and put it at top a
  * pb : Take the first element of top b and put it at top b

</details>


<details>
  <summary> rotate </summary>

  * ra : shift up all elements of stack a by 1
  * rb : shift up all elements of stack b by 1
  * rr : ra and rb

</details>

<details>
  <summary> reverse rotate </summary>

  * rra : shift down all elements of stack a by 1
  * rrb : shift down all elements of stack a by 1
  * rrr : rra and rrb

</details>

  ## Bonus
* Checker of push_swap

Make bonus :
```bash
make bonus
```

Run push_swap :
```bash
./checker 105 60 90
