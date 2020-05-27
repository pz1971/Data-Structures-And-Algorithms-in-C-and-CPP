#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

string BWT(const string &text)
{
	string result = "" ;
	
	vector<string> matrix ;
	for(int i = 0 ; i < text.size() ; i++){
		matrix.push_back( text.substr(i) + text.substr(0, i) ) ;
	}
	
	sort(matrix.begin(), matrix.end()) ;
	for(const auto &i : matrix)
		result.push_back(i.back()) ;

	return result;
}

int main()
{
	string text;
	cin >> text;
	cout << BWT(text) << endl;
	return 0;
}