//
//  LetterPhone.cpp
//  
//
//  Created by Dylan Miller on 2/13/17.
//
//

/*
 Given a digit string, return all possible letter combinations that the number could represent.
 
 A mapping of digit to letters (just like on the telephone buttons) is given below.
 
 The digit 0 maps to 0 itself.
 The digit 1 maps to 1 itself.
 
 Input: Digit string "23"
 Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 Make sure the returned strings are lexicographically sorted.
 */

void generateLetterCombos(
    const vector<vector<char>>& phone_letters, const string& digit_string,
    int digit_string_offset, string& combo, vector<string>& combos)
{
    if (digit_string_offset == digit_string.length())
    {
        combos.push_back(combo);
        return;
    }
    
    int digit = digit_string[digit_string_offset] - '0';
    const vector<char>& digit_letters = phone_letters[digit];
    for (int i = 0; i < digit_letters.size(); i++)
    {
        string new_combo = combo;
        new_combo.push_back(digit_letters[i]);
        generateLetterCombos(phone_letters, digit_string, digit_string_offset+1, new_combo, combos);
    }
}

vector<string> Solution::letterCombinations(string A)
{
    vector<vector<char>> phone_letters;
    vector<char> zero;
    zero.push_back('0');
    vector<char> one;
    one.push_back('1');
    vector<char> two;
    two.push_back('a');
    two.push_back('b');
    two.push_back('c');
    vector<char> three;
    three.push_back('d');
    three.push_back('e');
    three.push_back('f');
    vector<char> four;
    four.push_back('g');
    four.push_back('h');
    four.push_back('i');
    vector<char> five;
    five.push_back('j');
    five.push_back('k');
    five.push_back('l');
    vector<char> six;
    six.push_back('m');
    six.push_back('n');
    six.push_back('o');
    vector<char> seven;
    seven.push_back('p');
    seven.push_back('q');
    seven.push_back('r');
    seven.push_back('s');
    vector<char> eight;
    eight.push_back('t');
    eight.push_back('u');
    eight.push_back('v');
    vector<char> nine;
    nine.push_back('w');
    nine.push_back('x');
    nine.push_back('y');
    nine.push_back('z');
    phone_letters.push_back(zero);
    phone_letters.push_back(one);
    phone_letters.push_back(two);
    phone_letters.push_back(three);
    phone_letters.push_back(four);
    phone_letters.push_back(five);
    phone_letters.push_back(six);
    phone_letters.push_back(seven);
    phone_letters.push_back(eight);
    phone_letters.push_back(nine);
    
    string combo;
    vector<string> combos;
    generateLetterCombos(phone_letters, A, 0, combo, combos);
    
    return combos;
}

// Difficulty: Easy
