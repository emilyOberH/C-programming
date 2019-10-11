# Cprogramming
Set of exercise solved in C

    Lab 1:
  1) Program that asks the user for one integer number, one real number, one character and one C-style string and then outputs all these values given by the user.
  
  2) Program that outputs the value of a square function y=ax^2+bx+c. Values for a, b, c and x are given by the user. 
  
  3) Program asks the user for three integers. It then displays the arithmetic average and greatest value on the screen.
  
  4) Program that outputs the value of a function y=(ax+b)(cx+d). Values a, b, c, d, x are given by the user.
  
  5) Program that calculates the coefficients a and b of a straight line: y = ax + b passing through two points. The coordinates of the two points are given by the user.  
  
  6) Program that computes the volume and surface area of a cone. Radius and height are given by the user.

    Lab 2:
  1) Program that calculates he weighted arithmetic average of three grades, provided that weights are nonnegative and at least one weight is positive.
  
  2) Program that uses the switch statement to a numerical grade into a letter grade. 
  
  3) Program asks the user for the date in dd/mm/yy format and outputs it as "Dated this ___ day of ___ 20__".
  
  4) Program asks the user for the date in dd/mm/yy format and outputs which dates comes earlier in the calendar year.
  
  5) Program that calculates the area and perimeter of a triangle using Heron's formula. The user inputs the lengths of the triangle's sides.  
  
  6) Program that generates two random integers from the range [1,10] at a time e.g. 5, 7 and then asks the user "How much is 5 * 7?". After doing this 10 times, the user receives a grade based on how many out of the 10 questions were answered correctly.


    Lab 3:
  1) Program that is given two integers m and n and outputs first m multiples of n.
  
  2) Program that is given two integers m and n and outputs all positive multiples of m smaller than n.
  
  3) User is asked for one integer value n. Program outputs all even squares between 1 and n.
  
  4) Program computes the sum and arithmetic average of 10 integers given by the user using fixed length array.
  
  5) Program computes the sum and arithmetic average of n integers. n is given by the user.
  
  6) Program simplifies a fraction that is given by the user e.g. 4/18 --> 2/9.
  
  7) Program computes the greatest common diivisor of three integers.
  
  8) Program prints out the multiplication table from m to n onto the console. n and m are given by the user.
  
  9) Prints a one month calendar onto the console. User can select the month and the day of the week on which the month begins.
  
  10) User enters a positive number n and the program prints out the sum of all positive numbers smaller than n, which are relative prime with n.
  
  
    Lab 4:
  1) Program asks user for 5 integers, stores them in a dynamic array and outputs the arithmetic average of all integers different than the greatest value, sum of all integers different than the greatest value and number of all integers different than the greatest value. Elements in array are accessed using pointers.
  
  2) One-dimensional array of dimension n is filled with random integers. Program outputs all pairs of integers in the array whose sum is equal to M. n and M are given by the user.
  
  3) Program finds and displays all prime numbers equal or less than n. n is given by the user.
  
  
    Lab 5:
  1) A two-dimensional array of n rows and m columns is filled with random integers. Program displays array, the row of the array with the largest sum, the column of the array with the smallet arithmetic average and all rows of the array with at least two even values. n and m is given by the user.
  
  2) User is asked to enter numbers to fill two arrays. User specifies the length of both arrays. Program outputs a rectangular multiplication table, multiplying both arrays with each other. 
  
  3) Create a square n*n matrix and displays it on screen. User enters integer value for n. Program then outputs the sum of all values in the diagonal of the matrix, the sum of all values above the diagonal of the matrix and the sum of all values below the diagonal of the matrix.
  
  4) Create a n*m matrix and an a*b matrix. Program outputs both matrices on the screen, multiplies them with each other and outputs the result. User specifies m, n, a and b.
  
  5) Program generates a random walk across a 10*10 matrix and visually displays the walk on screen. At the beginning all elements of the matrix will be filled with a '.' character. As the program walks from element to element in the matrix, each walked over element will then be filled with a letter from 'A' to 'Z'.
  
  
    Lab 6:
  1) Program calculates the area and circumference of a rectangle. User is asked to enter all sides of the rectangle. Program checks if a rectangle can be constructed with the given sides, if so it performs the calculations for area and circumference, if not it notifies the user that two sides of equal length are needed to form a rectangle. User is askey if they want to repeat the program at the end (y/n). 
  
  2) Program generates an array with random integers using the function generateArray, displays it with function displayArray and reverses the array with function reverseArray. User specifies the length of array.
  
  3) User is asked to enter a positive integer n and outputs all factors of n and whether n is a prime number or not. 
  
  4) User is asked to enter 3 numbers and program informs the user about the average, sum and largest number. Program calls functions averageOf3, sumOf3 and largestOf3 outside the main function to do so.

  5) User is asked to enter the radius of a circle and program outputs the circumference and area of the circle by calling functions outside the main function. 
  
  6) Program asks user for a positive integer n and then calls a function that displays a triangle of '*' characters of heigth n on the left margin of the screen.
  
  7) Modified version of previuos exercise to create a triangle out of any character. User enters character c and program displays triangle made up of the entered character.

  8) Program asks user for a positive integer n and then calls a function that displays a diamond shape made out of '*' characters of heigth n.
  
  9) A parkin garage charges a minimum fee of 20$ to park up to 3 hours. Every additional hour adds an additional 5$ to the price, with 50$ being the maximum charge possible. User enters the hours parked by each customer all separated by a space character and the program displays the price to charge each cusumer, as well as the sum of all prices and hours combined.
  
  
    Lab 7:
  1) Program creates an array of size 10, populated with random integers from the range[-25, 25]. Program informs the user about the number of even intgers present and creates a new array containing only the even integers from the original array. The condition to determine whether an integer is even or not, is passed to the function countIfEven and the function copyIfEven by a pointer to a one-parameter function that returns a bool value.
  
  2) Program creates an array of size 4*5, containing random integers from the range[-5, 5]. The array itself, the number of positive integers contained in each column and the number of positive integers contained in each row is displayed on screen. 
  
  3) Program reads n integers that are given by the user and stores them in a one-dimensional array. Program displays the smallest value, largest value, the average of positive non-zero values and the number of positive values in array greater than 0. The condition to determine whether an integer is even or not, is passed to the functions by a pointer to a one-parameter function that returns a bool value.
  
  4) Program reads n integers that are given by the user and stores them in a one-dimensional array. Program displays the array, the number of values that meet the condition of being positive and even, and the sum as well as the arithmetic average of all values meeting the condition. The condition is passed to the functions by a pointer to a one-parameter function that returns a bool value.
  
  5) Program creates random integers and stores them in an array of dimension n. n is given by the user. Then program sorts all numbers in non-decrasing order using the bubble-sort algorithm and displays the sorted array on screen.
  
  6) Program creates random integers and stores them in an array of dimension n. n is given by the user. Then program sorts all numbers in non-decrasing order using the quick-sort algorithm (with qsort function from C library and a custom compare function) and displays the sorted array on screen.
  
  
    Lab 8:
  1) A structure is defined to represent a fraction. User is asked to enter integers for the nominator and denominator of two fractions A and B. Program computes the sum, difference, product and quotient of A and B.
  
  2) A structure is defined to represent a fraction. User is asked to enter integers for the nominator and denominator of n fractions. Program finds and displays the largest fraction.

  3) (multi-file program)A structure named Point represents the coordinates of a point on a plane. User is asked to enter a point and the program outputs the distance from the point of origin(0, 0) to the entered point. Next the user is asked to enter the values for an array of n points. Program computes and displays the point with the shortest distance to the very first point entered.
  
  4) A structure named Point represents the coordinates of a point on a plane, another structure named Circle represents the center point and radius of a point. The program finds out which points from an array of points (of size n) lie in or on the circle.
  
  
    Lab 9:
  1) A structure is defined to represent a Student, which is composed of data representing name, surname, year of birth, year of study, sum of ECTS points and average of grades. User is asked to enter information for n number of students. n is given by user. Program displays the information about all students on the screen, finds and displays the information about the best student and finds and displays the global average of all students.
  
  2) As above, the program asks for and displays the information about all students on the screen. The information about all students is then stored in a text file and appended to the same folder as the program it is in.
  
  3) A structure is defined to represent a Participant, which is composed of data representing the name, grade for task 1, grade for task 2, grade for task 3 and the sum of all three grades. User is asked to enter information for n number of participants. n is given by user. Program displays the information about all participants on the screen, finds participants with a grade average higher than the global average of all participanta and writes their data into a text file. The file will be placed in the same folder as the program it is in.
  
  
    Lab 10:
  1) Program creates a file named "story.txt" and appends n lines of text to it, each time the program is called. n is given by the user. The entire file is displayed on the screen, as well as the number of lines in the current version of the file. All contents from file "story.txt" are then copied to file "story_copy.txt". 
  
  2) Program creates a file named "numbers.txt" and appends n numbers to it, each time the program is called. n and each individual number is given by the user. The entire file is displayed on the screen, as well as the arithmetic average of all numbers in the current version of the file. All numbers greater than this average from file "numbers.txt" are then copied to file "greater_than_average.txt".
  
  3) Program reads contents from a file named "file1.c" and copies its content to "copy_file1.c", adding the line number at the beginning of each line.
  
  4) Program merges contents from file "file1.c" and file "file2.c" and copies them into file "merge.txt". Program then displays contents of file "merge.txt" on screen.
  
  5) In file "averages" the id numbers and grades of students are stored in the format "%d;%f\n". Program reads file line by line and diaplays all studensts with their id, their average and the global average of all students together.


    Lab 11:
  1) In file "listOfStudents.txt" all information about each individual student is stored in the format "%s;%s;%d;%d;%d;%lf\n". Program reads file line by line and diaplays all studensts and their information on screen. It then copies all students above a certain grade average (given by the user) into a new file and displays them on screen. 
  
  2) Program reads and displays file "sentences.txt" as well as the number of characters, lines, spaces and letters on screen.
  
  3) After the program reads and displays the contents of file "sentences.txt", it asks the user for a name of a new file. It then creates a file with the given name and copies every line from file "sentences.txt" that contains at least one occurrence of string str. str is given by th user.
  
  4) Program reads and displays file "Alice_Merton_song.txt" and displays the number of words, characters, lines and letters on screen.
  
  5) Program reads and displays file "Alice_Merton_song.txt" and creates and a version of this file with only capital letters instead of lower case letters. User is asked for the name of the new file.
 
  6) Program reads and displays file "words.txt" and creates a version of this file containing only words that start with character ch. ch is given by the user.
  
  7) Program reads and displays file "words.txt" and creates a version of this file, where all letters that do no match the first or last letter in each line are replaced with a '*' character.
  
  8) Program reads file "students.txt" and creates a version of this file where all students are stored in a list, then displays contents of new file.
  
  9) Program reads file "students.txt" and finds and displays the best student of each year, as well as the best student overall.
