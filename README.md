# RoundRobinScenarioCalculator
The goal of this small tool is to repractice C++ while making a round robin scenario calculator, allowing me to display the different outcomes and their odds of happening. 
for example if a team is guaranteed to make it to playoffs or if a team can comeback by doing a "miracle run" 

The different outcomes can be represented by a binary tree where every node represents a match and each of it's child a possible outcome. 
with n being the number of matches left, we get a n depth and 2^n-1 possible outcomes.

The tree is made with it's level order traversal, generated with a dumb iterative function that needs to change. 
each path from root to leaf represents a possible outcome, so we recursively print all the root to leaf paths.
The creation and root to leaf path could probably be combined into one function generating the tree and the paths on the go. 

Most of the driver code is sadly in the main.cpp but at some point i got too lazy to keep everything nice and tidy. Promise i'll refactor it. 

What's left to do : 
code refactoring
translating tree's path into standings objects => easy, count the number of times each teams number appears in a path and update the scores accordingly
Counting "similar scenarios" I.E paths that ends with the same standings => Easy
Computing the odds of said scenarios => Easy 
Taking tie breakers in account => Moderate, need to get every team with same score and then add matches accordingly

possible features :
Compute a "win probability" for each team and each match according to previous match history 
Scrap current standings from a website.
maybe implement the whole thing iteratively. 
