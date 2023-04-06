/*
Description
============
Rules for adding commas to an existing piece of text are as follows: 

1) If a word anywhere in the text is preceded by a comma, find all occurrences of that word in the text, and put a comma before each of those occurrences, except in the case where such an occurrence is the first word of a sentence or already preceded by a comma.

  foo bar foo, bar foo bar foo. bar foo, bar.

  foo, bar foo, bar foo, bar foo. bar foo, bar.

2) If a word anywhere in the text is succeeded by a comma, find all occurrences of that word in the text, and put a comma after each of those occurrences, except in the case where such an occurrence is the last word of a sentence or already succeeded by a comma. 

  foo, bar foo, bar foo, bar foo. bar foo, bar.

3) Apply rules 1 and 2 repeatedly until no new commas can be added using either of them. 

  foo, bar baz, zoo baz, bar.

As an example, consider the text
--------------------------------
input: please sit spot. sit spot, sit. spot here now here. 

Because there is a comma after spot in the second sentence, a comma should be added after spot in the third sentence as well (but not the first sentence, since it is the last word of that sentence). Also, because there is a comma before the word sit in the second sentence, one should be added before that word in the first sentence (but no comma is added before the word sit beginning the second sentence because it is the first word of that sentence). Finally, notice that once a comma is added after spot in the third sentence, there exists a comma before the first occurrence of the word here. Therefore, a comma is also added before the other occurrence of the word here. There are no more commas to be added so the final result is

output: please, sit spot. sit spot, sit. spot, here now, here. 

please, sit spot. sit spot, sit. spot, here now, here.
      ^                              ^         ^
   rule1                            rule-2
                                              rule-3/1

please, sit spot. sit spot, sit. spot, here now, here. 

Input
-----
The input contains one line of text. Each character is either a lowercase letter, a comma, a period, or a space. And: 
The text begins with a word. 
Between every two words in the text, there is either a single space, a comma followed by a space, or a period followed by a space (denoting the end of a sentence and the beginning of a new one). 
The last word of the text is followed by a period with no trailing space.

Sample Output 
-------------
Sample 1: 
Input:  please sit spot. sit spot, sit. spot here now here. 
Output: please, sit spot. sit spot, sit. spot, here now, here. 

Sample 2: 
Input: one, two. one tree. four tree. four four. five four. six five. 
Output: one, two. one, tree. four, tree. four, four. five, four. six five.


*/


#include <iostream>
#include <bits/stdc++.h>
#include <iterator>

using namespace std;

enum char_before {nothing_before, com_before, period_before};
enum char_after {nothing_after, com_after, period_after};


string applyRules(vector<string> words) {
  int n = words.size();
  unordered_map<int, pair<string, pair<char_before, char_after>>> masterMap;
  unordered_map<string, vector<int>> sameStringIDs;  // for fast access - here id is the key of master map
  queue<pair<int, int>> taskQ;
  int id = 0; // incremental ids help in reconstructing the final string from the states and the string (these states will be updated until they cant be anymore)
  for(int i=0;i<n;i++) {
    if(words[i][0] != '.' && words[i][0] != ',') {

        // cout << "words[i]: " << words[i][0] << endl;

        char_before cb = nothing_before;
        char_after ca = nothing_after;

        if(i-1 >=0) {
          if(words[i-1][0] == '.') {
              cb = period_before;
          }
          if(words[i-1][0] == ',') {
              cb = com_before;
          }
        }

        if(i+1 <n) {
          if(words[i+1][0] == ',') {
              ca = com_after;
          }
          if(words[i+1][0] == '.') {
              ca = period_after;
          }
        }

        masterMap[id] = {words[i], {cb, ca}};
        sameStringIDs[words[i]].push_back(id);

        if(cb == com_before) {
          taskQ.push({1, id}); // type 1 task
        }

        if(ca == com_after) {
          taskQ.push({2, id}); // type 2 task
        }
        id++;
    }
  }

  // return "abc";

  while(!taskQ.empty()) {
    pair<int, int> task = taskQ.front();
    taskQ.pop();
    int taskType = task.first;
    int id = task.second;
    string word = masterMap[id].first;

    if(taskType == 1) {
      for(int sid : sameStringIDs[word]) {
        if(sid == id) continue;
        char_before cb = masterMap[sid].second.first;
        if( cb == nothing_before) {
          masterMap[sid].second.first = com_before; //change of state

          // this also changes the state of id-1
          if(sid - 1 >= 0) {
            char_after ca = masterMap[sid].second.second;
            if( ca == nothing_after) {
              masterMap[sid-1].second.second = com_after; //change of state and addition of new task of type 2
              taskQ.push({2, sid-1}); 
            }
        }
      }
    }
  }
  else {
    for(int sid : sameStringIDs[word]) {
        if(sid == id) continue;
        char_after ca = masterMap[sid].second.second;
        if( ca == nothing_after) {
          masterMap[sid].second.second = com_after;//change of state

          // this also changes the state of id+1
          if(sid + 1 < n) {
            char_before cb = masterMap[sid+1].second.first;
            if( cb == nothing_before) {
              masterMap[sid+1].second.first = com_before;  //change of state and addition of new task of type 2
              taskQ.push({1, sid+1}); 
            }
        }
      }
    }
  }
  }

  // construct string from masterMap
  string finalStr = "";
  for(int i=0;i<id;i++) {
    string word = masterMap[i].first;
    char_before cb =  masterMap[i].second.first;

    if(cb == com_before) {
      finalStr += ",";
    }
    if(cb == period_before) {
      finalStr += ".";
    }

    finalStr += word;

    finalStr += " ";
  }

  // only for last one do separately
  char_after ca = masterMap[id-1].second.second;
  if(ca == com_after) {
    finalStr += ",";
  }
  if(ca == period_after) {
    finalStr += ".";
  }

  
  return finalStr;
}

// To execute C++, please define "int main()"
int main() {
  vector<string> words = {"please", "sit", "spot", ".", "sit", "spot", ",", "sit", ".", "spot", "here", "now", "here", "." };
  // Output: please, sit spot. sit spot, sit. spot, here now, here. 

  cout << "INPUT" << endl;
  for(auto i : words) {
    cout << i << " ";
  }
  cout << endl;
  
  cout << "OUTPUT" << endl;
  cout << applyRules(words) << endl;
  return 0;
}
