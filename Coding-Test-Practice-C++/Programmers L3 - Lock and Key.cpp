//// ≥ª «Æ¿Ã
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