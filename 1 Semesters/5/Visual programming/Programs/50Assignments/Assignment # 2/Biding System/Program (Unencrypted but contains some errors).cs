//
//    -----PLEASE READ-----PLEASE READ-----PLEASE READ-----PLEASE READ-----
//    -----PLEASE READ-----PLEASE READ-----PLEASE READ-----PLEASE READ-----
//    -----PLEASE READ-----PLEASE READ-----PLEASE READ-----PLEASE READ-----
//    -----PLEASE READ-----PLEASE READ-----PLEASE READ-----PLEASE READ-----
//    -----PLEASE READ-----PLEASE READ-----PLEASE READ-----PLEASE READ-----
//    -----PLEASE READ-----PLEASE READ-----PLEASE READ-----PLEASE READ-----
//
//    Please Go to Project -> Add Refrance -> COM
//    Then search for library "Microsoft Excel"
//    Then add it to Project
//
//    Microsoft Excel should be installed on system. Otherwise this project is useless.
//
//    Default Password for Admin is: admin
//
//    Assignment # 02
//               Biding System
//
//    Group Members
//               Usama Iftikhar Butt   17114119-005
//               Gulfam Sidhu          17114119-030
//               Nabeel Ahsan          17114119-043
//               Waleed                17200856-021 
//



using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Excel = Microsoft.Office.Interop.Excel;   // For using Microsoft Excel
using System.IO;    // For File Handling

namespace Biding_System
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Clear();
            Console.Title = "Biding System";
            Console.SetWindowSize(100, 40);
            Console.OutputEncoding = System.Text.Encoding.UTF8;

            Console.WriteLine("Please wait a moment...");

            Console.CursorVisible = false;
            if (Database.CheckFile())
            {
                bool NotExit = true;
                do
                {
                    Console.Clear();
                    Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
                    Console.WriteLine("                                 Welcome to Biding Community");
                    Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
                    Console.WriteLine("     1. Admin");
                    Console.WriteLine("     2. User");
                    Console.WriteLine("     0. Exit");
                    Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
                    Console.WriteLine("  Please select any option.");
                    Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════");

                    do
                    {
                        char option = Convert.ToChar(Console.ReadKey(true).KeyChar);

                        if/***/ (option == '1') { new Admin().Login();/**/ break; }
                        else if (option == '2') { new User().menu();/****/ break; }
                        else if (option == '0') { NotExit = false;/******/ break; }
                    } while (true);
                } while (NotExit);
            }

            Console.Clear();

            Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
            Console.WriteLine("                                        Project Details");
            Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════");
            Console.WriteLine(@"
     ╔══════════════════════════════════════════════════════════════════════════════════════╗
     ║                                                                                      ║
     ║   ╔══════════════════════════════════════════════════════════════════════════════╗   ║
     ║   ║                                                                              ║   ║
     ║   ║                                                                              ║   ║
     ║   ║             Assignment # 02                                                  ║   ║
     ║   ║                    Biding Project in C#                                      ║   ║
     ║   ║                                                                              ║   ║
     ║   ║             Group Members:                                                   ║   ║
     ║   ║                    Usama Iftikhar Butt   17114119-005                        ║   ║
     ║   ║                    Gulfam Sidhu          17114119-030                        ║   ║
     ║   ║                    Nabeel Ahsan          17114119-043                        ║   ║
     ║   ║                    Waleed                17200856-021                        ║   ║
     ║   ║                                                                              ║   ║
     ║   ║                                                                              ║   ║
     ║   ║                                                                              ║   ║
     ║   ║                   88                                                         ║   ║
     ║   ║                   88                                                         ║   ║
     ║   ║                   88                                                         ║   ║
     ║   ║                   88,dPPYba,  8b       d8  ,adPPYba,                         ║   ║
     ║   ║                   88P'    ""8a `8b     d8' a8P_____88                         ║   ║
     ║   ║                   88       d8  `8b   d8'  8PP""""""""                            ║   ║
     ║   ║                   88b,   ,a8""   `8b,d8'   ""8b,   ,aa                         ║   ║
     ║   ║                   8Y""Ybbd8""'      Y88'     `""Ybbd8""'                         ║   ║
     ║   ║                                   d8'                                        ║   ║
     ║   ║                                  d8'                                         ║   ║
     ║   ║                                                                              ║   ║
     ║   ║                                                                              ║   ║
     ║   ╚══════════════════════════════════════════════════════════════════════════════╝   ║
     ║                                                                                      ║
     ╚══════════════════════════════════════════════════════════════════════════════════════╝
");

            Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════");
            Console.WriteLine("  Press Enter to continue...");
            Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════");

            while (Console.ReadKey(true).Key != ConsoleKey.Enter) { }
        }
    }

    // This manages all the Admin functionality
    #region Admin Class

    class Admin : Person
    {
        public string Password;

        public Admin()  // Constructor
        {

        }

        public void Login() // Login the Admin
        {
        LoginAgain:

            Console.Clear();
            Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
            Console.WriteLine("                                 Please Login to Continue");
            Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
            Console.CursorVisible = true;
            Console.Write("     Please enter Admin Password  : ");
            string pass = this.GetPassword();

            Console.CursorVisible = false;

            Console.Clear();
            Console.WriteLine("Please wait a moment...");

            if (!Database.IsAdminPassword(pass))  // Check wheather password is correct or not
            {
                Console.CursorVisible = false;
                Console.Clear();
                Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
                Console.WriteLine("                                         Incorrect");
                Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
                Console.WriteLine("Sorry! This is not correct password.");
                Console.WriteLine("Do you want to enter Password again? [Y/N]");
                Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
                Console.WriteLine("  Press Y or N.");
                Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");

                do
                {
                    char option = Convert.ToChar(Console.ReadKey().KeyChar);

                    if/***/ (option == 'y' || option == 'Y') goto LoginAgain;
                    else if (option == 'n' || option == 'N') return;
                    else/**********************************/ Console.Write("\b \b");
                } while (true);
            }

            Console.Clear();
            Console.WriteLine("Please wait a moment...");

            Database.GetAdminProfile(this); // Initialize all variables of Admin

            this.Menu();
        }

        private void Menu() // Create menu for Admin and controls all the Admin functionality
        {
            do
            {
                Console.Clear();
                Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
                Console.WriteLine("                                           Admin Panel");
                Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
                Console.WriteLine("     1. Create new Item");
                Console.WriteLine("     2. Show all Items");
                Console.WriteLine("     3. Show an Item");
                Console.WriteLine("     4. Sell Item");
                Console.WriteLine("     5. Profile");
                Console.WriteLine("     6. Show all Users");
                Console.WriteLine("     7. Show User Profile");
                Console.WriteLine("     0. Back to Main Menu");
                Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
                Console.WriteLine("  Please select any option.");
                Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");

                do
                {
                    char option = Convert.ToChar(Console.ReadKey().KeyChar);

                    if/***/ (option == '1') { this.CreateNewItem();/**/ break; }
                    else if (option == '2') { this.ShowAllItems();/***/ break; }
                    else if (option == '3') { this.ShowItem();/*******/ break; }
                    else if (option == '4') { this.Sell();/***********/ break; }
                    else if (option == '5') { this.Profile();/********/ break; }
                    else if (option == '6') { this.ShowUsers();/******/ break; }
                    else if (option == '7') { this.ShowUser();/*******/ break; }
                    else if (option == '0') { return;/***********************/ }
                    else/*****************/ { Console.Write("\b \b");/*******/ }
                } while (true);
            } while (true);
        }

        private void CreateNewItem()    // Creates new Item
        {
            Console.Clear();
            Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
            Console.WriteLine("                                         Please insert all Fields");
            Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
            Console.CursorVisible = true;

            Item NewItem = new Item();

            Console.Write("     Enter Item Name    : ");
            NewItem.Name = Console.ReadLine();

            Console.Write("     Enter Price        : ");
            NewItem.Price = float.Parse(Console.ReadLine());

            Console.Write("     Enter Description  : ");
            NewItem.Description = Console.ReadLine();

            Console.CursorVisible = false;
            Console.WriteLine("\n\nPlease wait a moment...");

            NewItem.Id = Database.NextItemId();
            NewItem.SelledTo = "NaN";
            Database.InsertItem(NewItem);
        }

        private void ShowAllItems() // Prints all Items
        {
            Console.Clear();
            Console.WriteLine("Please wait a moment...");
            List<Item> ItemList = Database.AllItems(false);

            Console.Clear();
            if (ItemList.Count == 0)
            {
                Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
                Console.WriteLine("                                           No Items");
                Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
                Console.WriteLine("     No Items found.");
            }
            else
            {
                Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
                Console.WriteLine("                                       These are all Items");
                Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
                Console.WriteLine("     ╔════════════════╦════════════════╦════════════════╦════════════════╦════════════════╗");
                Console.WriteLine("     ║ Id             ║ Name           ║ Price          ║ Selled To      ║ Last Bide      ║");
                Console.WriteLine("     ╠════════════════╬════════════════╬════════════════╬════════════════╬════════════════╣");
                foreach (Item item in ItemList)
                    Console.WriteLine("     " + "║ " + item.Id.PadRight(15) + "║ " + item.Name.PadRight(15) + "║ " + item.Price.ToString().PadRight(15) + "║ " + item.SelledTo.PadRight(15) + "║ " + ((item.LastBide == 0.0f) ? "NaN" : item.LastBide.ToString()).PadRight(15) + "║ ");

                Console.WriteLine("     ╚════════════════╩════════════════╩════════════════╩════════════════╩════════════════╝");
            }

            Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
            Console.WriteLine("  Press Enter to continue...");
            Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
            while (Console.ReadKey(true).Key != ConsoleKey.Enter) { }
        }

        private void ShowItem() // Print only one Item
        {
            Console.Clear();
            Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
            Console.WriteLine("                                         Enter Item Id");
            Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
            Console.CursorVisible = true;
            Console.Write("     Enter Item Id  : ");
            string itemid = Console.ReadLine();

            Console.CursorVisible = false;
            Console.Clear();
            Console.WriteLine("Please wait a moment...");

            Item item = Database.GetItem(itemid, false);


            if (item == null)
            {
                Console.Clear();
                Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
                Console.WriteLine("                                  Sorry! We cannot find that item");
                Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
                Console.WriteLine("     Id          : NaN");
                Console.WriteLine("     Name        : NaN");
                Console.WriteLine("     Description : NaN");
                Console.WriteLine("     Price       : NaN");
                Console.WriteLine("     Selled To   : NaN");
                Console.WriteLine("     Last Bide   : NaN");
            }
            else
            {
                List<Bide> BideList = Database.GetAllBidesofItem(itemid);

                Console.Clear();
                Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
                Console.WriteLine("                                        Details of " + item.Id);
                Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
                Console.WriteLine("     Id          : " + item.Id);
                Console.WriteLine("     Name        : " + item.Name);
                Console.WriteLine("     Description : " + item.Description);
                Console.WriteLine("     Price       : " + item.Price);
                Console.WriteLine("     Selled To   : " + item.SelledTo);
                Console.WriteLine("     Last Bide   : " + ((item.LastBide == 0.0f) ? "NaN" : item.LastBide.ToString()));

                if (BideList.Any())
                {
                    Console.WriteLine("\n\n     Following are the Bides on this Item.");
                    Console.WriteLine("     ╔════════════════╦════════════════╦════════════════╗");
                    Console.WriteLine("     ║ Id             ║ User Id        ║ Price          ║");
                    Console.WriteLine("     ╠════════════════╬════════════════╬════════════════╣");
                    foreach (Bide bide in BideList)
                        Console.WriteLine("     " + "║ " + bide.Id.PadRight(15) + "║ " + bide.UserId.PadRight(15) + "║ " + bide.Price.ToString().PadRight(15) + "║ ");
                    Console.WriteLine("     ╚════════════════╩════════════════╩════════════════╝");
                }
                else
                    Console.WriteLine("\n\n     No one Bide on this Item.");
            }

            Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
            Console.WriteLine("  Press Enter to continue...");
            Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
            while (Console.ReadKey(true).Key != ConsoleKey.Enter) { }
        }

        private void Sell()
        {
            Console.Clear();
            Console.CursorVisible = true;
            Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
            Console.WriteLine("                                            Enter Item Id");
            Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
            Console.Write("     Enter Item Id  : ");
            string itemid = Console.ReadLine();

            Console.CursorVisible = false;
            Console.Clear();
            Console.WriteLine("Please wait a moment...");

            Item item = Database.GetItem(itemid, true);
            Console.Clear();

            if (item == null)
            {
                Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
                Console.WriteLine("                           Sorry! Item not Exists or it is already Selled");
                Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
                Console.WriteLine("     No records.");
            }
            else
            {
                string userid = Database.GetUserIdofLastBide(item.Id);

                if (userid == null)
                {
                    Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
                    Console.WriteLine("                                            No Bides");
                    Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
                    Console.WriteLine("     No user have Bide on this Item. So you can't sell it.");
                }
                else
                {
                    Database.SellItem(item.Id, userid);
                    Console.Clear();
                    Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
                    Console.WriteLine("                                              Selled");
                    Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
                    Console.WriteLine("     Item selled successfully to " + userid);
                }
            }

            Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
            Console.WriteLine("  Press Enter to continue...");
            Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
            while (Console.ReadKey(true).Key != ConsoleKey.Enter) { }
        }

        private void Profile()  // Prints Admin Profile. Also Edit Profile
        {
        PrintAgain:

            Console.Clear();

            Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
            Console.WriteLine("                                        Admin Profile");
            Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
            Console.WriteLine("     Your Id          : " + this.Id);
            Console.WriteLine("     Your Name        : " + this.Name);
            Console.WriteLine("     Your Password    : " + this.Password);
            Console.WriteLine("     Your Contact No. : " + this.ContactNo);
            Console.WriteLine("     Your Address     : " + this.Address);

            Console.WriteLine("\n\n     1. Edit Profile");
            Console.WriteLine("     0. Back");
            Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
            Console.WriteLine("  Please select any option.");
            Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
            do
            {
                char option = Convert.ToChar(Console.ReadKey().KeyChar);

                if (option == '1')
                {
                    Console.Clear();
                    Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
                    Console.WriteLine("                                       Enter all fields");
                    Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
                    Console.CursorVisible = true;

                    Console.Write("     Enter your Name        : ");
                    this.Name = Console.ReadLine();

                    Console.Write("     Enter your Password    : ");
                    this.Password = this.GetPassword();

                    Console.Write("     Enter your Contact No. : ");
                    this.ContactNo = Console.ReadLine();

                    Console.Write("     Enter your Address     : ");
                    this.Address = Console.ReadLine();

                    Console.CursorVisible = false;
                    Console.Clear();
                    Console.WriteLine("Please wait a moment...");

                    Database.UpdateAdmin(this);

                    goto PrintAgain;
                }
                else if (option == '0')
                    return;
                else
                    Console.Write("\b \b");
            } while (true);
        }

        private void ShowUsers()
        {
            Console.Clear();
            Console.WriteLine("Please wait a moment...");

            List<User> UserList = Database.GetAllUsers();

            Console.Clear();
            if (UserList.Count == 0)
            {
                Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
                Console.WriteLine("                                           No Users");
                Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
                Console.WriteLine("     There are no User Accounts.");
            }
            else
            {
                Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
                Console.WriteLine("                                       These are all Users");
                Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
                Console.WriteLine("     ╔════════════════╦════════════════╦════════════════╦════════════════╗");
                Console.WriteLine("     ║ Id             ║ Name           ║ Contact No     ║ Address        ║");
                Console.WriteLine("     ╠════════════════╬════════════════╬════════════════╬════════════════╣");

                foreach (User user in UserList)
                    Console.WriteLine("     " + "║ " + user.Id.PadRight(15) + "║ " + user.Name.PadRight(15) + "║ " + user.ContactNo.PadRight(15) + "║ " + user.Address.PadRight(15) + "║");
                Console.WriteLine("     ╚════════════════╩════════════════╩════════════════╩════════════════╝");
            }

            Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
            Console.WriteLine("  Press Enter to continue...");
            Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
            while (Console.ReadKey(true).Key != ConsoleKey.Enter) { }
        }

        private void ShowUser()
        {
            Console.Clear();
            Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
            Console.WriteLine("                                         Enter User Id");
            Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
            Console.Write("     Please enter User Id : ");
            Console.CursorVisible = true;
            string userid = Console.ReadLine();
            Console.CursorVisible = false;

            Console.Clear();
            Console.WriteLine("Please wait a moment...");

            User user = Database.GetUser(userid);
            List<Bide> BideList = Database.GetAllBidesofUser(userid);

            if (user == null)
            {
                Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
                Console.WriteLine("                                Sorry! We could not find any thing");
                Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
                Console.WriteLine("     Id      : NaN");
                Console.WriteLine("     Name    : NaN");
                Console.WriteLine("     Contact : NaN");
                Console.WriteLine("     Address : NaN");
            }
            else
            {
                Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
                Console.WriteLine("                                        Details of " + user.Id);
                Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
                Console.WriteLine("     Id      : " + user.Id);
                Console.WriteLine("     Name    : " + user.Name);
                Console.WriteLine("     Contact : " + user.ContactNo);
                Console.WriteLine("     Address : " + user.Address);

                if (BideList.Any())
                {
                    Console.WriteLine("\n\n     All Bides of this " + user.Id + ".");
                    Console.WriteLine("     ╔════════════════╦════════════════╦════════════════╗");
                    Console.WriteLine("     ║ Id             ║ Item Id        ║ Price          ║");
                    Console.WriteLine("     ╠════════════════╬════════════════╬════════════════╣");
                    foreach (Bide bide in BideList)
                        Console.WriteLine("     " + "║ " + bide.Id.PadRight(15) + "║ " + bide.ItemId.PadRight(15) + "║ " + bide.Price.ToString().PadRight(15) + "║ ");
                    Console.WriteLine("     ╚════════════════╩════════════════╩════════════════╝");
                }
                else
                    Console.WriteLine("\n\n     This user has not Bide any Item.");
            }

            Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
            Console.WriteLine("  Press Enter to continue...");
            Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
            while (Console.ReadKey(true).Key != ConsoleKey.Enter) { }
        }

        private string GetPassword()  // Get password from User in bullets and returns
        {
            string pass = "";
            ConsoleKeyInfo info = Console.ReadKey(true);
            do
            {
                if (info.Key != ConsoleKey.Backspace && ((info.KeyChar > 64 && info.KeyChar < 91) || (info.KeyChar > 96 && info.KeyChar < 123) || (info.KeyChar > 47 && info.KeyChar < 58)))
                {
                    Console.Write("•");
                    pass += info.KeyChar;
                }
                else if (info.Key == ConsoleKey.Backspace && !string.IsNullOrEmpty(pass))
                {
                    pass = pass.Substring(0, pass.Length - 1);      // Remove last Character
                    Console.Write("\b \b"); // Move cursor one character to left
                }

                info = Console.ReadKey(true);
            } while (info.Key != ConsoleKey.Enter);

            return pass;
        }
    }

    #endregion

    // This manages all the User functionality
    #region User Class

    class User : Person
    {
        public User()   // Constructor
        {

        }

        public void menu()  // This prints the menu for user and controlls all the user functionality
        {
            do
            {
                Console.Clear();

                Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
                Console.WriteLine("                                         User Panel");
                Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
                Console.WriteLine("     1. Create new User");
                Console.WriteLine("     2. Show all Items");
                Console.WriteLine("     3. Show an Item");
                Console.WriteLine("     4. Bide an item");
                Console.WriteLine("     0. Back to Main Menu");
                Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
                Console.WriteLine("  Please select any option.");
                Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");

                char option = Convert.ToChar(Console.ReadKey().KeyChar);

                if/***/ (option == '1') this.CreateNewUser();
                else if (option == '2') this.ShowItems();
                else if (option == '3') this.ShowItem();
                else if (option == '4') this.Bide();
                else if (option == '0') return;

            } while (true);
        }

        private void CreateNewUser()    // Create new User
        {
            Console.Clear();
            Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
            Console.WriteLine("                            Please enter all the fields to Sign Up");
            Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
            Console.CursorVisible = true;

            Console.Write("     Enter your Name            : ");
            this.Name = Console.ReadLine();

            Console.Write("     Enter your Contact Number  : ");
            this.ContactNo = Console.ReadLine();

            Console.Write("     Enter your Address         : ");
            this.Address = Console.ReadLine();

            Console.CursorVisible = false;
            Console.Clear();
            Console.WriteLine("Please wait a moment...");

            string userid = Database.GetNextUserId();
            Database.InsertUser(userid, this.Name, this.ContactNo, this.Address);

            Console.Clear();
            Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
            Console.WriteLine("                                   Please remember your Id");
            Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
            Console.WriteLine("     Your Id is " + userid);

            Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
            Console.WriteLine("  Press Enter to continue...");
            Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
            while (Console.ReadKey(true).Key != ConsoleKey.Enter) { }
        }

        private void ShowItems()    // Print all Items
        {
            Console.Clear();
            Console.WriteLine("Please wait a moment...");

            List<Item> ItemList = Database.AllItems(true);

            Console.Clear();
            if (ItemList.Count == 0)
            {
                Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
                Console.WriteLine("                                           No Items");
                Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
                Console.WriteLine("     No Items found.");
            }
            else
            {
                Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
                Console.WriteLine("                                       These are all Items");
                Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
                Console.WriteLine("     ╔════════════════╦════════════════╦════════════════╦════════════════╗");
                Console.WriteLine("     ║ Id             ║ Name           ║ Price          ║ Last Bide      ║");
                Console.WriteLine("     ╠════════════════╬════════════════╬════════════════╬════════════════╣");

                foreach (Item item in ItemList)
                    Console.WriteLine("     " + "║ " + item.Id.PadRight(15) + "║ " + item.Name.PadRight(15) + "║ " + item.Price.ToString().PadRight(15) + "║ " + ((item.LastBide == 0.0f) ? "NaN" : item.LastBide.ToString()).PadRight(15) + "║ ");
                Console.WriteLine("     ╚════════════════╩════════════════╩════════════════╩════════════════╝");
            }


            Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
            Console.WriteLine("  Press Enter to continue...");
            Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
            while (Console.ReadKey(true).Key != ConsoleKey.Enter) { }
        }

        private void ShowItem() // Print an Item
        {
            Console.Clear();
            Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
            Console.WriteLine("                                         Enter Item Id");
            Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
            Console.CursorVisible = true;
            Console.Write("     Enter Item Id  : ");
            string itemid = Console.ReadLine();
            Console.CursorVisible = false;

            Console.Clear();
            Console.WriteLine("Please wait a moment...");

            Item item = Database.GetItem(itemid, true);

            Console.Clear();
            if (item == null)
            {
                Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
                Console.WriteLine("                                  Sorry! We cannot find that item");
                Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
                Console.WriteLine("     Id          : NaN");
                Console.WriteLine("     Name        : NaN");
                Console.WriteLine("     Description : NaN");
                Console.WriteLine("     Price       : NaN");
                Console.WriteLine("     Last Bide   : NaN");
            }
            else
            {
                Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
                Console.WriteLine("                                        Details of " + item.Id);
                Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
                Console.WriteLine("     Id          : " + item.Id);
                Console.WriteLine("     Name        : " + item.Name);
                Console.WriteLine("     Description : " + item.Description);
                Console.WriteLine("     Price       : " + item.Price);
                Console.WriteLine("     Last Bide   : " + ((item.LastBide == 0.0f) ? "NaN" : item.LastBide.ToString()));
            }
            Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
            Console.WriteLine("  Press Enter to continue...");
            Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
            while (Console.ReadKey(true).Key != ConsoleKey.Enter) { }
        }

        private void Bide() // Create Bide
        {
            Console.Clear();
            Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
            Console.WriteLine("                                           Enter Item Id");
            Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
            Console.CursorVisible = true;
            Console.Write("     Enter Item Id  : ");
            string itemid = Console.ReadLine();

            Console.CursorVisible = false;
            Console.Clear();
            Console.WriteLine("Please wait a moment...");
            Item item = Database.GetItem(itemid, true);

            Console.Clear();

            if (item == null)
            {
                Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
                Console.WriteLine("                                             Sorry!");
                Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
                Console.WriteLine("     Sorry! We cannot find that item");
            }
            else
            {
                Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
                Console.WriteLine("                                  These are Details of Item");
                Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
                Console.WriteLine("     Id          : " + item.Id);
                Console.WriteLine("     Name        : " + item.Name);
                Console.WriteLine("     Description : " + item.Description);
                Console.WriteLine("     Price       : " + item.Price);
                Console.WriteLine("     Selled To   : " + item.SelledTo);
                Console.WriteLine("     Last Bide   : " + ((item.LastBide == 0.0f) ? "NaN" : item.LastBide.ToString()));

                Console.CursorVisible = true;
                Console.Write("\n\n     Enter your Id : ");
                string userid = Console.ReadLine();
                Console.CursorVisible = false;
                Console.Write("     Please wait a moment...");
                Console.CursorLeft = 0;

                if (Database.IsUser(userid))
                {
                    Console.CursorVisible = true;
                    Console.Write("     Enter an Price greater then Last Bide  : ");
                    Console.CursorVisible = false;
                    float price;
                    try
                    {
                        Console.CursorVisible = true;
                        price = float.Parse(Console.ReadLine());
                        Console.CursorVisible = false;

                        if (item.LastBide != 0.0f && price <= item.LastBide)
                            Console.WriteLine("     Invalid! Price should be greater then Last Bide");
                        else if (price == 0.0f)
                            Console.WriteLine("     Invalid! Price should be greater then 0.0");
                        else
                        {
                            Console.Write("     Please wait a moment...");
                            Console.CursorLeft = 0;
                            Bide bide = new Bide();
                            bide.Id = Database.GetNextBideId();
                            bide.UserId = userid;
                            bide.ItemId = item.Id;
                            bide.Price = price;
                            Database.InsertBide(bide);
                            Console.WriteLine("     Bide Successfully recorded.");
                        }
                    }
                    catch
                    {
                        Console.WriteLine("     Invalid input");
                    }
                }
                else
                    Console.WriteLine("     That user doesn't exists.");
            }

            Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
            Console.WriteLine("  Press Enter to continue...");
            Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
            while (Console.ReadKey(true).Key != ConsoleKey.Enter) { }
        }
    }

    #endregion

    // This class manages all the file handling
    #region Database Class

    static class Database
    {
        private static Excel.Application ExcelFile;   // This is the acctual file where records are saved
        private static object misValue = System.Reflection.Missing.Value;
        private static string FilePath = Environment.CurrentDirectory + "/Database.xls";

        #region Admin Functions

        public static void GetAdminProfile(Admin admin) // Set the values for Admin
        {
            ExcelFile = new Excel.Application();
            Excel.Workbook WorkBook = ExcelFile.Workbooks.Open(FilePath);
            Excel.Worksheet AdminSheet = (Excel.Worksheet)WorkBook.Worksheets["Admin"];

            admin.Id = AdminSheet.Cells[2, 1].Text;
            admin.Name = AdminSheet.Cells[2, 2].Text;
            admin.Password = AdminSheet.Cells[2, 3].Text;
            admin.ContactNo = AdminSheet.Cells[2, 4].Text;
            admin.Address = AdminSheet.Cells[2, 5].Text;

            WorkBook.Close();
            ExcelFile.Quit();

            System.Runtime.InteropServices.Marshal.ReleaseComObject(ExcelFile);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(WorkBook);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(AdminSheet);
        }

        public static void UpdateAdmin(Admin admin) // Update Admin data
        {
            ExcelFile = new Excel.Application();
            Excel.Workbook WorkBook = ExcelFile.Workbooks.Open(FilePath);
            Excel.Worksheet AdminSheet = (Excel.Worksheet)WorkBook.Worksheets["Admin"];

            AdminSheet.Cells[2, 2].value = admin.Name;
            AdminSheet.Cells[2, 3].value = admin.Password;
            AdminSheet.Cells[2, 4].value = admin.ContactNo;
            AdminSheet.Cells[2, 5].value = admin.Address;

            WorkBook.Save();
            WorkBook.Close();
            ExcelFile.Quit();

            System.Runtime.InteropServices.Marshal.ReleaseComObject(ExcelFile);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(WorkBook);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(AdminSheet);
        }

        public static bool IsAdminPassword(string pass) // Checks wheather entered Admin password is correct or not
        {
            ExcelFile = new Excel.Application();
            Excel.Workbook WorkBook = ExcelFile.Workbooks.Open(FilePath);
            Excel.Worksheet AdminSheet = (Excel.Worksheet)WorkBook.Worksheets["Admin"];

            string OrignalPass = AdminSheet.Cells[2, 3].value;

            WorkBook.Close();
            ExcelFile.Quit();

            System.Runtime.InteropServices.Marshal.ReleaseComObject(ExcelFile);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(WorkBook);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(AdminSheet);

            return pass == OrignalPass;
        }

        #endregion

        #region User Functions

        public static void InsertUser(string Id, string Name, string Contact, string Address)   // This Insert the User Record
        {
            ExcelFile = new Excel.Application();

            Excel.Workbook WorkBook = ExcelFile.Workbooks.Open(FilePath);
            Excel.Worksheet UserSheet = (Excel.Worksheet)WorkBook.Worksheets["User"];

            for (int row = 2; row <= UserSheet.Rows.Count; row++)
            {
                if (UserSheet.Cells[row, 1].value == null)
                {
                    UserSheet.Cells[row, 1].value = Id;   // Id
                    UserSheet.Cells[row, 2].value = Name;   // Name
                    UserSheet.Cells[row, 3].value = Contact;   // Contact
                    UserSheet.Cells[row, 4].value = Address;   // Address
                    break;
                }
            }

            WorkBook.Save();
            WorkBook.Close();
            ExcelFile.Quit();

            System.Runtime.InteropServices.Marshal.ReleaseComObject(ExcelFile);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(WorkBook);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(UserSheet);
        }

        public static List<User> GetAllUsers()  // Returns all the Users data
        {
            ExcelFile = new Excel.Application();

            Excel.Workbook WorkBook = ExcelFile.Workbooks.Open(FilePath);
            Excel.Worksheet UserSheet = (Excel.Worksheet)WorkBook.Worksheets["User"];

            List<User> UserList = new List<User>();

            for (int row = 2; row <= UserSheet.Rows.Count; row++)
            {
                if (UserSheet.Cells[row, 1].value == null)
                    break;
                else
                {
                    User user = new User();

                    user.Id = UserSheet.Cells[row, 1].Text;   // Id
                    user.Name = UserSheet.Cells[row, 2].Text;   // Name
                    user.ContactNo = UserSheet.Cells[row, 3].Text;   // Contact
                    user.Address = UserSheet.Cells[row, 4].Text;   // Address

                    UserList.Add(user);
                }
            }

            WorkBook.Close();
            ExcelFile.Quit();

            System.Runtime.InteropServices.Marshal.ReleaseComObject(ExcelFile);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(WorkBook);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(UserSheet);

            return UserList;
        }

        public static User GetUser(string userid)   // Return only one User
        {
            ExcelFile = new Excel.Application();

            Excel.Workbook WorkBook = ExcelFile.Workbooks.Open(FilePath);
            Excel.Worksheet UserSheet = (Excel.Worksheet)WorkBook.Worksheets["User"];

            User user = null;

            for (int row = 2; row <= UserSheet.Rows.Count; row++)
            {
                if (UserSheet.Cells[row, 1].value == null)
                    break;
                else if (UserSheet.Cells[row, 1].Text == userid)
                {
                    user = new User();
                    user.Id = UserSheet.Cells[row, 1].Text;   // Id
                    user.Name = UserSheet.Cells[row, 2].Text;   // Name
                    user.ContactNo = UserSheet.Cells[row, 3].Text;   // Contact
                    user.Address = UserSheet.Cells[row, 4].Text;   // Address
                }
            }

            WorkBook.Close();
            ExcelFile.Quit();

            System.Runtime.InteropServices.Marshal.ReleaseComObject(ExcelFile);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(WorkBook);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(UserSheet);

            return user;
        }

        public static string GetNextUserId()    // This creates new Id for User
        {
            ExcelFile = new Excel.Application();

            Excel.Workbook WorkBook = ExcelFile.Workbooks.Open(FilePath);
            Excel.Worksheet UserSheet = (Excel.Worksheet)WorkBook.Worksheets["User"];

            int row;

            for (row = 2; row < UserSheet.Rows.Count; row++)
                if (UserSheet.Cells[row, 1].value == null) break;

            WorkBook.Close();
            ExcelFile.Quit();

            System.Runtime.InteropServices.Marshal.ReleaseComObject(ExcelFile);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(WorkBook);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(UserSheet);

            return "User" + (row - 1).ToString();
        }

        public static bool IsUser(string Id)    // Checks either that user Exists
        {
            ExcelFile = new Excel.Application();

            Excel.Workbook WorkBook = ExcelFile.Workbooks.Open(FilePath);
            Excel.Worksheet UserSheet = (Excel.Worksheet)WorkBook.Worksheets["User"];

            bool found = false;

            for (int row = 2; row < UserSheet.Rows.Count; row++)
                if (UserSheet.Cells[row, 1].value == null) break;
                else if (UserSheet.Cells[row, 1].Text == Id) found = true;

            WorkBook.Close();
            ExcelFile.Quit();

            System.Runtime.InteropServices.Marshal.ReleaseComObject(ExcelFile);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(WorkBook);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(UserSheet);

            return found;
        }

        #endregion

        #region Item Functions

        public static void InsertItem(Item NewItem) // This Inserts the new Item
        {
            ExcelFile = new Excel.Application();
            Excel.Workbook WorkBook = ExcelFile.Workbooks.Open(FilePath);
            Excel.Worksheet ItemSheet = (Excel.Worksheet)WorkBook.Worksheets["Item"];

            for (int row = 2; row <= ItemSheet.Rows.Count; row++)
            {
                if (ItemSheet.Cells[row, 1].value == null)
                {
                    ItemSheet.Cells[row, 1].value = NewItem.Id;   // Id
                    ItemSheet.Cells[row, 2].value = NewItem.Name;   // Name
                    ItemSheet.Cells[row, 3].value = NewItem.Description;   // Description
                    ItemSheet.Cells[row, 4].value = NewItem.Price;   // Price
                    ItemSheet.Cells[row, 5].value = NewItem.SelledTo;   // Selled To
                    break;
                }
            }

            WorkBook.Save();
            WorkBook.Close();
            ExcelFile.Quit();

            System.Runtime.InteropServices.Marshal.ReleaseComObject(ExcelFile);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(WorkBook);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(ItemSheet);
        }

        public static List<Item> AllItems(bool OnlyNotSelled)   // Returns all Items
        {
            ExcelFile = new Excel.Application();
            Excel.Workbook WorkBook = ExcelFile.Workbooks.Open(FilePath);
            Excel.Worksheet ItemSheet = (Excel.Worksheet)WorkBook.Worksheets["Item"];

            Excel.Worksheet BideSheet = (Excel.Worksheet)WorkBook.Worksheets["Bide"];

            List<Item> ItemList = new List<Item>();

            for (int row = 2; row <= ItemSheet.Rows.Count; row++)
            {
                if (ItemSheet.Cells[row, 1].value == null) break;

                if (ItemSheet.Cells[row, 5].Text == "NaN" || !OnlyNotSelled)
                {
                    Item item = new Item();
                    item.Id = ItemSheet.Cells[row, 1].value;
                    item.Name = ItemSheet.Cells[row, 2].value;
                    item.Description = ItemSheet.Cells[row, 3].value;
                    item.Price = float.Parse(ItemSheet.Cells[row, 4].Text);
                    item.SelledTo = ItemSheet.Cells[row, 5].value;

                    item.LastBide = 0.0f;

                    for (int BideRow = 2; BideRow <= BideSheet.Rows.Count; BideRow++)
                        if (BideSheet.Cells[BideRow, 1].value == null)
                            break;
                        else if (BideSheet.Cells[BideRow, 3].Text == item.Id)
                            item.LastBide = float.Parse(BideSheet.Cells[BideRow, 4].Text);

                    ItemList.Add(item);
                }
            }

            WorkBook.Close();
            ExcelFile.Quit();

            System.Runtime.InteropServices.Marshal.ReleaseComObject(ExcelFile);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(WorkBook);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(ItemSheet);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(BideSheet);

            return ItemList;
        }

        public static Item GetItem(string Id, bool OnlyNotSelled)   // This returns a specific Item
        {
            ExcelFile = new Excel.Application();
            Excel.Workbook WorkBook = ExcelFile.Workbooks.Open(FilePath);
            Excel.Worksheet ItemSheet = (Excel.Worksheet)WorkBook.Worksheets["Item"];

            Excel.Worksheet BideSheet = (Excel.Worksheet)WorkBook.Worksheets["Bide"];

            Item item = null;

            for (int row = 2; row <= ItemSheet.Rows.Count; row++)
            {
                if (ItemSheet.Cells[row, 1].value == null) break;

                if (ItemSheet.Cells[row, 1].Text == Id)
                {
                    if (ItemSheet.Cells[row, 5].Text == "NaN" || !OnlyNotSelled)
                    {
                        item = new Item();
                        item.Id = ItemSheet.Cells[row, 1].Text;
                        item.Name = ItemSheet.Cells[row, 2].Text;
                        item.Description = ItemSheet.Cells[row, 3].Text;
                        item.Price = float.Parse(ItemSheet.Cells[row, 4].Text);
                        item.SelledTo = ItemSheet.Cells[row, 5].Text;

                        item.LastBide = 0.0f;

                        for (int BideRow = 2; BideRow <= BideSheet.Rows.Count; BideRow++)
                            if (BideSheet.Cells[BideRow, 1].value == null)
                                break;
                            else if (BideSheet.Cells[BideRow, 3].Text == item.Id)
                                item.LastBide = float.Parse(BideSheet.Cells[BideRow, 4].Text);
                    }

                    break;
                }
            }

            WorkBook.Close();
            ExcelFile.Quit();

            System.Runtime.InteropServices.Marshal.ReleaseComObject(ExcelFile);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(WorkBook);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(ItemSheet);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(BideSheet);

            return item;
        }

        public static string NextItemId()   // This function Generates the next Id for new Item
        {
            ExcelFile = new Excel.Application();
            Excel.Workbook WorkBook = ExcelFile.Workbooks.Open(FilePath);
            Excel.Worksheet ItemSheet = (Excel.Worksheet)WorkBook.Worksheets["Item"];

            int row;

            for (row = 2; row < ItemSheet.Rows.Count; row++)
                if (ItemSheet.Cells[row, 1].value == null) break;

            WorkBook.Close();
            ExcelFile.Quit();

            System.Runtime.InteropServices.Marshal.ReleaseComObject(ExcelFile);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(WorkBook);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(ItemSheet);

            return "Item" + (row - 1).ToString();
        }

        public static void SellItem(string itemid, string userid)
        {
            ExcelFile = new Excel.Application();
            Excel.Workbook WorkBook = ExcelFile.Workbooks.Open(FilePath);
            Excel.Worksheet ItemSheet = (Excel.Worksheet)WorkBook.Worksheets["Item"];

            for (int row = 2; row < ItemSheet.Rows.Count; row++)
                if (ItemSheet.Cells[row, 1].value == null)
                    break;
                else if (ItemSheet.Cells[row, 1].Text == itemid)
                    ItemSheet.Cells[row, 5].value = userid;

            WorkBook.Save();
            WorkBook.Close();
            ExcelFile.Quit();

            System.Runtime.InteropServices.Marshal.ReleaseComObject(ExcelFile);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(WorkBook);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(ItemSheet);
        }

        #endregion

        #region Bide Functions

        public static void InsertBide(Bide bide) // Creates new Bide
        {
            ExcelFile = new Excel.Application();
            Excel.Workbook WorkBook = ExcelFile.Workbooks.Open(FilePath);
            Excel.Worksheet BideSheet = (Excel.Worksheet)WorkBook.Worksheets["Bide"];

            for (int row = 2; row <= BideSheet.Rows.Count; row++)
            {
                if (BideSheet.Cells[row, 1].value == null)
                {
                    BideSheet.Cells[row, 1].value = bide.Id;   // Id
                    BideSheet.Cells[row, 2].value = bide.UserId;   // User Id
                    BideSheet.Cells[row, 3].value = bide.ItemId;   // Item Id
                    BideSheet.Cells[row, 4].value = bide.Price;   // Price
                    break;
                }
            }

            WorkBook.Save();
            WorkBook.Close();
            ExcelFile.Quit();

            System.Runtime.InteropServices.Marshal.ReleaseComObject(ExcelFile);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(WorkBook);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(BideSheet);
        }

        public static string GetNextBideId()
        {
            ExcelFile = new Excel.Application();

            Excel.Workbook WorkBook = ExcelFile.Workbooks.Open(FilePath);
            Excel.Worksheet BideSheet = (Excel.Worksheet)WorkBook.Worksheets["Bide"];

            int row;

            for (row = 2; row < BideSheet.Rows.Count; row++)
                if (BideSheet.Cells[row, 1].value == null) break;

            WorkBook.Close();
            ExcelFile.Quit();

            System.Runtime.InteropServices.Marshal.ReleaseComObject(ExcelFile);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(WorkBook);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(BideSheet);

            return "Bide" + (row - 1).ToString();
        }

        public static string GetUserIdofLastBide(string itemid) // Returns Id of Last User how Bide on specific Item
        {
            ExcelFile = new Excel.Application();

            Excel.Workbook WorkBook = ExcelFile.Workbooks.Open(FilePath);
            Excel.Worksheet BideSheet = (Excel.Worksheet)WorkBook.Worksheets["Bide"];

            string userid = null;

            for (int row = 2; row < BideSheet.Rows.Count; row++)
            {
                if (BideSheet.Cells[row, 1].value == null)
                    break;
                else if (BideSheet.Cells[row, 3].Text == itemid)
                    userid = BideSheet.Cells[row, 2].Text;
            }

            WorkBook.Close();
            ExcelFile.Quit();

            System.Runtime.InteropServices.Marshal.ReleaseComObject(ExcelFile);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(WorkBook);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(BideSheet);

            return userid;
        }

        public static List<Bide> GetAllBidesofItem(string itemid)   // Returns all Bides on specific Item
        {
            ExcelFile = new Excel.Application();
            Excel.Workbook WorkBook = ExcelFile.Workbooks.Open(FilePath);
            Excel.Worksheet BideSheet = (Excel.Worksheet)WorkBook.Worksheets["Bide"];

            List<Bide> BideList = new List<Bide>();

            for (int row = 2; row <= BideSheet.Rows.Count; row++)
            {
                if (BideSheet.Cells[row, 1].value == null)
                    break;
                else if (BideSheet.Cells[row, 3].Text == itemid)
                {
                    Bide bide = new Bide();
                    bide.Id = BideSheet.Cells[row, 1].Text;
                    bide.UserId = BideSheet.Cells[row, 2].Text;
                    bide.ItemId = BideSheet.Cells[row, 3].Text;
                    bide.Price = float.Parse(BideSheet.Cells[row, 4].Text);

                    BideList.Add(bide);
                }
            }

            WorkBook.Close();
            ExcelFile.Quit();

            System.Runtime.InteropServices.Marshal.ReleaseComObject(ExcelFile);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(WorkBook);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(BideSheet);

            return BideList;
        }

        public static List<Bide> GetAllBidesofUser(string userid)   // Returns all Bides of a User
        {
            ExcelFile = new Excel.Application();
            Excel.Workbook WorkBook = ExcelFile.Workbooks.Open(FilePath);
            Excel.Worksheet BideSheet = (Excel.Worksheet)WorkBook.Worksheets["Bide"];

            List<Bide> BideList = new List<Bide>();

            for (int row = 2; row <= BideSheet.Rows.Count; row++)
            {
                if (BideSheet.Cells[row, 1].value == null)
                    break;
                else if (BideSheet.Cells[row, 2].Text == userid)
                {
                    Bide bide = new Bide();
                    bide.Id = BideSheet.Cells[row, 1].Text;
                    bide.UserId = BideSheet.Cells[row, 2].Text;
                    bide.ItemId = BideSheet.Cells[row, 3].Text;
                    bide.Price = float.Parse(BideSheet.Cells[row, 4].Text);

                    BideList.Add(bide);
                }
            }

            WorkBook.Close();
            ExcelFile.Quit();

            System.Runtime.InteropServices.Marshal.ReleaseComObject(ExcelFile);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(WorkBook);
            System.Runtime.InteropServices.Marshal.ReleaseComObject(BideSheet);

            return BideList;
        }

        #endregion

        #region Functions runs at StartUp

        public static bool CheckFile()  // This checks if Excel file is existed
        {
            if (Type.GetTypeFromProgID("Excel.Application") == null)    // Here we check if Excel is installed or not
            {
                Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
                Console.WriteLine("                                       Excel not installed");
                Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════\n");
                Console.WriteLine("     We are sorry. Excel is required to run this project.");
                Console.WriteLine("\n═══════════════════════════════════════════════════════════════════════════════════════════════════");
                Console.WriteLine("  Press enter to continue...");
                Console.WriteLine("═══════════════════════════════════════════════════════════════════════════════════════════════════");

                while (Console.ReadKey(true).Key != ConsoleKey.Enter) { }
                return false;
            }

            Database.ExcelFile = new Excel.Application();

            if (!File.Exists(Environment.CurrentDirectory + "/Database.xls"))   // If the Excel is not present then we create a new file
            {
                Excel.Workbook WorkBook = ExcelFile.Workbooks.Add(System.Reflection.Missing.Value);

                CreateSheets(WorkBook, true, true, true, true);

                Excel.Sheets worksheets = ExcelFile.Worksheets;
                worksheets[5].Delete();

                WorkBook.SaveAs(Environment.CurrentDirectory + "/Database.xls", Excel.XlFileFormat.xlWorkbookNormal, misValue, misValue, misValue, misValue, Excel.XlSaveAsAccessMode.xlExclusive, misValue, misValue, misValue, misValue, misValue);
                WorkBook.Close();
                ExcelFile.Quit();

                System.Runtime.InteropServices.Marshal.ReleaseComObject(ExcelFile);
                System.Runtime.InteropServices.Marshal.ReleaseComObject(WorkBook);
            }
            else   // If file already exists
            {
                Excel.Workbook WorkBook = ExcelFile.Workbooks.Open(Environment.CurrentDirectory + "/Database.xls");

                // Now we check if all the Sheets are also present in file
                // If not then we create new Sheets
                bool NoAdminSheet = true;
                bool NoUserSheet = true;
                bool NoItemSheet = true;
                bool NoBideSheet = true;

                foreach (Excel.Worksheet sheet in WorkBook.Sheets)
                {
                    if (sheet.Name == "Admin") NoAdminSheet = false;
                    else if (sheet.Name == "User") NoUserSheet = false;
                    else if (sheet.Name == "Item") NoItemSheet = false;
                    else if (sheet.Name == "Bide") NoBideSheet = false;
                }

                CreateSheets(WorkBook, NoAdminSheet, NoUserSheet, NoItemSheet, NoBideSheet);

                WorkBook.Save();
                WorkBook.Close();
                ExcelFile.Quit();

                System.Runtime.InteropServices.Marshal.ReleaseComObject(ExcelFile);
                System.Runtime.InteropServices.Marshal.ReleaseComObject(WorkBook);
            }

            return true;
        }   // End CheckFile()

        private static void CreateSheets(Excel.Workbook WorkBook, bool Admin, bool User, bool Item, bool Bide)  // This creates Sheets
        {
            if (Bide)   // Creating Bide Sheet
            {
                Excel.Worksheet BideSheet = (Excel.Worksheet)WorkBook.Worksheets.Add();
                BideSheet.Name = "Bide";

                BideSheet.Cells[1, 1].value = "Id";
                BideSheet.Cells[1, 2].value = "User Id";
                BideSheet.Cells[1, 3].value = "Item Id";
                BideSheet.Cells[1, 4].value = "Price";

                System.Runtime.InteropServices.Marshal.ReleaseComObject(BideSheet);
            }

            if (Item)   // Create Item Sheet
            {
                Excel.Worksheet ItemSheet = (Excel.Worksheet)WorkBook.Worksheets.Add();
                ItemSheet.Name = "Item";

                ItemSheet.Cells[1, 1].value = "Id";
                ItemSheet.Cells[1, 2].value = "Name";
                ItemSheet.Cells[1, 3].value = "Description";
                ItemSheet.Cells[1, 4].value = "Price";
                ItemSheet.Cells[1, 5].value = "Selled To";

                System.Runtime.InteropServices.Marshal.ReleaseComObject(ItemSheet);
            }

            if (User)   // Create User Sheet
            {
                Excel.Worksheet UserSheet = (Excel.Worksheet)WorkBook.Worksheets.Add();
                UserSheet.Name = "User";

                UserSheet.Cells[1, 1].value = "Id";
                UserSheet.Cells[1, 2].value = "Name";
                UserSheet.Cells[1, 3].value = "Contact No.";
                UserSheet.Cells[1, 4].value = "Address";

                System.Runtime.InteropServices.Marshal.ReleaseComObject(UserSheet);
            }

            if (Admin)  // Create Admin Sheet
            {
                Excel.Worksheet AdminSheet = (Excel.Worksheet)WorkBook.Worksheets.Add();
                AdminSheet.Name = "Admin";

                AdminSheet.Cells[1, 1].value = "Id";
                AdminSheet.Cells[1, 2].value = "Name";
                AdminSheet.Cells[1, 3].value = "Password";
                AdminSheet.Cells[1, 4].value = "Contact No.";
                AdminSheet.Cells[1, 5].value = "Address";

                AdminSheet.Cells[2, 1].value = "admin"; // Id
                AdminSheet.Cells[2, 2].value = "admin"; // Name
                AdminSheet.Cells[2, 3].value = "admin"; // Password
                AdminSheet.Cells[2, 4].value = "NaN"; // Password
                AdminSheet.Cells[2, 5].value = "NaN"; // Password

                System.Runtime.InteropServices.Marshal.ReleaseComObject(AdminSheet);
            }
        }

        #endregion
    }

    #endregion

    #region Other Classes

    class Person    // This class contains the basic properties which will use in Admin & User classes using inheritance
    {
        public string Id;
        public string Name;
        public string ContactNo;
        public string Address;
    }

    class Item
    {
        public string Id;
        public string Name;
        public string Description;
        public float Price;
        public string SelledTo;
        public float LastBide;
    }

    class Bide
    {
        public string Id;
        public string UserId;
        public string ItemId;
        public float Price;
    }

    #endregion
}