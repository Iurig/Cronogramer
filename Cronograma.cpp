#include<bits/stdc++.h>
#define profs dias*aulas
const int dias = 5;
const int aulas = 6;
using namespace std;
int crono[dias][aulas];
int materias;
string semana[5] = {"Segunda:  ", "Terça:    ", "Quarta:   ", "Quinta:   ", "Sexta:    "};
pair<string, set<pair<int,int> > > disp[profs];
int dobra[profs];
int ncrono;
int resolve (int i){
	if (i>=materias) {
		for (int h = 0; h < dias; ++h){
			cout << semana[h];
			for (int j = 0; j < aulas; ++j){
				cout << disp[crono[h][j]].first << "\t";
			}
			cout << "\n";
		}
		cout << "\n\n";
		ncrono--;
		if (ncrono==0) exit(0);
		return 0;
	}
	if (dobra[i]==0)for (auto hor: disp[i].second){
		if (crono[hor.first][hor.second]==-1){
			crono[hor.first][hor.second]=i;
			resolve (i+1);
			crono[hor.first][hor.second]=-1;
		}
	}
	if (dobra[i]!=0)for (auto hor: disp[i].second){
		if (crono[hor.first][hor.second]==-1 && hor.second!=5 && crono[hor.first][hor.second+1]==-1 && disp[i].second.count(make_pair(hor.first,hor.second+1))==1){
			crono[hor.first][hor.second]=i;
			crono[hor.first][hor.second+1]=i;
			resolve (i+1);
			crono[hor.first][hor.second]=-1;
			crono[hor.first][hor.second+1]=-1;
		}
	}
	return 0;
}
int main () {
	materias=profs;
	cin >> ncrono;
	for (int i = 0; i < profs; ++i)
	{
		dobra[i]=0;
	}
	for (int i=0; i<dias; i++){
		for (int j=0; j < aulas; j++){
			crono[i][j]=-1;
		}
	}
	for (int i = 0; i < materias; ++i){
		int naulas, dobradinha;
		cin >> disp[i].first;
		cin >> naulas;
		cin >> dobradinha;
		for (int j = 0; j < naulas; j++)
		{
			int dia, aula;
			cin >> dia;
			cin >> aula;
			dia=dia-2;
			aula--;
			disp[i].second.insert(make_pair(dia,aula));
		}
		if (dobradinha!=0){
			dobra[i]++;
			materias--;
		}
	}
	resolve(0);
	cout << "Não há mais cronogramas\n";
	return 0;
}
