#include<bits/stdc++.h>
using namespace std;
stack <pair <char,int> > st;
pair <char,int>mp;
map<char,int> ops;
vector< vector <string> > grammar;
vector< string> pro;
vector<string> news;

string findPro(int ipt){
	pro.clear();
	int sz=grammar.size();
	int pt;
	for(int pt=ipt;pt>=0;pt--){
		if(news[pt][0]=='_'){
			break;
		}
	}
	int flg=0,ptt;
	string production="";
	for(int i=pt;i<news.size();i++){
		if(news[i][0]=='_') break;
		else{
			if(news[i][0]!='~'){
				production+=news[i];
				flag++;
				if(flag!=1){
					news[i]="~";
				}
				else if(flag==1){
					ptt=i;
				}
			}
		}
	
	}
	news[ptt]=production;
	int fl=0;
	for(int i=0;i<sz;i++){
		pro.clear();
		pro=grammar[i];
		int sz1=pro.size();
		for(int j=1;j<sz1;j++){
			if(pro[j]==production){
				news[ptt]=pro[0];
				fl=1;
				break;
			}
		}
		if(fl) break;
	}
	
}

int main(){
       
        int p;
        char ch;
        cin>>ch;
        p=ch-'0';
        
        for(int i=0;i<p;i++){
                pro.clear();
                string g="";
                cin>>g;
                while(g[0]!='~'){
                        pro.push_back(g);
                        cin>>g;

                }
                grammar.push_back(pro);
        }
        int it=grammar.size();
        for(int i=0;i<it;i++){
                pro.clear();
                pro=grammar[i];
                int it1=pro.size();
                cout<<pro[0]<<"->";
                for(int j=1;j<it1;j++){
                        cout<<pro[j]<<"|";
                }
                cout<<endl;
        }
        int n=6;
        string op[6]={"i","*","/","+","-","$"};
        
        ops['i']=0;
        ops['*']=1;
        ops['/']=2;
        ops['+']=3;
        ops['-']=4;
        ops['$']=5;


        int prec[6][6];
        string s;
        
        int matched;
        cout<<"Enter the input string \n";
        cin>>s;
        int  len=s.length();
        for(int i=0;i<len;i++){
        	news[i]="_";
        }
        cout<<s<<endl;
        int ipt,pt=0;
        int max=s.length();

        for(int i=0;i<n;i++){
                char val;
                for(int j=0;j<n;j++){
                        cin>>val;
                        prec[i][j]=val-'0';
                }
        }
        cout<<"  ";
        for(int i=0;i<n;i++){
                cout<<op[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
                cout<<op[i]<<" ";
                for(int j=0;j<n;j++){

                        int x=prec[i][j];
                        if(x==0) cout<<"E ";
                        else if(x==1) cout<<"L ";
                        else if(x==2) cout<<"G ";
                        else if(x==3) cout<<"W ";
                        else cout<<"A ";
                }
                cout<<endl;
        }



		mp={'$',1000};
		pt=0,ipt=-1;
		st.push(mp);
        while(!(st.top().first=='$' && s[pt]=='$')){
			if(preval==1 || preval==0){
				mp={char(s[pt]),pt};
				pt++;
				st.push(mp);				
			}
			else if(preval==2){
				mp=st.pop();
				news[mp.second]=""+mp.first;
				string ret=findPro(mp.second);
			}
			else if(preval==3){
				cout<<"Error while parsing breaking bad...!\n";
				break;
			}
			else if(preval==4){
				cout<<"Congrats string is Accepted...!\n";
			}
        }
        return 0;


}

