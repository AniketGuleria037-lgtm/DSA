class Solution {
public:
    bool letter_difference(string a, string b) {
        if(a.size() != b.size()) return false;
        int i=0;

        int c=0;
        while(i<a.size()) {
            if(a[i] != b[i]) c++;
            if(c>1) break;
            i++;
        }
        return (c==1);
    }

    map<string, vector<string>> adj_list(string beginWord, vector<string> wordList) {
        if (find(wordList.begin(), wordList.end(), beginWord) == wordList.end()) {
            wordList.push_back(beginWord);
        }
        int n = wordList.size();

        map<string, vector<string>> adj;

        for(int i=0; i<n; i++) {
            for(int j =i+1; j<n; j++) {
                if(letter_difference(wordList[i], wordList[j])) {
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        return adj;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        map<string, int> dist;

        map<string, vector<string>> adj = adj_list(beginWord, wordList);

        for(int i=0; i<wordList.size(); i++) {
            dist[wordList[i]] = INT_MAX;
        }

        dist[beginWord] = 0;

        queue<string> q;
        q.push(beginWord);

        while(!q.empty()) {
            string w = q.front();
            q.pop();
            int d = dist[w];
            for(auto it : adj[w]) {
                if(d!=INT_MAX && d+1 < dist[it]) {
                    dist[it] = d+1;
                    q.push(it);
                }
            }
        }
        return dist[endWord] == INT_MAX ? 0: dist[endWord]+1;
    }
};