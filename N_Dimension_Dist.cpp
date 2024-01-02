#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
#include<numbers>
#include<array>
#include<format>
#include<cstdint>

//stupid, fix
using namespace std;

template<typename T>
class NDIM{
private:
	vector<T> c_vector;
public:
	NDIM(){}

	NDIM(NDIM &other):c_vector(other.c_vector),size(other.size){};

	NDIM(vector<T> &inp_vector):c_vector(inp_vector),size(inp_vector.size()){};

	uint64_t size;
	//int64_t size; // не хочешь сделать математику для отрицательных измерений?)

	//print
	void printPoints(){
		cout << "\nPoints: \n";
		for( typename vector<T>::iterator it = c_vector.begin();it != c_vector.end(); it++)
			cout << *it << " ";
		cout << endl;
	}
	template <typename K> friend K Dist(NDIM<K>& obj1, NDIM<K>& obj2);
};

template<class T>
vector<T> VectorInsert(vector<T>& inp_vector, size_t dim){	
	T tmp;
	for(size_t i = 1; i <= dim; i++){
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
	typename vector<T>::iterator it1 = obj1.c_vector.begin();
	typename vector<T>::iterator it2 = obj2.c_vector.begin();
	for( ; it1 != obj1.c_vector.end(); it1++, it2++)
		res += pow(*it2-*it1, 2);
	return sqrt(res);
}

template<class T>
struct Hypersphere{
	NDIM<T> center; //center of the sphere
	T radius;
	Hypersphere(NDIM<T> center,T radius):center(center),radius(radius){}

	//Vn=CnR^n
	//         pi^(n/2)
	//Cn =  --------------
	//      gamma((n/2)+1)
	//TODO:
	//user-defined pi
	//user-defined floating point class for more accuracy
	//user-defined POW
	//user-defined gammafunc
	T volume(){
		return (pow(std::numbers::pi,(static_cast<long double>(center.size)/2))/tgamma((static_cast<long double>(center.size)/2)+1)) 
		* pow(radius,static_cast<long double>(center.size));
	}


};

//long double
template<class T>
bool HypersphereTest(){
	bool passed = true;
	//hypesphere in 0,0...0
	//radius = 1
	cout << "hypersphere in 0,0...0\nradius=1" << endl;
	array<long double,20> answers1 = {1, 2, 3.141592654, 4.188790205, 4.934802201,
	       	5.263789014, 5.167712780, 4.724765970, 4.058712126, 3.298508903, 2.550164040, 1.884103879,
	       	1.335262769, 0.910628755, 0.599264529, 0.381443281, 0.235330630, 0.140981107, 0.082145887,
	       	0.046621601};
	vector<T> init = {};
	NDIM dims(init);
	for(int i =0; i<20;i++){
		NDIM dims(init);
		Hypersphere<T> s(dims,1.0);
		//check stupid af
		//maybe std::numeric_limits<T>::epsilon()?
		if( abs(s.volume() - answers1[i]) > 0.000000001 ){
			passed = false;
			cout << "Error i=" << i << " calc volume: " << s.volume() << " Expected: " <<answers1[i] << endl;
		}
		init.push_back(0);
	}
	return passed;
}


int main(){
	size_t dim;
	double tmp;
	

	vector<int> inp_vector;
	cout << "What dimensional you want to use? "; cin >> dim;

	VectorInsert(inp_vector, dim);

	NDIM obj1(inp_vector);
	NDIM obj1_c(obj1);

	obj1.printPoints();
	obj1_c.printPoints();

	int res = Dist(obj1, obj1_c);

	cout << "\nDist is:" << res << endl;

	return 0;
}

