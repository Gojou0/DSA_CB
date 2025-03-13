#include<iostream>
using namespace std;

int a[100005];
int n, students;

bool kyabooksbatpayi(int d){
    int student = 1;
    int pages = 0;
    for (int i = 0; i < n; i++){
        if (pages + a[i] <= d){                 // agr pages count allowed pages se kam h ya barabar h to kitab dedo ek hi student ko
            pages += a[i];
        }else{
            student++;                          // agr nhi h ... to naye student ko do
            pages = a[i];
        }
    }
    if (student <= students) return true;
    else return false;
}

int main(){
    int t; cin >> t;

    while (t--){
        cin >> n >> students;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        int s = 0;
        int e = 0;
        int ans = 0;
        for (int i = 0; i < n; i++){
            s = max(s, a[i]);
            e += a[i];
        }
        while (s <= e){
            int mid = s + (e - s) / 2;
            if (kyabooksbatpayi(mid)){
                ans = mid;
                e = mid - 1;                // agr mid m partition kr dia to usse jyada me bhi ho jaega ..isliye jyada wali range hata di
            }else{
                s = mid + 1;                // aggr mid m partition(booksbatpayi) nhi hua to jyada wali range m check kro
            }
        }
        cout << ans;
    }
}