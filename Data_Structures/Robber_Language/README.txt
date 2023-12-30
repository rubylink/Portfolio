Name: Ruby Link  

The task of this project is to take in a txt file containing a sentence and translate it to robber language which just doubles every consonant and adds one 'o' in the middle, leaving consonants as they are. The file in processed in FileProcessor.cpp and outputs the results in HTML. Model.cpp has two functions that tranlate either a vowel or a consonant in a sentence. Translator.cpp has three functions. IsVowel() returns a boolean to check if the letter is a vowel or a consonant. translateEnglishWord() takes in a string and converts each letter accordingly by calling isVowel() and then one of the two functions in Model.cpp. The thrid function translates and entire sentence by calling translateEnglishWord() for every word in the sentence. 

I used the following link to help me with lines 21-30 in the fileProcessor.cpp class
https://www.tutorialspoint.com/how-to-read-a-text-file-with-cplusplus#:~:text=close()%20method.-,Call%20open()%20method%20to%20open%20a%20file%20%E2%80%9Ctpoint.,it%20into%20the%20string%20tp.


To compile type: g++ *.cpp -o Main1.exe
To run: ./Main1.exe
