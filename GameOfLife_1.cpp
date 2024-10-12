#include <iostream>
#include<string>
#include<vector>
#include<iterator>
#include<type_traits>
#include<iterator>
#include<algorithm>
#include<utility>
#include<fstream>
#include <vector>
#include <ncurses.h>
#include <cstring>
#include <thread> // Required for sleep_for  
#include <chrono> // Required for milliseconds


using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;
using std::ostream;
using std::pair;


const int row=24;
const int column=80;
int generationNumber=0;

using VEC = vector<int>;
using MATRIX = vector<VEC>;

MATRIX currentMatrix(row,VEC(column,0));
MATRIX nextMatrix(row,VEC(column,0));

void printMatrix(MATRIX a);
int countNeighbours(MATRIX a,int row1,int column1);
void generatingFollowingMatrix(MATRIX &input,MATRIX &output);



int main(){
     cout<<"How many generations would you like to play ? ";
     cin>>generationNumber;
     cout<<endl;
     
     MEVENT event;
     
     initscr ();// Initialize the ncurses mode, setting up the screen
     noecho();// Disable echoing of typed characters to the screen.  
     cbreak();// Disable line buffering, so input is available immediately.  
     keypad(stdscr, TRUE);// Enable special keys (like arrow keys, function keys, etc.) to be captured.
     curs_set(0);// Hide the cursor in the ncurses window. 
     mouseinterval(3); // Set the interval for mouse events (this sets how quickly you want to receive mouse events). 
     mousemask(ALL_MOUSE_EVENTS, NULL);// Enable all mouse events to be captured.
     
     //GetUserConfiguration();
     
      // Define the boundaries for row and column  
     const int rowMin = 0;    // Minimum row limit  
     const int rowMax = row-1;   // Maximum row limit  
     const int colMin = 0;    // Minimum column limit  
     const int colMax = column-1;   // Maximum column limit 
    
    
    
    while (1) {  
        int c = getch();  
        switch (c) {  
            case KEY_MOUSE:  
                if (getmouse(&event) == OK) {  
                    // Check if the clicked position is within bounds  
                    if (event.bstate & BUTTON1_PRESSED) {  
                        if (event.y >= rowMin && event.y <= rowMax &&  
                            event.x >= colMin && event.x <= colMax) {  
			    
			    currentMatrix[event.y][event.x]=1; //Set the live cell
			    mvprintw(event.y, event.x, "X");  
                            refresh();  
                        }  
                    }  
                }  
                break;  
            case 'q':  
                goto beginGeneration;  
        }  
    }
    
beginGeneration:  
       
       
       for(int i=0;i<generationNumber;++i){
       
       	   // Generate the next state 	
       	   generatingFollowingMatrix(currentMatrix,nextMatrix);
       	   
       	   // Print the next state and then swap matrices  
           printMatrix(nextMatrix);  
       	   
       	   // Create a delay to get a better display effect  
           std::this_thread::sleep_for(std::chrono::milliseconds(1000));

       	   // Swap matrices for the next generation 
       	   currentMatrix= nextMatrix;
       	   
       }
       
            
       endwin(); 
       return 0;
}





















