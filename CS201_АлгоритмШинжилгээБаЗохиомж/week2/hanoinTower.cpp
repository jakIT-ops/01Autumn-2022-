#include <iostream>
using namespace std;

// hanoin disk n = 7
// moves = 127
int totalMove = 0;

void moveDisk(char fp, char tp){
    cout << "moving disk from " << fp << " to " << tp << endl;
    totalMove++;
}

void hanoinTower(int disks, char fromPole, char toPole, char withPole){
    if (disks >= 1){
        hanoinTower(disks-1, fromPole, withPole, toPole);
        moveDisk(fromPole, toPole);
        hanoinTower(disks-1, withPole, toPole, fromPole);
    }
}

int main() {
    hanoinTower(7, 'A', 'B', 'C');
    cout<<"\ntotal move: "<<totalMove;
}

