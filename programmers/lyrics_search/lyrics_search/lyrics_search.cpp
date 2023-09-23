#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    for (int i = 0; i < queries.size(); i++)
    {
        int alphcount = 0;
        string temp = queries[i];

        for (int k = 0; k < words.size(); k++)
        {
            if (queries[0] == "?") {
                alphcount++;
                
            }
            else {

            }
        }
        answer.push_back(alphcount);
    }
    return answer;
}