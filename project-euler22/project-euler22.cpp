#include <iostream>
#include <vector>
#include <string>
#define LEN_MAX 12
using namespace std;

vector<string> names;
vector<int> namesScore;

/*
 * Radix sort an array of Strings
 * Assume all are all ASCII
 * Assume all have length bounded by maxLen
 */
void radixSort( vector<string> & arr, int maxLen )
{
    const int BUCKETS = 256;

    vector<vector<string>> wordsByLength( maxLen + 1 );
    vector<vector<string>> buckets( BUCKETS );

    for( string & s : arr )
        wordsByLength[ s.length( ) ].push_back( std::move( s ) );

    int idx = 0;
    for( auto & wordList : wordsByLength )
        for( string & s : wordList )
            arr[ idx++ ] = std::move( s );

    int startingIndex = arr.size( );    
    for( int pos = maxLen - 1; pos >= 0; --pos )
    {
        startingIndex -= wordsByLength[ pos + 1 ].size( );

        for( int i = startingIndex; i < arr.size( ); ++i )
            buckets[ arr[ i ][ pos ] ].push_back( std::move( arr[ i ] ) );

        idx = startingIndex;
        for( auto & thisBucket : buckets )
        {
            for( string & s : thisBucket )
                arr[ idx++ ] = std::move( s );

            thisBucket.clear( );
        }
    }
}

int calcNameScore(string name, int position) {
    int size = name.size();
    int score = 0;
    for (int i = 0; i < size; i++) {
        score += name[i] - 0x40;
    }
    return score * position;
}

void fillScoreVector() {
    int size = names.size();
    for (int i = 0; i < size; i++) 
        namesScore.push_back(calcNameScore(names[i], i +1));
}

int findNameIndex(string name) {
    int size = names.size();
    for (int i = 0; i < size; i++) 
        if(name.compare(names[i]) == 0)
            return i;
}

int main() {
    int t0;
    cin >> t0;
    while (t0--) {
        string str;
        cin >> str;
        names.push_back(str);
    }
    radixSort(names, LEN_MAX);
    fillScoreVector();

    int q;
    cin >> q;
    while (q--) {
        string str;
        cin >> str;

        cout << namesScore[findNameIndex(str)] << endl;
    }

    return 0;
}
