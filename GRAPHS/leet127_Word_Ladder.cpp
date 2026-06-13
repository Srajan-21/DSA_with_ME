#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
#include <iostream>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    
    // Make the set
    unordered_set<string>wordSet(wordList.begin() , wordList.end());

    // edge case
    if(!wordSet.count(endWord))return 0;

    unordered_set<string>visited;
    visited.insert(beginWord);

    queue<pair<string,int>>q;
    q.push({beginWord,1});

    while(!q.empty()){

        string current = q.front().first;
        int level = q.front().second;
        string word = current;

        q.pop();

        for(int i = 0 ; i < word.size() ; i++)
        {
            char og = word[i];
            for(char c = 'a' ; c <= 'z' ; c++)
            {
                if(c == og)continue;

                word[i] = c;

                if(word == endWord)return level+1;

                if(wordSet.count(word) && !visited.count(word))
                {
                    visited.insert(word);
                    q.push({word,level+1});
                }
            }
            word[i] = og;
        }
    }
    return 0;
}

int main()
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout<<ladderLength(beginWord,endWord,wordList);
    return 0;
}