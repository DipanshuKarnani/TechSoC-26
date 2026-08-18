#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int maxstorage;
    cin>> maxstorage;

    float noc;    //number of containers - noc
    cin>>noc;

    vector<int> woec(noc);     //weight of each container - woec
    for(int i=0; i< noc; i++){
        cin>> woec[i];
    }

    float sum=0;
    for(int j=0; j< noc; j++){
        sum+=woec[j];
    }

    float acw;    //average container weight acw
    acw = sum/noc;

    cout<<"Total Shipment Weight: "<< sum<< endl;

    cout<<"Average Container Weight: "<< acw << endl;

    cout<<"Heaviest Container: "<< *max_element(woec.begin(), woec.end())<< endl;

    cout<<"Lightest Container: "<< *min_element(woec.begin(), woec.end())<< endl;

    if(sum < 200){
        cout<<"Classification: "<< "Light"<< endl;
    }

    else{
        cout<<"Classification: " <<"Heavy"<< endl;;
    }

    cout<<"Port Capacity: "<< maxstorage<< endl;

    if(sum> maxstorage){
        cout<<"Status"<<"Shipment exceeds port capacity"<< endl;
    }

    else{
        cout<<"Status: "<<"Shipment can be unloaded"<< endl;
    }

    return 0;
}