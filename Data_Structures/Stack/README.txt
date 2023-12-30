1) 
Name: Ruby Link

2) Assignement 
The program takes in a txt file that has the heights of people sitting in an audience that are assembled in rows. BEGIN denotes the front of the audienct and END denotes the back. 
The program uses stacks to calculate the which people are able to see the stage, that is, they are taller than every person in front of them. 

I utilize a stack (Monostack.cpp) that holds values in either ascending or descending order, specified upon implementaon. If using a descending stack, whena value is pushed to 
the stack that is large than the value at the top, the stack is cleared and only the largest value kept. 

My code utilizes a descending stack and pushes the heights of the audience in each column, starting with the back row. After each row is pushed to the monostack, the values of the 
heights are popped, revealing who is able to see in each row. 

3) To run:

docker start compsci
docker attach compsci

g++ *.cpp -o mainM.cpp
./e.exe 
