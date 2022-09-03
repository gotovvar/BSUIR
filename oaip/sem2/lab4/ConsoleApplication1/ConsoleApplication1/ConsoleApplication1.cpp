#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct TInfo {
    string FIO;
    int rus;
    int phis;
    int math;
    int angl;
    double sr_ball;
} info, info1[100];


void Quick_Sort(TInfo a[], int begin, int end) {
    int left, right;
    double x;
    left = begin;
    right = end;
    x = a[(left + right) / 2].sr_ball;
    TInfo r;
    while (left <= right) {
        while (info1[left].sr_ball > x) left++;
        while (info1[right].sr_ball < x) right--;
        if (left <= right) {
            r = info1[left];
            info1[left] = info1[right];
            info1[right] = r;
            left++;
            right--;
        }
    }
    if (begin < right)
        Quick_Sort(a, begin, right);
    if (left < end)
        Quick_Sort(a, left, end);
}


void menu() {
    cout << "1) - Create file " << endl;
    cout << "2) - View information  " << endl;
    cout << "3) - Add information " << endl;
    cout << "4) - Linear search in a file" << endl;
    cout << "5) - Student sorting" << endl;
    cout << "6) - Binary search in sorted array" << endl;
    cout << "7) - Individual task" << endl;
    cout << "8) - EXIT" << endl;
}

int main()
{
    while (true) {
        int c;
        menu();
        cin >> c;
        switch (c) {
        case 1: {

            ofstream in("uni.txt");
            in.close();
            break;
        }
        case 2: {
            ifstream from;
            string text;
            from.open("uni.txt");
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
            cin >> info.FIO;
            cout << "Physics grade: " << endl;
            cin >> info.phis;
            cout << "Mathematics grade: " << endl;
            cin >> info.math;
            cout << "Informatics grade: " << endl;
            cin >> info.rus;
            cout << "Chemistry grade: " << endl;
            cin >> info.angl;
            info.sr_ball = (info.phis + info.math + info.rus + info.angl) / 4.;
            cout << "Average rating: " << info.sr_ball << endl;

            ofstream in("uni.txt", ios_base::app);
            in << info.FIO << " " << info.phis << " " << info.math << " " << info.rus << " " << info.angl << " " << info.sr_ball << endl;
            in.close();
            break;
        }

        case 4: {
            int counter = 0;
            ifstream from("uni.txt");
            while (!from.eof())
            {
                from >> info.FIO >> info.phis >> info.math >> info.rus >> info.angl >> info.sr_ball;
                counter++;
            }
            from.close();

            from.open("uni.txt");

            int kol = 0;
            for (int i = 1; i < counter; i++)
            {
                from >> info.FIO >> info.phis >> info.math >> info.rus >> info.angl >> info.sr_ball;
                info1[kol] = info;
                kol++;
            }
            from.close();

            double score;
            cout << "Enter student score" << endl;
            cin >> score;
            for (int i = 0; i < kol; i++)
                if (info1[i].sr_ball == score) {
                    cout << info1[i].FIO << " " << info1[i].phis << " " << info1[i].math << " " << info1[i].rus << " " << info1[i].angl << " " << info1[i].sr_ball << endl;
                }

            break;
              }
        case 5: {
            int counter = 0;
            double sum = 0;
            ifstream from("uni.txt");
            while (!from.eof())
            {
                from >> info.FIO >> info.phis >> info.math >> info.rus >> info.angl >> info.sr_ball;
                sum += info.sr_ball;
                counter++;
            }
            double uniSr_ball = 0;
            uniSr_ball = sum / counter;
            from.close();

            from.open("uni.txt");

            int kol = 0;
            for (int i = 1; i < counter; i++)
            {
                from >> info.FIO >> info.phis >> info.math >> info.rus >> info.angl >> info.sr_ball;
                info1[kol] = info;
                kol++;
                
            }
            from.close();

            ofstream in("uni.txt");
            in.close();
            ofstream at("uni1.txt");
            at.close();

            int choise;
            cout << "1)- QuickSort" << endl;
            cout << "2)- BubleSort" << endl;
            cin >> choise;
            switch (choise) {
            case 1: {
                Quick_Sort(info1, 0, kol - 1);
                break;
            }
            case 2: {
                TInfo r;
                for (int i = 1; i < kol; i++) {
                    for (int j = 0; j < kol - i; j++)
                        if (info1[j].sr_ball < info1[j + 1].sr_ball) {
                            r = info1[j];
                            info1[j] = info1[j+1];
                            info1[j+1] = r;
                        }

                }
                break;
            }
            default:
                cout << "Mistake!" << endl;
                return 0;
            }
            for (int i = 0; i < kol; i++) {
                cout << "FIO:" << info1[i].FIO << endl <<
                    "Physics grade:" << info1[i].phis << endl <<
                    "Mathematics grade:" << info1[i].math << endl <<
                    "Russian grade:" << info1[i].rus << endl <<
                    "English grade:" << info1[i].angl << endl <<
                    "Average rating:" << info1[i].sr_ball << endl << endl;
                if (info1[i].sr_ball > uniSr_ball) {
                    ofstream at("uni1.txt", ios_base::app);
                    at << info1[i].FIO << " " << info1[i].phis << " " << info1[i].math << " " << info1[i].rus << " " << info1[i].angl << " " << info1[i].sr_ball << endl;
                    at.close();
                }
                ofstream in("uni.txt", ios_base::app);
                in << info1[i].FIO << " " << info1[i].phis << " " << info1[i].math << " " << info1[i].rus << " " << info1[i].angl << " " << info1[i].sr_ball << endl;
                in.close();
            }   
            break;
        }

        case 6: {
            int counter = 0;
            ifstream from("uni1.txt");
            while (!from.eof())
            {
                from >> info.FIO >> info.phis >> info.math >> info.rus >> info.angl >> info.sr_ball;
                counter++;
            }
            from.close();

            from.open("uni1.txt");

            int kol = 0;
            for (int i = 1; i < counter; i++)
            {
                from >> info.FIO >> info.phis >> info.math >> info.rus >> info.angl >> info.sr_ball;
                info1[kol] = info;
                kol++;
            }
            from.close();

            double score;
            bool x = true;
            cout << "Enter student score" << endl;
            cin >> score;
            int mid = 0, right = kol - 1, left = 0;
            while (score != info1[mid].sr_ball) {
                mid = (left + right) / 2;
                if (left > right) {
                    x = false;
                    cout << "Student not found" << endl;
                    break;
                }
               if (score < info1[mid].sr_ball)
                    left = mid + 1;
               else
                    right = mid - 1;
            }
            if (x == true)
                cout << info1[mid].FIO << " " << info1[mid].phis << " " << info1[mid].math << " " << info1[mid].rus << " " << info1[mid].angl << " " << info1[mid].sr_ball << endl;
            break;
        }
        case 7: {
            ifstream from;
            string text;
            from.open("uni1.txt");
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
        case 8: {
            return 0;
            break;
        }
        }
    }
}
    
