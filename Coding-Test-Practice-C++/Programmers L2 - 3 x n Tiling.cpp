//// ≥ª «Æ¿Ã
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int solution(int n) {
//    if (n & 1)
//        return 0;
//
//    vector<int> v = { 3 };
//
//    int last_ver = 1;
//
//    for (int i = 2; i < n; i += 2)
//    {
//        v.push_back((v.back() * 3 + last_ver * 2) % 1000000007);
//        last_ver += v[v.size() - 2];
//    }
//
//    return v.back();
//}
//
//int main()
//{
//    cout << solution(6);
//
//    return 0;
//}