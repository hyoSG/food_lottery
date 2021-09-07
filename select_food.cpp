//practice in cli environment.

#include <iostream>
//#include <fstream>
#include <cstdio>
#include <vector>
#include <string>
#include <ctime>
#include "log.cpp"

#define MAXIMUM 20

using namespace std;

//  ex) food-list : [chicken , pizza , hamburger]
void print_list(vector<string> &food){
	int len=food.size();
	if(len==0){
		cout<<"you have no food :D "<<endl;
		return;
	}

	cout<<"\nfood-list : [";
	for(int i=0;i<len;i++){
		cout<<food[i];
		if(i==len-1){
			cout<<"]\n\n";
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
	string food_name="";
	string check_right="y";
	int element_num=0;

	cout<<"\n\n\n\n"<<endl;
	
	cout<<"> Do You Want To Add Food ? [y / n]"<<endl;
	cin>>check;
	if(check!="n"){
		while(element_num<MAXIMUM){
			if(check!="y"){
				cout<<"You have to type y or n"<<endl;
				continue;
			}
			cout<<"### if you want to finish this add stage, type 'exit' ###"<<endl;
			cout<<">> Which kind of food do you want to add?"<<endl;
			
			cin>>food_name;
			if(food_name=="exit") break;
			food.push_back(food_name);
			element_num++;

			print_list(food);
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
	
	cout<<"\n\n####### Your Choise is : "+food[draw]+" #######\n\n"<<endl;
		
	return draw;
}

int main(){
	vector<string> food=add_food();
	if(food.size()==0) return 0;
	int index=draw_food(food);
	write_log(food[index]);

	return 0;
}
