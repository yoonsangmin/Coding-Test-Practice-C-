//// 내 풀이
//#include <string>
//#include <vector>
//
//using namespace std;
//
//bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
//    int comp_size = key.size() + (lock.size() - 1) * 2;
//    vector<vector<int>> comp(comp_size, vector<int>(comp_size, 1));
//
//    for (int i = 0, base = lock.size() - 1; i < key.size(); i++)
//        for (int j = 0; j < key.size(); j++)
//            comp[base + i][base + j] = key[i][j] ? 0 : 1;
//
//    for (int i = 0; i <= comp_size - lock.size(); i++)
//        for (int j = 0; j <= comp_size - lock.size(); j++)
//        {
//            bool flag_0 = true;
//            bool flag_90 = true;
//            bool flag_180 = true;
//            bool flag_270 = true;
//            for (int r = 0; r < lock.size(); r++)
//                for (int c = 0; c < lock.size(); c++)
//                {
//                    if (flag_0 && comp[i + r][j + c] != lock[r][c])
//                        flag_0 = false;
//                    if (flag_90 && comp[j + c][i + lock.size() - 1 - r] != lock[r][c])
//                        flag_90 = false;
//                    if (flag_180 && comp[i + lock.size() - 1 - r][j + lock.size() - 1 - c] != lock[r][c])
//                        flag_180 = false;
//                    if (flag_270 && comp[j + lock.size() - 1 - c][i + r] != lock[r][c])
//                        flag_270 = false;
//
//                    if (!flag_0 && !flag_90 && !flag_180 && !flag_270)
//                        break;
//                }
//            if (flag_0 || flag_90 || flag_180 || flag_270)
//                return true;
//        }
//
//    return false;
//}

//// 다른 사람 풀이
//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<vector<int>> rotate(vector<vector<int>> a) {
//    int n = a.size();
//    for (int i = 0; i < n / 2; i++) {
//        for (int j = i; j < n - i - 1; j++) {
//            int temp = a[i][j];
//            a[i][j] = a[n - j - 1][i];
//            a[n - j - 1][i] = a[n - 1 - i][n - 1 - j];
//            a[n - 1 - i][n - 1 - j] = a[j][n - 1 - i];
//            a[j][n - 1 - i] = temp;
//        }
//    }
//    return a;
//}
//bool check(vector<vector<int>> v) {
//    for (vector<int> vector : v) {
//        for (int n : vector) {
//            // 열쇠 구멍이 걸리는 경우 또는 구멍이 비어있는 경우
//            if (n == 0 || n == -1) return false;
//        }
//    }
//    return true;
//}
//
//vector<vector<int>> matching(vector<vector<int>> key, vector<vector<int>> lock, int k, int l) {
//    int lastIndexOfKey = key.size() - 1;
//    int lastIndexOfLock = lock.size() - 1;
//    int i = 0, j = 0, x = i - lastIndexOfKey + k, y = j - lastIndexOfKey + l;
//    vector<vector<int>> temp = lock;
//
//    // 모든 열쇠 순회 - i, j는 키의 인덱스
//    for (i = 0; i <= lastIndexOfKey; i++) {
//        for (j = 0; j <= lastIndexOfKey; j++) {
//            // x, y는 락의 인덱스
//            x = i - lastIndexOfKey + k;
//            y = j - lastIndexOfKey + l;
//
//            // 접근하려는 락이 범위 안에 있을 때만
//            if (x >= 0 && x <= lastIndexOfLock && y >= 0 && y <= lastIndexOfLock) {
//                // 비교
//                // 열쇠가 락에 맞을 경우
//                if (key[lastIndexOfKey - i][lastIndexOfKey - j] != lock[x][y]) {
//                    temp[x][y] = 1;
//                }
//                // 열쇠가 락에 안 맞는 부분이 있는 경우
//                else {
//                    temp[0][0] = -1;
//                    return temp;
//                }
//            }
//        }
//    }
//    // 열쇠 구멍에 맞춘 후 맞춘 결과를 리턴해서 체크함 - 키랑 락이랑 안 겹친 부분에 비어있는 곳이 있을 수 도 있음
//    return temp;
//}
//
//bool insertKey(vector<vector<int>> key, vector<vector<int>> lock) {
//    int lastIndexOfKey = key.size() - 1;
//    int lastIndexOfLock = lock.size() - 1;
//
//    // 키와 락의 길이를 합친 것보다 한 번 적게 반복(키랑 락이랑 겹칠 수 있는 경우의 수)
//    int times = lastIndexOfKey + lastIndexOfLock + 1;
//
//    for (int i = 0; i < times; i++) {
//        for (int j = 0; j < times; j++) {
//            if (check(matching(key, lock, i, j))) {
//                return true;
//            }
//        }
//    }
//
//    return false;
//
//
//}
//
//bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
//    bool answer = false;
//
//    // 90도씩 회전해서 4가지 키를 만듦
//    vector<vector<int>> key1 = key;
//    vector<vector<int>> key2 = rotate(key1);
//    vector<vector<int>> key3 = rotate(key2);
//    vector<vector<int>> key4 = rotate(key3);
//
//    if (insertKey(key1, lock)) {
//        return true;
//    }
//    if (insertKey(key2, lock)) {
//        return true;
//    }
//    if (insertKey(key3, lock)) {
//        return true;
//    }
//    if (insertKey(key4, lock)) {
//        return true;
//    }
//    return false;
//}