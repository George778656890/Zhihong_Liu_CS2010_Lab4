#include <vector>  
#include <ncurses.h>  
  

using std::vector;  
using VEC = vector<int>;
using MATRIX = vector<VEC>;

const int row=24;
const int column=80; 


extern int generationNumber;
extern MATRIX currentMatrix;   
extern MATRIX nextMatrix; 
 

int countNeighbours(MATRIX a,int row1,int column1){

	int finalResult=0;
	
	 // Check upper left  
	if( ((row1-1)>=0) && ((row1-1)<=(row-1)) && ((column1-1)>=0) && ((column1-1)<=(column-1))){
		if(a[row1-1][column1-1]==1){
			++finalResult;
		}
	}
	
	// Check directly above 
	if( ((row1-1)>=0) && ((row1-1)<=(row-1)) ){
		if(a[row1-1][column1]==1){
			++finalResult;
		}
	}
	
	 // Check upper right  
	if( ((row1-1)>=0) && ((row1-1)<=(row-1)) && ((column1+1)>=0) && ((column1+1)<=(column-1))){
		if(a[row1-1][column1+1]==1){
			++finalResult;
		}
	}
	
	
	// Check left  
	if(((column1-1)>=0) && ((column1-1)<=(column-1))){
		if(a[row1][column1-1]==1){
			++finalResult;
		}
	}
	
	// Check right  
	if(((column1+1)>=0) && ((column1+1)<=(column-1))){
		if(a[row1][column1+1]==1){
			++finalResult;
		}
	}
	
	// Check lower left  
	if( ((row1+1)>=0) && ((row1+1)<=(row-1)) && ((column1-1)>=0) && ((column1-1)<=(column-1))){
		if(a[row1+1][column1-1]==1){
			++finalResult;
		}
	}
	
	 // Check directly below 
	if( ((row1+1)>=0) && ((row1+1)<=(row-1)) ){
		if(a[row1+1][column1]==1){
			++finalResult;
		}
	}
	
	// Check lower right 
	if( ((row1+1)>=0) && ((row1+1)<=(row-1)) && ((column1+1)>=0) && ((column1+1)<=(column-1))){
		if(a[row1+1][column1+1]==1){
			++finalResult;
		}
	}
	
	return finalResult;
}

void generatingFollowingMatrix(MATRIX &input,MATRIX &output){

    for(int i=0;i<row;++i){
     	for(int j=0;j<column;++j){
               int neighbourNumber=countNeighbours(input,i,j);
               
               //Any dead cell with exactly three live neighbours becomes a live cell
               if( (input[i][j]==0) && (neighbourNumber==3) ){
               		output[i][j]=1;
               }else if( (input[i][j]==1) ){
               
               	switch(neighbourNumber)
               	{
               	case 0:
               	case 1:output[i][j]=0;break;//Any live cell with fewer than two live neighbours dies
               	
               	case 2://Any live cell with two or three live neighbours lives on to the next generation.
               	case 3:output[i][j]=1;break;
               	
               	default:output[i][j]=0;break; //Any live cell with more than three live neighbours dies
               	}
               	
               }
               
     	}
     	
     }


}

void printMatrix(MATRIX a){

     for(int i=0;i<row;++i){
     	for(int j=0;j<column;++j){
     		if(a[i][j]==1){
     			mvprintw(i,j, "X");// Print "X" at the (i, j) position of the matrix
     		}else {  
                       mvprintw(i, j, " "); // Print empty space for dead cells  
            } 
     	}
     }
     refresh(); // Update the display to show the printed "X".
}

    
    
