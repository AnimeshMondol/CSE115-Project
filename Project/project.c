#include <stdio.h>
#include <string.h>

struct Player{

    char name [20];
    char country [20];
    char hand [10];
    char type [20];
    int pos;
    float six;
    char strong [30];
}p[150];

int n,i,num,flag,g,sum=0;
float max=-9999.00;

int printMenu(){

    printf("\n");
    printf("Cricket Management System\n\n");
    int choice;
    printf(" 1. Add New Player.");
    printf("\n 2. Edit Player Profile.");
    printf("\n 3. Delete Player Profile.");
    printf("\n 4. View All Player Profile.");
    printf("\n 5. Player Batting Position.");
    printf("\n 6. Longest Six hit by a player.");
    printf("\n 7. Player Strong Point.");
    printf("\n 8. Exit.");
    printf("\n\n##\tMust Exit After Use To Save The New Data To The Database\t##");
    printf("\n\n Enter choice: ");
    scanf("%d", &choice);
    printf("\n");
    return choice;
}

//file read
void read(){

    FILE *fp = fopen("db.txt","r");
    if(fp == NULL){
        fp = fopen("db.txt","w");
        fclose(fp);
        printf("File does not exist, I Just Created It.\n\n");
    }
    num = fread(p, sizeof(struct Player),150, fp);
    fclose(fp);
}

//file write
void write(){

    FILE *fp2 = fopen("db2.txt","a");
    if(fp2==NULL){
        printf("Error");
    }
    fwrite(p, sizeof(struct Player),num, fp2);

    fclose(fp2);
    remove("db.txt");
    rename("db2.txt","db.txt");
}

//Add Player
void addplayer(){

    printf("Player Data Stored On The Database :%d\n\n",num); //prints how many entered data exists on the database
    printf("How Many Player Profile Did You Want To Input :\n");
    scanf("%d",&n);
    sum=n+num;

    for(i=num; i<sum; i++){
        fflush(stdin);
        printf("Enter Player Name :");
        gets(p[i].name);
        fflush(stdin);
        printf("Enter Player Country :");
        gets(p[i].country);
        fflush(stdin);
        printf("Which Hand Batsman or Bowler(Left/right) :");
        gets(p[i].hand);
        fflush(stdin);
        printf("What Type of Player Batsman/Bowler/All-rounder(Bat/Bowl/All) :");
        gets(p[i].type);
        fflush(stdin);
        printf("Enter Playing Position(1-11) :");
        scanf("%d",&p[i].pos);
        fflush(stdin);
        printf("Longest Six Hit By The Player :");
        scanf("%f",&p[i].six);
        fflush(stdin);
        printf("Enter Player Strong Point :");
        gets(p[i].strong);
        fflush(stdin);
        printf("\n");
        num++;
    }
    printf("Data Stored Successful!!\n");
}

//Edit player info
void editplayer(){

    int m;
    fflush(stdin);
    printf("Enter the Id no of that player(0 - %d) :",num-1); //Inputs the player Id that
    scanf("%d",&m);
    if(m<num){
        fflush(stdin);
        printf("Enter the new player name :");
        gets(p[m].name);
        fflush(stdin);
        printf("Enter player new country :");
        gets(p[m].country);
        fflush(stdin);
        printf("Enter player which hand prafarable(left/right) :");
        gets(p[m].hand);
        fflush(stdin);
        printf("Which Type of player(bat/bowl/all) :");
        gets(p[m].type);
        fflush(stdin);
        printf("Enter new batting position :");
        scanf("%d",&p[m].pos);
        fflush(stdin);
        printf("Enter new longest six :");
        scanf("%f",&p[m].six);
        fflush(stdin);
        printf("Enter new strong point :");
        gets(p[m].strong);
    }
    else{
        printf("\n\nInvalid Serial \nTry Again !!\n\n");
    }
    printf("\nInsertion Successful !!\n");
}

//Delete Player Info
void deleteplayer(){

    int key;

    printf("Enter The Player Id That You Want To Delete :");
    scanf("%d",&key);

    while(key<num){
        strcpy(p[key].name,p[key+1].name);
        strcpy(p[key].country,p[key+1].country);
        strcpy(p[key].hand,p[key+1].hand);
        strcpy(p[key].type,p[key+1].type);
        p[key].pos=p[key+1].pos;
        p[key].six=p[key+1].six;
        strcpy(p[key].strong,p[key+1].strong);
        key++;
    }
    num--;
    printf("Delete Successful!!\n\n");
}

//View Player Info
void viewplayer(){

    printf("Viewing Player Profile.");

    for(i=0; i<num; i++){
        printf("\n");
        printf("Player Id :%d\n",i);
        printf("Player Name :");
        puts(p[i].name);
        printf("Player Country :");
        puts(p[i].country);
        printf("Left or Right Hand:");
        puts(p[i].hand);
        printf("Player Type :");
        puts(p[i].type);
        printf("Batting Position :%d\nHighest Six :%.2f\n",p[i].pos,p[i].six);
        printf("Player Strong Point :");
        puts(p[i].strong);
        printf("\n\n");
    }
}

//Prints the Batting position
void battingposition(){

    printf("Enter Player Name To Find His Batting Position...\n");
    char name[50];
    int f=1;
    fflush(stdin);
    printf("Enter Player Name :");
    gets(name);
    fflush(stdin);

    for(g=0;g<num;g++){
        if(strcmp(name,p[g].name)==0){
            printf("\n");
            printf("Player Id :%d\n",g);
            printf("Player Name :");
            puts(p[g].name);
            printf("Batting Position : %d",p[g].pos);
            printf("\n\n");
            f=0;
        }
    }
    if(f==1)
        printf("The Name You Have Entered Doesn't Exist In The DataBase :(");
}

//Prints the longest six hit by a player in the existing database
void longsix(){

    printf("# It Will Show The Hight Six Hit By A Player On The Existing DataBase #\n");

    for(g=0;g<num;g++){
        if(p[g].six > max)
            max=p[g].six;
    }
    printf("\n");
    printf("Highest Six : %.2f\n",max);

    for(g=0;g<num;g++){
        if(max==p[g].six){
            printf("Player Name :");
            puts(p[g].name);
        }
    }
}

//Prints the desired player strong point
void strongpoint(){

    printf("Enter Player Name To Find His Strong Point...\n");
    char name[50];
    int f=1;
    fflush(stdin);
    printf("Enter Player Name :");
    gets(name);
    fflush(stdin);

    for(g=0;g<num;g++){
        if(strcmp(name,p[g].name)==0){
            printf("\n");
            printf("Player Id :%d\n",g);
            printf("Player Name :");
            puts(p[g].name);
            printf("Player Strong Point :");
            puts(p[g].strong);
            printf("\n\n");
            f=0;
        }
    }
    if(f==1)
        printf("The Name You Have Entered Doesn't Exist In The DataBase :(");
}

int main(){

    read();
    int a;
    do {
        a = printMenu();
        switch(a){
            case 1: addplayer();
                    break;

            case 2: editplayer();
                    break;

            case 3: deleteplayer();
                    break;

            case 4: viewplayer();
                    break;

            case 5: battingposition();
                    break;

            case 6: longsix();
                    break;

            case 7: strongpoint();
                    break;

            case 8: write();
                    printf("Thank you. Good bye :) ");
                    break;

            default: printf("Wrong choice!! Try again");
                     break;
        }
    } while (a!=8);
    return 0;
}
