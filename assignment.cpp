#include<iostream>
#define t_size 11

using namespace std;

struct employee{
    int id;
    string name;
    long int salary;
};

employee hashtable[t_size];

int hashfunc(int key){
    return (key%t_size);
}

void insert(int id,string name,long int salary){
    int index=hashfunc(id);
    for(int i=0;i<t_size;i++){
        if(hashtable[(index+i)%t_size].id==-1||hashtable[(index+i)%t_size].id==-2){
            hashtable[index+i].id=id;
            hashtable[index+i].name=name;
            hashtable[index+i].salary=salary;
            return ;
        }
    }
    cout<<"Memory overflow"<<endl;

}
int search(int id){
    int index=hashfunc(id);
     for(int i=0;i<t_size;i++){
        if(hashtable[(index+i)%t_size].id==id){

            return ((index+i)%t_size);
        }
        if(hashtable[index+i%t_size].id==-1){
            cout<<" Invalid input"<<endl;
            return -1;
        }
    }
    cout<<" Invalid input"<<endl;
    return -1;
}

int deletedata(int id){
    int index=search(id);
    if(index==-1){
         cout<<" Invalid input"<<endl;
    }else{
        hashtable[index].id=-2;
    }
}


int main() {
    for(int i=0;i<t_size;i++){
       hashtable[i].id=-1;
    }
    insert(11,"ABC",100000);
    insert(21,"CDE",200000);
    insert(31,"GHI",100000);
    insert(45,"KLD",100000);
    insert(67,"HJK",700000);
    insert(12,"HUJ",300000);
    deletedata(5);
    cout<<"index"<<search(11)<<endl;
    for(int i=0;i<t_size;i++){
       cout<<"id:"<<hashtable[i].id<<endl;
       cout<<"name:"<<hashtable[i].name<<endl;
       cout<<"salary:"<<hashtable[i].salary<<endl;
       cout<<endl;
    }
   
    return 0;
}

