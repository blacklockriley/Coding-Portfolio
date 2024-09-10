///////////////////////// TO-DO (1) //////////////////////////////
  /// Include necessary header files
  /// Hint:  Include what you use, use what you include
  ///
  /// Do not put anything else in this section, i.e. comments, classes, functions, etc.  Only #include directives

#include <algorithm>
#include <cctype>
#include <cstddef>
#include <istream>
#include <locale>
#include <string>
#include <unordered_map>
#include <utility>

#include "WordFrequency.hpp"

/////////////////////// END-TO-DO (1) ////////////////////////////







// unnamed, anonymous namespace providing non-member private working area
namespace
{
  std::string sanitize( const std::string & word )
  {
    constexpr char bad_char[] = " \t\r\n\b\v_-\"'(){}+/*,=.!?:;";          // leading and trailing characters to be removed
    static std::locale locality{ "en_GB.UTF-8" };

    auto startIndex = word.find_first_not_of( bad_char );                  // start with the first non-bad character
    if( startIndex == std::string::npos ) startIndex = word.size();        // if the word contains only bad characters ...

    std::size_t count    = 0;                                              // assume the word contains only bad characters ...
    auto        endIndex = word.find_last_not_of( bad_char );              // end with the first non-bad character

    if( endIndex != std::string::npos ) count = endIndex - startIndex + 1; // number of characters to use in results

    auto result = word.substr( startIndex, count );                        // strip the leading and trailing bad characters
    for( auto & c : result ) c = std::tolower( c, locality );              // convert to lower case

    return result;
  }
}  // unnamed, anonymous namespace







// Implement WordFrequency::WordFrequency( std::istream ) - See requirements
///////////////////////// TO-DO (2) //////////////////////////////

WordFrequency::WordFrequency( std::istream & iStream )
{
  std::string word = "";      // word to be read from the input stream
  while( iStream >> word )    // read a word from the input stream
  {
    word = sanitize( std::move( word ) );    // sanitize the word
    ++wordCountMap[std::move( word )];       // increment the count of the word in the map
  }
}

/////////////////////// END-TO-DO (2) ////////////////////////////







// Implement WordFrequency::numberOfWords() const - See requirements
///////////////////////// TO-DO (3) //////////////////////////////

std::size_t WordFrequency::numberOfWords() const
{
  return wordCountMap.size();    // return the size of the map
}

/////////////////////// END-TO-DO (3) ////////////////////////////







// Implement WordFrequency::wordCount( const std::string & ) const - See requirements
///////////////////////// TO-DO (4) //////////////////////////////

std::size_t WordFrequency::wordCount( const std::string & word ) const
{
  std::string cleaned_word = sanitize( std::move( word ) );        // sanitize the word
  if( wordCountMap.find( cleaned_word ) != wordCountMap.end() )    // if the word is in the map ...
    return wordCountMap.at( cleaned_word );                        // return the count of the word
  return 0;                                                        // otherwise, return 0
}

/////////////////////// END-TO-DO (4) ////////////////////////////







// Implement WordFrequency::mostFrequentWord() const - See requirements
///////////////////////// TO-DO (5) //////////////////////////////

std::string WordFrequency::mostFrequentWord() const
{
  std::string result = "";    // most frequent word
  std::size_t count  = 0;     // count of the most frequent word

  for( const auto & [word, wordCount] : wordCountMap )    // for each word in the map ...
  {
    if( wordCount > count )    // if the word is more frequent than the current most frequent word ...
    {
      result = std::move( word );         // update the most frequent word
      count  = std::move( wordCount );    // update the count of the most frequent word
    }
  }

  return result;    // return the most frequent word
}

/////////////////////// END-TO-DO (5) ////////////////////////////







// Implement WordFrequency::maxBucketSize() const - See requirements
///////////////////////// TO-DO (6) //////////////////////////////
  /// Hint: see the unordered_map's bucket interface at https://en.cppreference.com/w/cpp/container/unordered_map

std::size_t WordFrequency::maxBucketSize() const
{
  std::size_t result = 0;    // size of the largest bucket in the hash table

  for( const auto & bucket : wordCountMap )                                                                       // for each bucket in the map ...
    result = std::max( std::move( result ), wordCountMap.bucket_size( wordCountMap.bucket( bucket.first ) ) );    // update the size of the largest bucket
  return result;                                                                                                  // return the size of the largest bucket
}

/////////////////////// END-TO-DO (6) ////////////////////////////
