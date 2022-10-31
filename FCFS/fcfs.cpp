// First come first serve implementation 
#include <iostream>

void identifyWaitingTime(int processes[], int burstTime[], int waitingTime[], int process){
    // Waiting time of first process is 0 as rule

    waitingTime[0] = 0;
    int i;
    for(int i = 1; i < process; ++i){
        waitingTime[i] = burstTime[i-1] + waitingTime[i-1];
    }

}


void identifyTimeAroundTime(int processes[], int burstTime[], int waitingTime[], int process, int turnAroundTime[]){
    // Turn aroud time is one of the criterias of CPU Scheduling
    // for defining the around time we need to add up burstTime and waitingTime
    int i;
    for(i = 0 ; i < process; ++i){
        turnAroundTime[i] = waitingTime[i] + burstTime[i];
    }
}

void identifyAvarageTime(int processes[], int burstTime[], int process){
    int waitingTime[process], turnAroundTime[process];
    int totalWaitingTime = 0 , totalTurnAroundTime = 0;

    // Find waiting time
    identifyWaitingTime(processes, burstTime,  waitingTime,  process);


    // Find turn around time
    identifyTimeAroundTime(processes, burstTime, waitingTime, process, turnAroundTime);

    // Output of each criteria

    std::cout << "Processes " << "Burst time" << "Waiting time" << "Turn around time " << std::endl;

    for(int i = 0 ; i < process; ++i){
        totalWaitingTime += waitingTime[i];
        totalTurnAroundTime += turnAroundTime[i];

        // Output
        std::cout << "  " << i+1 << "\t\t" << burstTime[i] << "\t   " << waitingTime[i] << "\t   "<< turnAroundTime[i] << std::endl; 
    }

    // Identify avarage time
    float avarageTurnAroundTime = (float)totalTurnAroundTime / (float)process;
    float avarageWaitingTime = (float)totalWaitingTime / (float)process;
    std::cout << "Avarage waiting time:" << avarageWaitingTime << std::endl;
    std::cout << "Avarage turn around time:" << avarageTurnAroundTime << std::endl;
}

int main(){
    int processes[] = {1,2,3};
    int process = sizeof(processes[0]) / sizeof(processes);
    // Burst time of processes
    int burstTime[] = {4,8,9};

    identifyAvarageTime(processes, burstTime, process);
    return 0;
}