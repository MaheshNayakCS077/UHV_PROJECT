#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

string jumbledword(string str)
{
    int word_size=str.size(), word_size_1=0, word_size_2=0;
    char letter;

    for(int i=0;i<3;i++)
    {
         while(word_size_1==word_size_2)
        {
            word_size_1= rand() % word_size;
            word_size_2= rand() % word_size;
        }

        letter=str[word_size_1];
        str[word_size_1]=str[word_size_2];
        str[word_size_2]=letter;
    }
    return str; 
}

void declare_result(int score1, int score2, string player1, string player2)
{
    cout<<"\n\n";
    cout<<player1<<" your score is "<<score1<<endl;
    cout<<player2<<" your score is "<<score2<<endl;

    if(score1>score2)
    {
        cout<<player1<<" you won the game \n";
    }
    else if(score1<score2)
    {
        cout<<player2<<" you won the game \n";
    }
    else
    {
        cout<<"The match is draw\n";
    }
}
int main()
{
    string str[50]={"BANANA", "MANGO", "FRUITS", "CARROT", "KEERTHAN", "MAN", "VAN", "CAN", "HUT", "INDIA", "DUBAI", "MNGALORE", "KARNATAK", "KERALA", "NATION", "WAR", "PRIME", "MALE", "FEMALE", "BOY", "MISSION", "BREAKFAST", "LUNCH", "DINNER", "COLLEGE", "FATHER", "COMING", "CALL", "WHATSAPP", "MOBILE", "TELEVISION", "HEALTH", "CORONA", "PEOPLE", "BUS", "CRIKET", "SPORTS", "TRAIN", "BENGALORE", "CALCULATOR", "GOOD", "MORNING", "EVENING", "NIGHT", "AFTERNOON", "SUN", "MOON", "LAPTOP", "BILL", "ELECTRICITY"};

    cout<<" WELCOME TO JUMBLED WORD GAME \n";

    string player1_name, player2_name;

    cout<<"Enter the name of player 1 \n";
    getline(cin, player1_name);

    cout<<"Enter the name of player 2 \n";
    getline(cin, player2_name);

    int word_count=1, word_random_number, player1_score=0, player2_score=0;
    string original_word, jumbled_word, ans_player1, ans_player2;
    
    while(word_count<=10)
    {
        word_random_number=rand()%50;

        original_word=str[word_random_number];

        jumbled_word=jumbledword(original_word);

        cout<<"jumbled_word is "<<jumbled_word<<endl;


        if(word_count%2==0)
        {
            
            cout<<player1_name<<" its your turn\n Guess the word\n";
            cin>>ans_player1;

            if(ans_player1==original_word)
            {
                cout<<"Hey you hit! Your guess was correct\n";
                player1_score+=10;
            }
            else
            {
                cout<<player2_name<<" its your turn\n Guess the word\n";
                cin>>ans_player2;

                if(ans_player2==original_word)
                {
                    cout<<"Hey you hit! Your guess was correct\n\n";
                    player2_score+=10;
                }
            }
        }
        else
        {
             cout<<player2_name<<" its your turn\n Guess the word\n";
             cin>>ans_player2;

            if(ans_player2==original_word)
            {
                cout<<"Hey you hit! Your guess was correct\n";
                player2_score+=10;
            }
            else
            {
                cout<<player1_name<<" its your turn\n Guess the word\n";
                cin>>ans_player1;

                if(ans_player1==original_word)
                {
                    cout<<"Hey you hit! Your guess was correct\n\n";
                    player1_score+=10;
                }
            }
        }
        word_count++;
    }

    declare_result(player1_score, player2_score, player1_name, player2_name);

    cout<<"\n**********THANK YOU**********\n";

    return 0;
}