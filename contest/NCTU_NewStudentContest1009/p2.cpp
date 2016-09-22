#include<bits/stdc++.h>
using namespace std;

double PI = acos(-1);
double g = 9.8;
struct Bomb {
    int x, y, z;
    int v;
} bomb;

struct Building {
    int x, y, z;
    int h;
} building;

struct Target {
    int x, y, z;
} target;

void input() {
    cin >> bomb.v;
    cin >> bomb.x >> bomb.y >> bomb.z;
    cin >> target.x >> target.y >> target.z;
    cin >> building.x >> building.y >> building.z;
    cin >> building.h;
}

double get_delta(double x, double y) {
    double res = 180*atan2(y, x)/PI;
    return ((res >= 0) ? res : (res + 360));
}

double to_hodo(double delta) {
    return PI*delta/180;
}

double get_value(double delta, double d, double v, double h) {
    double res = tan(to_hodo(delta))*d - g*d*d/(2*v*v*cos(to_hodo(delta))*cos(to_hodo(delta))) - h;
    return res;
}

double get_h_delta() {
    double v = bomb.v, d = sqrt((target.x-bomb.x)*(target.x-bomb.x) + (target.y-bomb.y)*(target.y-bomb.y)),
           h = target.z - bomb.z;
    double lo = 9, hi = 46, mid;
    double eps = 0.00001;
    while ( hi - lo > eps ) {
        double mid = (hi+lo)/2;
        if ( get_value(mid, d, v, h) > 0 ) hi = mid;
        else lo = mid;

    }
    return lo;
}

double get_b_delta() {
    double v = bomb.v, d = sqrt((building.x-bomb.x)*(building.x-bomb.x) + (building.y-bomb.y)*(building.y-bomb.y)),
           h = building.z + building.h - bomb.z;
    double lo = 5, hi = 80, mid;
    double eps = 0.00001;

    //cout << v << " " << d << " " << h << endl;

//    for ( int i = 5 ; i < 80 ; i++ ) {
//        cout << "(" << i << ", " << v << " " << d << " " << h << " = " << get_value(i, d, v, h) << endl;
//    }

    while ( hi - lo > eps ) {
        double mid = (hi+lo)/2;
        if ( get_value(mid, d, v, h) > 0 ) hi = mid;
        else lo = mid;
    }
//    printf("building: %.4f\n", lo);
    if ( lo < 9 ) lo = 5;
    if ( lo > 45 ) lo = 50;
    return lo;
}


bool is_direction_danger() {
//    printf("d1 %d %d\n", target.x-bomb.x, target.x-bomb.y);
    double delta1 = get_delta(target.x-bomb.x, target.y-bomb.y);
    double delta2 = get_delta(building.x-bomb.x, building.y-bomb.y);
//    printf("dir %.4f, %.4f\n", delta1, delta2);
    return fabs(delta1-delta2) < 1; // eps?
}

bool is_safe() {
//    printf("dist to building: %.4f, dist to target: %.4f\n", sqrt( (building.x-bomb.x) * (building.x-bomb.x) + (building.y-bomb.y) * (building.x-bomb.x)),
//           sqrt( (target.x-bomb.x) * (target.x-bomb.x) + (target.y-bomb.y) * (target.x-bomb.x)  ));
    if ( sqrt( (building.x-bomb.x) * (building.x-bomb.x) + (building.y-bomb.y) * (building.x-bomb.x)  )
     <   sqrt( (target.x-bomb.x) * (target.x-bomb.x) + (target.y-bomb.y) * (target.x-bomb.x)  )
         ) { // if bomb, building, target
//        printf("to building: %.4f , to target: %.4f\n", get_b_delta(), get_h_delta());
        if ( get_h_delta() - get_b_delta() > 1 || get_b_delta() == 5 ) { // eps
            return true;
        } else {
            return false;
        }
    } else {
        return true;
    }
}

void solve() {
    if ( is_direction_danger() ) {
        if ( is_safe() ) {
            printf("火砲射擊的方位角: %.4f\n", get_delta(target.x-bomb.x, target.y-bomb.y) );
            printf("火砲射擊的仰角: %.4f\n", get_h_delta() );
            cout << "是否可以安全射擊: Yes" << endl;
        } else {
            printf("火砲射擊的方位角: %.4f\n", get_delta(target.x-bomb.x, target.y-bomb.y) );
            printf("火砲射擊的仰角: %.4f\n", get_h_delta() );
            cout << "是否可以安全射擊: No" << endl;
        }
    } else {
        printf("火砲射擊的方位角: %.4f\n", get_delta(target.x-bomb.x, target.y-bomb.y) );
        printf("火砲射擊的仰角: %.4f\n", get_h_delta() );
        cout << "是否可以安全射擊: Yes" << endl;
    }
}


int main() {
    freopen("data25.txt","r",stdin);
    input();
    solve();
}
