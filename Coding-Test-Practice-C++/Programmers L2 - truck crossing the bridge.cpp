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
//        // 트럭이 올라갈 수 있으면
//        if (back + 1 < truck_weights.size() && truck_weights[back + 1] + weight_sum <= weight)
//        {
//            // 트럭을 한 대 다리에 얹고 다리 안에 있는 트럭들은 한 칸씩 앞으로 밈
//            back++;
//            weight_sum += truck_weights[back];
//
//            for (int i = front; i <= back; i++)
//            {
//                truck_pos[i]++;
//            }
//            // 맨 앞 트럭이 다리에서 탈출했는지 체크
//            if (truck_pos[front] == bridge_length + 1)
//            {
//                weight_sum -= truck_weights[front];
//                front++;
//            }
//
//            // 시간 1 지남
//            answer++;
//        }
//        // 트럭이 더 이상 못 올라가면 맨 앞에 있는 트럭 탈출하게 만듦
//        else
//        {
//            int left = bridge_length - truck_pos[front] + 1;
//
//            // 첫 트럭이 탈출할 때까지 앞으로 밈
//            for (int i = front; i <= back; i++)
//            {
//                truck_pos[i] += left;
//            }
//            // 맨 앞 트럭 탈출
//            weight_sum -= truck_weights[front];
//            front++;
//
//            // 시간 left 만큼 지남
//            answer += left;
//
//            // 탈출했을 때 바로 탈 수 있는지 체크
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