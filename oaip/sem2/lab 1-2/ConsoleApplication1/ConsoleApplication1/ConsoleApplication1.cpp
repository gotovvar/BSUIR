#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct TInfo{
    string FIO;
    int year;
    int num_group;
    int inf;
    int phis;
    int math;
    int chem;
    double sr_ball;
}info;


void menu() {
    cout << "1) - Create file " << endl;
    cout << "2) - View information  " << endl;
    cout << "3) - Add information " << endl;
    cout << "4) - Correction" << endl;
    cout << "5) - Solving an individual task" << endl;
    cout << "6) - EXIT" << endl;
}

int main()
{   
    string text;
    while (true) {
        int choice;
        menu();
        cin >> choice;
        switch (choice) {
        case 1: {
            cout << "FIO: " << endl;
            cin >> info.FIO;
            cout << "Year of birth: " << endl;
            cin >> info.year;
            cout << "Group number: " << endl;
            cin >> info.num_group;
            cout << "Physics grade: " << endl;
            cin >> info.phis;
            cout << "Mathematics grade: " << endl;
            cin >> info.math;
            cout << "Informatics grade: " << endl;
            cin >> info.inf;
            cout << "Chemistry grade: " << endl;
            cin >> info.chem;
            info.sr_ball = (info.phis + info.math + info.inf + info.chem) / 4.;
            cout << "Average rating: " << info.sr_ball << endl;

            ofstream in("student.txt");
            in << info.FIO << " " << info.year << " " << info.num_group << " " << info.phis << " " << info.math << " " << info.inf << " " << info.chem << " " << info.sr_ball << endl;
            in.close();
            break;
        }
        case 2: {
            ifstream from;
            from.open("student.txt");
            if (!from.is_open()) {
                cout << "Error";
                from.close();
                return 0;
            }

            while (getline(from, text)) {
                cout << text << "\n";
            }
            from.close();
            break;
        }

        case 3: {
            cout << "FIO: " << endl;
            cin>>info.FIO;
            cout << "Year of birth: " << endl;
            cin >> info.year;
            cout << "Group number: " << endl;
            cin >> info.num_group;
            cout << "Physics grade: " << endl;
            cin >> info.phis;
            cout << "Mathematics grade: " << endl;
            cin >> info.math;
            cout << "Informatics grade: " << endl;
            cin >> info.inf;
            cout << "Chemistry grade: " << endl;
            cin >> info.chem;
            info.sr_ball = (info.phis + info.math + info.inf + info.chem) / 4.;
            cout << "Average rating: " << info.sr_ball << endl;

            ofstream in("student.txt", ios_base::app);
            in << info.FIO << " " << info.year << " " << info.num_group << " " << info.phis << " " << info.math << " " << info.inf << " " << info.chem << " " << info.sr_ball << endl;
            in.close();
            
            break;
        }
        case 4: {
            TInfo data[999];
            int line = 0, num;
            ifstream from("student.txt");
            if (!from.is_open()) {
                cout << "Error";
                return 0;
            }
            while (!from.eof())
            {
                from >> info.FIO >> info.year >> info.num_group >> info.phis >> info.math >> info.inf >> info.chem >> info.sr_ball;
                data[line] = info;
                line++;
            }
            from.close();
            
            TInfo info1;
            cout << "Enter the number of the line you want to correct" << endl;
            cin >> num;
            cout << "Enter new data" << endl;
            cout << "FIO: " << endl;
            cin >> info1.FIO;
            cout << "Year of birth: " << endl;
            cin >> info1.year;
            cout << "Group number: " << endl;
            cin >> info1.num_group;
            cout << "Physics grade: " << endl;
            cin >> info1.phis;
            cout << "Mathematics grade: " << endl;
            cin >> info1.math;
            cout << "Informatics grade: " << endl;
            cin >> info1.inf;
            cout << "Chemistry grade: " << endl;
            cin >> info1.chem;
            info1.sr_ball = (info1.phis + info1.math + info1.inf + info1.chem) / 4.;
            data[num - 1] = info1;
            ofstream in("student.txt");
            for (int i = 0; i < line - 1; i++) {
                in << data[i].FIO << " " << data[i].year << " " << data[i].num_group<< " " << data[i].phis<< " " << data[i].math << " " << data[i].inf << " " << data[i].chem << " " << data[i].sr_ball << "\n";
            }
            in.close();

            break;
        }
        case 5: {
            int n, counter = 0;
            bool f = true;
            ifstream from("student.txt");
            while (!from.eof())
            {
                from >> info.FIO >> info.year >> info.num_group >> info.phis >> info.math >> info.inf >> info.chem >> info.sr_ball;
                counter++;
            }
            from.close();

            cout << "Enter the number of the group you are interested in:" << endl;
            cin >> n;
            from.open("student.txt");

            ofstream fout("student1.txt");
            fout.close();

            for (int i = 1; i < counter; i++) 
            {
                from >> info.FIO >> info.year >> info.num_group >> info.phis >> info.math >> info.inf >> info.chem >> info.sr_ball;

                if ((n == info.num_group) && (info.sr_ball >= 9))
                {
                    cout << "FIO:" << info.FIO << endl <<
                        "Year of birth:" << info.year << endl <<
                        "Group number:" << info.num_group << endl <<
                        "Physics grade:" << info.phis << endl <<
                        "Mathematics grade:" << info.math << endl <<
                        "Informatics grade:" << info.inf << endl <<
                        "Chemistry grade:" << info.chem << endl <<
                        "Average rating:" << info.sr_ball << endl << endl;
                    f = false;

                    ofstream fout("student1.txt", ios_base::app);
                    fout << info.FIO << " " << info.year << " " << info.num_group << " " << info.phis << " " << info.math << " " << info.inf << " " << info.chem << " " << info.sr_ball << endl;
                    fout.close();
                }
            }
            if (f == true)
            {
                cout << "Error!" << endl;
                break;
            }
            from.close();
            break;
        }

        case 6:
            return 0;
            break;
        }

       
    }




    
}


