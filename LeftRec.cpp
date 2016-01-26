#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int main(){
	std :: vector <string> production;
	std :: vector <string> beta;
	std :: vector <string> alpha;
	string s;
	cout<<"enter number of productions\n";
	int n;
	cin>>n;
	cout<<"enter productions in standard format ( S->A|B|c ) \n";
	for(int i=0;i<n;i++){
		cin>>s;
		production.pb(s);
	}
	for(int i=0;i<n;i++){
		string pro=production[i];
		int l=pro.length();
		int ind=3;
		while(ind!=l){
			if(pro[ind]==pro[0]){
				string al="";
				ind++;
				while(pro[ind]!='|'){
					al+=pro[ind];
					ind++;
				}
				alpha.pb(al);
				ind++;
			}
			if(pro[ind]>='A' && pro[ind]<='Z'){
				string bt="";
				while(pro[ind]!='|'){
					bt+=pro[ind];
					ind++;
				}
				beta.pb(bt);
				ind++;
			}
		}
		cout<<"here \n";
		for(int x=0;x<alpha.size();x++){
			cout<<alpha[x]<<" ";
		}
		cout<<endl;
		for(int x=0;x<beta.size();x++){
			cout<<beta[x]<<" ";
		}
		cout<<endl;
	}
	return 0;
}