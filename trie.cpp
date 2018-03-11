#include"trie.hpp"
#include<algorithm>
#include<fstream>
using namespace std;
int main(){
	trie directory;
	ifstream file;
	file.open("name_number.txt");
	string contact;
	long long int num;
	while(!file.eof()){
		file>>contact>>num;
		transform(contact.begin(),contact.end(),contact.begin(),::tolower);
		directory.insertnode(contact,num);
	}
	file.close();
	char z='y';
	while(z=='y'|| z=='Y'){
		string name;
		cout<<"Please enter full/partial contact name: "<<endl;
		cin>>name;
		transform(name.begin(),name.end(),name.begin(),::tolower);
		int res=directory.search(name);
		name[0]=toupper(name[0]);
		if (res==0)cout<<"Contact not found."<<endl;
		else if(res<=5){
			cout<<"We found "<<res<<" contacts matching "<<name<<". They are:"<<endl;
			directory.printvector();
		}
		else{
			cout<<"We found "<<res<<" contacts matching "<<name<<", with top 5 as follows:"<<endl;
			directory.printvector();
		}
		cout<<"Do you want to continue?[Y/N]"<<endl;
		cin>>z;
	}
	return 0;
}
