#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

string fill_time(int num){
	string check="";
	if(num<10){
		check+=("0"+to_string(num));
	}
	else{
		check+=to_string(num);
	}
	return check;
}

const char* get_date(){
	string sDate="";
	const char* cDate;
	
	time_t timer;
	tm* t;
	timer=time(NULL);
	t=localtime(&timer);

	t->tm_year+=1900;
	t->tm_mon++;
	
	sDate+="./log/";	
	sDate+=fill_time(t->tm_year%100);
	sDate+=fill_time(t->tm_mon);
	sDate+=fill_time(t->tm_mday)+"_";
	sDate+=fill_time(t->tm_hour)+"h";
	sDate+=fill_time(t->tm_min)+"m.txt";
		
	cDate=sDate.c_str();	

	return cDate;
}

// record function
void write_log(string menu){
        string check;
        cout<<"Do You Want To Log Your Choise ? [yes/( anything )]"<<endl;
        cin>>check;

        if(check=="yes" || check=="y"){
		FILE* pFile=fopen(get_date(),"w");
		fprintf(pFile,menu.c_str());
		fclose(pFile);
	}
}
