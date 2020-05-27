#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::istringstream;
using std::map;
using std::string;
using std::vector;

// Preprocess the Burrows-Wheeler Transform bwt of some text
// and compute as a result:
//   * starts - for each character C in bwt, starts[C] is the first position
//       of this character in the sorted array of
//       all characters of the text.
//   * occ_count_before - for each character C in bwt and each position P in bwt,
//       occ_count_before[C][P] is the number of occurrences of character C in bwt
//       from position 0 to position P inclusive.
void PreprocessBWT(const string &bwt,
				   map<char, int> &starts,
				   map<char, vector<int>> &occ_count_before)
{
	map<char, int> cumulative ;
	for(auto i : bwt)
		cumulative[i]++ ;
	for(auto i = cumulative.begin() ; i != cumulative.end() ; i++){
		auto j = i ;
		if(++j != cumulative.end())
			j -> second += i -> second ;
	}

	starts[(cumulative.begin()) -> first] = 0 ;
	for(auto i = cumulative.begin() ; i != cumulative.end() ; i++){
		auto j = i ;
		if(++j != cumulative.end()){
			starts[j -> first] = i -> second ;
		}
	}

	for(auto &i : starts){
		occ_count_before[i.first] = vector<int> (bwt.size() + 2, 0) ;	// initializing the matrix
	}
	for(int i = 0 ; i < bwt.size() ; i++){
		occ_count_before[ bwt[i] ][i + 1] = 1 ;
	}
	for(auto &i : occ_count_before){	// cumulative helps here
		for(int j = 1 ; j < i.second.size() ; j++)
			i.second[j] += i.second[j-1] ;
	}
}

// Compute the number of occurrences of string pattern in the text
// given only Burrows-Wheeler Transform bwt of the text and additional
// information we get from the preprocessing stage - starts and occ_counts_before.
int CountOccurrences(string pattern,
					 const string &bwt,
					 map<char, int> &starts,
					 map<char, vector<int>> &occ_count_before)
{
	int top = 0 ;
	int bottom = bwt.length() - 1 ;

	while(top <= bottom){
		if(!pattern.empty()){
			char symbol = pattern.back() ;
			pattern.pop_back() ;

			if(!starts.count(symbol))	// symbol doesn't exist in the pattern.
				return 0 ;

			top = starts[symbol] + occ_count_before[symbol][top] ;
			bottom = starts[symbol] + occ_count_before[symbol][bottom + 1] - 1 ;
		}
		else 
			return bottom - top + 1 ;
	}
	
	return 0;
}

int main()
{
	string bwt;
	cin >> bwt;
	int pattern_count;
	cin >> pattern_count;
	// Start of each character in the sorted list of characters of bwt,
	// see the description in the comment about function PreprocessBWT
	map<char, int> starts;
	// Occurrence counts for each character and each position in bwt,
	// see the description in the comment about function PreprocessBWT
	map<char, vector<int>> occ_count_before;
	// Preprocess the BWT once to get starts and occ_count_before.
	// For each pattern, we will then use these precomputed values and
	// spend only O(|pattern|) to find all occurrences of the pattern
	// in the text instead of O(|pattern| + |text|).
	PreprocessBWT(bwt, starts, occ_count_before);
	for (int pi = 0; pi < pattern_count; ++pi)
	{
		string pattern;
		cin >> pattern;
		int occ_count = CountOccurrences(pattern, bwt, starts, occ_count_before);
		printf("%d ", occ_count);
	}
	printf("\n");
	return 0;
}
