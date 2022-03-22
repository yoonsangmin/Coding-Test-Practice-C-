//// 내 풀이
//// 3중 for 문으로 모든 수를 더해 봄
// #include <vector>
//#include <cmath>
//using namespace std;
//
//int solution(vector<int> nums) {
//    int answer = 0;
//
//    bool flag;
//    int num;
//
//    for (int i = 0; i < nums.size() - 2; i++)
//    {
//        for (int j = i + 1; j < nums.size() - 1; j++)
//        {
//            for (int k = j + 1; k < nums.size(); k++)
//            {
//                num = nums[i] + nums[j] + nums[k];
//                flag = true;
//
//                // 좀 더 연산을 줄이고자 sqrt를 써서 필요없는 소수 체크 연산을 줄여봄
//                // 그냥 숫자나 숫자 / 2 보다 제곱근을 사용하면 훨씬 빠름
// 
//                if (num == 1) return false;
//                for (int i = 2; i <= sqrt(num); i++)
//                {
//                    if (num % i == 0)
//                    {
//                        flag = false;
//                        break;
//                    }
//                }
//
//                if (flag) answer++;
//            }
//        }
//    }
//
//    return answer;
//}

//// 함수 써도 속도 차이가 별로 없는 것 같음
//// inline 메쏘드 써도 비슷한 듯 - 오히려 느릴 때도 있는 듯
//// inline 을 안 써도 현대 컴파일러는 자동으로 인라인화 시켜준다고 함
//
//#include <vector>
//#include <cmath>
//using namespace std;
//
//bool is_prime(int num)
//{
//    // 좀 더 연산을 줄이고자 sqrt를 써서 필요없는 소수 체크 연산을 줄여봄
//    // 그냥 숫자나 숫자 / 2 보다 제곱근을 사용하면 훨씬 빠름
// 
//    if (num == 1) return false;
//    for (int i = 2; i <= sqrt(num); i++)
//    {
//        if (num % i == 0)
//        {
//            return false;
//        }
//    }
//
//    return true;
//}
//
//int solution(vector<int> nums) {
//    int answer = 0;
//
//    for (int i = 0; i < nums.size() - 2; i++)
//    {
//        for (int j = i + 1; j < nums.size() - 1; j++)
//        {
//            for (int k = j + 1; k < nums.size(); k++)
//            {
//                if (is_prime(nums[i] + nums[j] + nums[k])) answer++;
//            }
//        }
//    }
//
//    return answer;
//}

//#include <vector>
//#include <cmath>
//#define MAX 2998
//using namespace std;
//
//void prime_check(vector<bool>& is_prime)
//{
//    is_prime[1] = false;
//
//    for (int i = 2; i <= MAX; i++)
//    {
//        if (!is_prime[i]) continue;
//        for (int j = i + i; j <= MAX; j += i)
//        {
//            is_prime[j] = false;
//        }
//    }
//}
//
//int solution(vector<int> nums) {
//    int answer = 0;
//
//    vector<bool> is_prime(MAX, true);
//
//    prime_check(is_prime);
//
//    for (int i = 0; i < nums.size() - 2; i++)
//    {
//        for (int j = i + 1; j < nums.size() - 1; j++)
//        {
//            for (int k = j + 1; k < nums.size(); k++)
//            {
//                if (is_prime[nums[i] + nums[j] + nums[k]]) answer++;
//            }
//        }
//    }
//
//    return answer;
//}

//// next_permutation 으로 풀어봄
//// 무식하게 3중 for 문을 쓰는게 훨씬 빠름
//#include <vector>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//
//bool is_prime(int num)
//{
//    if (num == 1) return false;
//    for (int i = 2; i <= sqrt(num); i++)
//    {
//        if (num % i == 0)
//        {
//            return false;
//        }
//    }
//
//    return true;
//}
//
//int solution(vector<int> nums) {
//    int answer = 0;
//    vector<bool> comb(nums.size(), false);
//
//    for (int i = 0; i < 3; i++)
//    {
//        comb[nums.size() - 1 - i] = true;
//    }
//
//    int number = 0;
//    //int number_count = 0;
//    do
//    {
//        number = 0;
//        //number_count = 0;
//
//        for (int i = 0; i < comb.size(); i++)
//        {
//            if (comb[i])
//            {
//                number += nums[i];
//                //number_count++;
//            }
//            // 불필요한 연산이 많아지면 느려질까봐 이런식으로 탈출 연산을 했는데 오히려 느렸음
//            // 수의 개수가 엄청 많고 조건 연산이 길었으면 오히려 탈출 조건을 거는 게 좋을 수도 있어 보임
//            // 직접 비교해보고 판단해야겠음
//            //if (number_count == 3)
//            //    break;
//        }
//        if (is_prime(number)) answer++;
//    } while (next_permutation(comb.begin(), comb.end()));
//
//    return answer;
//}

//// 비트 마스크도 연습해보려고 했는데 비트 마스크는 특정 개수만큼만 뽑는 것이 아니라 모든 조합의 수를 구하는 것 (nC0 + nC1 + ... + nCc)
//
//// 다른 사람 풀이
//#include <vector>
//#include <algorithm>
//using namespace std;
//#define MAXSUM 3001
//bool prime[3001]; //1000이하의 자연수이므로
//
//// 소수 구하기는 에라토스테네스의 방법을 사용한다
//// 에라토스테네스의 체
//// 미리 연산해 놓았기 때문에 개수가 적으면 속도가 느리고 많으면 어느 정도 이득을 볼 수 있을 것 같음
//// 각각 계산하는 것보다 매우 빠름
//void CheckPrime() {
//    fill(prime, prime + MAXSUM, 1);
//    for (int i = 2; i < MAXSUM; i++) {
//        if (prime[i] == 0) continue;
//        for (int j = i + i; j <= MAXSUM; j += i)
//            prime[j] = 0;
//    }
//}
//
//// 재귀 함수를 사용해 3개를 선택함
///*
//void Combination(vector<int> &nums, int pos, int r, int sum, int &answer){
//    if(r == 0){ //3개를 다 선택함
//        if(prime[sum]){
//            answer++;
//            return;
//        }
//    }
//    if(pos == nums.size()) return; //끝까지 확인함
//
//    Combination(nums, ++pos, r, sum, answer); //현재 숫자를 선택하지 않음
//    sum += nums[pos-1]; //하나를 선택함
//    Combination(nums, pos, --r, sum, answer);
//}
//*/
//
//// 내가 푼 방법과 비슷하게 다음 순열을 사용함
//void Combination(vector<int> nums, int& answer) {
//    int sum = 0;
//    int s = nums.size();
//    vector<int> per(s - 3);
//    for (int i = 0; i < 3; i++) per.push_back(1);
//
//    //do {
//    //    sum = 0;
//    //    for (int i = 0; i < per.size(); i++)
//    //        if (per[i] == 1) sum += nums[i];
//    //    if (prime[sum]) answer++;
//    //} while (next_permutation(per.begin(), per.end()));
//
//    for (int i = 0; i < nums.size() - 2; i++)
//    {
//        for (int j = i + 1; j < nums.size() - 1; j++)
//        {
//            for (int k = j + 1; k < nums.size(); k++)
//            {
//                if (prime[nums[i] + nums[j] + nums[k]]) answer++;
//            }
//        }
//    }
//}
//
//
//int solution(vector<int> nums) {
//    int answer = 0; int pos = 0;
//    int sum = 0; int r = 3;
//
//    CheckPrime();
//    Combination(nums, answer);
//    return answer;
//}