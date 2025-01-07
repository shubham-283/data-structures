//Game
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct player{
    string name;
    int total;
    struct player *next;
}*start=NULL,*finish=NULL,*ptr=NULL;

struct player *takeMemory(const string& name) {
    struct player *newPlayer = new player();
    if (newPlayer == NULL) {
        cout << "Memory Not Found";
        exit(1);
    }
    newPlayer->name = name;
    newPlayer->total = 0;
    newPlayer->next = NULL;
    return newPlayer;
}

void AddPlayer(string name) {
    struct player *newPlayer = takeMemory(name);
    if (start == NULL) {
        start = newPlayer;
        finish = newPlayer; 
    } else {
        finish->next = newPlayer;
        finish = newPlayer;
    }
}

int generateNumber() {
    return (rand() % 6) + 1;
}

void diceRoll(){
    int dice=0;
    ptr=start;
    while (ptr != NULL) {
        bool reroll = true;
        int chance =1;
        cout<<ptr->name <<"! Press 1 to Roll the dice & 0 to Skip your current Roll:";
        cin>>chance;
        if(chance==1){
            while (reroll) {
                dice = generateNumber();
                cout << ptr->name << " has obtained ---> " << dice << std::endl;
    
                if (dice == 6) {
                    int skip= 0;
                    cout << ptr->name << ", it's 6! Enter 1 to Reroll & 0 to skip " << endl;
                    cin>>skip;
                    if(skip==1){
                        continue;
                    }
                    else{
                        reroll=false;
                        break;
                    }
                    
                } else {
                    ptr->total += dice;
                    reroll = false;
                }
            }
        }
        else
            ptr->total=ptr->total+0;
        ptr = ptr->next;
    }
}


// void startGame() {
//     int i = 0;
//     int dice = 0;

//     while (i < 4) { 
//         ptr = start;

//         while (ptr != NULL) {
//             bool reroll = true;

//             while (reroll) {
//                 dice = generateNumber();
//                 cout << ptr->name << " has obtained --->" << dice << std::endl;

//                 if (dice == 6) {
//                     std::cout << "It's 6! Time to reroll for " << ptr->name << std::endl;
//                 } else {
//                     ptr->total += dice;
//                     reroll = false;
//                 }
//             }

//             ptr = ptr->next;
//         }

//         i++;
//     }
// }


void scorecard(struct player *ptr) {
    cout << ptr->name << "\t\t\t\t" << ptr->total << endl;
    if (ptr->next != NULL)
        scorecard(ptr->next);
    
}

void winner(){
    int maxTotal=0;
    string winName;
    ptr=start;
    while(ptr!=NULL){
        if(ptr->total>maxTotal){
            maxTotal=ptr->total;
            winName=ptr->name;
        }
        ptr=ptr->next;
    }
    cout<<"Congratulations "<<winName<<"! You won the game. \nYour Score is "<<maxTotal<<endl;
}

int main() { 
    
    int numberOfPlayers=0;
    int gameRound=0;
    int i=0;
    int j=0;
    string playerName;
    cout<<"Enter Total Number of Players:";
    cin>>numberOfPlayers;
    while(i<numberOfPlayers){
        cout<<"Enter Name of Player Number "<<i+1<<" : ";
        cin>>playerName;
        AddPlayer(playerName);
        i++;
        cout<<endl;
    }
    
    // AddPlayer("Shubham");
    // AddPlayer("Shubh");
    // AddPlayer("Shu");
    // AddPlayer("Sh");
    // cout<<"Done"<<endl;
    //startGame();
    
    srand(time(0));
    cout<<"Enter Number rounds you want to play:";
    cin>>gameRound;
    while(j<gameRound){
        cout<<endl;
        cout<<"Round "<<j+1<<":"<<endl;
        diceRoll();
        j++;
        cout<<endl;
    }
    cout << "Name\t\t\t\tScore" << endl;
    scorecard(start);
    
    cout<<endl;
    winner();
}
