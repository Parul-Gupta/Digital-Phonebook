# Digital-Phonebook
The data structure used is a trie. The user can get the contact of a person using his or her full/partial name.
In order to compile and run the programs, type on the console:
	g++ trie.cpp -std=c++11 -o a
	./a
  
To insert a name in the trie, the string name is parsed character by character and if the corresponding index in the character array is found empty then memory is allocated to that index. If the word ends at that node, then the bool islast is marked true and the corresponding number is inserted there.

While inserting, whenever I pass a character node, I update its words attribute by 1, so that at the end it will represent the number of words rooted at that node.

Using a similar approach, a name can be found in the trie.
Now to get the first 5 matching words, I find the prefix in the trie, and then using a string argument, I update a vector upto size 5.
In the end I print that vector.

Orders:
Insertnode-----O(d) [d=max length of a name]
search---------O(d) [d=max length of a name]  
