#include <iostream>   
#include <fstream>    
#include <string>
#include <cstdlib>     
#include <ctime>      
#include <windows.h>

using namespace std;

const int Total_capacity = 400;
const int Single_vehicle = 100;
const int Max_members = 100;

const string RESET = "\033[0m";
const string BLACK = "\033[30m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";
const string B_BLACK = "\033[90m";
const string B_RED = "\033[91m";
const string B_GREEN = "\033[92m";
const string B_YELLOW = "\033[93m";
const string B_BLUE = "\033[94m";
const string B_MAGENTA = "\033[95m";
const string B_CYAN = "\033[96m";
const string B_WHITE = "\033[97m";

int count1 = 0, count2 = 0, count3 = 0, count4 = 0;

struct VEHICLE {
    string serialnumber;
    string numberPlate;
    char type;
};
struct Membership {
    string cardNumber;
    string name;
    string contact;
};

Membership members[Max_members];
int numMembers = 0;

VEHICLE Car[Single_vehicle];
VEHICLE Bus[Single_vehicle];
VEHICLE Motorbike[Single_vehicle];
VEHICLE Rickshaw[Single_vehicle];

int carCount = 0, busCount = 0, bikeCount = 0, rickshawCount = 0;

char asktask() {
    char choice;
    cout <<B_RED<<"             <<< Press the following button >>>\n\n\n"<<RESET;
    cout <<YELLOW<< "[ P ]"<<RESET<<"  Park a Vehicle                  "<<YELLOW<<"[ R ]"<<RESET<<"  Remove a vehicle\n\n\n"<<YELLOW<<"[ S ]"<<RESET<<"  Showing Status                 "<<YELLOW<<" [ A ]"<<RESET<<"  Admin Terminal\n\n\n"<<YELLOW<<"                        [ Q ]"<<RESET<<"  Quit\n\n"<<GREEN<<" >>>> ";
    cout<<B_BLACK ;
    cin >> choice;
    cout<<RESET;
    return choice;
} 

void CS() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void saveData() {
    ofstream outFile("D:\\Codes\\Resume Projects\\Parking management System\\Parking_data.txt", ios::trunc);
    // ofstream outFile("Parking_data.txt", ios::trunc);
   outFile << carCount << " " << busCount << " " << bikeCount << " " << rickshawCount << endl;
    for (int i = 0; i < carCount; i++) {
        outFile << Car[i].serialnumber << " " << Car[i].numberPlate << " " << Car[i].type << endl;
    }
    for (int i = 0; i < busCount; i++) {
        outFile << Bus[i].serialnumber << " " << Bus[i].numberPlate << " " << Bus[i].type << endl;
    }
    for (int i = 0; i < bikeCount; i++) {
        outFile << Motorbike[i].serialnumber << " " << Motorbike[i].numberPlate << " " << Motorbike[i].type << endl;
    }
    for (int i = 0; i < rickshawCount; i++) {
        outFile << Rickshaw[i].serialnumber << " " << Rickshaw[i].numberPlate << " " << Rickshaw[i].type << endl;
    }
    outFile << numMembers << endl;
    for(int i=0; i <Max_members; i++){
        outFile << members[i].cardNumber << " " << members[i].name << " " << members[i].contact << endl;
    }
    outFile.close();
}

void loadData() {
    ifstream inFile("D:\\Codes\\Resume Projects\\Parking management System\\Parking_data.txt");
    // ifstream inFile("Parking_data.txt");
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return;
    }
    inFile >> carCount >> busCount >> bikeCount >> rickshawCount;
    count1 = carCount;
    count2 = busCount;
    count3 = bikeCount;
    count4 = rickshawCount;
    for (int i = 0; i < carCount; ++i) {
        inFile >> Car[i].serialnumber >> Car[i].numberPlate >> Car[i].type;
    }
    for (int i = 0; i < busCount; ++i) {
        inFile >> Bus[i].serialnumber >> Bus[i].numberPlate >> Bus[i].type;
    }
    for (int i = 0; i < bikeCount; ++i) {
        inFile >> Motorbike[i].serialnumber >> Motorbike[i].numberPlate >> Motorbike[i].type;
    }
    for (int i = 0; i < rickshawCount; ++i) {
        inFile >> Rickshaw[i].serialnumber >> Rickshaw[i].numberPlate >> Rickshaw[i].type;
    }
    inFile >> numMembers;
   for (int i = 0; i < Max_members; ++i) {
        inFile >> members[i].cardNumber >> members[i].name >> members[i].contact;
    }
    inFile.close();
}

void addMember() {
    if (numMembers < Max_members) {
        Membership member;
        cout <<B_CYAN<< "Enter card number: "<<RESET;
        cin >> member.cardNumber;
        cout <<B_CYAN<< "Enter member name: "<<RESET;
        cin.ignore();
        getline(cin, member.name);
        
        cout <<B_CYAN<< "Enter member contact: "<<RESET;
        getline(cin, member.contact);
        

        members[numMembers++] = member;
        CS();
        cout <<B_GREEN<< "Member added successfully.\n"<<RESET;
        Sleep(500);
    } else {
        cout <<RED<< "Maximum number of members reached.\n"<<RESET;
    }
    saveData();
}


bool check(const string &cardNumber) {
    for (int i = 0; i < numMembers; ++i) {
        if (members[i].cardNumber == cardNumber) {
            return true;
        }
    }
    return false; saveData();
}

void parkVehicle() {
    char e;
    string cardNumber;

CS();
    cout <<MAGENTA<< "Do you have a membership card? (y/n): "<<RESET;
    cin >> e;
    if (e == 'y' || e == 'Y') {
    hook: 
    CS();   
        cout <<MAGENTA<< "Enter card number: "<<RESET;
        cin >> cardNumber;
        if (check(cardNumber)) {
            CS();
            cout <<GREEN<< "Membership verified.\n"<<RESET;
        } else {
            CS();
            char h;
            cout <<RED<< "Invalid card number\n"<<RESET; 
            cout<<B_GREEN<<"Do you want to skip?  (y/n): "<<RESET; cin>>h;
            if(h == 'n' || h == 'N'){ CS(); goto hook;}
            else{CS();}

        }
    } 
    else {
    CS();  
    }
    
}

void removeVehicle(VEHICLE Car[], VEHICLE Bus[], VEHICLE Motorbike[], VEHICLE Rickshaw[], int& carCount, int& busCount, int& bikeCount, int& rickshawCount, const string& serialnumber) {
    for (int i = 0; i < carCount; ++i) {
        if (Car[i].serialnumber == serialnumber) {
            cout <<GREEN<< "Car with serial number: " <<RESET<<RED<<"' "<< "C-" << serialnumber <<" '"<<RESET<<GREEN<< " is found.. \nCharges: "<<RESET<<YELLOW<<"Rs. 80" << endl<<RESET;
            Car[i] = Car[--carCount];
            count1--;
            saveData();
            return;
        }
    }
    for (int i = 0; i < busCount; ++i) {
        if (Bus[i].serialnumber == serialnumber) {
            cout <<GREEN<< "Bus with serial number: " <<RESET<<RED<<"' "<< "B-" << serialnumber <<" '"<<RESET<<GREEN<< " is found..\nCharges: "<<RESET<<YELLOW<<"Rs. 200." << endl<<RESET;
            Bus[i] = Bus[--busCount];
            count2--;
            saveData();
            return;
        }
    }
    for (int i = 0; i < bikeCount; ++i) {
        if (Motorbike[i].serialnumber == serialnumber) {
            cout <<GREEN<< "Bike with serial number: " <<RESET<<RED<<"' "<< "M-" << serialnumber <<" '"<<RESET<<GREEN<< " is found..\nCharges: "<<RESET<<YELLOW<<"Rs.20" << endl<<RESET;
            Motorbike[i] = Motorbike[--bikeCount];
            count3--;
            saveData();
            return;
        }
    }
    for (int i = 0; i < rickshawCount; ++i) {
        if (Rickshaw[i].serialnumber == serialnumber) {
            cout <<GREEN<< "Rickshaw with serial number: " <<RESET<<RED<<"' "<< "R-" << serialnumber <<" '"<< " is found..\nCharges: "<<RESET<<YELLOW<<"Rs. 50" << endl<<RESET;
            Rickshaw[i] = Rickshaw[--rickshawCount];
            count4--;
            saveData();
            return;
        }
    }
    cout <<CYAN<< "Vehicle with serial number: " <<RESET<< serialnumber <<RESET<< " is not found." << endl<<RESET; 
}
void remove_member(VEHICLE Car[], VEHICLE Bus[], VEHICLE Motorbike[], VEHICLE Rickshaw[], int& carCount, int& busCount, int& bikeCount, int& rickshawCount, const string& serialnumber) {
    for (int i = 0; i < carCount; ++i) {
        if (Car[i].serialnumber == serialnumber) {
            cout <<GREEN<< "Car with serial number: " <<RESET<<RED<<"' "<< "C-" << serialnumber <<" '"<<RESET<<GREEN<< " is found.. \nCharges: "<<RESET<<YELLOW<<"Rs. 40" << endl<<RESET;
            Car[i] = Car[--carCount];
            count1--;
            saveData();
            return;
        }
    }
    for (int i = 0; i < busCount; ++i) {
        if (Bus[i].serialnumber == serialnumber) {
            cout <<GREEN<< "Bus with serial number: " <<RESET<<RED<<"' "<< "B-" << serialnumber <<" '"<<RESET<<GREEN<< " is found..\nCharges: "<<RESET<<YELLOW<<"Rs. 100" << endl<<RESET;
            Bus[i] = Bus[--busCount];
            count2--;
            saveData();
            return;
        }
    }
    for (int i = 0; i < bikeCount; ++i) {
        if (Motorbike[i].serialnumber == serialnumber) {
            cout <<GREEN<< "Bike with serial number: " <<RESET<<RED<<"' "<< "M-" << serialnumber <<" '"<<RESET<<GREEN<< " is found..\nCharges: "<<RESET<<YELLOW<<"Rs.15" << endl<<RESET;
            Motorbike[i] = Motorbike[--bikeCount];
            count3--;
            saveData();
            return;
        }
    }
    for (int i = 0; i < rickshawCount; ++i) {
        if (Rickshaw[i].serialnumber == serialnumber) {
            cout <<GREEN<< "Rickshaw with serial number: " <<RESET<<RED<<"' "<< "R-" << serialnumber <<" '"<< " is found..\nCharges: "<<RESET<<YELLOW<<"Rs. 30" << endl<<RESET;
            Rickshaw[i] = Rickshaw[--rickshawCount];
            count4--;
            saveData();
            return;
        }
    }
    cout <<CYAN<< "Vehicle with serial number: " <<RESET<< serialnumber <<RESET<< " is not found." << endl<<RESET; 
}
void addVehicle(VEHICLE Car[], VEHICLE Bus[], VEHICLE Motorbike[], VEHICLE Rickshaw[], int& carCount, int& busCount, int& bikeCount, int& rickshawCount, const string& serialnumber, const string& numberPlate, const char type) {
    if (carCount + busCount + bikeCount + rickshawCount >= Total_capacity) {
        cout <<B_RED<< "Oops!! Parking is full"<< endl<<RESET;
        return;
    }
    VEHICLE vehicle;
    vehicle.serialnumber = serialnumber;
    vehicle.numberPlate = numberPlate;
    vehicle.type = type;

    if (type == 'c' || type == 'C') {
        if (carCount < Single_vehicle) {
            Car[carCount++] = vehicle;
            cout <<CYAN<< "You have parked a Car with serial number: " <<RESET<<RED<<"' "<< "C-" << serialnumber <<" '"<<RESET<<CYAN<< " with number plate: " <<RESET<<"' "<<RED<< numberPlate <<" '"<<RESET;
            count1++;
            saveData();
        } else {
            cout <<B_RED<< "Maximum limit reached for Cars\nPlease wait!!" << endl<<RESET;
        }
    } else if (type == 'b' || type == 'B') {
        if (busCount < Single_vehicle) {
            Bus[busCount++] = vehicle;
            cout <<CYAN<< "You have parked a Bus with serial number: " <<RESET<<RED<<"' "<< "B-" << serialnumber <<" '"<<RESET<<CYAN<< " with number plate: " <<RESET<<RED<<"' "<< numberPlate <<" '"<<RESET;
            count2++;
            saveData();
        } else {
            cout <<B_RED<< "Maximum limit reached for buses\nPlease wait!!" << endl<<RESET;
        }
    } else if (type == 'm' || type == 'M') {
        if (bikeCount < Single_vehicle) {
            Motorbike[bikeCount++] = vehicle;
            cout <<CYAN<< "You have parked a Bike with serial number: " <<RESET<<RED<<"' "<< "M-" << serialnumber <<" '"<<RESET<<CYAN<< " with number plate: " <<RESET<<RED<<"' "<< numberPlate <<" '"<<RESET;
            count3++;
            saveData();
        } else {
            cout <<RED<< "Maximum limit reached for bikes\nPlease wait!!" << endl<<RESET;
        }
    } else if (type == 'r' || type == 'R') {
        if (rickshawCount < Single_vehicle) {
            Rickshaw[rickshawCount++] = vehicle;
            cout <<CYAN<< "You have parked a Rickshaw with serial number: " <<RESET<<RED<<"' "<< "R-" << serialnumber <<" '"<<RESET<<CYAN<< " with number plate: " <<RESET<<RED<<"' "<< numberPlate <<" '"<<RESET;
            count4++;
            saveData();
        } else {
            cout <<RED<< "Maximum limit reached for rickshaws\nPlease wait!!" << endl<<RESET;
        }
    } else {
        cout <<RED<< "Invalid vehicle type!!" << endl<<RESET; 
    }
}
void removeVehicleWithFine(VEHICLE Car[], VEHICLE Bus[], VEHICLE Motorbike[], VEHICLE Rickshaw[], int& carCount, int& busCount, int& bikeCount, int& rickshawCount, const string& serialnumber) {
    for (int i = 0; i < carCount; ++i) {
        if (Car[i].serialnumber == serialnumber) {
            cout << GREEN << "Car with serial number: " << RESET << RED << "' " << "C-" << serialnumber << " '" << RESET << GREEN << " is found and fined Rs. 300.\nCharges: " << RESET << YELLOW << "Rs. 380" << endl << RESET;
            Car[i] = Car[--carCount];
            count1--;
            saveData();
            return;
        }
    }
    for (int i = 0; i < busCount; ++i) {
        if (Bus[i].serialnumber == serialnumber) {
            cout << GREEN << "Bus with serial number: " << RESET << RED << "' " << "B-" << serialnumber << " '" << RESET << GREEN << " is found and fined Rs. 300.\nCharges: " << RESET << YELLOW << "Rs. 500" << endl << RESET;
            Bus[i] = Bus[--busCount];
            count2--;
            saveData();
            return;
        }
    }
    for (int i = 0; i < bikeCount; ++i) {
        if (Motorbike[i].serialnumber == serialnumber) {
            cout << GREEN << "Bike with serial number: " << RESET << RED << "' " << "M-" << serialnumber << " '" << RESET << GREEN << " is found and fined Rs. 300.\nCharges: " << RESET << YELLOW << "Rs. 320" << endl << RESET;
            Motorbike[i] = Motorbike[--bikeCount];
            count3--;
            saveData();
            return;
        }
    }
    for (int i = 0; i < rickshawCount; ++i) {
        if (Rickshaw[i].serialnumber == serialnumber) {
            cout << GREEN << "Rickshaw with serial number: " << RESET << RED << "' " << "R-" << serialnumber << " '" << RESET << GREEN << " is found and fined Rs. 300.\nCharges: " << RESET << YELLOW << "Rs. 350" << endl << RESET;
            Rickshaw[i] = Rickshaw[--rickshawCount];
            count4--;
            saveData();
            return;
        }
    }
    cout << CYAN << "Vehicle with serial number: " << RESET << serialnumber << RESET << " is not found." << endl << RESET;
}

int GSN(int base) {
    return rand() % 100 + base;
}

void admin_panel(){
admin:
do{

        
        cout << YELLOW << "[ 1 ]" << RESET << "  List all parked vehicles\n";
        cout << YELLOW << "[ 2 ]" << RESET << "  Remove vehicle with fine\n";
        cout << YELLOW << "[ 3 ]" << RESET << "  Membership cards\n";
        cout << YELLOW << "[ 4 ]" << RESET << "  Back to main menu\n\n";
        char c;
        cout << GREEN << ">>>  " << RESET;
        cout << B_BLACK;
        cin >> c;
        cout << RESET;
        {CS();
        if (c == '1') {
            // cout << GREEN << "**** List of All Parked Vehicles ****\n\n" << endl << RESET;
        cout<<B_GREEN<<"=============================================================="<<endl; 
        cout<<"[|]                                                        [|]"<<endl;
        cout<<"[|]               \033[93mList of All Parked Vehicles\033[0m\033[92m              [|]"<<endl;
        cout<<"[|]                                                        [|]"<<endl;
        cout<<"=============================================================="<<RESET<<"\n\n"; 
         
            for (int i = 0; i < carCount; ++i) {
                cout << MAGENTA << "Number Plate: " << RESET << RED << Car[i].numberPlate << RESET << MAGENTA << ", Serial Number: " << RESET << RED << Car[i].serialnumber << RESET << MAGENTA << ", Type: " << RESET << YELLOW << " Car" << endl << RESET;
            }
            for (int i = 0; i < busCount; ++i) {
                cout << MAGENTA << "Number Plate: " << RESET << RED << Bus[i].numberPlate << RESET << MAGENTA << ", Serial Number: " << RESET << RED << Bus[i].serialnumber << RESET << MAGENTA << ", Type: " << RESET << YELLOW << " Bus" << endl << RESET;
            }
            for (int i = 0; i < bikeCount; ++i) {
                cout << MAGENTA << "Number Plate: " << RESET << RED << Motorbike[i].numberPlate << RESET << MAGENTA << ", Serial Number: " << RESET << RED << Motorbike[i].serialnumber << RESET << MAGENTA << ", Type: " << RESET << YELLOW << " Motorbike" << endl << RESET;
            }

            for (int i = 0; i < rickshawCount; ++i) {
                cout << MAGENTA << "Number Plate: " << RESET << RED << Rickshaw[i].numberPlate << RESET << MAGENTA << ", Serial Number: " << RESET << RED << Rickshaw[i].serialnumber << RESET << MAGENTA << ", Type: " << RESET << YELLOW << " Rickshaw" << endl << RESET;
            }
            cout << GREEN << "\n\n**************************************************************\n" << endl << RESET;
        
            cout <<MAGENTA<< "Press any key to continue>>>>> "<<RESET;
            cout<<B_BLACK; getchar(); getchar();
            CS(); goto admin;
        } 
        else if (c == '2') {
        string sn_r;
        cout << CYAN << "Enter the Serial number of the vehicle >> " << RESET;
        cout << B_BLACK;
        cin >> sn_r;
        cout << RESET;
        CS();
        removeVehicleWithFine(Car, Bus, Motorbike, Rickshaw, carCount, busCount, bikeCount, rickshawCount, sn_r);

        cout <<MAGENTA<< "Press any key to continue>>>>> "<<RESET;
        cout<<B_BLACK; getchar(); getchar();
        CS(); goto admin;

        }else if(c == '3'){
        dosri:
        cout<<B_GREEN<<"=============================================================="<<endl; 
    cout<<"[|]                                                        [|]"<<endl;
    cout<<"[|]                \033[93mMemborship Card Management\033[0m\033[92m              [|]"<<endl;
    cout<<"[|]                                                        [|]"<<endl;
    cout<<"=============================================================="<<RESET<<"\n\n";
             char m;
                 cout << YELLOW << "[ 1 ]" << RESET << "  Add Member\n";
                 cout << YELLOW << "[ 2 ]" << RESET << "  Delete a Member\n";
                 cout << YELLOW << "[ 3 ]" << RESET << "  List of Members\n";
                 cout << YELLOW << "[ 4 ]" << RESET << "  Back to main menu\n\n";
                 cout<<B_GREEN<<">>>"<<RESET; cin >> m;
                if(m=='4'){
                    CS(); goto admin;
                }
               else if (m == '1') {
                    CS();
                    addMember();
                } else if (m == '2') {
                    CS();
                     string cardNumber;
                del:
                    cout <<B_CYAN<< "Enter card number to delete: "<<RESET;
                    cin >> cardNumber;
                    
                    for (int i = 0; i < numMembers; ++i) {
                        if (members[i].cardNumber == cardNumber) {
                            for (int j = i; j < numMembers - 1; ++j) {
                                members[j] = members[j + 1];
                            }
                            --numMembers;
                            cout <<GREEN<< "Member deleted successfully.\n"<<RESET;
                            cout <<MAGENTA<< "Press any key to continue>>>>> "<<RESET;
                            cout<<B_BLACK; getchar(); getchar();
                            CS(); goto dosri;
                        }
                    }
                    char u;
                    CS();
                    cout <<RED<< "Card number not found."<<RESET<<MAGENTA<<"\nDo you want to back? (y/n): "<<RESET; cin>>u;
                    if(u=='y'||u=='Y'){CS(); goto dosri;}
                    else{CS(); goto del;} 
                    saveData();
                }else if(m=='3'){
            CS();
            cout << GREEN << "**** List of All Parked Vehicles ****\n\n" << endl << RESET;
            for (int i = 0; i < numMembers; ++i) {
            cout << MAGENTA << "card number : " << RESET << RED << members[i].cardNumber << RESET << MAGENTA << ", Name : " << RESET << RED << members[i].name << RESET << MAGENTA << ", Contact : " << RESET << RED << members[i].contact << endl << RESET;
            }
            cout << GREEN << "\n\n**** End ****\n" << endl << RESET;
            cout <<MAGENTA<< "Press any key to continue>>>>> "<<RESET;
            cout<<B_BLACK; getchar(); getchar();
            CS(); goto dosri;
                } 
                else {
                    CS();
                    cout <<RED<< "Invalid choice.\n"<<RESET; 
                    goto dosri;
                }
                    CS();
        } 
        else if (c == '4') {
            break;
        } else {
        
        cout << RED << "Invalid input. Please try again." << endl << RESET;
        cout <<MAGENTA<< "Press any key to continue>>>>> "<<RESET;
        cout<<B_BLACK; getchar(); getchar();
        CS();
        
        }}
} while(true);
}

int main() {
    loadData();
    srand(time(0));
    string serialnumber;
    string numberPlate;
    char type;
    char choice;

    while (true) {
        
        CS();
        Start:
    cout<<B_GREEN<<"=============================================================="<<endl; 
    cout<<"[|]                                                        [|]"<<endl;
    cout<<"[|]                \033[93mWelcome To Parking System\033[0m\033[92m               [|]"<<endl;
    cout<<"[|]                                                        [|]"<<endl;
    cout<<"=============================================================="<<RESET<<"\n\n";

        choice = asktask();

        if (choice == 'Q' || choice == 'q') {
            CS();
            cout <<B_MAGENTA<< "Thanks for visiting!!\n"<<RESET; 
            break;
        }

        switch (choice) {
            case 'p':
            case 'P': {
                CS();
                cout <<CYAN <<"Enter the Number plate (Only digits) >> "<<RESET;
                cout<<B_BLACK;
                cin >> numberPlate;
                cout<<RESET;
                CS();

            H:   
                cout <<YELLOW<< "' C ' "<<RESET<<" Car\n"<<YELLOW<<"' B ' "<<RESET<<" Bus\n"<<YELLOW<<"' M ' "<<RESET<<" MotorBike\n"<<YELLOW<<"' R ' "<<RESET <<" Rickshaw\n\n" <<CYAN<< "Enter the type >>> "<<RESET;
                cout<<B_BLACK;
                cin >> type;
                cout<<RESET;
                CS();

                int base;
                if (type == 'c' || type == 'C') {
                    base = 1;
                } else if (type == 'b' || type == 'B') {
                    base = 201;
                } else if (type == 'm' || type == 'M') {
                    base = 101;
                } else if (type == 'r' || type == 'R') {
                    base = 301;
                } else {
                    cout <<RED<< "Invalid vehicle type!!\n\n"<<RESET; goto H;
                    break;
                }

                int serial_num = GSN(base);
                serialnumber = to_string(serial_num);

                addVehicle(Car, Bus, Motorbike, Rickshaw, carCount, busCount, bikeCount, rickshawCount, serialnumber, numberPlate, type);
                cout <<CYAN<< "\n\nYour serial number is: " <<RESET<<YELLOW<< serial_num << endl<<RESET;
                break;
            }
            case 'r':
            case 'R': {  
                CS();
            R:
                cout <<CYAN<< "Enter the Serial number (only digits) >> "<<RESET;
                cout<<B_BLACK;
                cin >> serialnumber;
                cout<<RESET;
                CS();
                 char e;
                 string cardNumber;
yoyo:
CS();
            cout <<MAGENTA<< "Do you have a membership card? (y/n): "<<RESET;
            cin >> e;
            if (e == 'y' || e == 'Y') {
            hook: 
            CS();   
                cout <<CYAN<< "Enter card number: "<<RESET;
                cin >> cardNumber;
                if (check(cardNumber)) {
                    CS();
                    cout <<B_GREEN<< "Membership verified.\n\n"<<RESET;
                    remove_member(Car, Bus, Motorbike, Rickshaw, carCount, busCount, bikeCount, rickshawCount, serialnumber);
                } else {
                    CS();
                    char h;
                    cout <<B_RED<< "Invalid card number\n"<<RESET; 
                    cout<<B_CYAN<<"Do you want to skip?  (y/n): "<<RESET; cin>>h;
                    if(h == 'n' || h == 'N'){ CS(); goto hook;}
                    else{CS();goto yoyo;}

                }
            } 
            else {
            CS();  
                        removeVehicle(Car, Bus, Motorbike, Rickshaw, carCount, busCount, bikeCount, rickshawCount, serialnumber);  
            }
                    cout<<B_YELLOW<<"\nPress any key to continue ('B' for Main Menu) >>> "<<RESET; char b; cin>>b;
                    if(b=='B'||b=='b'){CS(); goto Start;}
                    else { goto R;}
                        break;
                    }
            case 's':
            case 'S': {
                CS();
                cout <<RED<< "Parking lot status:" << endl;
                cout << "=====================" << endl<<RESET;
                cout <<GREEN<< "\nTotal Cars parked = " <<RESET<<YELLOW<< count1 << endl<<RESET;
                cout <<GREEN<< "Total buses parked = " <<RESET<<YELLOW<< count2 << endl<<RESET;
                cout <<GREEN<< "Total Motorbikes parked = " <<RESET<<YELLOW<< count3 << endl<<RESET;
                cout <<GREEN<< "Total Rickshaws parked = " <<RESET<<YELLOW<< count4<<RESET;
                cout <<GREEN<< "\n\nTotal Vehicles parked in the area = " <<RESET<<YELLOW<< count1 + count2 + count3 + count4 << "\n\n"<<RESET;
                break;
            }
           case 'a':
           case 'A': {
CS();
string p;

P:
    cout << CYAN << "Enter the Password >> " << RESET;
    cout << B_BLACK;
    cin >> p;
    cout << RESET;
    CS();
    cout<<B_GREEN<<"=============================================================="<<endl; 
    cout<<"[|]                                                        [|]"<<endl;
    cout<<"[|]                \033[93mWelcome To The Admin Panel\033[0m\033[92m              [|]"<<endl;
    cout<<"[|]                                                        [|]"<<endl;
    cout<<"=============================================================="<<RESET<<"\n\n";
    if (p == "proton"){
    cout<<GREEN<<"Admin: "<<RESET<< RED << "Shadow Wolf\n\n" << RESET;
    admin_panel();
    }
    else if (p == "areeb"){
    cout <<GREEN<<"Admin: "<<RESET<< RED << "Areeb Dinpuri\n\n" << RESET;
    admin_panel();
    }
    else if (p == "maaz"){
    cout <<GREEN<<"Admin: "<<RESET<< RED << "Maaz Shafiq\n\n" << RESET;
    admin_panel();
    }
    else if (p == "hannan"){
    cout <<GREEN<<"Admin: "<<RESET<< RED << "Hannan\n\n" << RESET;
    admin_panel();
    } 
    else {
        CS();
        cout << RED << "Wrong Password!\n" << RESET;
        goto P;
    }
    break;
}
default:{
    CS();
    cout << RED << "Invalid input. Please try again." << endl << RESET;  goto Start;
}

        }
 
        cout <<MAGENTA<< "Press any key to continue>>>>> "<<RESET;
        cout<<B_BLACK; getchar(); getchar();
    }
    cout<<B_YELLOW;
    system("Pause");
    cout<<RESET;
    return 0;
}

