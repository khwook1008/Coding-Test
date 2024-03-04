#include <iostream>
#include <list>

using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  list<char> a;
  string str;
  cin >> str;
  
  for(auto i : str){
      a.push_back(i);
  }
  
  int N;
  cin >> N;
  auto cursor = a.end(); //cursor 위치 마지막 글자 오른쪽, iterator
  
  while(N--){
      char cmd;
      cin >> cmd;
      if(cmd == 'L'){
          if(cursor != a.begin()){ //맨 왼쪽 있을때 제외
              cursor--;
          }
      }
      else if(cmd == 'D'){
          if(cursor != a.end()){
              cursor++;
          }
      }
      else if(cmd == 'B'){
          if(cursor != a.begin()){
              cursor--;           //cursor를 땡겨서 지울 원소의 위치로 이동
              cursor = a.erase(cursor); //삭제 후 a.erase()의 return 값은 삭제한 다음 원소를 가리킨다
              
          }
      }
      else if(cmd == 'P'){
          char p;
          cin >> p;
          a.insert(cursor, p);
      }
  }
  for(auto i : a){
      cout << i;
  }
}