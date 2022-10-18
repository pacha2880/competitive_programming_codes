#include <bits/stdc++.h>
//estos son macros para escribir mas rapido
#define mp					make_pair
#define pb					push_back
#define f 					first
#define s 					second
#define sz(a)				a.size()
#define fore(i, b, e)		for(int i = b; i < e; i++)
#define forn(i, n)			for(int i = 0; i < n; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
//si no esta esta linea se tiene que poner std:: cada vez que se use algo de esa libreria
using namespace std;
//acortar el tipo long long a ll
typedef long long 		ll;
//constantes
const int MOD = 1e9+7;
const double EPS = 1e-9;
const int tam = 100010;


int main()
{
	//descomentar esta linea si en el input hay mas de 10^5 elementos
	//ios::sync_with_stdio(0); cin.tie(0);

	//para leer y escribir archivos, solo se cambia lo que esta entre comillas para ver donde
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);

	int a, b;
	string s = "hola", nom;
	cout<<"ingrese 2 numeros\n";
	cin>>a>>b;
	cout<<"los numeros son\n";
	//en c++ no se pueden sumar enteros con strings
	cout<<a<<' '<<b<<'\n'; //'\n' es salto de linea
	cout<<"ingresa tu nombre\n";
	cin>>nom;
	cout<<s<<' '<<nom<<'\n';

	//asi son los arreglos
	int ar[3];
	ar[0] = 1;
	ar[1] = 2;
	ar[2] = 3;
	cout<<"el arreglo\n";
	for(int i = 0; i < 3; i++)
		cout<<ar[i]<<'\n';

	//equivalente a arraylist (no se necesita hacer new)
	vector<int> vec;
	for(int i = 0; i < 10; i++)
		vec.push_back(10 - i);
	//con macro
	vec.pb(123);
	cout<<"los numeros del vector\n";
	for(int i = 0; i < vec.size(); i++)
	{
		cout<<vec[i]<<' ';
	}
	cout<<'\n';
	//ordenar vector
	sort(vec.begin(), vec.end());
	cout<<"los numeros del vector ordenado\n";
	for(int i = 0; i < vec.size(); i++)
	{
		cout<<vec[i]<<' ';
	}
	cout<<'\n';

	//los pares son muy utiles
	//pair<tipo, tipo>
	pair<int, int> a1(3, 4), b1;
	a1 = {3, 4};
	b1 = make_pair(5, 4);
	//con macro
	b1 = mp(4, 5);
	cout<<"a1.first<<' '<<a1.f<<' '<<a1.s<<' '<<a1.second\n";
	cout<<a1.first<<' '<<a1.f<<' '<<a1.s<<' '<<a1.second<<'\n';;
	pair<int, int> ar1[3];
	ar1[0] = b1;
	ar1[1] = a1;
	ar1[2] = {3, 2};
	//se comparan lexicograficamente primero first y luego second
	//ordenar arreglo
	sort(ar1, ar1 + 3);
	cout<<"arreglo de pairs ordenado\n";
	fore(i, 0, 3)
		cout<<ar1[i].f<<' '<<ar1[i].s<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	