#include<iostream>
using namespace std;

int ranks[100005];
int totalparathas, n;

bool kyaparathebanpaaye(int d){
    int parathas = 0;                        //count total paratha in mid time 
    for (int i = 0; i < n; i++){
		int minutes = 0;
        int parathabyr = 1;                 //count paratha rank wise
        while (minutes + (ranks[i] * parathabyr) <= d){
			parathas++;
			minutes += ranks[i] * parathabyr;
            parathabyr++;
		}
    }
    if (parathas >= totalparathas) return true;
    else return false;
}

int main(){
    cin >> totalparathas;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> ranks[i];
    }
	// sort(ranks, ranks + n);
    int s = 0;
    int e = ranks[n-1] * (totalparathas * (totalparathas + 1));
    int ans = 0;
    while (s <= e){
        int mid = s + (e - s) / 2;
        if (kyaparathebanpaaye(mid)){
            ans = mid;
            e = mid - 1;                // agr mid time me jitne paranthe bane wo total se jyada ya barabar ho to usse jyada m bhi bn jaenge
        }else{
            s = mid + 1;                // nhi toh time bda kr check kro
        }
    }
    cout << ans;
}