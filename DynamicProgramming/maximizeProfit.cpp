#include <bits/stdc++.h>
using namespace std;


int dp[1000][1000];

class job{
public:

    int finish,deadline,profit;

    job(){}

    job(int f, int d, int p){
        this->finish = f;
        this->deadline = d;
        this->profit = p;
    }
};

bool cmp(job a, job b){
    if (a.deadline == b.deadline){
        return a.profit > b.profit;
    }
    return a.deadline < b.deadline;
}


void printsc(int n, int d, job a[]){
    if (n==0) return;
    if (dp[n][d] == dp[n-1][d]){
        printsc(n-1,d, a);
    }
    else{
        printsc(n-1,min(d,a[n].deadline) - a[n].finish,a);
        cout<<"schedule job "<<n<<" at "<<min(d,a[n].deadline) - a[n].finish<<"\n";
    }
}

int maximizeProfit(job a[], int n, int d){
    int currenttime = 0;
    for (int i = 0; i < n+1; i++){
        currenttime = 0;
        for (int j = 0; j < d+1; j++){
            if (i==0 || j==0){
                dp[i][j] = 0;
            }
            else if (currenttime + a[i].finish <= j && j <= a[i].deadline && j >= a[i].finish){
                dp[i][j] = max(a[i].profit + dp[i-1][j-a[i].finish], dp[i-1][j]);
                if (dp[i][j] == a[i].profit + dp[i-1][j-a[i].finish])
                currenttime += a[i].finish;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    printsc(n,d,a);
    return dp[n][d];
}

// int maximizeProfit(job a[], int n, int d){
//     int currenttime = 0;
//     for (int i = 0; i < n+1; i++){
//         currenttime = 0;
//         for (int j = 0; j < d+1; j++){
//             if (i==0){
//                 dp[i][j] = 0;
//             }
//             else if (min(j,a[i].deadline) - a[i].finish >= 0){
//                 dp[i][j] = max(a[i].profit + dp[i-1][min(j,a[i].deadline) - a[i].finish], dp[i-1][j]);
//             }
//             else{
//                 dp[i][j] = dp[i-1][j];
//             }
//         }
//     }
//     printsc(n,d,a);
//     return dp[n][d];
// }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin>>n;
    int f,d,p;
    job* a = new job[n+1];
    a[0] = job(0,0,0);
    for (int i = 1; i < n+1; i++){
        cin>>f>>d>>p;
        a[i] = job(f,d,p);
    }
    sort(a, a+n+1, cmp);
    d = a[n].deadline;
    cout<<maximizeProfit(a,n,d);
    return 0;
}