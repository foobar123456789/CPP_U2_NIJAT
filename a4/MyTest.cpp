#include <iostream>
#include "levenshtein.hpp"

using namespace std ;

int main() {
	bool res = levenshtein_distance("Katze", "katze") == 1;
	cout << "res = " << res << endl ;
	return 0 ;
}
