#include<iostream>
#include<cmath>
#include<iomanip>
#include<array>
#include<iterator>
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
	array<T, ARRAY_LEN> arr;
public:
	NDIM(){}

	//setter
	void setPoint(array<T, ARRAY_LEN> inp_arr){arr = inp_arr;}

	//getter


	//print
	void printPoints(){
		cout << "\nPoints: \n";
		for(T i = arr.begin(); i != arr.end(); ++i){
			cout << "Var " << i << "/" << ARRAY_LEN << " = " << *i;
		}
	}

};
int main(){

	// FourD<double> point1;
	// FourD<double> point2;

	int dim = 5;
	string tmp;
	int arr_in;

	// // point1.setPoint(3456.345345, 45723.3646, 45734.56734, 67823.235345);
	// // point2.setPoint(34563.235346, 567567.457632, 235346.3452, 45745.3644356);
	// point1.setPoint(3456, 45723, 45734, 67823);
	// point2.setPoint(34563, 567567, 235346, 45745);


	// // point1.printPoints();
	// // point2.printPoints();


	// // cout << point1.getX();

	// Dist(point1, point2);


	// cout << "What dimensional you want to use? "; cin >> dim;

	NDIM<int, dim> pnt1;
	NDIM<int, dim> pnt2;

	array<int, dim> arr;
	for(int i = 0; i < dim; i++){
		cout << "Var " << i << "/" << dim << ": ";
		cin >> arr_in;
		arr.push_back(arr_in);
	}
	pnt1.setPoint(arr);
	pnt2.setPoint(arr);

	pnt1.printPoints();
	pnt2.printPoints();


	return 0;
}

