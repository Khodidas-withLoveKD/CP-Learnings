#include<iostream>

using namespace std;

void static_demo(){

	static int count = 1;

	cout<<"Static_demo = "<<count<<endl;
	count++;
}

void demo(){

	int count = 5;

	cout<<"KAHLI DEMO = "<<count<<endl;
	count--;
}

int main(){

	for(int i=0; i<5; i++){
		static_demo();
		demo();
	}
}
