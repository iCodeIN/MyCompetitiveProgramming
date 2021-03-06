/*************************************************************************
 *                                                                       *
 *                     XVI Olimpiada Informatyczna                       *
 *                                                                       *
 *   Zadanie:  Slonie (SLO)                                              *
 *   Plik:     slob3.cpp                                                 *
 *   Autor:    Pawel Parys                                               *
 *   Opis:     Rozwiazanie wzorcowe O(n) w ktorym brakuje long longow    *
 *                                                                       *
 *************************************************************************/

#include <cstdio>
#include <algorithm>

#define REP(a,n) for (int a=0; a<(n); ++a)

using namespace std;

#define INF 1000000000

///////////////////////////

#define MAXN 1000000

int wagi[MAXN];
int orig[MAXN]; // orig[i] = kto stal na pozycji i
int perm[MAXN]; // slon i ma wyladowac na pozycji slonia perm[i]
bool vis[MAXN]; // nalezy do juz zbadanego cyklu

int minw = INF; // minimalna waga

int main()
{
	int N;
	scanf("%d", &N);
	REP(a, N)
	{
		scanf("%d", &wagi[a]);
		minw = min(minw, wagi[a]);
	}
	REP(a, N)
	{
		scanf("%d", &orig[a]);
		--orig[a];
	}
	REP(a, N)
	{
		int nr;
		scanf("%d", &nr);
		--nr;
		perm[nr] = orig[a];
	}
	int wynik = 0;
	REP(pocz, N)
		if (!vis[pocz])
		{
			int minc = INF; // minimalna waga w cyklu
			int suma = 0; // suma wag w cyklu
			int cur = pocz;
			int dl = 0; // dlugosc cyklu
			for (;;) 
			{
				minc = min(minc, wagi[cur]);
				suma += wagi[cur];
				cur = perm[cur];
				vis[cur] = true;
				++dl;
				if (cur==pocz)
					break;
			}
			wynik += min(suma+(dl-2)*minc, suma+minc+(dl+1)*minw);
		}
	printf("%d\n", wynik);
}
