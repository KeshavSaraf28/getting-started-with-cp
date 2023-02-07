// Problem statment
// while(n>1) do
// if n%2=0
// {
//     n/=2;
// }
// else{
//     n=n*3+3;
// }
// will it stop?
// output "TAK" for yes and "NIE" for no
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    ll k = (n + (n - 1)) & n; // bitwise And of n and n+(n-1) gives n if n=pow(2,z).
    if (n == k)
        cout << "TAK";
    else
        cout << "NIE";

    return 0;
}