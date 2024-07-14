#include<iostream>
#include<string>
#include<vector>
#define W 10
#define H 10





// using namespace std;

// int player[] = {0, 1};

// char currentChoice = '+';

// string canvas[H];
// vector<string> states;

// void update(){
//     bool move = true;
//     int oldX = player[0];
//     int oldY = player[1];
//     switch (currentChoice)
//     {
//     case 'w':
//         player[1] -= 1;
//         break;
//     case 's':
//         player[1] += 1;
//         break;
//     case 'a':
//         player[0] -= 1;
//         break;
//     case 'd':
//         player[0] += 1;
//         break;
//     case 'p':
//     case 'c':
//         move = false;
//         break;
//     default:
//         cout << "Please enter a valid choice." << endl;
//         return;
//         break;
//     }

//     player[0] = player[0] % W;
//     player[1] = player[1] % H;

//     if(move){
//         canvas[player[1]][player[0]] = '@';
//         canvas[oldY][oldX] = ''
//     }

// }
// void render(){
//     system("cls");
//     cout << string(W + 2, '#') << endl;
//     for(int y = 0; y < H; y++){
//         cout << '#' <<  canvas[y] << '#' <<  endl;
//     }
//     cout << string(W + 2, '#') << endl;
//     cout << "States saved : " << endl;
//     for(auto i = states.begin(); i != states.end(); ++i){
//         cout << *i << endl;
//     }
// }

// int main(){
//     // Setting up canvas
//     for(int y = 0; y < H; y++){
//         canvas[y] = string(W, ' ');
//     }
//     cout << "Your choices are as follows : " << endl;
//     cout << "1. Move Up : 'w'" << endl;
//     cout << "2. Move Down : 's'" << endl;
//     cout << "3. Move Left : 'a'" << endl;
//     cout << "4. Move Right : 'd'" << endl;
//     cout << "5. Move Paint : 'p" << endl;
//     cout << "6. Move Clear : 'c'" << endl;

//     while(true){
//         update();
//         render();
//         cout << "Enter your choice : ";
//         cin >> currentChoice;
//     }

//     return 0;
// }

using namespace std;

class Player{
    public:
        int x,y;
        Player(int x, int y){
            this->x = x;
            this->y = y;
        }
};

int *MainGrid;
char currentChoice = ']';
Player player(0, 0);
vector<string> states;

void render(){
    system("cls");
    cout << string(W + 2, '-') << endl;

    for(int y = 0; y < H; y++){
        cout << '|';
        for(int x = 0; x <W; x++){
            int point = *(MainGrid + y * W + x);
            if(point == 0) cout << " "; // Unpainted
            else if(point == 1) cout << "@"; // Painted
            else if(point == 2) cout << "#"; // Unpainted, but player on tile.
            else if(point == 3) cout << "#"; // Implies, is painted and the player is on the tile.
            else{
                cerr << "How did this even happen." << point << x << y << endl;
                exit(1);
            }
        }
        cout << '|' << endl;
    }

    cout << string(W + 2, '-') << endl;

    string ultimateState = "";


    for(auto &i: states){
        ultimateState += i;
        cout << i << endl;
    }

    // cout << ultimateState << endl;

    string flagStates = "1000010002100001000010000100001000010000100001000001111000000000000000000000000000000000000000000000\
0000000002000000000000000000000000000000000000000001111000000000000000000000000000000000000000000000\
1000010002100001000010100100001010010000101001000001111000000000000000000000000000000000000000000000\
1111100002001000000000100000000010000000001000000001111000000000000000000000000000000000000000000000\
0000000002100010000011001000001010100000100110000010001000000000000000000000000000000000000000000000";

    // The end target is the draw the flag and then that will verify the flag. The solution would be to retrace the steps from the flag states given in this.

    if(flagStates.compare(ultimateState)){
        cout << "Damn, you knew the flag." << endl;
    }
}

void saveState(){
    string newState = "";
    for(int i = 0; i < W*H; i++){
        newState += (char)(*(MainGrid + i) + '0');
    }
    states.emplace_back(newState);
}

void update(){
    if(currentChoice == 'q'){
        saveState();
        return;
    }

    bool move = true;
    int oldX = player.x;
    int oldY = player.y;
    switch (currentChoice)
    {
    case 'w':
        player.y -= 1;
        break;
    case 's':
        player.y += 1;
        break;
    case 'a':
        player.x -= 1;
        break;
    case 'd':
        player.x += 1;
        break;
    case 'p':
    case 'c':
        move = false;
        break;
    default:
        cout << "Please enter a valid choice." << endl;
        return;
        break;
    }

    player.x = player.x % W;
    player.y = player.y % H;

    if(move){
        // *(MainGrid + oldY*W + oldX) &= ~((unsigned long)1 << 2); // Clearing the 2nd bit
        // *(MainGrid + player.y*W + player.x) |= ((unsigned long)1 << 2); // Setting the 2nd Bit 
            //      if(point == 0) cout << " "; // Unpainted
            // else if(point == 1) cout << "@"; // Painted
            // else if(point == 2) cout << "#"; // Unpainted, but player on tile.
            // else if(point == 3) cout << "#"; // Implies, is painted and the player is on the tile.
        int oldVal = *(MainGrid + oldY*W + oldX);
        int newVal = *(MainGrid + player.y*W + player.x);
        bool oldPainted = oldVal == 3;
        bool newPainted = newVal == 1;

        // if(oldPainted){
        //     *(MainGrid + oldY*W + oldX) = 1;
        // }else{
        //     *(MainGrid + oldY*W + oldX) = 0;
        // }
        *(MainGrid + oldY*W + oldX) = (int) oldPainted;

        // if(newPainted){
        //     *(MainGrid + player.y*W + player.x) = 3;
        // }else{
        //     *(MainGrid + player.y*W + player.x) = 2;
        // }
        *(MainGrid + player.y*W + player.x) = (int) newPainted + 2;
    } else{
        if(currentChoice == 'p'){
            // *(MainGrid + player.y*W + player.x) |= ((unsigned long)1 << 1); // Setting the 1st bit
            *(MainGrid + player.y*W + player.x) = 3;
        }else if(currentChoice == 'c'){
            *(MainGrid + player.y*W + player.x) = 2; // Clearing the 2nd bit.
        }
    }

}

int main(){
    MainGrid = new int[H*W];
    for(int y = 0; y < H; y++){
        for(int x = 0; x <W; x++){
            *(MainGrid + y * W + x) = 0;
        }
    }
    *(MainGrid + player.y*W + player.x) = 2;
    while(true){
        update();
        render();
        cout << "Your choices are as follows : " << endl;
        cout << "1. Move Up : 'w'" << endl;
        cout << "2. Move Down : 's'" << endl;
        cout << "3. Move Left : 'a'" << endl;
        cout << "4. Move Right : 'd'" << endl;
        cout << "5. Move Paint : 'p" << endl;
        cout << "6. Move Clear : 'c'" << endl;
        cout << "7. Save state : 'q'" << endl;
        cout << "Enter your choice : " << endl;
        cin.clear();
        cin >> currentChoice;
    }
}