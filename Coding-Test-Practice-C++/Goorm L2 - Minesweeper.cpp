//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//	int m, n;
//
//	cin >> m >> n;
//
//	vector<vector<char>> v(m, vector<char>(n, '0'));
//
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			char temp;
//			cin >> temp;
//
//			if (temp == '*')
//			{
//				v[i][j] = '*';
//
//				if (i > 0 && v[i - 1][j] != '*')
//					v[i - 1][j]++;
//				if (i < m - 1 && v[i + 1][j] != '*')
//					v[i + 1][j]++;
//				if (j > 0 && v[i][j - 1] != '*')
//					v[i][j - 1]++;
//				if (j < n - 1 && v[i][j + 1] != '*')
//					v[i][j + 1]++;
//				if (i > 0 && j > 0 && v[i - 1][j - 1] != '*')
//					v[i - 1][j - 1]++;
//				if (i < m - 1 && j > 0 && v[i + 1][j - 1] != '*')
//					v[i + 1][j - 1]++;
//				if (i > 0 && j < n - 1 && v[i - 1][j + 1] != '*')
//					v[i - 1][j + 1]++;
//				if (i < m - 1 && j < n - 1 && v[i + 1][j + 1] != '*')
//					v[i + 1][j + 1]++;
//			}
//		}
//	}
//
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cout << v[i][j];
//		}
//		cout << endl;
//	}
//
//	return 0;
//}