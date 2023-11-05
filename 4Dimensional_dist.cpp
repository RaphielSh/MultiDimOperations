#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

template<class T>
class FourD{
private:
	T x;
	T y;
	T z;
	T k;
public:
	FourD(){x = 0.0; y = 0.0; z = 0.0; k = 0.0;}
	//setter
	void setPoint(T a, T b, T c,T d){
		x = a;
		y = b;
		z = c;
		k = d;
	}
	//getters
	T getX(){return x;}
	T getY(){return y;}
	T getZ(){return z;}
	T getK(){return k;}

	template<class U>
	void Dist(){}

	//print
	void printPoints(){cout << setprecision(15);cout << "\n X = " << x << " Y = " << y << " Z = " << z << " K = " << k << endl;}
};

template <class T>
T Square(T x){return pow(x, 2);}

template <class T>
void Dist(T object, T object2){
	cout << "Sqrt( (xᵦ - xₐ)² + (yᵦ - yₐ)² + (zᵦ - zₐ)² + (kᵦ - kₐ)² )" << endl;
	cout << "First point: ";
	object.printPoints();
	cout << "Second point: ";
	object2.printPoints();
	long double res = sqrt( Square(object2.getX() - object.getX()) + Square(object2.getY() - object.getY()) + Square(object2.getZ() - object.getZ()) + Square(object2.getK() - object.getK()) );
	cout << "Distance between A and B = " << res << endl;
}

template<class T, int ARRAY_LEN>
class NDIM{
private:
	int dimension;
	T arr[ARRAY_LEN];
public:
	NDIM(){}

	//setter
	void setPoint(double inp[ARRAY_LEN]){arr = inp;}

	//getter


	//print
	void printPoints(){
		cout << "\nPoints: \n";
		for(int i = 0; i < ARRAY_LEN; i++){
			cout << "Var " << i << "/" << ARRAY_LEN << " = " << arr[i];
		}
	}

};

// int lol(int dim){cin>> dim; return dim}

int main(){

	// FourD<double> point1;
	// FourD<double> point2;

	const int dim;
	double tmp;
	double arr_in[dim];

	// // point1.setPoint(3456.345345, 45723.3646, 45734.56734, 67823.235345);
	// // point2.setPoint(34563.235346, 567567.457632, 235346.3452, 45745.3644356);
	// point1.setPoint(3456, 45723, 45734, 67823);
	// point2.setPoint(34563, 567567, 235346, 45745);


	// // point1.printPoints();
	// // point2.printPoints();


	// // cout << point1.getX();

	// Dist(point1, point2);


	cout << "What dimensional you want to use? "; cin >> dim;


	NDIM<double, dim> pnt1;
	NDIM<double, dim> pnt2;

	for(int i = 0; i < dim; i++){
		cout << "Var " << i << "/" << dim << ": ";
		cin >> arr_in[i];
	}
	pnt1.setPoint(arr_in);
	pnt2.setPoint(arr_in);

	pnt1.printPoints();
	pnt2.printPoints();


	return 0;
}

