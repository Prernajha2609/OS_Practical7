//Round Robin scheduling implementation in C++
#include<iostream> 
using namespace std; 

//The Function to find the waiting time for all processes 
void fWaitingTime(int bt[],int n, int wt[], int quantum){ 
	// copy of burst times bt[] to store remaining burst times
	int rem_bt[n];
	
	for (int i = 0 ; i < n ; i++) 
		rem_bt[i] = bt[i]; 

	int t = 0; // for Current time 

	// traverse the processes in the round robin manner until all processes get executed.

	while (1){ 
		bool done = true; 
		for (int i = 0 ; i < n; i++){ 
			// If burst time of a process is greater than 0 then there is a need to process further
			if (rem_bt[i] > 0){ 
				done = false;
				if (rem_bt[i] > quantum){  
					t += quantum; 
					rem_bt[i] -= quantum; 
				} 
				// If burst time is smaller than or equal to the quantum then it is Last cycle for this process 
				else{ 
					t = t + rem_bt[i]; 
					wt[i] = t - bt[i]; 
					rem_bt[i] = 0; 
				} 
			} 
		} 

		// If all the processes are done 
		if (done == true) 
		break; 
	} 
} 

// turn around time 
void fTurnAroundTime(int bt[], int n, int wt[], int tat[]){ 
	for (int i = 0; i < n ; i++) 
		tat[i] = bt[i] + wt[i]; 
} 

//average time 
void findavgTime(int bt[], int n, int quantum){ 
	int wt[n], tat[n], total_wt = 0, total_tat = 0; 

	// Function to find waiting time of all processes 
	fWaitingTime(bt, n, wt, quantum); 

	// Function to find turn around time for all processes 
	fTurnAroundTime(bt, n, wt, tat); 

	// Display processes along with all details 
	cout << "Processes "<< " Burst time "<< " Waiting time " << " Turn around time\n"; 

	for (int i=0; i<n; i++){ 
		total_wt = total_wt + wt[i]; 
		total_tat = total_tat + tat[i]; 
		cout << " " << i+1 << "\t\t" << bt[i] <<"\t "<< wt[i] <<"\t\t " << tat[i] <<endl; 
	} 

	cout << "\nAverage waiting time = "<< (float)total_wt / (float)n; 
	cout << "\nAverage turn around time = "<< (float)total_tat / (float)n; 
} 

//========= main ===========
int main() 
{   int n,time_slice;
    cout<<"\nEnter Number of Process: ";
    cin>>n;
    int bt[n];
    cout<<"\nEnter Burst time for each process:\n";
    for(int i=0; i<n; i++){
        cout<<"Process P"<<(i+1)<<" : ";
        cin>>bt[i];
    }
    
    cout<<"\nEnter time slice: ";
    cin>>time_slice;
	findavgTime(bt,n,time_slice); 
	return 0; 
} 