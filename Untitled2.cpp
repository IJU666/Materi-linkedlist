#include<iostream>
#include<vector>
using namespace std;

int main(){

//	int num = 5;
//	vector<vector<int> >matrix(num, vector<int> (num, 0));
//	matrix[0][1] = 1;
//	matrix[1][2] = 1;
//	matrix[2][3] = 1;
//	matrix[3][4] = 1;
//	matrix[4][5] = 1;
//	
//	cout << "Directed GRaph : " << endl;
//	for(int i = 0; i < num; i++){
//		for(int j = 0; j < num; j++){
//		
//		cout << matrix[i][j];
//			
//		}
//		cout << endl;
//	}


int num;
cout << "insert"; cin >> num;
vector<vector<int> > matrix(num, vector<int>(num, 0));
int numedges;
int source, destination;
cout << "masukan jumlah edge"; cin >> numedges;

cout << "masukan nilai edge source dan destination" << endl;
for(int i = 0; i < numedges; i++){
	
	cin >> source >> destination;
	
	
	matrix[source][destination] = 1;
	matrix[destination][source] = 1; // UNDIRECTED
}

cout << "Directed GRaph : " << endl;

	for(int i = 0; i < num; i++){
		for(int j = 0; j < num; j++){
		
		cout << matrix[i][j] << " ";
			
		}
		cout << endl;
	}
}
	

