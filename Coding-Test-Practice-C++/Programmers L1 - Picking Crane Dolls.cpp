//#include <string>
//#include <vector>
//#include <stack>
//
//using namespace std;
//
//int solution(vector<vector<int>> board, vector<int> moves) {
//    int answer = 0;
//	int picked_doll;
//	stack<int> doll_stack;
//
//	for (int move : moves)
//	{
//		int y = move - 1;
//		for (int x = 0; x < board.size(); x++)
//		{
//			picked_doll = board[x][y];
//
//			if (picked_doll != 0)
//			{
//				if (!doll_stack.empty() && doll_stack.top() == picked_doll)
//				{
//					answer += 2;
//					doll_stack.pop();
//				}
//				else
//					doll_stack.push(picked_doll);
//
//				board[x][y] = 0;
//
//				break;
//			}
//		}
//	}
//
//    return answer;
//}