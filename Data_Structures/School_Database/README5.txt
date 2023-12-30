1) 
Full name: Ruby Link

2) Resources:
Used for overloaded operators: https://www.learncpp.com/cpp-tutorial/overloading-the-comparison-operators/ 

3)Assignment 

Implementing a simple database system using a special type of binary search tree. DB will allows the user to insert, delete, and query data. Information in DB consists of student and faculty records. The information for each will be stored in its own table.

For database table implementation, I am using a version of BSTs called Lazily Balanced Binary Search Trees, which behave similarly to classic BSTs, except when things get too imbalanced, the tree is totally rebuilt. To accomplish this, each node in the tree keeps track of the depth of the left subtree and the depth of the right subtree anchored at that node. When the difference between the depths of the left and right subtrees at the root of the tree is more than a factor of 1.5, the tree is automatically rebuilt to be perfectly balanced based on the following algorithm:

Each of the N values in the LB-BST is placed in an array of size N in ascending order
The median value of the collection is chosen and inserted into a new LB-BST as the root/leaf
The median value of everything less than the root/leaf is chosen and inserted into the tree is inserted as the root’s/leaf’s left child.
The median value of everything greater than the root/leaf is chosen and inserted into the tree is inserted as the root’s/leaf’s right child.

The database system consists of two tables, Student and Faculty, which contain the following types of records, respectively:

Student Records:
Student records are stored in a Student class. Student records contain a unique student ID (an integer), a string name field, a string level field (Freshman, Sophomore, etc.), a string major field, a double GPA field, and an integer advisor field, which will contain the Faculty ID of their advisor.

Faculty Records:
Faculty records are similar to student records and are be stored in a Faculty class. 
Faculty records contain an integer Faculty ID, a string name, a string department, and a list of integers corresponding to all of the faculty member’s advisees’ ids.

The Database System:
The program keeps references to both the faculty and student tables in memory. These references are simply LazyBST instances.
Once the tables have been created, a menu is presented to the user to allow them to manipulate the database. The choices are:

1. Print all students and their information (sorted by ascending id #)
2. Print all faculty and their information (sorted by ascending id #)
3. Find and display student information given the student id
4. Find and display faculty information given the faculty id
5. Add a new student
6. Delete a student given the id
7. Add a new faculty member
8. Delete a faculty member given the id.
9. Change a student’s advisor given the student id and the new faculty id.
10. Remove an advisee from a faculty member given the ids
11. Exit

All of the commands  enforce referential integrity. (Ex. If a faculty member is deleted, then their advisees must have their advisors changed) 

After each command is executed, the menu is displayed again, and the user allowed to continue.

4) Instructions for running the assignment. 

docker start compsci
docker attach compsci
g++ *.cpp -o e.exe
./e.exe
then follow the prompts on the terminal
