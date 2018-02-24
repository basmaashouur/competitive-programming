/*
Name: 230 - Borrowers
Online Judge: UVa
Tags: vectors, sorting, strings
Tutorial: Each book has its OWN POSITION on the shelves, and it need to be returned on that position.
make a string parsing with the input then put it in vector<pair<author,title >> sort them all 
now we don't need author name anymore replace it with "1" it means the book is on the shelve
when "borrow" then make first pair= "-1", when "return" put all the return books in a vector
when "Shelve" change the "-1" to "1" in the vector of that value and put them all in their original 
index but in a new vector and then see what is the "1" that is before it then print them.
*/


// C O D E

#include <bits/stdc++.h>

using namespace std;

int main() 
{

  vector < pair < string, string >> vec;
  vector < string > ret;
  while (true) {
    string val, title, auth;
    int index;
    getline(cin, val);
    if (val == "END") break;

    // save the title
    title += '"';
    for (int x = 1; x < val.length(); x++) 
    {
      title += val[x];
      if (val[x] == '"') 
      {
        index = x + 1;
        break;
      }
    }
    // save the author
    auth.append(val.begin() + index, val.end());

    vec.push_back(make_pair(auth, title));
  }

  sort(vec.begin(), vec.end());
  for (int x = 0; x < vec.size(); x++)
    vec[x].first = "1";
    
  while (true) 
  {
    string val, fin;
    getline(cin, val);
    if (val == "END") break;

    //shelve
    if (val[5] == 'E') {
      vector < string > shelve(vec.size());
      for (int x = 0; x < ret.size(); x++) 
      {
        string rett = ret[x];
        for (int y = 0; y < vec.size(); y++)
         {
          if (rett == vec[y].second) 
          {
            shelve[y] = rett, vec[y].first = "1";
            break;
          }
        }
      }
      // print the shelve
      string before = "";
      for (int x = 0; x < shelve.size(); x++) 
      {
        if (shelve[x] != "" && before == "") cout << "Put " << shelve[x] << " first" << endl;
        else if (shelve[x] != "") cout << "Put " << shelve[x] << " after " << before << endl;
        if (vec[x].first == "1") before = vec[x].second;
      }
      cout << "END" << endl;
      ret.clear();
    }

    //borrow
    else if (val[5] == 'W') 
    {
      fin.append(val.begin() + 7, val.end());
      for (int x = 0; x < vec.size(); x++)
        if (vec[x].second == fin) 
        {
          vec[x].first = "-1";
          break;
        }
    }
    // return
    else 
    {
      fin.append(val.begin() + 7, val.end());
      ret.push_back(fin);
    }
  }

  return 0;
}
