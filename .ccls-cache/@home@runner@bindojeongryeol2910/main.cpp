#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int n, m, r, o; //n,m은 첫째줄 r은 둘째줄 o는 벡터의 갯수
bool overlap;
vector<pair<int, long int>> vec; // first 값, second 빈도
map <int, int> order; 

bool crit(pair<int, long int> a, pair<int, long int> b) 
{
  if (a.second == b.second)
		return order[a.first] < order[b.first];

    return a.second > b.second;
}

int main()
{
  ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  
    cin >> n >> m;

    cin >> r;

    vec.push_back(pair<int, long int>(r, 1));

    for (int i = 1; i < n; i++)
    {
        overlap = false;
        o++; // 벡터의 갯수

        cin >> r;

        for (int j = 0; j < o; j++)
        {
            if (vec[j].first == r)
            {
                vec[j].second = vec[j].second + 1;
                o--; // 같은 것이 있어서 벡터 추가 못함, 추가라는 정보 돌리기
                overlap = true;
                break;
            }
            else continue;
        }

        if (overlap) continue;
        else
        {
            vec.push_back(pair<int, long int>(r, 1)); // 같은 것이 없으니 새로운 벡터 추가
        }
    }

    //vec.second에 따라 내림차순 정리
    sort(vec.begin(), vec.end(), crit);

    // vec.first를 vec.second 만큼 출력 반복
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].second; j++)
        {
            cout << vec[i].first << " ";
        }
    }
}