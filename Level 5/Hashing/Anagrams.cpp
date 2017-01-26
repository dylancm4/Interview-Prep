//
//  Anagrams.cpp
//  
//
//  Created by Dylan Miller on 1/25/17.
//
//

/*
 Given an array of strings, return all groups of strings that are anagrams. Represent a group by a list of integers representing the index in the original list. Look at the sample case for clarification.
 
 Anagram : a word, phrase, or name formed by rearranging the letters of another, such as 'spar', formed from 'rasp'
 Note: All inputs will be in lower-case.
 Example :
 
 Input : cat dog god tca
 Output : [[1, 4], [2, 3]]
 cat and tca are anagrams which correspond to index 1 and 4.
 dog and god are another set of anagrams which correspond to index 2 and 3.
 The indices are 1 based ( the first element has index 1 instead of index 0).
 
 Ordering of the result : You should not change the relative ordering of the words / phrases within the group. Within a group containing A[i] and A[j], A[i] comes before A[j] if i < j.
 */

vector<vector<int> > Solution::anagrams(const vector<string> &A)
{
    // Create a map where the key is the string sorted by character,
    // and the value is the index+1.
    unordered_map<string, vector<int>> anagrams_map;
    for (int i = 0; i < A.size(); i++)
    {
        string sorted_string = A[i];
        sort(sorted_string.begin(), sorted_string.end());
        anagrams_map[sorted_string].push_back(i+1);
    }
    
    // Convert the map to a vector.
    vector<vector<int>> anagrams_vector;
    for (unordered_map<string, vector<int>>::iterator it = anagrams_map.begin();
         it != anagrams_map.end();
         it++)
    {
        vector<int>& anagram_vector = it->second;
        anagrams_vector.push_back(anagram_vector);
    }
    
    return anagrams_vector;
}

// Difficulty: Easy
