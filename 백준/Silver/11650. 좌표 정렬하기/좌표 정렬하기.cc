#include <iostream>
#include <algorithm>

using namespace std;

struct map{
    int x;
    int y;
};

int compare(map first, map second){
    if(first.x == second.x){
        return first.y < second.y;
    }
    else{
        return first.x < second.x;
    }
    return 0;
}
int main()
{
    
    int N;
    cin >> N;

    struct map mapping[N] = {0,};
    
    for(int i = 0; i < N; i++){
        cin >> mapping[i].x >> mapping[i].y;
    }
    
    sort(mapping, mapping + N, compare);
    
    for(int i = 0; i < N; i++){
        cout << mapping[i].x << " " << mapping[i].y << "\n";
    }
    

    return 0;
}
