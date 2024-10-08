#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);

double distance(double x1, double y1, double z1, double x2, double y2, double z2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1));
}

double ternary_search(double Ax, double Ay, double Az,
    double Bx, double By, double Bz,
    double Cx, double Cy, double Cz) {
    double l = 0.0, r = 1.0;  // t = 0 ~ 1 범위 탐색

    while (r - l > 1e-9) {  
        double t1 = l + (r - l) / 3.0;
        double t2 = r - (r - l) / 3.0;

        // t1과 t2에서 선분 위의 점 계산
        double px1 = Ax + t1 * (Bx - Ax);
        double py1 = Ay + t1 * (By - Ay);
        double pz1 = Az + t1 * (Bz - Az);

        double px2 = Ax + t2 * (Bx - Ax);
        double py2 = Ay + t2 * (By - Ay);
        double pz2 = Az + t2 * (Bz - Az);

        // 두 점 사이의 거리 계산
        double dist1 = distance(px1, py1, pz1, Cx, Cy, Cz);
        double dist2 = distance(px2, py2, pz2, Cx, Cy, Cz);

        // 삼분 탐색
        if (dist1 > dist2)
            l = t1;
        else
            r = t2;
    }

    // 최종 최소 거리 계산
    double t = (l + r) / 2.0;
    double px = Ax + t * (Bx - Ax);
    double py = Ay + t * (By - Ay);
    double pz = Az + t * (Bz - Az);

    return distance(px, py, pz, Cx, Cy, Cz);
}


int main() {

	FASTIO;

    double Ax, Ay, Az, Bx, By, Bz, Cx, Cy, Cz;
    cin >> Ax >> Ay >> Az >> Bx >> By >> Bz >> Cx >> Cy >> Cz;

    // 선분과 점 사이의 최소 거리 출력 (소수점 6자리까지)
    cout << fixed << setprecision(6) << ternary_search(Ax, Ay, Az, Bx, By, Bz, Cx, Cy, Cz) << endl;

	return 0;
}