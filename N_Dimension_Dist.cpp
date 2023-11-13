#include<iostream>
#include<cmath>
#include<iomanip>
#include <vector>

using namespace std;

template<typename T>
class NDIM{
private:
	vector<T> c_vector;
public:
	NDIM(){}

	NDIM(vector<T> inp_vector){c_vector = inp_vector;}

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

	int res = Dist(obj1, obj2);

	cout << "\nDist is:" << res << endl;

	return 0;
}

