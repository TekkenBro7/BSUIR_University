#include <iostream>
#include <cmath>
using namespace std;
int main() {
    long double W, H, x1, y1, x2, y2, w, h, r;
    cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
    if (w <= W && h <= H) {
        if (w <= x1 && h <= y1) {
            cout << 0;
        }
        else if ((w >= x1 && h <= y1) || (h >= y1 && w <= x1)) {
            cout << 0;
        }
        else if (w > x1 && h > y1 && w < x2 && h < y2 && h + (y2 - y1) > H && w + (x2 - x1) <= W) {
            r = w - x1;
            cout << r;
        }
        else if (w > x1 && h > y1 && w < x2 && h < y2 && h + (y2 - y1) <= H && w + (x2 - x1) > W) {
            r = h - y1;
            cout << r;
        }
        else if (w > x1 && h > y1 && w < x2 && h < y2 && h + (y2 - y1) <= H && w + (x2 - x1) <= W) {
            if (w - x1 < h - y1) {
                r = w - x1;
                cout << r;
            }
            else if (h - y1 < w - x1) {
                r = h - y1;
                cout << r;
            }
            else if (h - y1 == w - x1) {
                r = w - x1;
                cout << r;
            }
        }
        else if (w > x1 && h > y1 && w == x2 && h == y2 && h + (y2 - y1) <= H && w + (x2 - x1) <= W) {
            r = w - x1;
            cout << r;
        }
        else if (w > x1 && h > y1 && w > x2 && h > y2 && h + (y2 - y1) <= H && w + (x2 - x1) <= W) {
            if (w - x1 < h - y1) {
                r = w - x1;
                cout << r;
            }
            else if (h - y1 < w - x1) {
                r = h - y1;
                cout << r;
            }
            else if (h - y1 == w - x1) {
                r = h - y1;
                cout << r;
            }
        }
        else if (w > x1 && h > y1 && w == x2 && h < y2 && h + (y2 - y1) <= H && w + (x2 - x1) <= W) {
            r = h - y1;
            cout << r;
        }
        else if (w > x1 && h > y1 && w < x2 && h == y2 && h + (y2 - y1) <= H && w + (x2 - x1) <= W) {
            r = w - x1;
            cout << r;
        }

        else if (w > x1 && h > y1 && h == y2 && w > x2 && h + (y2 - y1) <= H && w + (x2 - x1) <= W) {
            r = h - y1;
            cout << r;
        }
        else if (w > x1 && h > y1 && h > y2 && w == x2 && h + (y2 - y1) <= H && w + (x2 - x1) <= W) {
            r = w - x1;
            cout << r;
        }

        else if (w > x1 && h > y1 && h == y2 && w == x2 && h + (y2 - y1) > H && w + (x2 - x1) <= W) {
            r = w - x1;
            cout << r;
        }
        else if (w > x1 && h > y1 && h > y2 && w > x2 && h + (y2 - y1) > H && w + (x2 - x1) <= W) {
            r = w - x1;
            cout << r;
        }
        else if (w > x1 && h > y1 && h == y2 && w > x2 && h + (y2 - y1) > H && w + (x2 - x1) <= W) {
            r = w - x1;
            cout << r;
        }
        else if (w > x1 && h > y1 && h > y2 && w == x2 && h + (y2 - y1) > H && w + (x2 - x1) <= W) {
            r = w - x1;
            cout << r;
        }
        else if (w > x1 && h > y1 && h == y2 && w < x2 && h + (y2 - y1) > H && w + (x2 - x1) <= W) {
            r = w - x1;
            cout << r;
        }
        else if (w > x1 && h > y1 && h > y2 && w < x2 && h + (y2 - y1) > H && w + (x2 - x1) <= W) {
            r = w - x1;
            cout << r;
        }
        else if (w > x1 && h > y1 && h == y2 && w == x2 && h + (y2 - y1) <= H && w + (x2 - x1) > W) {
            r = h - y1;
            cout << r;
        }
        else if (w > x1 && h > y1 && h > y2 && w > x2 && h + (y2 - y1) <= H && w + (x2 - x1) > W) {
            r = h - y1;
            cout << r;
        }
        else if (w > x1 && h > y1 && h > y2 && w == x2 && h + (y2 - y1) <= H && w + (x2 - x1) > W) {
            r = h - y1;
            cout << r;
        }
        else if (w > x1 && h > y1 && h == y2 && w > x2 && h + (y2 - y1) <= H && w + (x2 - x1) > W) {
            r = h - y1;
            cout << r;
        }
        else if (w > x1 && h > y1 && h < y2 && w == x2 && h + (y2 - y1) <= H && w + (x2 - x1) > W) {
            r = h - y1;
            cout << r;
        }
        else if (w > x1 && h > y1 && h < y2 && w > x2 && h + (y2 - y1) <= H && w + (x2 - x1) > W) {
            r = h - y1;
            cout << r;
        }
        else if (h + (y2 - y1) > H && w + (x2 - x1) > W) {
            cout << -1;
        }
    }
    return 0;
}