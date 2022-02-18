//#include <string>
//#include <vector>
//
//using namespace std;
//
//int solution(int bridge_length, int weight, vector<int> truck_weights) {
//    int answer = 0;
//    int weight_sum = 0;
//    vector<int> truck_pos(truck_weights.size(), 0);
//
//    int front = 0, back = -1;
//
//    while (truck_pos[truck_pos.size() - 1] != bridge_length + 1)
//    {
//        // Ʈ���� �ö� �� ������
//        if (back + 1 < truck_weights.size() && truck_weights[back + 1] + weight_sum <= weight)
//        {
//            // Ʈ���� �� �� �ٸ��� ��� �ٸ� �ȿ� �ִ� Ʈ������ �� ĭ�� ������ ��
//            back++;
//            weight_sum += truck_weights[back];
//
//            for (int i = front; i <= back; i++)
//            {
//                truck_pos[i]++;
//            }
//            // �� �� Ʈ���� �ٸ����� Ż���ߴ��� üũ
//            if (truck_pos[front] == bridge_length + 1)
//            {
//                weight_sum -= truck_weights[front];
//                front++;
//            }
//
//            // �ð� 1 ����
//            answer++;
//        }
//        // Ʈ���� �� �̻� �� �ö󰡸� �� �տ� �ִ� Ʈ�� Ż���ϰ� ����
//        else
//        {
//            int left = bridge_length - truck_pos[front] + 1;
//
//            // ù Ʈ���� Ż���� ������ ������ ��
//            for (int i = front; i <= back; i++)
//            {
//                truck_pos[i] += left;
//            }
//            // �� �� Ʈ�� Ż��
//            weight_sum -= truck_weights[front];
//            front++;
//
//            // �ð� left ��ŭ ����
//            answer += left;
//
//            // Ż������ �� �ٷ� Ż �� �ִ��� üũ
//            if (back + 1 < truck_weights.size() && truck_weights[back + 1] + weight_sum <= weight)
//            {
//                back++;
//                weight_sum += truck_weights[back];
//                truck_pos[back]++;
//            }
//        }
//    }
//
//    return answer;
//}
//
//int main()
//{
//    solution(2, 10, { 7, 4, 5, 6 });
//}