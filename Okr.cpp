#include <iostream>
#include <fstream>
#include <cmath>
#include <stdlib.h>

using namespace std;

int main(){
    setlocale(LC_ALL, "rus");
    double x1, y1, x2, y2;
    double a, b, c;

    ifstream inputCoor("input.txt");
    inputCoor >> x1;
    inputCoor >> y1;
    inputCoor >> x2;
    inputCoor >> y2;
    inputCoor.close();
    cout << "First coordinate: " << x1 << " " << y1 << endl;
    cout << "Second coordinate: " << x2 << " " << y2 << endl;
        const float e = 10e-8;
        c = abs((y2 * x1 - x2 * y1) / sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
        a = sqrt(pow(x1, 2) + pow(y1, 2));
        b = sqrt(pow(x2, 2) + pow(y2, 2));
        int count = 0;
        if (x1!= x2 or y1 != y2){
            if ((2 * x1 * x1 - 2 * x1 * x2 + 2 * y1 * y1 - 2 * y1 * y2 < 0) or (2 * x2 * x2 - 2 * x1 * x2 + 2 * y2 * y2 - 2 * y1 * y2 < 0))
                count = (int)(max(a, b) + e) - (int)(min(a, b) - e);
            else {
                count = (int)(a + e) - (int)(c - e);
                count = count + (int)(b + e) - (int)(c - e);
                if ((abs(round(c) - c) < e) and (abs(c) > e)) {
                    count--;
                }
            }
        }
        else {
            count = 0;
        }
        cout << "Intersections: " << count;


    ofstream outputCount("output.txt");
    outputCount << count;
    outputCount.close();
    return 0;
}
