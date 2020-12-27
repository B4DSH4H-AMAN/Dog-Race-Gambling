#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Using Structs Naming it to Dog Gambling Game
// We will store all the Information about the Game inside this Struct
struct DogGamblingGame{
    char Name[50]; // Storing Name with Limit of 50
    int WinningOdds; // Percentage of Winning
    int Payouts; // Storing Winning Amount
};

char GameStart(); // Game Menu
void DogList(); // Displaying List of Dogs
void DogInfo(); // Storing Dog Information
void Randomizer(); // Randomizing the Winning Odds percentage
int DogRace(); // Making sure to get result different everytime
void DogRaceInformation(); // Processing the Data and giving output
void RaceData(); // Storing the previous Race Data for showing the all the Race Result


int main(void){
    char Option;
    char RaceData[1000][100];
    int counter = 0;
    struct DogGamblingGame Dog[9]; // Importing Structure of DogGamblingGame as Dog object
    int RandomNumbers[100];
    DogInfo(Dog); // Calling DogInfo
    Randomizer(Dog, RandomNumbers); // Calling Randomizer function

    printf("\n**********************************************************");
    printf("\n*************  WELCOME TO DOG RACING TRACK   *************\n");
    printf("*************  PICK A DOG PLACE A WAGER        ***********\n");
    printf("*************  WIN THE CASH IF YOU ARE CORRECT ***********\n");
    printf("**********************************************************\n");

    do{
        Option = GameStart(); // Calling GameStart Function and storing the Choice data to Option
        if(Option == 'G'){
            // Calling Dog Race Information and setting datas in Dog, RandomNumbers, RaceData
            DogRaceInformation(Dog, RandomNumbers, RaceData[counter]);
        }else if(Option == 'R'){
            // Accessing the Race Data for Future use
            for(int i = 0; i < counter; i++){
                printf("%s",RaceData[i]); // Displaying Result of Last Matches
            }
        }else if(Option == 'L'){
            // Exiting the Program
            printf("\n**********      THANKS FOR JOINING US        **********\n");
        }else {
            printf("\n**********  PLEASE SELECT PROPER OPTION  **********\n");
        } counter++;
    }while(Option != 'L');
}

char GameStart(){
    // Menu Displaying Options:
    printf("\n***********************************************************");
    printf("\n****************  WHAT YOU WANNA DO:        ***************\n");
    printf("****************  RESULT OF ALL RACES: [R]  ***************\n");
    printf("****************  PLACE GAMBLE: [G]         ***************\n");
    printf("****************  LEAVE THE DOG TRACK: [L]  ***************\n");
    printf("***********************************************************\n");
    printf("\n****** ENTER YOUR CHOICE: ");
    char Choice; // Taking User Choice
    scanf(" %c",&Choice);
    return Choice; // Returing the Choice
}

void DogList(struct DogGamblingGame* Dog){
    printf("\n***********************************************************\n");
    printf("**************   PICK A DOG FOR YOUR WAGER   **************\n");
    printf("***********************************************************\n");
    printf("\n**********  S.NO    DOG NAME     PAYOUTS     ODDS OF WINNING  \n");
    // Displaying All the Dog Data
    for(int i = 0; i < 9; i++){
        printf("**********   %d.    %7s   %4d to 1   %7d%%\n", i+1, Dog[i].Name, Dog[i].Payouts, Dog[i].WinningOdds);
    }
}

void DogInfo(struct DogGamblingGame* Dog){
    // Storing Names of Dogs
    char Names_of_Dogs[9][32] = {"FurryPals","Boxers","Rottweiler","Poodles","Bulldog", "Beagles","Bulldogs","Retrievers","Shepherds"};
    int Payouts[9] = {2,5,10,15,50,20,10,5,3}; // Storing Payouts
    int WinningOdds[9] = {40,10,8,6,1,4,8,10,13}; // Storing Win Percentage
    // Storing the Information using Loop
    for(int i = 0; i < 9; i++){
        strcpy(Dog[i].Name, Names_of_Dogs[i]);
        Dog[i].Payouts = Payouts[i];
        Dog[i].WinningOdds = WinningOdds[i];
    }
}

void Randomizer(struct DogGamblingGame* Dog, int *RandomNum){
    int Random = 0;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < Dog[i].WinningOdds; j++){ // Accessing the Random Dog to Race with
            RandomNum[Random++] = i;
        }
    }
}

int DogRace(int* RandomNum){
    srand(time(0)); // Timing starting with Zero
    int Random = rand()%100; // Returing Random Number
    return RandomNum[Random];
}

void DogRaceInformation(struct DogGamblingGame* Dog, int *RandomNum, char* buffer){
    int Wager;
    int DogPick;
    int Result;
    DogList(Dog); // Calling DogList Function

    printf("\n***********************************************************\n");
    printf("**********  PLEASE ENTER GREG INPUT A WAGER: ");
    scanf("%d", &Wager);
    printf("\n********** PICK A DOG FROM LIST: ");
    scanf("%d", &DogPick);
    printf("***********************************************************\n");

    DogPick = DogPick - 1;
    Result = DogRace(RandomNum); // Calling DogRace Function

    if(DogPick == Result){
        printf("\n%s WINS THE RACE\nYOU WON %d\n", Dog[DogPick].Name, Wager*(Dog[DogPick].Payouts)); // Display Result
        sprintf(buffer, "\n%s WINS THE RACE\nYOU WON %d\n", Dog[DogPick].Name, Wager*(Dog[DogPick].Payouts)); // Store Result
    }else {
        printf("\n%s LOOSE THE RACE\n%s WINS THE RACE\n", Dog[DogPick].Name, Dog[Result].Name); // Display Result
        sprintf(buffer,"\n%s LOOSE THE RACE\n%s WINS THE RACE\n", Dog[DogPick].Name, Dog[Result].Name); // Store Result
    }
}

void RaceData(char** Data, int Counter){
    Data = Data; // Storing the results inside Data
    Counter = Counter + 1;
}
