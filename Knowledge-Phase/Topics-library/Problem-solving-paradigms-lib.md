# Problem Solving Paradigms

Table of Contents
================= 

- [Brute Force](#brute-force)
  * [Iterative](#iterative)
    + [Iteratively Subsets](#iteratively-subsets)
  * [Recursive](Recursive)
    + [Recursively Subsets][#recursively-subsets]
 - [Greedy](#greedy)
   * [Sup Sup Topic](#sup-sup-topic)
     + [Tag](#tag)
   
   
## Brute Force
### Iterative
#### Iteratively Subsets 
- Basic code
  ```cpp 
  int main()
  {
        string all, fi;
        cin >> all;
        fi += all[0];
        vector<string>subset;
        subset.push_back(fi);
        subset.push_back("");
        for (int x = 1; x < all.length(); x++)
        {
                int t = subset.size();
                for (int y = 0; y < t; y++)
                        subset.push_back(subset[y] + all[x]);
        }
        for (int x = 0; x < subset.size(); x++)
                cout << subset[x] << endl;
        return 0;
                                       
   }
  ```

### Recursive
#### Recursively Subsets
- Basic code
  ```cpp 
  string all;
  vector<string>subset;
  void gensubset(int index, string sup)
  {
        // the end of recursion call (leaf)
        if (index == all.length())
        {
                subset.push_back(sup);
                return;
        }

        gensubset(index + 1, sup);
        gensubset(index + 1, sup += all[index]);
  }

  int main()
  {
        cin >> all;
        gensubset(0, "");
        for (int x = 0; x < subset.size(); x++)
                cout << subset[x] << endl;

        return 0;
  }

  ```
  
## Greedy
### Sup Sup Topic
#### Tag
