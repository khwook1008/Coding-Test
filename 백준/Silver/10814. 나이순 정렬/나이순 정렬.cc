#include <iostream>
#include <algorithm>

using namespace std;

struct Person{
    int Age, idx;
    string Name;
};

int compare(Person now, Person last){
    if(now.Age != last.Age){
        return now.Age < last.Age;
    }
    return now.idx < last.idx;
}

int main()
{
    
    int N;
    cin >> N;

    Person people[100001] = {0,};
    
    for(int i = 0; i < N; i++){
        cin >> people[i].Age >> people[i].Name; 
        people[i].idx = i;
    }
    
    sort(people, people + N, compare);
    
    for(int i = 0; i < N; i++){
        cout << people[i].Age << " " << people[i].Name << "\n";
    }
    

    return 0;
}
