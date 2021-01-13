#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////           FUNCTIONS           ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void display(int mat[9][9]){
	
		cout<<endl<<endl<<"\t\t\t";
		for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<mat[i][j]<<" ";
			if((j+1)%3==0 && j<8)
				cout<<" || ";
			}
			cout<<endl<<"\t\t\t";
		if((i+1)%3==0 && i<8)
			cout<<"-------------------------"<<endl<<"\t\t\t";
		
	
	}
}

void input(int mat[9][9],int k,int l){
	int i,j,num;
	cout<<endl<<endl<<"\t\t\t";
while(1){	
	for( i=0;i<9;i++){
		for( j=0;j<9;j++){
			if(i==k && j==l){
				cout<<"H"<<" ";

			}
			else cout<<mat[i][j]<<" ";
			if((j+1)%3==0 && j<8)
				cout<<" || ";
			}
			cout<<endl<<"\t\t\t";
		if((i+1)%3==0 && i<8)
			cout<<"-----------------------------"<<endl<<"\t\t\t";
		
	}
	cout<<endl;
		
	cout<<"Enter the number you want to enter at H, enter 0 for blank"<<endl;
	cin>>num;
	if(num > 9 || num < 0 ){
	system("CLS");
	cout<<"Enter valid choice"<<endl<<endl<<"\t\t\t";
	}
	else {
	mat[k][l]=num;
	system("CLS");
	break;
	}
	}
}
	
int checker1(int mat[9][9]){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			for(int k=0;k<9;k++){
				if(mat[i][j] != 0){
				if(mat[i][j] == mat[k][j] && i != k ){
					return 0;
				}
				if(mat[i][j] == mat[i][k] && j != k){
					return 0;
				}
			}
			}
		}
	}
	return 1;
}

int checker2(int mat[9][9]){
	
	for(int x=0;x<9;x++){
		for(int y=0;y<9;y++){
			if(mat[x][y] != 0){
	    	int i1=x/3*3;
			int j1=y/3*3; 
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					if(mat[i1+i][j1+j] == mat[x][y] && i1+i != x && j1+j != y)
						return 0;
					}
			}
			}
		}
	}
	return 1;
}


int vaildcheck(int mat[9][9],int x,int y,int val){
	for(int j=0;j<9;j++){
		if(mat[x][j] == val)
			return 0;
		if(mat[j][y] == val)
			return 0;
			
		}
	
		
	int i1=x/3*3;
	int j1=y/3*3; 
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(mat[i1+i][j1+j] == val)
				return 0;
		}
	}
	return 1;
}



void solver(int mat[9][9],int i,int j){
	if(i == 9){
		display(mat);
		getche();
		exit(0);
	}
	int i1,j1;
	if(j == 8){
		i1=i+1;
		j1=0;
	}
	else {
		i1=i;
		j1=j+1;
	}
	
	if(mat[i][j] != 0){
		solver(mat,i1,j1);
	}
	else {
		for(int val = 1; val <= 9 ; val++){
			if(vaildcheck(mat,i,j,val) == 1 ){
				mat[i][j]=val;
				solver(mat,i1,j1);
				mat[i][j]=0;
			}
		}
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////            MAIN               ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){
	int mat[9][9];
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			mat[i][j]=0;
		}
	}
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			input(mat,i,j);
		}
	}
	
	int c1=checker1(mat);
	int c2=checker2(mat);
	if(c1==1 && c2==1){
	cout<<"entered sudoku is ";
	display(mat);
	solver(mat,0,0);
	}
	else{
		display(mat);
		cout<<endl<<"\t\t\t"<<"Entered sudoku is incorrect ";
		}
	getche();
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////             END               ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
