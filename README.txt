To run the program, execute "make run" or execute runMe. The program will compile and run.

It will then ask you to enter a word. If the word matches a word in the dictionary, it will start the timer, print all words starting with the same first 2 letters, and then stop the timer and output the result.

If the word does not match, then it will suggest a word that is similar to what was typed, and ask if you meant that word.

If you enter yes, it will act as if that was the word you originally typed. Otherwise, the program will end.

If the word you typed is not a similar match to anything, the program will end.

The list of words is placed into a hashmap to reduce time.
