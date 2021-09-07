// #include <string>
// #include <vector>
// #include <iostream>
// #include <map>
// #include <algorithm>
// using namespace std;

// bool cmp(int a, int b) { return a > b; }
// int dp[999];
// map<int, int>::iterator it, it2;
// void recur(vector<int> &vec1, vector<int> &vec2, map<int,int> &mp, int idx, bool &ans, int depth)
// {
// 	if (ans)
// 		return;
// 	if (depth == vec1.size())
// 	{
// 		ans = true;
// 		if (mp.size())
// 			ans = false;
// 		return;
// 	}

// 	for(int i = idx; i < vec2.size(); ++i)
// 	{
// 		for(auto &p : vec1)
// 		{
// 			if (ans)
// 				return;
// 			int t = p;
// 			int t2 = vec2[i] - p;
// 			it = mp.find(t);
// 			it2 = mp.find(t2);
// 			if (it != mp.end() && it2 != mp.end())
// 			{
// 				mp[t]--;
// 				mp[t2]--;
// 				if (!mp[t])
// 					mp.erase(it);
// 				if (!mp[t2])
// 					mp.erase(it2);
// 				recur(vec1, vec2, mp, i + 1, ans, depth + 1);
// 				mp[t]++;
// 				mp[t2]++;
// 			}
// 		}
// 	}
// }

// vector<bool> solution(vector<vector<int>> vec1, vector<vector<int>> vec2) {
// 	int sz = vec1.size();
// 	vector<bool> ans(sz, 1);
// 	for(int i = 0; i < sz; ++i)
// 	{
// 		int sum = 0;
// 		int sum2 = 0;
// 		for(auto &p : vec1[i])
// 			sum += p;
// 		for(auto &p : vec2[i])
// 			sum2 += p;
// 		if (sum != sum2)
// 			ans[i] = false;
// 	}
// 	for(int i = 0; i < sz; ++i)
// 	{
// 		if (!ans[i]) continue;
// 		for(auto &p : vec1[i])
// 		{
// 			for(auto &q : vec2[i])
// 			{

// 				if (p == q)
// 				{
// 					p = q = -1;
// 					break;
// 				}
// 			}
// 		}
// 		sort(vec1[i].begin(), vec1[i].end(), cmp);
// 		sort(vec2[i].begin(), vec2[i].end(), cmp);
// 		while (vec1.size() && vec1[i].back() == -1)
// 			vec1.pop_back();
// 		while (vec2.size() && vec2[i].back() == -1)
// 			vec2.pop_back();
// 	}
// 	for(int i = 0; i < sz; ++i)
// 	{
// 		map<int, int> mp;
// 		if (!ans[i]) continue;
// 		for(auto &p : vec1[i])
// 			mp[p]++;
// 		bool ret = false;
// 		recur(vec1[i], vec2[i], mp, 0, ret, 0);
// 		ans[i] = ret;
// 	}
// 	return ans;
// }

// int main(){
// 	// vector<vector<int>> vec1 = {{4,3,3},{1,2,3},{3,2,4}};
// 	// vector<vector<int>> vec2 = {{5,5},{5,1},{1,8}};
// 	vector<vector<int>> vec1 = {{3,2,4}};
// 	vector<vector<int>> vec2 = {{1,8}};
// 	// vector<vector<int>> vec1 = {{5,3,2,2,1}};
// 	// vector<vector<int>> vec2 = {{7,2,4}};
// 	vector<bool> ans = solution(vec1, vec2);
// 	for(int i = 0; i < ans.size(); ++i)
// 		cout << ans[i] << ' ';
// }


#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int n;
vector<int> vec;
int main()
{
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		vec.push_back(a);
	}
	for(auto &p : vec)
		cout << p << '\n';
}