using System;
using System.Collections.Generic;
using System.Linq;
using System.Media;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Tic_Tac_Toe
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.CursorVisible = false;
            TicTacToe ob = new TicTacToe();
            ob.StartGame();
        }
    }

    class TicTacToe
    {
        private bool turn;                      // To switch between 2 Players
        private int Player1Wining;
        private int Player2Wining;
        private bool TwoPlayers;                // Tell wheather game is one player or two player
        private int Draws;                      // Total no. to Draw matches
        private string[] data = new string[9];  // Saves the states of match

        private SoundPlayer sound = new SoundPlayer();     // For playing sounds

        private void GameControler()    // This controls all the game
        {
            this.Print(false, false);

            for (int i = 1; i < 10; i++)    // Loop runs for 9 times because there are 9 positions in the Game
            {
                if (TwoPlayers || turn) // Check wheather its user Turn or computer Turn
                {
                    do // This loop runs until user press any key
                    {
                        char choice = Convert.ToChar(Console.ReadKey().KeyChar.ToString()); // Capturing user pressed key

                        if (choice > '0' && choice <= '9')
                        {
                            if (data[choice - '1'] == choice.ToString())    // Check wheather the selected box is empty
                            {
                                data[choice - '1'] = turn ? "√" : "x";      // Marks selected box
                                break;
                            }
                        }
                        else if (choice == 'e' || choice == 'E')
                            Environment.Exit(0);    // Exit the Game
                        this.Print(false, false);
                    } while (true); // This loop runs until user press correct key
                }
                else   // This is Computer Turn
                {
                    int choice = this.MakeChoice(); // Get the Computer Choice
                    if (data[choice] == (choice + 1).ToString())    // Check wheather computer choice is not invalid
                        data[choice] = "x";
                    else
                    {
                        Console.WriteLine("COMPUTER ERROR {0}", choice);    // If computer makes some wrong choice then print error and exit.
                        Environment.Exit(0);
                    }
                }

                sound.SoundLocation = Environment.CurrentDirectory + (turn ? "/tic.wav" : "/toc.wav");  // Sets the Audio File path
                sound.Play();

                turn = !turn;   // Toggle the player
                if (i > 4 && this.IsWin())  // Checks either any player won the game
                {
                    if (turn) { this.Player2Wining++; this.turn = false; }
                    else/***/ { this.Player1Wining++; this.turn = true; }
                    this.Print(true, false);
                    i = 9;  // So that the game will not continue further
                }
                else
                {
                    if (i == 9) { this.Draws++; this.Print(false, true); }  // Increament the Drawa as no player is won
                    else/*****/ {/************/ this.Print(false, false); }
                }
            }
        }

        private bool IsWin()    // Checks wheather any player won
        {
            //  0 1 2
            //  3 4 5
            //  6 7 8

            if/***/ (this.data[0] == this.data[1] && this.data[1] == this.data[2]) return true;     // 1 row
            else if (this.data[3] == this.data[4] && this.data[4] == this.data[5]) return true;     // 2 row
            else if (this.data[6] == this.data[7] && this.data[7] == this.data[8]) return true;     // 3 row

            else if (this.data[0] == this.data[3] && this.data[3] == this.data[6]) return true;     // 1 coloum
            else if (this.data[1] == this.data[4] && this.data[4] == this.data[7]) return true;     // 2 coloum
            else if (this.data[2] == this.data[5] && this.data[5] == this.data[8]) return true;     // 3 coloum

            else if (this.data[0] == this.data[4] && this.data[4] == this.data[8]) return true;     // 1 diagnol
            else if (this.data[2] == this.data[4] && this.data[4] == this.data[6]) return true;     // 2 diagnol
            else return false;  // No one win
        }

        private int MakeChoice()    // In one player mode this function make choices
        {
            Thread.Sleep(1500);     // Delay

            // These statements predict is their a chance for computer win or user win
            // If there is chance for computer wining then it return that index
            // And if there is chance for user wining then it try to block it

            // indexes  //Saved in array
            //  0 1 2        // 1 2 3
            //  3 4 5        // 4 5 6
            //  6 7 8        // 7 8 9

            if/***/ (this.data[0] == this.data[1] && this.data[2] == "3") return 2;    // 1 row 0 2 ?
            else if (this.data[0] == this.data[2] && this.data[1] == "2") return 1;    // 1 row 0 ? 2
            else if (this.data[1] == this.data[2] && this.data[0] == "1") return 0;    // 1 row ? 1 2

            else if (this.data[3] == this.data[4] && this.data[5] == "6") return 5;    // 2 row 3 4 ?
            else if (this.data[3] == this.data[5] && this.data[4] == "5") return 4;    // 2 row 3 ? 5
            else if (this.data[4] == this.data[5] && this.data[3] == "4") return 3;    // 2 row ? 4 5

            else if (this.data[6] == this.data[7] && this.data[8] == "9") return 8;    // 3 row 6 7 ?
            else if (this.data[6] == this.data[8] && this.data[7] == "8") return 7;    // 3 row 6 ? 8
            else if (this.data[7] == this.data[8] && this.data[6] == "7") return 6;    // 3 row ? 7 8

            else if (this.data[0] == this.data[3] && this.data[6] == "7") return 6;    // 1 column 
            else if (this.data[0] == this.data[6] && this.data[3] == "4") return 3;    // 1 column 
            else if (this.data[3] == this.data[6] && this.data[0] == "1") return 0;    // 1 column 

            else if (this.data[1] == this.data[4] && this.data[7] == "8") return 7;    // 2 column 
            else if (this.data[1] == this.data[7] && this.data[4] == "5") return 4;    // 2 column 
            else if (this.data[4] == this.data[7] && this.data[1] == "2") return 1;    // 2 column 

            else if (this.data[2] == this.data[5] && this.data[8] == "9") return 8;    // 3 column 
            else if (this.data[2] == this.data[8] && this.data[5] == "6") return 5;    // 3 column 
            else if (this.data[5] == this.data[8] && this.data[2] == "3") return 2;    // 3 column 

            else if (this.data[0] == this.data[4] && this.data[8] == "9") return 8;    // 1 Diagonal
            else if (this.data[0] == this.data[8] && this.data[4] == "5") return 4;    // 1 Diagonal
            else if (this.data[4] == this.data[8] && this.data[0] == "1") return 0;    // 1 Diagonal

            else if (this.data[2] == this.data[4] && this.data[6] == "7") return 6;    // 2 Diagonal
            else if (this.data[2] == this.data[6] && this.data[4] == "5") return 4;    // 2 Diagonal
            else if (this.data[4] == this.data[6] && this.data[2] == "3") return 2;    // 2 Diagonal

            // Now after the fails of above statements there is no chance for wining for Computer or User
            // So now we have to make some decision that will help in Computer Victory in future


            // Now we check if any of the corner block is not marked

            // indexes  //Saved in array
            //  0 1 2        // 1 2 3
            //  3 4 5        // 4 5 6
            //  6 7 8        // 7 8 9
            else if (this.data[0] == "1") return 0;
            else if (this.data[2] == "3") return 2;
            else if (this.data[6] == "7") return 6;
            else if (this.data[8] == "9") return 8;

            // Now we check for some random block
            else if (this.data[1] == "2") return 1;
            else if (this.data[3] == "4") return 3;
            else if (this.data[4] == "5") return 4;
            else if (this.data[5] == "6") return 5;
            else/***********************/ return 7;
        }

        public void StartGame()     // This provides the menu to user
        {
            char option;

        restart:
            this.ResetAttributes(true); // Reset the Game Compeletly

            do
            {
                Console.Clear();

                Console.WriteLine(@"
       ╔═════════════════════════════════════════════════╗
       ║ ╔═════════════════════════════════════════════╗ ║
       ║ ║                                             ║ ║
       ║ ║   Welcome to Tic Tac Toe                    ║ ║
       ║ ║   Please select the Game mode               ║ ║
       ║ ║                                             ║ ║
       ║ ║   1. One Player                             ║ ║
       ║ ║   2. Two Players                            ║ ║
       ║ ║   0. Exit                                   ║ ║
       ║ ║                                             ║ ║
       ║ ║                                             ║ ║
       ║ ║                                             ║ ║
       ║ ║                                             ║ ║
       ║ ║       Visual Programming Assignment # 01    ║ ║
       ║ ║                 Group Members               ║ ║
       ║ ║                                             ║ ║
       ║ ║       Usama Iftikhar Butt    17114119-005   ║ ║
       ║ ║       Gulfam Sidhu           17114119-030   ║ ║
       ║ ║       Nabeel Ahsan           17114119-043   ║ ║
       ║ ║       Waleed                 17200856-021   ║ ║
       ║ ║                                             ║ ║
       ║ ╚═════════════════════════════════════════════╝ ║
       ╚═════════════════════════════════════════════════╝
                ");

                option = Console.ReadKey().KeyChar;

                if/***/ (option == '1') this.TwoPlayers = false;
                else if (option == '2') this.TwoPlayers = true;
                else if (option == '0') return;
                else continue;

                break;
            } while (true);

            option = (char)13;      // We set it to 13(Enter) because in first iteration User already selected the option to play Game
            do // This loop runs until user press any key
            {
                if (option == (char)13)
                {
                    this.ResetAttributes(false);     // Reset the values (not Compeletly)
                    this.GameControler();
                }
                else if (option == 'e' || option == 'E')
                    Environment.Exit(0);
                else if (option == 'r' || option == 'R')
                    goto restart;

                option = Console.ReadKey().KeyChar;
            } while (true);
        }

        private void Print(bool isWon, bool isDraw)  // This prints the game in console
        {
            Console.Clear();

            if/****/ (isWon) Console.WriteLine("\n\n                        Player {0} Won", this.turn ? "1" : "2");
            else if (isDraw) Console.WriteLine("\n\n                          Draw Match");
            else/**********/ Console.WriteLine("\n\n                        Player {0} Turn", this.turn ? "1" : "2");

            if (this.TwoPlayers) Console.WriteLine("\n           Player One: {0}   Draw: {1}   Player Two: {2}", this.Player1Wining, this.Draws, this.Player2Wining);
            else/**************/ Console.WriteLine("\n                 You: {0}    Draw: {1}    Computer: {2}", this.Player1Wining, this.Draws, this.Player2Wining);

            Console.WriteLine(@"
                         ║         ║
                     {0}   ║    {1}    ║   {2}
                         ║         ║
                  ═══════╬═════════╬═══════
                         ║         ║
                     {3}   ║    {4}    ║   {5}
                         ║         ║
                  ═══════╬═════════╬═══════
                         ║         ║
                     {6}   ║    {7}    ║   {8}
                         ║         ║


             ", data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7], data[8]);

            if (isWon)
                Console.WriteLine("Congratulation! {0} won the game.", this.turn ? "Player 1" : "Player 2");

            if (isWon || isDraw)
            {
                Console.WriteLine("Enter :  To start game again.");
                Console.WriteLine("r     :  To restart game.");
                Console.WriteLine("e     :  To exit.");
            }
            else
            {
                Console.WriteLine("Press the Coresponding button to mark");
                Console.WriteLine("Press 'E' for exit.");
            }
        }

        private void ResetAttributes(bool CompleteReset)    // This initialize and resets the attributes
        {
            if (CompleteReset)  // This runs only if we have to Reset the game
            {
                this.turn = true;
                this.Player1Wining = 0;
                this.Player2Wining = 0;
                this.Draws = 0;
            }
            data[0] = "1";
            data[1] = "2";
            data[2] = "3";
            data[3] = "4";
            data[4] = "5";
            data[5] = "6";
            data[6] = "7";
            data[7] = "8";
            data[8] = "9";
        }
    }
}
