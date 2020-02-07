#include <iostream>
#include <cmath>
using namespace std;

const int N = 32;
const int M = 72;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M];
    int s,x,y;
    
    // init image
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            image[row][col] = false;
        }
    }
    
    do {
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    } while(s != 0 && x != 0 && y != 0 );
    
    return 0;
}

// Write definition of updateImage() and showImage() here
void updateImage(bool img[][M], int bushSize, int x, int y) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            int a = pow(row-x, 2);
            int b = pow(col-y, 2);
            if (sqrt(a + b) <= bushSize-1)
                img[row + 1][col + 1] = true;
        }
    }
}

void showImage(const bool img[][M]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            if (row == 0 || row == N-1) cout << '-';
            else if (col == 0 || col == M-1) cout << '|';
            else if (img[row][col]) cout << '*';
            else cout << ' ';
        }
        cout << endl;
    }
}
