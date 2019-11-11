# Automatic Conversion of Recursive Code to Iterative version using Stacks

Description :  This project inputs a Recursive code ( in a specific format) and outputs the iterative alternative for it. This can be helpful in tutorials for other students to understand the working of recursive programs.

Resource used : 
We followed the methodology suggested at the following article:
https://secweb.cs.odu.edu/~zeil/cs361/web/website/Lectures/recursionConversion/page/recursionConversion.html#stackconvert

Methodology : 

We can simulate the recursive process using Stacks to store the following at each recursive step:
1. Actual parameters
2. Local Variables

In the stack :
1. Recursive calls get replaced by __PUSH__
2. Returns from recursive calls get replaced by __POP__
3. main calculation of recursive routine gets __PUT__ inside a while loop
