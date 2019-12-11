#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;



class Mat3 {
public:
	Mat3() {
		val = new double* [3];
		for (int i = 0; i < 3; i++) {
			val[i] = new double[3];

		}
	}
	Mat3(const Mat3& r) {
		val = new double* [3];
		for (int i = 0; i != 3; i++) {
			val[i] = new double[3];
			for (int j = 0; j != 3; j++) {
				val[i][j] = r.val[i][j];
			}
		}

	}
	~Mat3() {
		for (int i = 0; i != 3; i++) {
			delete[]val[i];
		}
		delete[]val;
	}
	void print() {
		for (int i = 0; i != 3; i++) {

			for (int j = 0; j != 3; j++) {
				cout << val[i][j] << " ";
			}
			cout << endl;
		}
	}
	double* operator[](const int i)const {
		return val[i];
	}
	Mat3 operator+ (const Mat3& a) {
		Mat3 ans;
		for (int i = 0; i != 3; i++) {
			for (int j = 0; j < 3; j++) {
				ans[i][j] = val[i][j] + a.val[i][j];
			}
		}
		return ans;
	}
	Mat3 operator-() {
		Mat3 ans;
		for (int i = 0; i != 3; i++) {
			for (int j = 0; j < 3; j++) {
				ans[i][j] = -val[i][j];
			}
		}
		return ans;
	}
	Mat3 operator-(const Mat3& a) {
		Mat3 ans;
		for (int i = 0; i != 3; i++) {
			for (int j = 0; j < 3; j++) {
				ans[i][j] = val[i][j] - a.val[i][j];
			}
		}
		return ans;
	}
	//멤버로 구현할 수가 없음 숫자가 앞으로 가도록 nonmember로 구현해주어야 한다 
	Mat3 operator*(int a) {
		Mat3 ans;
		for (int i = 0; i != 3; i++) {
			for (int j = 0; j < 3; j++) {
				ans[i][j] = val[i][j] * a;
			}
		}
		return ans;
	}
	Mat3 operator++(int) {
		Mat3 ans;
		for (int i = 0; i != 3; i++) {
			for (int j = 0; j < 3; j++) {
				ans[i][j] = val[i][j]++;
			}
		}
		return ans;
	}
	Mat3 operator++() {
		Mat3 ans;
		for (int i = 0; i != 3; i++) {
			for (int j = 0; j < 3; j++) {
				ans[i][j] = ++val[i][j];
			}
		}
		return ans;
	}
	double** val;
};

void main() {
	Mat3 a, b;
	for (int i = 0; i != 3; i++) {
		for( int j = 0; j < 3; j++){
			a[i][j] = i * 3 + j;
			b[i][j] = 0.5 * j + i + 0.5;
}
	}

	a.print();
	b.print();
	(a + b).print();
	(-a - b).print();
	(a++).print();
	(++a).print();
	
}
















