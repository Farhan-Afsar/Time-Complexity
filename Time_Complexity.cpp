#include<bits/stdc++.h>
using namespace std;

int get_Max_inbuilt(int a,int b,int c){   //Time Complexity of this function is O(1)
    return max({a,b,c});                  //Max inbuilt function runs in constant time
}
int get_Sum(int a,int b,int c){
    return a+b+c;                     //Time Complexity of this function is O(1) 
}

void get_max_vector(vector<int> v,int n){
    int max = INT_MIN;                
                                       
    for(int i = 0; i < n; i++){   // O(n) for max comparison loop
        if(v[i] > max)            // O(1) for max variable and print and if inside comparison loop
            max = v[i];           //Overall Complaxity for this function O(n+1+1+1) = O(n+1) = O(n)                                           
    }                                                              
    cout << "Max: " << max << endl;
}
void get_occurrance(vector<int> v,int n){
    for(int i = 0; i < n; i++){            //For ans variable print statement and if condition inside 
        string ans = "No\n";               //nested loop all are constant O(1)
        for(int j = 0; j < n; j++){        //Time Complexity O(1+1+1+n^2) = O(n^2)
            if(i == j)
                continue;
            if(v[i] == v[j])
                ans = "Yes\n";
        }
        cout <<"i = " << i << " "<< ans;
    }
}
int fibonacci(int n){                    
    if (n < 2)             //Time Complexity of this fibonacci function is O(2^n + 1) = O(2^n)
        return n;          //In this function every time two function is called 
                           //for one function call so for n function call function will be 
    return fibonacci(n-1)+fibonacci(n-2);  //called 2*n time until base case is matched
}
int Binary_Serach(vector<int> v,int low ,int high,int key){
    bool flag = -1;                      //For flag three conditon inside loop are all constant O(1)
    while(low <= high){                  //For while loop we are taking only half of the element to 
        int mid = low + (high-low)/2;    //search if not found. so for n iteration we are making the
        if(v[mid] == key){               //vector size as (n/2^n).if after k iteration our vector size                          
            return mid;                  //is 1 then we can say (n/2^k) = 1 so thats log2 n.
        }
        if(v[mid] >  key)                //so overall complexity O(log n + 1) = O(log n)
            high = mid - 1;
        else
           low = mid + 1; 
    }
    return -1;
}
void Print_Number(int i, int n){
    if (i > n)
        return;           //In this function we are recursively printing i to n number
                          //until base case is matched.as n is user input 
    cout << i << " ";     //Time Complexity O(n + 1) = O(n)
    Print_Number(i+1, n);
}
void nlogn(int n){
    cout<< "\n";
    for(int i = 0; i < n; i++){
        for (int j = 1; j < n; j = j * 2){  //For first loop which is running n time and in nested loop 
            cout<< j << " ";                //it is multiplying its increment which runs in logn time
        }                                   //Time Complexity O(n*logn) = O(nlogn)
        cout << "\n";
    }
}
void qube(int n){
    int count = 0;
    for(int i = 0; i < n; i++){              //Nested three loop running n time
        for(int j = 0; j < n; j++){          //Time Complexity O(n^3)
            for(int k = 0; k < n; k++){
                cout << count++ << " ";
            }
        }
    }
}
int Sum_of_N_Number_factorial(int n){
    if (n == 0)        //For if condition O(1)
        return 0;      //For function call O(n)
                       //Time Complexity O(n + 1) = O(n)
    return n + Sum_of_N_Number_factorial(n-1);
}
int main(){
    int a,b,c;
    cout << "Enter three number "<<endl;
    cin >> a >> b >> c;
    cout <<"Max inbuilt:" <<get_Max_inbuilt(a,b,c) << endl;
    cout << "Sum: "<<get_Sum(a,b,c) << endl;
    int n;
    cout << "Enter vector size: "<<endl;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){       
        cin >> v[i];                  
    } 
    get_max_vector(v,n);
    get_occurrance(v,n);
     
    cout << "Which fibonacci you need: ";
    int fib;
    cin >> fib;
    cout <<"Fibonacci: " <<fibonacci(fib) << endl;

    int key;
    cout << "Enter key to search: ";
    cin >> key;
    cout << "Index of search element: "<< Binary_Serach(v,0,n-1,key)<< endl;
    int m;
    cout << "Until which number you want to print: ";
    cin >> m;
    Print_Number(1,m);
    cout<<"\n";
    nlogn(m);
    cout<<"\n";
    qube(n);
    cout<<"\n";
    cout<<"Sum of n factorial number: "<<Sum_of_N_Number_factorial(n)<< endl;
}