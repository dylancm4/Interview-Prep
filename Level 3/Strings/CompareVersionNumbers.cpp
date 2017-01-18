//
//  CompareVersionNumbers.cpp
//  
//
//  Created by Dylan Miller on 1/17/17.
//
//

/*
 Compare two version numbers version1 and version2.
 
 If version1 > version2 return 1,
 If version1 < version2 return -1,
 otherwise return 0.
 You may assume that the version strings are non-empty and contain only digits and the . character.
 The . character does not represent a decimal point and is used to separate number sequences.
 For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
 
 Here is an example of version numbers ordering:
 
 0.1 < 1.1 < 1.2 < 1.13 < 1.13.4
 */

string getVersionRevisionString(string A, int a_size, int& i)
{
    string revision;
    for (; i < a_size;)
    {
        char a_i = A[i++];
        if (a_i == '.')
            break;
        else if (a_i != '0' || revision.size())
            revision.push_back(a_i);
    }
    if (!revision.size())
        revision.push_back('0');
    return revision;
}

int Solution::compareVersion(string A, string B)
{
    int a_size = A.size();
    int b_size = B.size();
    for (int i = 0, j = 0; i < a_size || j < b_size;)
    {
        string a_revision = getVersionRevisionString(A, a_size, i);
        string b_revision = getVersionRevisionString(B, b_size, j);
        if (a_revision.size() > b_revision.size())
            return 1;
        else if (a_revision.size() < b_revision.size())
            return -1;
        else
        {
            if (a_revision > b_revision)
                return 1;
            else if (a_revision < b_revision)
                return -1;
        }
    }
    return 0;
}
