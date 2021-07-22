#include<bits/stdc++.h>
#define profs dias*aulas
const int dias = 5;
const int aulas = 6;
using namespace std;
int crono[dias][aulas];
int c=0;
string semana[5] = {"Segunda:  ", "Terça:    ", "Quarta:   ", "Quinta:   ", "Sexta:    "};
pair<string, set<pair<int,int> > > disp[profs];

int resolve (int i){
	if (i>=profs) {
		for (int h = 0; h < dias; ++h){
			cout << semana[h];
			for (int j = 0; j < aulas; ++j){
				cout << disp[crono[h][j]].first << "\t";
			}
			cout << "\n";
		}
		cout << "\n\n";
		return 0;
	}
	for (auto hor: disp[i].second){
		if (crono[hor.first][hor.second]==-1){
			crono[hor.first][hor.second]=i;
			resolve (i+1);
			crono[hor.first][hor.second]=-1;
		}
	}
	return 0;
}
int main () {
	for (int i=0; i<dias; i++){
		for (int j=0; j < aulas; j++){
			crono[i][j]=-1;
		}
	}
	for (int i = 0; i < profs; ++i){
		int naulas;
		cin >> disp[i].first;
		cin >> naulas;
		for (int j = 0; j < naulas; j++)
		{
			int dia, aula;
			cin >> dia;
			cin >> aula;
			dia=dia-2;
			aula--;
			disp[i].second.insert(make_pair(dia,aula));
		}
	}
	resolve(0);
	cout << "Não há mais cronogramas\n";
	return 0;
}
