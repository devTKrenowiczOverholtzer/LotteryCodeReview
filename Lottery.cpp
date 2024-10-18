// This program is to simulate Powerball and Mega Millions
/*[CYB220] Lab requirements:
* This is a CS120 homework submission.
* IMPORTANT: You don't need to find the security related bugs (input validation,
type checking)
* (6 pts) 1. Fixed the arrays and make sure the arrays are shuffled correctly!
(This does not count toward a coding problem!)
* (24 pts) 2. There are at least 4 subtle coding problems in the code, find 3 of
them to get full points
* a. Read the homework requirement and Do a code review to find the problems
* b. Write a comment near the problem code, start your comment with [CYB220]
* c. Fix the code!
* 3. SUBMIT THIS .CPP FILE to CANVAS
*/
//NOTE1: array shuffle does not count as 1 coding problem.
//NOTE2: Same type of issue at different places count as 1 coding problem.
//NOTE3: Users entering a very large number, with characters and type mismatch, are
not the type of problem we are looking for in this lab.
//[CYB220] Start your comments like this (with [CYB220]) to make my grading easier.
Thanks!
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
int main ()
{
int PowerBallW[69]; //Array for PowerBall White
int PowerBallR[26]; //Array for PowerBall Red
int MegaMilW[70]; //Array for MegaMillions White
int MegaMilR[25];//Array for MegaMillions Red
int j = 0; //A variable to make choice loop work.
int White[5]; //Array for user input for white
int Red =0; //Variable for user input for red
int random = 0; //Variable for random number in array
int choice =0; //Variable storage for user choice
int correctWhite = 0;
int win_red = 0;
int redMatch = 0;
srand(time(NULL));
//----------------------Initialize Arrays-------------------------
for(int i=0; i<69; i++){
PowerBallW[i]= i+1;
i++;
}
for(int i=0; i<26; i++){
PowerBallR[i]= i+1;
i++;
}
for(int i=0; i<70; i++){
MegaMilW[i]= i+1;
i++;
}
for(int i=0; i<25; i++){
MegaMilR[i]= i+1;
i++;
}
//--------------------Start simulation code----------------------
do{
cout << "Would you like to play MegaMillions or PowerBall?" << endl;
cout << "Please enter 1 for Megamillions and 2 for PowerBall." <<endl;
cin >> choice;
if (choice == 1){
j++;
}else if (choice == 2){
j++;
}else {
cout << "Error. Please enter a valid option." << endl;
}
} while (j==0);
if (choice == 1){ //Conditional to show what the user chose
cout << "You have chosen to play MegaMillions." <<endl;
} else {
cout << "You have chosen to play PowerBall." <<endl;
}
cout << "Please enter 5 numbers for the white ball numbers you wish to play
with." << endl;
for (int i=0; i<5; i++){
int j =0;
if (choice == 1){ // Conditionals for valid numbers.
cout << "Please choose numbers between 1 & 70." << endl;
cin >> White[i];
if (White[i] <1 || White[i] >70) {
do{
cout << "Invalid number." << endl << "Try again.
Please enter a number." << endl;
cin >>White[i];
if (White[i] > 1 && White[i] <= 70){
j++;
} else {
cout << "No." << endl;
}
} while (j==0);
}
} else { //conditional for valid powerball number.
cout << "Please choose numbers between 1 & 69." << endl;
if (White[i] <1 || White[i] >69) {
do{
cout << "Invalid number." << endl << "Try again.
Please enter a number." << endl;
cin >>White[i];
if (White[i] >1 && White[i] <=69){
j++;
} else {
cout << "No." << endl;
}
} while (j==0);
}
}
}
j = 0; //To make the next conditionals work for keeping the numbers honest.
if (choice == 1) {
cout << "Please enter one number for the red ball." << endl;
cout << "Your number should be between 1 and 25." << endl;
cin >> Red;
if (Red < 1 || Red > 25) {
do{
cout << "Invalid number." << endl << "Try again. Please
enter a number." << endl;
cin >>Red;
if (Red > 1 && Red <= 25){
j++;
} else {
cout << "No." <<endl;
}
} while (j==0);
}
} else {
cout << "Please enter one number for the red ball." << endl;
cout << "Your number should be between 1 and 26." << endl;
if (Red < 1 || Red > 26) {
do{
cout << "Invalid number." << endl << "Try again. Please
enter a number." << endl;
cin >>Red;
if (Red > 1 && Red <= 26){
j++;
} else {
cout << "No. " << endl;
}
} while (j==0);
}
}
cout << "You have chosen for the white balls the numbers: " << White[0]<< " "
<< White[1] << " " << White[2]<<" " <<White[3] << " " << White[4] << "." << endl<<
endl;
cout << "You have chosen for the red ball: " << Red << "."<<endl;
cout << "-----------------------------------------" << endl << endl;
if (choice == 1){
for (int i = 0; i < 70; i++){ // Loop to shuffle numbers for Megamill
random =i+2;
int z; //temp variable
z = MegaMilW[i];
MegaMilW[i]=MegaMilW[random];
MegaMilW[random]=z;
}
} else { //PowerBall array shuffle.
for (int i =0; i <69; i++){
random =i+2;
int z;
z = PowerBallW[i];
PowerBallW[i]=PowerBallW[random];
PowerBallW[random] = z;
}
}
cout << "********* Now the results are: **********" << endl;
//check the first 5 elements of the array and compare them with the white
balls
if(choice == 1){
cout << "The winning white balls are: ";
for(int i=0; i<5;i++){
cout << MegaMilW[i] << " ";
if (White[0] == MegaMilW[i] || White[1] == MegaMilW[i]||White[2] ==
MegaMilW[i]|| White[3] == MegaMilW[i]|| White[4] == MegaMilW[i])
correctWhite++;
}
win_red = rand()%25;
}
else{
cout << "The winning white balls are: ";
for(int i=0; i<5;i++){
cout << PowerBallW[i] << " ";
if (White[0] == PowerBallW[i] || White[1] == PowerBallW[i]||White[2] ==
PowerBallW[i]|| White[3] == PowerBallW[i]|| White[4] == PowerBallW[i])
correctWhite++;
}
win_red = rand()%26;
}
cout << "\n\nYou have " << correctWhite << " White balls matched!" <<endl;
cout << "The winning red ball is: " << win_red << endl;
cout << "The red ball you guessed: " << Red << endl;
if (Red == win_red){
cout << "Your guessed correctly!" <<endl;
}
else {
cout << "You missed the red ball..." <<endl;
}
for(int i=0; i<70;i++){ // loop to see if shuffle worked.
cout << MegaMilW[i] << " ";
}
cout << endl <<endl;
return 0;
}
