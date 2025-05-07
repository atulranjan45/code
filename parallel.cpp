#include<iostream>
#include<omp.h>
#include<iomanip>
#include<limits>
#include<time.h> 
#include<chrono> 
using namespace std;

int sum_serial(int n) 
    { 
	int sum = 0; 
	for (int i = 0; i <= n; ++i) 
	    { 
		sum += i; 
	    } 
	return sum; 
    } 

int sum_parallel(int n) 
    { 
	int sum = 0; 
    #pragma omp parallel for reduction(+ : sum) 
	for (int i = 0; i <= n; ++i) 
	    { 
		sum += i; 
	    } 
	return sum; 
    } 
    
int average_serial(int n) 
    { 
	int sum = 0; 
	for (int i = 0; i <= n; ++i) 
	    { 
		sum += i; 
	    } 
	return sum/n; 
    } 

int average_parallel(int n) 
    { 
	int sum = 0; 
    #pragma omp parallel for reduction(+ : sum) 
	for (int i = 0; i <= n; ++i) 
	    { 
		sum += i; 
	    } 
	return sum/n; 
    } 
    
int min_serial(int n) 
    { 
	int min = n; 
	for (int i = n; i >= 0; i--) 
	    { 
		if (i+1 < min)
		    {
		    min = i;
		    }
	    } 
	return min; 
    } 

int min_parallel(int n) 
    { 
	int min = n; 
    #pragma omp parallel for reduction(min : min) 
	for (int i = n; i >= 0; i--) 
	    { 
		if (i+1 < min)
		    {
		    min = i;
		    }
	    } 
	return min; 
    }  
    
int max_serial(int n) 
    { 
	int max = 0; 
	for (int i = 0; i <= n; ++i) 
	    { 
		if (i+1 > max)
		    {
		    max = i;
		    } 
	    } 
	return max; 
    } 

int max_parallel(int n) 
    { 
	int max = 0; 
    #pragma omp parallel for reduction(max : max) 
	for (int i = 0; i <= n; ++i) 
	    { 
		if (i+1 > max)
		    {
		    max = i;
		    }
	    } 
	return max; 
    } 

int main() 
    { 
	const int n = 100000000; 
	
	auto ss_start_time = chrono::high_resolution_clock::now(); 
	int result_sum_serial = sum_serial(n); 
    auto ss_end_time = chrono::high_resolution_clock::now(); 
    chrono::duration<double> sum_serial_duration = ss_end_time - ss_start_time; 
    
    auto sp_start_time = chrono::high_resolution_clock::now(); 
	int result_sum_parallel = sum_parallel(n); 
	auto sp_end_time = chrono::high_resolution_clock::now(); 
	chrono::duration<double> sum_parallel_duration = sp_end_time - sp_start_time; 

    cout << "1. SUM"<<endl<<endl;
	cout << "Serial result: " << result_sum_serial << endl; 
	cout << "Parallel result: " << result_sum_parallel << endl; 
	cout << "Serial duration: "<< fixed << setprecision(10) << sum_serial_duration.count() << " seconds"<< endl; 
	cout << "Parallel duration: "<< fixed << setprecision(10) << sum_parallel_duration.count() << " seconds"<< endl; 
	cout << "Speedup: "<< sum_serial_duration.count() / sum_parallel_duration.count() << endl<<endl; 

    auto as_start_time = chrono::high_resolution_clock::now(); 
	int result_average_serial = average_serial(n); 
    auto as_end_time = chrono::high_resolution_clock::now(); 
    chrono::duration<double> average_serial_duration = as_end_time - as_start_time; 
    
    auto ap_start_time = chrono::high_resolution_clock::now(); 
	int result_average_parallel = average_parallel(n); 
	auto ap_end_time = chrono::high_resolution_clock::now(); 
	chrono::duration<double> average_parallel_duration = ap_end_time - ap_start_time; 

    cout << "2. AVERAGE"<<endl<<endl;
	cout << "Serial result: " << result_average_serial << endl; 
	cout << "Parallel result: " << result_average_parallel << endl; 
	cout << "Serial duration: "<< fixed << setprecision(10) << average_serial_duration.count() << " seconds"<< endl; 
	cout << "Parallel duration: "<< fixed << setprecision(10) << average_parallel_duration.count() << " seconds"<< endl; 
	cout << "Speedup: "<< average_serial_duration.count() / average_parallel_duration.count() << endl<<endl; 

    auto mins_start_time = chrono::high_resolution_clock::now(); 
	int result_min_serial = min_serial(n); 
    auto mins_end_time = chrono::high_resolution_clock::now(); 
    chrono::duration<double> min_serial_duration = mins_end_time - mins_start_time; 
    
    auto minp_start_time = chrono::high_resolution_clock::now(); 
	int result_min_parallel = min_parallel(n); 
	auto minp_end_time = chrono::high_resolution_clock::now(); 
	chrono::duration<double> min_parallel_duration = minp_end_time - minp_start_time; 

    cout << "3. MIN"<<endl<<endl;
	cout << "Serial result: " << result_min_serial << endl; 
	cout << "Parallel result: " << result_min_parallel << endl; 
	cout << "Serial duration: "<< fixed << setprecision(10) << min_serial_duration.count() << " seconds"<< endl; 
	cout << "Parallel duration: "<< fixed << setprecision(10) << min_parallel_duration.count() << " seconds"<< endl; 
	cout << "Speedup: "<< min_serial_duration.count() / min_parallel_duration.count() << endl<<endl; 

    auto maxs_start_time = chrono::high_resolution_clock::now(); 
	int result_max_serial = max_serial(n); 
    auto maxs_end_time = chrono::high_resolution_clock::now(); 
    chrono::duration<double> max_serial_duration = maxs_end_time - maxs_start_time; 
    
    auto maxp_start_time = chrono::high_resolution_clock::now(); 
	int result_max_parallel = max_parallel(n); 
	auto maxp_end_time = chrono::high_resolution_clock::now(); 
	chrono::duration<double> max_parallel_duration = maxp_end_time - maxp_start_time; 

    cout << "4. MAX"<<endl<<endl;
	cout << "Serial result: " << result_max_serial << endl; 
	cout << "Parallel result: " << result_max_parallel << endl; 
	cout << "Serial duration: "<< fixed << setprecision(10) << max_serial_duration.count() << " seconds"<< endl; 
	cout << "Parallel duration: "<< fixed << setprecision(10) << max_parallel_duration.count() << " seconds"<< endl; 
	cout << "Speedup: "<< max_serial_duration.count() / max_parallel_duration.count() << endl<<endl; 

	return 0; 
    }

