#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool string_cmp(pair<string, int> p1, pair<string, int> p2)
{
    return p1.second > p2.second;
}

bool int_cmp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second == p2.second)
    {
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> plays_per_genre;
    map<string, vector<pair<int, int>>> genre_musics;
    
    for (int i = 0; i < genres.size(); i++)
    {
        plays_per_genre[genres[i]] += plays[i];

        genre_musics[genres[i]].push_back({ i, plays[i] });
    }

    vector<pair<string, int>> vec(plays_per_genre.begin(), plays_per_genre.end());

    sort(vec.begin(), vec.end(), string_cmp);

    for (int i = 0; i < vec.size(); i++)
    {
        sort(genre_musics[vec[i].first].begin(), genre_musics[vec[i].first].end(), int_cmp);

        answer.push_back(genre_musics[vec[i].first][0].first);
        if(genre_musics[vec[i].first].size() > 1)
            answer.push_back(genre_musics[vec[i].first][1].first);
    }

    
    return answer;
}