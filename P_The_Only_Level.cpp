#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main() {
    freopen("C:\\Users\\Mehedi\\Desktop\\codes\\jediacademy3.in.txt", "w", stdout);
    srand(time(NULL));
    // Generate test cases
    int cnt=0;
    while(true) {
        int n = rand() % 100 + 1;
        cnt+=n;
        if(cnt>10000)break;
        //int n=10;
        cout<<n<<endl;
    for (int i = 0; i < n; i++) {
        double x1 = (double)(rand() % 1000) / 100.0; // Random float between 0 and 1000 with 2 decimal places
        double y1 = (double)(rand() % 100) / 100.0;
        double x2 = (double)(rand() % 10000) / 100.0;
        double y2 = (double)(rand() % 10) / 100.0;
         cout << fixed << setprecision(2);
        cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    }
    }
    cout << "0" << endl;
    return 0;
}