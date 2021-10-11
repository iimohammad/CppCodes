#include <vector>
#include <iostream>
using namespace std;
class superData{
    private:
    int y;
    string x;
    public:
        virtual void show()=0;

};
class Data1:public superData{
    private: 
        string x;
    public:
        Data1 (string input){
            x = input;
        }
        void show(){
            cout<<x <<endl;
        }
};
class Data2:public superData{
    private:
        int y;
    public:
        Data2 (int input ){
            y = input;
        }
        void show (){
            cout << y << endl;
        }
};


int main() {
    // We want to make a list of Data1 and Data2 with the following values: 
    //  12, "Jack", "Reza", 200, 
    //  Then print the values
        
        vector<superData*> mydata;
        mydata.push_back(new Data2(12));
        mydata.push_back(new Data1("Jack"));
        mydata.push_back(new Data1("Reza"));
        mydata.push_back(new Data2(200));
       
        for (int i=0;i<mydata.size();i++)
            mydata[i]->show();
   return 0;
}
