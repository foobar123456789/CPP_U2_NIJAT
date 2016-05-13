#include <iostream>
using namespace std ;

int main() {
    string* names = new string[3];
    names[0] = "foo";
    names[1] = "bar";
    for(int i = 0 ; i< 3 ; ++i)
    	cout << names[i] << endl ;

    int* numbers = new int[3];
    numbers[0] = 100 ;
    numbers[1] = 200 ;
    cout << numbers[0] << " , " << numbers[1] << " , " << numbers[2] << endl ;
	return 0;
}
