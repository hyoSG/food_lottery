#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <string>

using namespace std;

string get_date(){
	string sDate;
	time_t timer;
	tm* t;
	timer=time(NULL);
	t=localtime(&timer);

	t->tm_year+=1900;
	t->tm_mon++;
	
	sDate+=to_string(t->tm_year%100);
	if(t->tm_mon<10){
		sDate=sDate+"0"+to_string(t->tm_mon);
	}
	else{
		sDate+=to_string(t->tm_mon);
	}
	
	if(t->tm_mday<10){
		sDate=sDate+="0"+to_string(t->tm_mday);
	}
	else{
		sDate+=to_string(t->tm_mday);
	}

	return sDate;
}

// record function
void write_log(string menu){
        string check;
        cout<<"Do You Want To Log Your Choise ? [yes/( anything )]"<<endl;
        cin>>check;

        if(check=="yes" || check=="y"){
                ofstream fout;
		string sDate=get_date();
		
                fout.open(sDate+".txt");

                fout<<menu<<endl;

                fout.close();

        }
}
