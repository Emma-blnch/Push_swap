reste a faire: check norminette et que je comprends tout
check sujet correctement

<h1 align="center"> 💻 <strong>Push_swap</strong> </h1>

## 🏷️ **About the project**
> This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

This project is about sorting data on a stack by coding a performant sorting algorithm.

## 📥 **What I learned**
With this project, I learned how to really spend more time on the *planning part* than the *coding part*. I really took my time to **think** about how many functions I'll nead, the steps to do from easiest to hardest, etc...

I also learned how to implement **individual tests** for each function I did. Everytime I did a function, I tested it separatly to make sure it worked perfectly before doing the next function!

## ⚙️ **Requirements**
The function must be written in C. It must compile with clang and the following flags :
- -Wall
- -Wextra
- -Werror

You have at your disposal a **set of integer values**, **2 stacks**, and a **set of instructions** to manipulate both stacks.

## ➡️ **Instructions**
- [ ] *sa (swap a)*: Swap the first 2 elements at the top of stack a.
- [ ] *sb (swap b)*: Swap the first 2 elements at the top of stack b.
- [ ] *ss* : sa and sb at the same time.
- [ ] *pa (push a)*: Take the first element at the top of b and put it at the top of a.
- [ ] *pb (push b)*: Take the first element at the top of a and put it at the top of b.
- [ ] *ra (rotate a)*: Shift up all elements of stack a by 1. The first element becomes the last one.
- [ ] *rb (rotate b)*: Shift up all elements of stack b by 1.
- [ ] *rr* : ra and rb at the same time.
- [ ] *rra (reverse rotate a)*: Shift down all elements of stack a by 1. The last element becomes the first one.
- [ ] *rrb (reverse rotate b)*: Shift down all elements of stack b by 1.
- [ ] *rrr* : rra and rrb at the same time.

## 📍 **Bonus**
What to do for the bonus part:
> This project leaves little room for adding extra features due to its simplicity. However, how about creating your own checker?

## ♻️ **Testing**
I strongly recommand you do your own main function to test your program. And I suggest you to test each function you do *separatly* to make sure everything works fine **before** putting it together (it will help you debug).

If you want to make sure your program works, you can use third party testers like:
- [https://github.com/LeoFu9487/push_swap_tester](https://github.com/LeoFu9487/push_swap_tester)
- [https://github.com/Tripouille/printfTester](https://github.com/SimonCROS/push_swap_tester)
