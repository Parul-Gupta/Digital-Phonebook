#ifndef TRIE_HPP
#define TRIE_HPP
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

class node{
	private:
		char val;
		long long int number;
		int words;
		node* children[26];
		bool islast;
	public:
		node(char c);
		friend class trie; 
}; 

node::node(char c){
	val=c;
	number=0;
	words=0;
	islast=false;
	for(int i=0;i<26;i++){
		children[i]=NULL;
	}
}

class trie{
	node* root;
	vector<string> v;
	vector<long long int> vn;
	public:
		trie();
		void insertnode(string name,long long int num);
		int search(string name);
		void inorder(node* temp,string n);
		void printvector();
};

trie::trie(){
	root=new node(' ');
}

void trie::insertnode(string name,long long int num){
	node* temp=root;
	for(int i=0;i<name.length();i++){
		if(temp->children[name[i]-'a']==NULL){
			temp->children[name[i]-'a']=new node(name[i]);	
		}
		temp->words++;
		temp=temp->children[name[i]-'a'];
	}
	temp->islast=true;
	temp->number=num;
}

int trie::search(string name){
	node* temp=root;
	int count=0;
	int i=0;
	while(temp->children[name[i]-'a']!=NULL && i<name.length()){
		temp=temp->children[name[i]-'a'];
		i++;
	} 
	if(i==name.length()){
		count=temp->words;
		if(temp->islast==true)count++;		
	}
	v.clear();
	vn.clear();
	name[0]=toupper(name[0]);
	inorder(temp,name);
	return count;
}

void trie::inorder(node* temp,string n){
	if(temp->islast==true && v.size()<5){
		v.push_back(n);
		vn.push_back(temp->number);
	}
	int i=0;
	while(i<26 && v.size()<5){
		if(temp->children[i]!=NULL){
			n.push_back(temp->children[i]->val);
			inorder(temp->children[i],n);
			n.pop_back();
		}
		i++;
	}
	return;
}

void trie::printvector(){
	for(int i=0;i<v.size();i++){
		cout<<setw(15)<<left<<v[i]<<vn[i]<<endl;
	}
}

#endif
