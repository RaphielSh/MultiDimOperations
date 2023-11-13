#include<iostream>
#include<cmath>
#include<iomanip>
#include <vector>

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

template<typename T>
class NDIM{
private:
	vector<T> c_vector;

public:
	NDIM(){}

	NDIM(vector<T> inp_vector){c_vector = inp_vector;}

	//getters
	size_t getSize(){return c_vector.size();}

	//print
	void printPoints(){
		cout << "\nPoints: \n";
		for( typename vector<T>::iterator it = c_vector.begin();it != c_vector.end(); it++)
			cout << *it << " ";
		cout << endl;
	}
	// istream& operator >> (istream& stream, NDMIN& dim){
	// 	dim.pushBack()
	// }
	friend T Dist(NDIM& obj1, NDIM& obj2);
};

template<class T>
vector<T> VectorInsert(vector<T>& inp_vector, size_t dim){	
	T tmp;
	for(size_t i = 0; i < dim; i++){
		cout << "Var " << i << "/" << dim << ": ";
		cin >> tmp;
		inp_vector.push_back(tmp);
	}
	inp_vector.shrink_to_fit();
	return inp_vector;
}

template<class T>
T Dist(NDIM<T>& obj1, NDIM<T>& obj2){
	T res = 0;
	vector<T>::iterator it1 = obj1.c_vector.begin();
	vector<T>::iterator it2 = obj2.c_vector.begin();
	for( ; it1 != obj1.c_vector.end(); it1++, it2++){
		res = 0;
	}
}

int main(){
	size_t dim;
	double tmp;
	

	vector<int> inp_vector;
	cout << "What dimensional you want to use? "; cin >> dim;

	VectorInsert(inp_vector, dim);

	NDIM obj1(inp_vector);

	inp_vector.clear();
	VectorInsert(inp_vector, dim);
	NDIM obj2(inp_vector);

	obj1.printPoints();

	obj2.printPoints();


	return 0;
}

