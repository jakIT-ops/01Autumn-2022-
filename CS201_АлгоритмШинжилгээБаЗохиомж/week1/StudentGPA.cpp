#include<iostream>
#include <bits/stdc++.h>
using namespace std;

/** Бодлогын даалгавар:
 *      Оюутаны n хичээлийн дүн өгөгдсөн бол голч оноог бодож хэвлэ.
 **/

double myGrades[29] = {60.00, 79.00, 99.00, 100.00, 67.00, 81.00, 91.00, 67.00, 59.00, 48.00, 100.00, 58.00, 98.00, 100.00, 96.00, 93.00, 84.00, 84.00, 96.00, 75.00, 100.00, 84.00, 91.00, 95.00, 93.00, 91.00, 92.00, 55.00, 91.00};
double myCredits[29] = {3.0, 3.0, 3.0, 2.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 1.0, 3.0, 2.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 2.0};
const int allCredit = 82;
const double expectedGpa = 2.70; // calc oyutanii web

/** Үнэлгээний голч дүн (GPA)
 *      Үнэлгээний голч дүнг тооцохдоо, хичээл бүрийн үсгэн үнэлгээг үнэлгээний оноонд шилжүүлэн. улмаар тухайн хичээлийн харгалзах кредитээр үржүүлж, дундажлах замаар тодорхойлно.
 * */

void calcRatingScore(double grade[], vector<double>& ratingScore){

    for(int i = 0; i< 29; i++){
        if(grade[i] >= 96 && grade[i] <= 100) ratingScore.push_back(4.0); // A
        else if (grade[i] >= 91 && grade[i] <= 95) ratingScore.push_back(3.7); // A-
        else if (grade[i] >= 88 && grade[i] <= 90) ratingScore.push_back(3.4); // B+
        else if (grade[i] >= 84 && grade[i] <= 87) ratingScore.push_back(3.0); // B
        else if (grade[i] >= 81 && grade[i] <= 83) ratingScore.push_back(2.7); // B-
        else if (grade[i] >= 78 && grade[i] <= 80) ratingScore.push_back(2.4); // C+
        else if (grade[i] >= 74 && grade[i] <= 77) ratingScore.push_back(2.0); // C
        else if (grade[i] >= 71 && grade[i] <= 73) ratingScore.push_back(1.7); // C-
        else if (grade[i] >= 68 && grade[i] <= 70) ratingScore.push_back(1.3); // D+
        else if (grade[i] >= 64 && grade[i] <= 67) ratingScore.push_back(1.0); // D
        else if (grade[i] >= 60 && grade[i] <= 63) ratingScore.push_back(0.7); // D-
        else if (grade[i] >= 0 && grade[i] <= 59) ratingScore.push_back(0); // F
    }
}

int main(){
    vector<double> ratingScore;
    calcRatingScore(myGrades, ratingScore);

    double sum = 0;
    double total;
    double gpa;
    long totalLessons, totalCredits;

//    cout<<"Нийт хэдэн хичээл үзсэн бэ?"<<endl;
//    cin >> totalLessons;
//
//    double credits[totalLessons];
//    double points[totalLessons];

//    for(int i = 1; i <= totalLessons; i++){
//        cout<<"Хичээл: "<<i<<" Кредит"<<" : ";
//        cin>>credits[i];
//        cout<<"Хичээл: "<<i<<" Оноо"<<" : ";
//        cin>>points[i];
//        totalCredits = totalCredits + credits[i];
//        cout<<"-----------------------------------------"<<endl<<endl;
//    }
//
//    calcRatingScore(points, ratingScore);

    cout <<"size:"<< ratingScore.size()<<endl;
    for(int i = 0; i < ratingScore.size(); i++) {
        total = myCredits[i] * ratingScore[i];// chanariin onoo
        sum = sum + total;
    }

    gpa = sum / allCredit;
    cout<<"My GPA: "<<gpa<<endl;

    return 0;
}




































































































































	



