//
//  SubstringConcatenation.cpp
//  
//
//  Created by Dylan Miller on 1/29/17.
//
//

/*
 You are given a string, S, and a list of words, L, that are all of the same length.
 
 Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.
 
 Example :
 
 S: "barfoothefoobarman"
 L: ["foo", "bar"]
 You should return the indices: [0,9].
 (order does not matter).
 */

vector<int> Solution::findSubstring(string A, const vector<string> &B)
{
    vector<int> match_start_indices;
    
    if (!A.length() || !B.size())
        return match_start_indices;
    
    int word_length = B[0].length();
    int num_words = B.size();
    
    // Put all words into a map.
    map<string, int> word_map;
    for (int i = 0; i < B.size(); i++)
    {
        const string& word = B[i];
        map<string, int>::iterator word_map_it = word_map.find(word);
        if (word_map_it == word_map.end()) // not found
            word_map[word] = 1;
        else
            word_map_it->second++;
    }
    
    // Go through the entire string word_length times.
    for (int i = 0; i < A.length(); i++)
    {
        int match_start_index = -1;
        map<string, int> match_word_map;
        int num_matching_words = 0;
        for (int j = i; j + word_length <= A.length(); j += word_length)
        {
            string word(A, j, word_length);
            map<string, int>::iterator word_map_it = word_map.find(word);
            if (word_map_it != word_map.end()) // word found in word_map
            {
                int word_count = word_map_it->second;
                
                map<string, int>::iterator match_word_map_it = match_word_map.find(word);
                int match_word_count;
                if (match_word_map_it == match_word_map.end()) // word not found in match_word_map
                {
                    match_word_count = 1;
                    match_word_map[word] = match_word_count;
                }
                else
                {
                    match_word_map_it->second++;
                    match_word_count = match_word_map_it->second;
                }
                
                num_matching_words++;
                if (match_word_count <= word_count)
                {
                    if (match_start_index == -1)
                        match_start_index = j;
                    if (num_matching_words == num_words)
                    {
                        match_start_indices.push_back(match_start_index);
                        break;
                    }
                }
                else // word found too many times
                    break;
            }
            else // word not found in word_map
                break;
        }
    }
    
    return match_start_indices;
}

// Difficulty: Hard. My solution passed even though it was not the intended solution.
