//// �� Ǯ��
//// 3�� for ������ ��� ���� ���� ��
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
//                // �� �� ������ ���̰��� sqrt�� �Ἥ �ʿ���� �Ҽ� üũ ������ �ٿ���
//                // �׳� ���ڳ� ���� / 2 ���� �������� ����ϸ� �ξ� ����
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

//// �Լ� �ᵵ �ӵ� ���̰� ���� ���� �� ����
//// inline �޽�� �ᵵ ����� �� - ������ ���� ���� �ִ� ��
//// inline �� �� �ᵵ ���� �����Ϸ��� �ڵ����� �ζ���ȭ �����شٰ� ��
//
//#include <vector>
//#include <cmath>
//using namespace std;
//
//bool is_prime(int num)
//{
//    // �� �� ������ ���̰��� sqrt�� �Ἥ �ʿ���� �Ҽ� üũ ������ �ٿ���
//    // �׳� ���ڳ� ���� / 2 ���� �������� ����ϸ� �ξ� ����
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

//// next_permutation ���� Ǯ�
//// �����ϰ� 3�� for ���� ���°� �ξ� ����
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
//            // ���ʿ��� ������ �������� ��������� �̷������� Ż�� ������ �ߴµ� ������ ������
//            // ���� ������ ��û ���� ���� ������ ������� ������ Ż�� ������ �Ŵ� �� ���� ���� �־� ����
//            // ���� ���غ��� �Ǵ��ؾ߰���
//            //if (number_count == 3)
//            //    break;
//        }
//        if (is_prime(number)) answer++;
//    } while (next_permutation(comb.begin(), comb.end()));
//
//    return answer;
//}

//// ��Ʈ ����ũ�� �����غ����� �ߴµ� ��Ʈ ����ũ�� Ư�� ������ŭ�� �̴� ���� �ƴ϶� ��� ������ ���� ���ϴ� �� (nC0 + nC1 + ... + nCc)
//
//// �ٸ� ��� Ǯ��
//#include <vector>
//#include <algorithm>
//using namespace std;
//#define MAXSUM 3001
//bool prime[3001]; //1000������ �ڿ����̹Ƿ�
//
//// �Ҽ� ���ϱ�� �����佺�׳׽��� ����� ����Ѵ�
//// �����佺�׳׽��� ü
//// �̸� ������ ���ұ� ������ ������ ������ �ӵ��� ������ ������ ��� ���� �̵��� �� �� ���� �� ����
//// ���� ����ϴ� �ͺ��� �ſ� ����
//void CheckPrime() {
//    fill(prime, prime + MAXSUM, 1);
//    for (int i = 2; i < MAXSUM; i++) {
//        if (prime[i] == 0) continue;
//        for (int j = i + i; j <= MAXSUM; j += i)
//            prime[j] = 0;
//    }
//}
//
//// ��� �Լ��� ����� 3���� ������
///*
//void Combination(vector<int> &nums, int pos, int r, int sum, int &answer){
//    if(r == 0){ //3���� �� ������
//        if(prime[sum]){
//            answer++;
//            return;
//        }
//    }
//    if(pos == nums.size()) return; //������ Ȯ����
//
//    Combination(nums, ++pos, r, sum, answer); //���� ���ڸ� �������� ����
//    sum += nums[pos-1]; //�ϳ��� ������
//    Combination(nums, pos, --r, sum, answer);
//}
//*/
//
//// ���� Ǭ ����� ����ϰ� ���� ������ �����
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