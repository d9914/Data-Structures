// This program stores ten words entered by the user into a vector containing 15 elements then displays the vector and continuously 
//asks the user to enter a word to check if it's in the vector or not
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class rocky//declaration of class rocky
{
public:
rocky()
{
 int i;
 for (i=1;i<=15;i++){
  a.push_back("???");//fills all 15 spots of vector with ???
}
}

void display(void)//funcion to display contents of the vector
{int i;
 for (i=0;i<15;i++)
   cout<<a[i]<<"  ";
 cout<<endl;
}
 
 void store_it(string i){//function to store words into the vector
    int z;
    bool stored;
    int t=i.size()-1;
    z=i[0]+i[1]+i[t];
    z=z%15;//calculations of hash value
    
   if(a[z]=="???"){//if ??? is in position z then it must be empty
    a[z]=i;
    stored=true;
   }
        
    else{
       stored=false;
        }
    
    
    while(!stored)
    {
        ++z;
        
        if(z>14){//if z is greater than 14 cycle back to the begining of the vector
            z=0;}
        
        if(a[z]=="???"){//once we find an empty spot in the vector store the word
            a[z]=i;
            stored=true;}
 }
}

void search(string i)//function to search for designtated word
{
    int x;
    bool flag;
    int t=i.size()-1;
    x=i[0]+i[1]+i[t];
    x=x%15;//calculates hash value of chosen word
    
    if(a[x]==i){//checks to see if the initial spot contains the word
     cout<<"The word is in the array"<<endl;        
    flag=true;
        }
    else{
        flag=false;
    }
    
    while(!flag){//loop to cycle through rest of vector
    ++x;
    if(x>14){//if we go past 14 cycle back to the beginig of the vector
        x=0;
    }
    if(a[x]==i){//if position x ever contains the chosen word then it's present in the vector
        cout<<"The word is in the array "<<endl;
        flag=true;
    }
    if(a[x]=="???"){//if we get to a position in the vector that contains ??? then the word is not in the vector
        cout<<"The word is not in the array "<<endl;
        flag=true;
    }
    }
    
}





private:
vector <string> a;//private declaration of vecotr a


};

int main(void)//beginig of main
{  rocky x;//instance of rocky x
    string i;
   for(int y=0;y<10;y++){//have the user enter 10 words
   cout<<"Enter a string "<<endl;
   cin>>i;
   x.store_it(i);}//call function store_it
   x.display();//call function display
   
  
   bool k=true;
   while(k){//loop to search for words
   cout<<"Enter a word to search or type 444 to exit "<<endl;//enter word to search
   cin>>i;
   if(i=="444"){//if 444 is entered break out of loop
     k=false;
     break;
   }
   x.search(i);//call search function
   }
   
   return 0;//end of main
}