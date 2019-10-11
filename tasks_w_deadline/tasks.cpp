#include <bits/stdc++.h>


using namespace std;


typedef struct {
    int deadline;
    int profit;
}Task;



bool sort_cond(Task i, Task j){
    return (i.deadline < j.deadline);
}

void print_tasks(vector<Task> arr){

    int len = arr.size();

    for(int i = 0; i < len; i++)
        cout << "task " << i+1 << " deadline: " << arr[i].deadline << " profit: " << arr[i].profit << endl;

}



void max_profit(vector<Task> arr){


    vector<Task> chosen;

    Task best;

    sort(arr.begin(),arr.end(),sort_cond);

    for(int i = 1; i <= arr.size(); i++){

        best.profit = 0;

        while(arr[i-1].deadline == arr[i].deadline){
            
            if(arr[i-1].profit < arr[i].profit && best.profit < arr[i].profit)
                best = arr[i];
            

            else if(arr[i].profit < arr[i-1].profit && best.profit < arr[i-1].profit)
                best = arr[i-1];
        
        
            i++;

        }

        if(best.profit != 0)
            chosen.push_back(best);
        else
            chosen.push_back(arr[i-1]);

    }

    print_tasks(chosen);
}

//Maximizar lucro, ordenando tarefas
int main(){


    int N;

    vector<Task> tasks;

    cin >> N;
    cout << endl;

    for(int i = 0; i < N; i++){

        Task new_task;

        int dd, pft;

        cin >> dd >> pft;
        
        new_task.profit = pft;
        new_task.deadline = dd;

        tasks.push_back(new_task);

    }

    max_profit(tasks);

    return 0;
}