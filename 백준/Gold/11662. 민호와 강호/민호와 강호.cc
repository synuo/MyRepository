#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);

// 두 점 사이의 거리를 계산하는 함수
double distance(double x1, double y1, double x2, double y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// 삼분 탐색을 통해 두 사람의 최소 거리를 찾는 함수
double ternary_search(double Ax, double Ay, double Bx, double By,
    double Cx, double Cy, double Dx, double Dy) {
    double l = 0.0, r = 1.0;  // t = 0 ~ 1 사이에서 탐색

    while (r - l > 1e-9) {  // 오차 범위를 1e-9로 설정
        double t1 = l + (r - l) / 3;
        double t2 = r - (r - l) / 3;

        // 시간 t1과 t2에서 민호와 강호의 위치 계산
        double mx1 = Ax + (Bx - Ax) * t1;
        double my1 = Ay + (By - Ay) * t1;
        double gx1 = Cx + (Dx - Cx) * t1;
        double gy1 = Cy + (Dy - Cy) * t1;

        double mx2 = Ax + (Bx - Ax) * t2;
        double my2 = Ay + (By - Ay) * t2;
        double gx2 = Cx + (Dx - Cx) * t2;
        double gy2 = Cy + (Dy - Cy) * t2;

        // 두 사람 사이의 거리 계산
        double dist1 = distance(mx1, my1, gx1, gy1);
        double dist2 = distance(mx2, my2, gx2, gy2);

        // 삼분 탐색 조건
        if (dist1 > dist2)
            l = t1;
        else
            r = t2;
    }

    // 최소 거리를 계산
    double t = (l + r) / 2;
    double mx = Ax + (Bx - Ax) * t;
    double my = Ay + (By - Ay) * t;
    double gx = Cx + (Dx - Cx) * t;
    double gy = Cy + (Dy - Cy) * t;

    return distance(mx, my, gx, gy);
}



int main() {

	FASTIO;

	int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
	cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> Dx >> Dy;

	// 최소 거리 출력 (소수점 6자리까지 출력)
	cout << fixed << setprecision(6) << ternary_search(Ax, Ay, Bx, By, Cx, Cy, Dx, Dy) << endl;

	return 0;

	return 0;
}