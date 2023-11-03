#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

class FourD{
private:
	long int x;
	long int y;
	long int z;
	long int k;
public:
	FourD(){x = 0.0; y = 0.0; z = 0.0; k = 0.0;}
	//setter
	void setPoint(long int a, long int b, long int c,long int d){
		x = a;
		y = b;
		z = c;
		k = d;
	}
	//getters
	long int getX(){return x;}
	long int getY(){return y;}
	long int getZ(){return z;}
	long int getK(){return k;}

	//print
	void printPoints(){cout << "\n X = " << x << " Y = " << y << " Z = " << z << " K = " << k << endl;}
};

long long int Square(long int x){return pow(x, 2);}

void Dist(FourD object, FourD object2){
	cout << "Sqrt( (xᵦ - xₐ)² + (yᵦ - yₐ)² + (zᵦ - zₐ)² + (kᵦ - kₐ)² )" << endl;
	cout << "First point: ";
	object.printPoints();
	cout << "Second point: ";
	object2.printPoints();
	long int res = sqrt( Square(object2.getX() - object.getX()) + Square(object2.getY() - object.getY()) + Square(object2.getZ() - object.getZ()) + Square(object2.getK() - object.getK()));
	cout << "Distance between A and B = " << res << endl;
}


int main(){

	FourD point1;
	FourD point2;

	point1.setPoint(3456, 45723, 45734, 67823);
	point2.setPoint(34563, 567567, 235346, 45745);

	Dist(point1, point2);
	return 0;
}
