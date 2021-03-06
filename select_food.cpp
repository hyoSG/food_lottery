//practice in cli environment.

#include <iostream>
//#include <fstream>
#include <cstdio>
#include <vector>
#include <string>
#include <ctime>
#include "log.cpp"

using namespace std;

//  ex) food-list : [chicken , pizza , hamburger]
void print_list(vector<string> &food){
	int len=food.size();
	cout<<"food-list : [";
	for(int i=0;i<len;i++){
		cout<<food[i];
		if(i==len-1){
			cout<<"]\n";
		}
		else{
			cout<<" , ";
		}
	}
}

//add food-list
vector<string> add_food(){
	vector<string> food;
	string check="y";
	string food_name;
	while(true){
		cout<<"\n\nDo You Want To Add Food ? [y/n]"<<endl;
		cin>>check;
		if(check=="n") break;
		else if(check=="y"){
			cout<<"\n\nWhich kind of food do you want to add?"<<endl;
			cin>>food_name;
			food.push_back(food_name);
			print_list(food);
			continue;
		}
		else{
			cout<<"\n\nyou should choose between [y or n]"<<endl;
			continue;
		}
	}
	return food;		
}

// random output
int draw_food(vector<string> &food){
	int len=food.size();
	int draw=0;
	
	srand(time(NULL));
	draw=rand()%len;
	
	cout<<"\n\nYour Choise is : "+food[draw]+"\n\n"<<endl;
		
	return draw;
}

int main(){
	vector<string> food=add_food();
	int index=draw_food(food);
	write_log(food[index]);

	return 0;
}
