// Shao, Zihao
// CS211 Section 52B Homework 16

#include <iostream>
#include <cmath>
using namespace std;
//ok function
bool ok(int q[], int column){
    //create two 3*3 2d arrays for men and women
    int mp[3][3]={
        {0,2,1},
        {0,2,1},
        {1,2,0}};
    int wp[3][3]={
        {2,1,0},
        {0,1,2},
        {2,0,1}};
        
    //go check the input values are ok
    for (int i=0; i<column; i++){
        if (q[column]==q[i])
            return false;
        if((mp[i][q[column]] < mp[i][q[i]] && wp[q[column]][i] < wp[q[column]][column]) || (mp[column][q[i]] < mp[column][q[column]] && wp[q[i]][column] < wp[q[i]][i]))
            return false;
    }
    return true;
}
//print function
void print(int* q){
    static int count = 0;
    cout << "\nStable Matching #" << ++count << ": " << endl;
    cout << "Men:   0 1 2" << endl << "Women: ";
    for (int i=0; i<3; i++)
        cout <<  q[i] << ' ';
    cout << endl << endl;
}

void move(int* q, int i) {
    if(i==3) {
        print(q);
        return;
    }
    //j is row value
    for(int j=0;j<3;j++){
        q[i]=j;
        if(ok(q,i)) 
            move(q,i+1);//go next column otherwise try next j
    }
}
//main function
int main() {
    int q[3];
    move(q,0);
    return 0;
}


